vpath %.h ./include
vpath %.c ./src
vpath %.a ./lib
vpath %.so ./lib

CFLAGS=-std=c17

.PHONY:clean

all:libmod.a libfonts.a main

main:mod.o fonts.o

libmod.a:mod.o fonts.o
	$(AR) -rcs ./lib/$@ $^

libfonts.a:fonts.o
	$(AR) -rcs ./lib/$@ $^

mod.o:mod.h fonts.o
fonts.o:fonts.h

clean:
	$(RM) main ./lib/libmod.a ./lib/libfonts.a mod.o fonts.o