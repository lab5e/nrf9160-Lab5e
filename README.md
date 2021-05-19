# Getting started

Open the toolchain manager from nRFConnect and open a shell for the selected toolchain

## Hello World
1) Open west.yml and add the following lines in the remotes section:

```bash
    - name: lab5e
      url-base: https://github.com/lab5e
```

2) Add the following to the projects section:

projects:
```bash
    - name: nrf9160-Lab5e
      remote: lab5e
```

3) Save the file and run 
```bash
west update
```

The folder nrf9160-Lab5e should now appear under ncs\<toolchain version>\nrf\applications

4) Build a sample from the applications folder

nRF9160DK:

```bash
west build nrf9160-Lab5e\samples\hello_world -b nrf9160dk_nrf9160ns -p
```

Thingy91:

```bash
west build nrf9160-Lab5e\samples\hello_world -b thingy91_nrf9160ns -p
```

5) Flash the sample by running
```bash
west flash
```
from the applications folder.

6) Open up JLink RTT Viewer in order to view console output and view IMEI/IMSI necessary for registering your device in [Span](https://span.lab5e.com/).

7) Register your device in Span and reboot in order to send a hello world message.

## COAP
WIP...

## FOTA
WIP...











