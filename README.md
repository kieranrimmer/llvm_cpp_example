
## What is this?

This is an old example of the LLVM C++ backend, ported onto LLVM 5.0.

I'm writing a compiler and want to use LLVM for the backend.  This is useful as a sandbox / example.

All it actually does is print out the LLVM IR code.

### What does this reprepsent?

main.cpp is the llvm c++ backend representation of the following c program:

```
#include <stdio.h>

int some_function(int input)
{
  return input * 2;
}

int main()
{
  int answer = some_function(21);
  printf("Answer is %d\n", answer);
  return 0;
}

```


### Compilation

```
clang++ -g -O3 `llvm-config --cxxflags --ldflags --system-libs --libs all` main.cpp -o toy 

```

### Run it

```
./toy
```

### Acknowledgement

This is entirely based upon an example from Eloy Duran

https://gist.github.com/alloy/d86b007b1b14607a112f

https://github.com/alloy

...using the now defunct c++ backend for llvm.  I'm finding it useful to port this code to llvm 5.0
by way of an example.