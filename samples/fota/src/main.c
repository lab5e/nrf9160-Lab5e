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

#include "fota.h"

LOG_MODULE_REGISTER(app_main, CONFIG_APP_LOG_LEVEL);

void main() {
	fota_client_info client_info = {
		manufacturer: "Exploratory Engineering",
		model_number: "EE-FOTA-00",
		serial_number: "1",
		firmware_version: CONFIG_APP_FIRMWARE_VERSION,
	};

	// Initialize the application and run any self-tests before calling fota_init.
	// Otherwise, if initialization or self-tests fail after an update, reboot the system and the previous firmware image will be used.

	int ret = fota_init(client_info);
	if (ret) {
		LOG_ERR("fota_init: %d", ret);
		return;
	}
}
