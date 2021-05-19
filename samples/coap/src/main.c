/*
	Copyright [2019] [Exploratory Engineering]
	Modifications Copyright [2021] [Lab5e AS]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.#include <zephyr.h>
*/   

#include <zephyr.h>
#include <logging/log.h>

#include "coap.h"

LOG_MODULE_REGISTER(app_main, CONFIG_APP_LOG_LEVEL);

static int message_post(struct coap_resource *resource, struct coap_packet *request, struct sockaddr *addr, socklen_t addr_len) {
	coap_endpoint *coap = resource->user_data;

	uint16_t payload_len;
	const uint8_t *payload = coap_packet_get_payload(request, &payload_len);

	uint8_t *buf = k_calloc(payload_len + 1, 1);
	memcpy(buf, payload, payload_len);
	LOG_INF("Received CoAP POST: %s", log_strdup(buf));
	k_free(buf);

	int err = coap_endpoint_respond(coap, request, COAP_RESPONSE_CODE_CREATED, NULL, 0, addr, addr_len);
	if (err != 0) {
		LOG_ERR("coap_endpoint_respond: %d", err);
	}

	return 0;
}

static const char * const message_path[] = { "message", NULL };
static struct coap_resource resources[] = {
	{
		path: message_path,
		post: message_post,
	},
	{},
};

void main() {
	LOG_INF("CoAP sample application started");

	struct sockaddr_in local_addr = {
		.sin_family = AF_INET,
		.sin_port = htons(5683),
	};
	coap_endpoint *coap = coap_endpoint_init((struct sockaddr *)&local_addr, sizeof(local_addr), resources);
	if (coap == NULL) {
		LOG_ERR("coap_endpoint_init");
		return;
	}
	resources[0].user_data = coap;

	struct sockaddr_in remote_addr = {
		.sin_family = AF_INET,
		.sin_port = htons(5683),
	};
	net_addr_pton(AF_INET, "172.16.15.14", &remote_addr.sin_addr);
	uint8_t *msg = "Hello!";
	const char * const path[] = { "straight", "and", "narrow", NULL };
	int ret = coap_endpoint_post(coap, (struct sockaddr *)&remote_addr, sizeof(remote_addr), path, msg, strlen(msg));
	if (ret != COAP_RESPONSE_CODE_CREATED) {
		LOG_ERR("coap_endpoint_post: %d", ret);
		return;
	}
	
	LOG_INF("Sent Coap POST");
}
