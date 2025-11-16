obj-m += hello1.o
obj-m += hello2.o

ccflags-y := -I$(PWD)/inc

CFLAGS_hello1.o := -g -O0
CFLAGS_hello2.o := -g -O0

all:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
