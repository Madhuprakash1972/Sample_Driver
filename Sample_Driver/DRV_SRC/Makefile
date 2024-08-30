#DRV_NAME = Sample_drv.ko

obj-m += Sample_drv.o

KERN_DIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERN_DIR) M=$(shell pwd) modules
	rm   *.mod.c *.o *.order *.symvers
clean:
	make -C $(KERN_DIR) M=$(shell pwd) clean

