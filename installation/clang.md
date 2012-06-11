ROSE Install Guide - `Clang` Frontend
=====================================

**As of July 1, 2012**:
* `C` support is a *work in progress*
* `C++` support is *planned for the future*

---

**Table of contents**
* [Pre-requisite Software](#pre-requisite-software)
* [Build and Install `ROSE`](#build-and-install-rose)

---

## Pre-requisite Software
* [LLVM](http://llvm.org/releases/download.html#3.0)
* [Clang (v3.0)](http://llvm.org/releases/3.0/clang-3.0.tar.gz)

1. **Download** the source tarballs

   ``` bash
     $ curl -O http://llvm.org/releases/3.0/llvm-3.0.tar.gz
     $ curl -O http://llvm.org/releases/3.0/clang-3.0.tar.gz
   ```

2. **Unpack** the source code

   ``` bash
     # LLVM
     $ tar -xzf llvm-3.0.tar.gz

     # Clang - must be unpacked into [$LLVM_SRC/tools] as [clang]
     $ cd llvm-3.0.src/tools/
     $ tar -xzf ../../clang-3.0.tar.gz
     $ mv clang-3.0.src/ clang/
   ```

3. **Build and install**

   ``` bash
     # use a separate build tree to keep things clean
     $ mkdir build-llvm
     $ cd build-llvm

     # configure
     $ $LLVM_SRC/configure --prefix="/your/desired/install/path/"
     $ export REQUIRES_RTTI=1
  
     # build and install
     $ make
     $ make install
   ```
   
4. **Validate installation**

   * `${LLVM_INSTALL}/bin/clang`
   * `${LLVM_INSTALL}/bin/llvm-config`
   * `${LLVM_INSTALL}/include/*/*.inc` files: could be missing if you ran `make install` without running `make` first.
     (Observed on `32-bit RHEL5` and `64-bit Ubuntu`.)

     ```bash
       $ find "${LLVM_INSTALL}" -name "*.inc"
       ${LLVM_INSTALL}/include/clang/AST/AttrImpl.inc
       ...
     ```

## Build and Install `ROSE`

1. **Configure** `ROSE` to use the `Clang` frontend

   ``` bash
     # LLVM/Clang just needs to be in your `$PATH` for this to work.
     # ROSE uses `llvm-config` during `$ROSE/configure` to setup the
     # necessary header/library paths, flags, etc.
     $ export PATH="$LLVM_INSTALL/bin:$PATH"
   
     # use a separate build tree to keep things clean
     $ mkdir build-rose
     $ cd build-rose
  
     # --enable-clang-frontend
     $ $ROSE/configure --prefix="$ROSE_INSTALL" --enable-clang-frontend
   ```

2. **Build and install**

   ``` bash
     $ make
     $ make install
   ```
