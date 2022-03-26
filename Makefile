vpath %.h ./include
vpath %.c ./src
vpath %.a ./lib
vpath %.so ./lib

CFLAGS=-std=c17

.PHONY:clean
%.a:
	$(AR) -rcs ./lib/$@ $^


all:libmod.a libfonts.a main

main:mod.o fonts.o

libmod.a:mod.o fonts.o

libfonts.a:fonts.o

mod.o:mod.h fonts.o

fonts.o:fonts.h

clean:
	$(RM) main ./lib/libmod.a ./lib/libfonts.a mod.o fonts.o