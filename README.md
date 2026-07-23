# Memory Leak Detector

A memory profiler/leak detector built in C++. It intercepts heap allocation
calls — currently `malloc` and `free` — via `LD_PRELOAD`, allowing custom
tracking and reporting logic to run alongside normal program execution
without modifying the target program itself.

## Status

**Day 1** — Basic interception in place. Overrides forward to the real
`malloc`/`free` via `dlsym(RTLD_NEXT, ...)` and log each call. No leak
tracking yet.

## Usage

### Building the interceptor

From the `source/` directory:
```bash
g++ intercept_library.cpp -o ../build/intercept_library.so -fPIC -shared
```
### Building target executable
From the  `test_programs/` directory:
```bash
g++ basic_clean_test.cpp -o ./test_builds/basic_clean_test

```

### Running a program with the interceptor

From the root directory:
```bash
LD_PRELOAD=./build/intercept_library.so ./test_programs/test_builds/basic_clean_test
```

Any dynamically-linked executable can be substituted for the test program above.

### Modifying interception behavior

1. Edit `source/intercept_library.cpp` with your changes.
2. Rebuild using the build interceptor command above.
3. Run any target program with `LD_PRELOAD` pointing at the rebuilt `.so`.