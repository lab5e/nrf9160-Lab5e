# Hello world

This example prints the device IMSI and IMEI, connects to the mda.lab5e APN, and sends a simple message.

## Prerequisites

Please make sure you've followed [the instructions in the main README](../../README.md) before proceeding.

## Build and run

Now, let's get down to the business of sending data over NB-IoT.  Once you have your serial terminal application open and connected, and you have connected the nRF9160 DK to your computer via USB, build and flash the example application to the nRF9160 DK, as follows:

nRF9160DK:

```bash
west build nrf9160-Lab5e\samples\hello_world -b nrf9160dk_nrf9160ns -p
```

Thingy91:

```bash
west build nrf9160-Lab5e\samples\hello_world -b thingy91_nrf9160ns -p
```

Flash the sample by running
```bash
west flash
```

Once the application is flashed to the device, it will immediately begin running. In your serial terminal application you will see a lot of output about Zephyr booting, then possibly some delay, and then you will see the following application output:

	Example application started.
	IMEI: <imei>
	IMSI: <imsi>
	Connecting...

At this point, the application will try to connect to the IoT network, but it will not succeed because the device is not yet registered on the NB-IoT Developer Platform. Now is the time to copy the IMEI and IMSI and register the device as described in the [Getting Started](https://docs.nbiot.engineering/tutorials/getting-started.html) tutorial.

After registering the device, restart the application by pressing the RESET button on the nRF9160 DK. You will see the same output as before, but after some time (15-20 seconds, be patient!) you will additionally see that the device connected to the network and sent a message. On the device page on the Developer Platform you will also see that the message has been successfully transmitted.

Well done!
