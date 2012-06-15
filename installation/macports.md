ROSE Install Guide - MacPorts
=============================

## Install MacPorts

#### As Admin (sudo)

This step is easy if you have administrator privileges--just download the precompiled
package from the MacPorts website, http://www.macports.org.

#### As User

Installing MacPorts **without administrator privileges** will require you to install
MacPorts from source:

1. **Download** the [latest source](http://www.macports.org/install.php#source)

   ``` bash
     $ curl -O https://distfiles.macports.org/MacPorts/MacPorts-<latest>.tar.gz
   ```

2. **Configure** MacPorts without root privileges. For example,

   ``` bash
     $ $MACPORTS/configure --prefix="/Users/$USER/development/opt/macports" --with-no-root-privileges --with-install-user="$USER" --with-install-group=rose
   ```

3. **Build and install**

   ``` bash
     $MACPORTS $ make
     $MACPORTS $ make install
   ```

4. **$PATH** setup

   ``` bash
     $ export PATH="/Users/$USER/development/opt/macports/bin:$PATH"
   ```

5. **Synchronize** the ports tree

   ``` bash
     $ port -v sync
   ```

   ---
   **Note**: If you are at LLNL, you first need to open your firewall before doing this
   step. You can do so at https://cspservices.llnl.gov/eor.
    
   **Warning**: don't run `port selfupdate`. If your MacPorts base installation is out-of-date,
   [running `port selfupdate`](http://guide.macports.org/chunked/installing.macports.upgrade.html) will
   try to upgrade it. The problem is, the upgrade does not pass the correct `configure` options.
   In the process, the `--with-install-group=<group>` argument becomes malformed/lost.
   Here is an example error message:

   ```bash
     ...
     /usr/bin/install -c -d -o $USER -g THE-LABrose -m 755 /Users/$USER/development/opt/macports
     install: THE-LABrose: Invalid argument
     make[1]: *** [install] Error 67
     make: *** [install] Error 1
   ```
   
6. **Install ports** necessary for ROSE to compile:

   ``` bash
     $ port install git-core wget graphviz libtool doxygen texlive texlive-latex-extra boost gcc44
   ```

   Recommended ports: `ccache`, `graphviz-gui`

   **Install Boost**
   
   ROSE supports boost versions `1.36.0` to `1.47.0` (as of 6/18/2012).
   
   Install a supported version of boost as described in http://www.rosecompiler.org/ROSE_InstallationInstructions.pdf,
   and then update your library load path `$DYLD_LIBRARY_PATH` with your boost library path:

   ```bash
     $ export DYLD_LIBRARY_PATH=</path/to/your/boost/install/lib>:$DYLD_LIBRARY_PATH
   ```

7. **Link libtool to glibtool**

   ``` bash
     $ ln -s "/Users/$USER/development/opt/macports/bin/glibtool" "/Users/$USER/development/opt/macports/bin/libtool"
     $ ln -s "/Users/$USER/development/opt/macports/bin/glibtoolize" "/Users/$USER/development/opt/macports/bin/libtoolize"
   ```

   Make sure your symlinks are working:

   ``` bash
     $ which libtool
     /Users/$USER/development/opt/macports/bin/libtool
     $ which libtoolize
     /Users/$USER/development/opt/macports/bin/libtoolize
   ```

## Build and Install `ROSE`

1. [Fetch ROSE](https://github.com/rose-compiler/rose-docs/tree/master/collaborators#2-fetching-rose)

2. Developers: generate Autotools files
    
   ```bash
     $ cd $ROSE
     $ ./build
   ```

3. **Configure** `ROSE`

   ```bash
     # use a separate build tree to keep things clean
     $ mkdir build-rose
     $ cd build-rose
     
     $ $ROSE/configure --with-CXX_DEBUG=-ggdb3 --with-CXX_WARNINGS=-Wall --with-boost="/Users/$USER/development/opt/macports" --with-gfortran="/Users/$USER/development/opt/macports/bin/gfortran-mp-4.4" --with-alternate_backend_fortran_compiler=gfortran-mp-4.4 GFORTRAN_PATH="/Users/$USER/development/opt/macports/bin/gfortran-mp-4.4"
   ```
4. **Build and install**

   ```bash
     $ make
     $ make install
   ```