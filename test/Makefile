
CC = gcc
CCDIR = coverage
CCOBJDIR = $(CCDIR)/obj
CFLAGS = -I../bin -L../bin
LIBS = -lbmff

.SECONDEXPANSION:
OBJ_TESTS := $(patsubst %.c, %.o, $(wildcard *.c))

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

all: tests

.PHONY: style tests check clean

style:
	astyle --style=linux -n test/*.h test/*.c

%.o: %.c
	$(CC) -o $@ $< $(CFLAGS) $(LIBS)

deps:
	$(MAKE) -C ../ static

tests: deps $(OBJ_TESTS)

check: tests
	./test-runner.sh
ifeq ($(COVERAGE), 1)
	mkdir -p $(CCDIR)
	rm -f *.gcno
	rm -f $(CCOBJDIR)/*.gcda
	mv bin/*.gcno $(CCOBJDIR)/bin/
	lcov --directory $(CCOBJDIR) --capture --output-file $(CCDIR)/coverage.info
	genhtml --output-directory $(CCDIR)/html $(CCDIR)/coverage.info
endif

clean:
	rm -f -r $(ODIR) $(CCDIR)
	find . -type f -name '*.o' -exec rm {} \;
	find . -type f -name '*.o.dSYM' -exec rm {} \;
	find . -type f -name '*.o.gcno' -exec rm {} \;
	find . -type f -name '*.o.gcda' -exec rm {} \;
	find . -type f -name 'gmon.out' -exec rm {} \;
