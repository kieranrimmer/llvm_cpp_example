
## What is this?

This is an olde example of the LLVM C++ backend, ported onto LLVM 5.0.

I'm writing a compiler and want to use LLVM for the backend.  This is useful as a sandbox / example.

### Compilation

```
clang++ -g -O3 `llvm-config --cxxflags --ldflags --system-libs --libs core` main.cpp -o toy 

```

### Acknowledgement

This is entirely based upon an example from Eloy Duran

https://github.com/alloy

...uning the now defunct c++ backend for llvm.  I'm finding it useful to port this code to llvm 5.0
by way of an example.