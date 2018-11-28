obj-m += hello.o

all:
	echo "You need to use the options!"	

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	sudo dmesg -C

test:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	sudo insmod hello.ko whom="Vlad" howmuch=4
	dmesg
	sudo rmmod hello.ko
	dmesg

module_compile:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

module_clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

module_insert:
	sudo insmod hello.ko

module_remove:
	sudo rmmod hello.ko

logs_clean:
	sudo dmesg -C

logs_show:
	dmesg

