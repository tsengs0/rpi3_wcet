CC=arm-none-eabi
CFLAGS=-Wall -O0 -nostdlib -nostartfiles -ffreestanding

TARGET=skeleton

all :
	$(CC)-as start.s -o start.o
	$(CC)-gcc $(CFLAGS) -c $(TARGET).c -o kernel.o
	$(CC)-ld start.o kernel.o -T memmap -o $(TARGET).elf
	$(CC)-objcopy $(TARGET).elf -O binary kernel.img
clean :
	rm -f *.o *.elf *.img
