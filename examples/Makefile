
CC = gcc
CCOBJDIR = $(CCDIR)/obj
CFLAGS = -I../bin -L../bin
LIBS = -lbmff

.SECONDEXPANSION:
OBJ_EXS := $(patsubst %.c, %.o, $(wildcard *.c))

DEBUG ?= 0
PROFILING ?= 0

ifeq ($(PROFILING), 1)
	CFLAGS += -pg
	DEBUG = 1
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g
else
	CFLAGS += -O2
endif

all: examples

.PHONY: style tests check clean

style:
	astyle --style=linux -n examples/*.h examples/*.c

%.o: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

deps:
	$(MAKE) -C ../ static

examples: deps $(OBJ_EXS)

clean:
	rm -f -r $(ODIR) $(CCDIR)
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.o.dSYM' -exec rm {} \;
	find . -type f -name '*.o.gcno' -exec rm {} \;
	find . -type f -name '*.o.gcda' -exec rm {} \;
	find . -type f -name 'gmon.out' -exec rm {} \;
