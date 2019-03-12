-------------------
Generate a keypair
-------------------
gpg --gen-key

----------------------
Exporting a public key
----------------------
gpg --armor --export you@example.com > mykey.asc

--------------------------------------------------------
To transfer eeprom file from BeagleBone to local Desktop
--------------------------------------------------------
scp root@192.168.7.2:/sys/bus/i2c/devices/0-0050/eeprom ~/Desktop

---------------------------------------------------
To generate detached signature for eeprom using key
---------------------------------------------------
gpg --clearsign eeprom
gpg --detach-sign eeprom