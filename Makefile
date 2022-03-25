VPATH=./src
main:mod.o fonts.o
mod.o:fonts.o
fonts.o:fonts.h

.PHONY:clean
clean:
	-rm main mod.o fonts.o