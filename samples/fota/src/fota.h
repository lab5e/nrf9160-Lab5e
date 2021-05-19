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

#pragma once

// fota_client_info holds info that is reported by the LwM2M client.
// Most fields can have arbitrary data but the firmware_version field
// should match the version of a firmware image uploaded to https://api.nbiot.engineering/.
typedef struct {
	char *manufacturer;
	char *model_number;
	char *serial_number;
	char *firmware_version;
} fota_client_info;

// fota_init assumes that the LTE Link Control subsystem is initialized and a connection established.
// It initializes the Firmware-over-the-Air subsystem, starting the LwM2M client which downloads and installs firmware
// updates, rebooting the device as necessary.
// Call this function after you've initialized your application and done any self-tests to confirm that the system is
// functional after an update; otherwise, reboot the device and it will revert to the the previous confirmed image.
int fota_init(fota_client_info client_info);
