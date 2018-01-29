# ISO Base Media File Format Parser
Parses boxes/atoms from the following specs plus a few others.
ISO/IEC 14496-12:2015 (ISO BMFF File Format)
ISO/IEC 23001-7:2016 (Common Encryption in ISO BMFF)

## Overview
This library is intended for content analysis of Mp4/fMp4 files.

This software is licensed under an MIT license.
See the LICENSE file for licensing information.

## Multi-Threading
This library is single threaded and not thread-safe when attempting to
manipulate a single BMFF Context across multiple threads.

It is thread-safe if content is parsed using a separate BMFF Context per
thread.

## Documentation
The `src/bmff.h` header file contains the public API documentation.
This header is distributed with the Library files.

The best place to get started would be the examples which are in the `examples`
directory.
The examples are documented tutorials with instructions on how to work
with the library.

# Installation
## Dependencies
There are currently no external dependencies required to build this library.

It should be noted that development and testing by the author takes place on
Linux (Debian), and to date, no compilation and testing has been on attempted
on Little Endian Architectures.

## Makefile Targets
The Makefile contains the following targets:
- `make static` builds only the static library.
- `make tests` builds the static library and all unit tests.
- `make examples` builds the static library and all examples.
- `make all` or `make` builds all of the above.
- `make install` installs the library.
- `make check` builds static library and unit tests, then executes the tests.

## Debugging
To enable debugging add a `DEBUG=1` argument to the make target.
This will cause the library, unit tests and examples to be built with debugging
enabled.
```
 make all DEBUG=1
```

## Code Coverage
To output HTML code coverage statistics, use the `COVERAGE=1` argument when
using the `check` Make target.

Code Coverage uses `gcov`, `lcov` and `gentml` to gather and render statistics.
If you're using Debian, `gcov` is more than likely already installed, but you'll
need `lcov` which may also install `genhtml`.
```
 sudo apt-get install lcov
```

Run the tests with code coverage enabled:
```
 make check COVERAGE=1
```
The coverage documentation is output into a `coverage/html` directory.
The debug option `DEBUG=1` is automatically enabled when `COVERAGE=1` is set.

## Profiling
To build the library with `gprof` profiling set the variable `PROFILING=1` when
building the target.

`make tests PROFILING=1`
This will build the executables with profiling information.

To get a `gprof` report you will need to execute the executable which will
generate a `gmon.out` file. From there you can export the profiling report using
`gprof`.

### Example
This will build the examples with Profiling enabled, run the bmffinfo example,
output the profiling report to `profile_report.txt` and display the text of
`profile_report.txt` to the screen.

```
 make clean
 make examples PROFILING=1
 ./examples/<<example executable>>
 gprof examples/<<example executable>> > profile_report.txt
 less profile_report.txt
```

## Linux
From a terminal:
```
  make
```
Creates a `bin` directory containing static library and header files.
If you are wanting to build files for debugging pass in a `DEBUG=1` argument.
```
 make DEBUG=1`
```

To clean the repository and start a build from scratch:
```
 make clean
 make
```

To build and run all unit tests validating the library:
```
 make check
```

# Examples
Examples showing how to use the library are in the `examples` directory.
To build the examples:
```
 make examples
```
The examples are also built when using the `all` target.

The executables are built directly in the `examples` directory alongside the
example source code.
```
 ./examples/bmffinfo.o myfile.mp4
```

## Valgrind - Memory Leaks
valgrind example.
```
 valgrind --leak-check=yes --track-origins=yes --log-file=valgrind_report.txt examples/bmffinfo.o myfile.mp4`
```
