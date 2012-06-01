How to use Clang as frontend for ROSE?
======================================

We are using LLVM and Clang version 3.0 ([dowload page](http://llvm.org/releases/download.html#3.0) / [LLVM](http://llvm.org/releases/3.0/llvm-3.0.tar.gz) / [Clang](http://llvm.org/releases/3.0/clang-3.0.tar.gz)).
The Clang interface is only tested for C support now, but we are moving toward C++ support.

``` bash
# Download and Unpack
  wget http://llvm.org/releases/3.0/llvm-3.0.tar.gz
  wget http://llvm.org/releases/3.0/clang-3.0.tar.gz
  tar -xzf llvm-3.0.tar.gz
  cd llvm-3.0-src/tools/
  tar -xzf ../../clang-3.0.tar.gz
  mv clang-3.0-src clang
  cd ../..

# Build and Intall
  mkdir build-llvm
  cd build-llvm
  ../configure --prefix=$INSTALL_DIR
  export REQUIRES_RTTI=1
  make -jX
  make install

# Need to update the path
  export PATH=$INSTALL_DIR/bin:$PATH
```

Then you just have to configure ROSE with "--enable-clang-frontend":
``` bash
  $ROSE_SRC/configure --prefix=$ROSE_INSTALL --enable-clang-frontend
```

