# Firmware over the air (FOTA)

Before deploying a device into the field, you probably want to have a way to update it without someone having to manually get to the device and install a new firmware change. [Span](https://span.lab5e.com/) has implemented the firmware update part of LwM2M standard to simplify the process of firmware updates. This sample implements the minimum of what you need on the device side to do a firwmare update over the air. .

## Prerequisites

Please make sure you've followed [the instructions in the main README](../../README.md) to set up the build toolchain and register your device.


## Build and run fota

First you have to generate a private key for signing the firmware images

```sh
imgtool keygen --key cert.pem --type rsa-2048
```

Build the firmware and flash it to the device by running

nRF9160DK:

```bash
west build nrf9160-Lab5e\samples\fota -b nrf9160dk_nrf9160ns -p
```

Thingy91:

```bash
west build nrf9160-Lab5e\samples\fota -b thingy91_nrf9160ns -p
```

Flash the sample by running
```bash
west flash
``````

_Note: The default board is the nRF9160 Development Kit. If you want to build and upload to another nrf9160-based board, you have to add `-b <board-name>` for the build command above. So to build for the Thingy:91, the command would be: `west build -b nrf9160_pca20035ns samples/fota`_

Now, modify the firmware version on the command line (or by editing [prf.conf](prj.conf)), build again (but don't flash!).

```sh
rm -rf build  # unfortunately necessary, or Zephyr will not see the version change
pipenv run west build -- -DCONFIG_APP_FIRMWARE_VERSION=\"1.0.1\"
```

Login to the [Span](https://span.lab5e.com/) and go to the firmware tab for the collection your device is registered.

1. Choose «Device based management» as _Firmware management_ for the collection.

    ![Firmware management screenshot](img/management.png)

1. Upload the binary you just built (`build/zephyr/app_update.bin`) as version `1.0.1`.

    ![Upload screenshot](img/upload.png)


1. Go to the devices tab for the collection and choose your device.
1. Under the firmware tab for the device you'll see the current firmware status for the device. Since we haven't uploaded the 1.0.0 firmware to the IoT Gateway, it doesn't know much details about what's running on the device yet.
1. Change the target firmware image to version 1.0.1 and click the «Update device target firmware»-button.

    ![Firmware target screenshot](img/target.png)

The device state should change to *Pending*. A firmware upgrade will be triggered on the device the next time it updates its LwM2M registration — which is every 10 minutes, so in the interest of time you might just reboot the device. After it connects to the network and registers with the LwM2M server, it will start to download the image. Now the device state should change to *Downloading*. A couple minutes later, it will reboot with the new firmware and the state should change to *Current*. Et voilà!

![Firmware details screenshot](img/details.png)
