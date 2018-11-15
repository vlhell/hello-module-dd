ifneq ($(KERNELRELEASE),)
obj-m := hello.o
else
KDIR := /lib/modules/$(shell uname -r)/build
all:
	$(MAKE) -C $(KDIR) M=$(shell pwd)
test:
	sudo dmesg -C
	sudo insmod hello.ko
	sudo rmmod hello.ko
endif
