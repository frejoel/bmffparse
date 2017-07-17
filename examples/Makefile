
CC = gcc
ODIR = bin
CCDIR = coverage
INSTALL_DIR = /usr/local
CCOBJDIR = $(CCDIR)/obj
CFLAGS = -I../bin -L../bin
LIBS = -lbmff

.SECONDEXPANSION:
OBJ_EXAMPLES := $(patsubst %.c, %.o, $(wildcard *.c))

DEBUG ?= 0
COVERAGE ?= 0
PROFILING ?= 0

ifeq ($(COVERAGE), 1)
	CFLAGS += -fprofile-arcs -ftest-coverage -fprofile-dir=$(CCOBJDIR)
	DEBUG = 1
endif

ifeq ($(PROFILING), 1)
	CFLAGS += -pg
	DEBUG = 1
endif

ifeq ($(DEBUG), 1)
	CFLAGS += -O0 -g
else
	CFLAGS += -O2
endif

all: deps examples

deps:
	$(MAKE) -C ../ static

.PHONY: style clean

style:
	astyle --style=linux -n *.h *.c

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

examples: deps $(OBJ_EXAMPLES)

clean:
	rm -f -r $(ODIR) $(CCDIR)
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.o.dSYM' -exec rm {} \;
	find . -type f -name '*.o.gcno' -exec rm {} \;
	find . -type f -name '*.o.gcda' -exec rm {} \;
	find . -type f -name 'gmon.out' -exec rm {} \;
