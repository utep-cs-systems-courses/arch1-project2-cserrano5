COMMON_OBJECTS	=

CPU 		= msp430g2553

CFLAGS 		= -mmcu=${CPU} -I../h

LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler for internal make rules

CC		= msp430-elf-gcc

AS		= msp430-elf-as


all: buttonMain.elf

buttonMain.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o wdinterruptHandles.o led.o switches.o buttonMain.o buzzer.o state_machine.s ../lib/libTimer.a 

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: buttonMain.elf
	msp430loader.sh buttonMain.elf

clean:
	rm -f *.o *.elf *.c~ *.h~

