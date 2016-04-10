# Cloudshell-monitor

## How to start the program automatically

* STEP 1: Auto login

```
$ vi /etc/init/tty1.conf

#exec /sbin/getty -8 38400 tty1
exec /bin/login -f USERNAME < /dev/tty1 > /dev/tty1 2>&1
```

* STEP 2: Add your program into ~/.bashrc

```
$ vi ~/.bashrc

# Cloudshell monitor program

if [ $(tty) == /dev/tty1 ]; then
	/PATH/TO/YOUR/PROGRAM
fi
```
