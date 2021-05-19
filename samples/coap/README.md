# Constrained Application Protocol (CoAP)

This sample demonstrates how a device can act as a CoAP node (client and server).

## Prerequisites

Please make sure you've followed [the instructions in the main README](../../README.md) before proceeding.

## Build and run

Navigate to the Live Stream tab of the device you've registered in the [Telenor NB-IoT Service](https://nbiot.engineering/).  Then build the firmware and flash it to the device by running

nRF9160DK:

```bash
west build nrf9160-Lab5e\samples\coap -b nrf9160dk_nrf9160ns -p
```

Thingy91:

```bash
west build nrf9160-Lab5e\samples\coap -b thingy91_nrf9160ns -p
```

Flash the sample by running
```bash
west flash
```

After the device boots, it may take some time before it is connected to the network.  Then, it will send a CoAP POST message upstream and start listening for downstream messages.  You should see the upstream message in the Live Stream tab.

To send a downstream message, select `CoAP` in the Message Type field, enter `message` in the Path field, enter a payload string, check the Encode Payload box, and click Send Message.  The device should report having received the POST request in its serial output.

