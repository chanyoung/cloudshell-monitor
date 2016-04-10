# Cloudshell-monitor

This is a simple monitoring program for Odroid Cloudshell TFT 2.2" LCD.  


Program is currently just print out "Hello world!", but it will be improved to 
show networking status and many different useful informations for server.

## How to start the program automatically

* Step 1: Auto login

```
$ vi /etc/init/tty1.conf
#exec /sbin/getty -8 38400 tty1
exec /bin/login -f USERNAME < /dev/tty1 > /dev/tty1 2>&1
```

* Step 2: Add your program into ~/.bashrc

```
$ vi ~/.bashrc
if [ $(tty) == /dev/tty1 ]; then
	/PATH/TO/YOUR/PROGRAM
fi
```
