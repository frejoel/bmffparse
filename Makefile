
CC = gcc
ODIR = bin
CCDIR = coverage
ONAME = libbmff
INSTALL_DIR = /usr/local
CCOBJDIR = $(CCDIR)/obj
CFLAGS = -Ibin -Lbin
LIBS = -lbmff
SRC_HDRS = src/bmff.h src/boxes.h src/descriptors.h

.SECONDEXPANSION:
OBJ_SRC := $(patsubst %.c, %.o, $(wildcard src/*.c))

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

all: static tests examples

.PHONY: style static tests check clean

style:
	astyle --style=linux -n src/*.h src/*.c

static: $(OBJ_SRC)
	mkdir -p $(ODIR)
	ar rcs $(ODIR)/$(ONAME).a $(OBJ_SRC)
	cp $(SRC_HDRS) $(ODIR)/

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

install: static
	mkdir -p $(INSTALL_DIR)/include/$(ONAME)
	mkdir -p $(INSTALL_DIR)/lib
	cp $(ODIR)/*.h $(INSTALL_DIR)/include/$(ONAME)/
	cp $(ODIR)/$(ONAME).a $(INSTALL_DIR)/lib/

remove:
	rm -f $(INSTALL_DIR)/include/$(ONAME)/*.h
	rm -r -f $(INSTALL_DIR)/include/$(ONAME)
	rm -f $(INSTALL_DIR)/lib/$(ONAME).a

tests: static
	$(MAKE) -C test/

examples: static
	$(MAKE) -C examples/

check:
	$(MAKE) -C test/ check

clean:
	$(MAKE) -C test clean
	rm -f -r $(ODIR) $(CCDIR)
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.o.dSYM' -exec rm {} \;
	find . -type f -name '*.o.gcno' -exec rm {} \;
	find . -type f -name '*.o.gcda' -exec rm {} \;
	find . -type f -name 'gmon.out' -exec rm {} \;
