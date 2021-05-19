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












