SageBuilder Tutorials
=====================

## I - Introduction

#### 1 - Hello World

We will learn how to build a C++ Hello World from scratch using the SageBuilder.
The result will be:
``` C++
  #include <iostream>
  
  int main() {
    std::cout << "Hello World !" << std::endl;
    return 0;
  }
```

#### 2 - Hello You

``` C++
  #include <iostream>
  
  int main(int argc, char ** argv) {
    if (argc == 1)
      std::cout << "Hello, what is your name?" << std::endl;
    else if (argc == 2)
      std::cout << "Hello " << argv[1] << "!" <<std::endl;
    else
      std::cout << "I don't know what to do with more than one argument." << std::endl;
    return 0;
  }
```
