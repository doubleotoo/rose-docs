ROSE Install Guide - Mac OS
===========================

* [MacPorts Tool Chain](#macports-tool-chain)

---

## MacPorts Tool Chain

### Install MacPorts (http://www.macports.org)
1. **As Admin (sudo)**: This step is easy if you have administrator privileges--just
download the precompiled package from the MacPorts website.

2. **As User**: Installing MacPorts **without administrator privileges** will
require you to compile MacPorts from source:

    **Download** the [latest source](http://www.macports.org/install.php#source)

   ``` bash
      $ curl -O https://distfiles.macports.org/MacPorts/MacPorts-<latest>.tar.gz
    ```

      Note: If your MacPorts core installation is out-of-date, running `port selfupdate` will try to upgrade it.
      The problem is, the upgrade does not pass the correct `configure` options.
      In the process, the `--with-install-group=<group>` argument becomes malformed/lost.
      Here is an example error message:

      ``` bash
      ...
      /usr/bin/install -c -d -o $USER -g THE-LABrose -m 755 /Users/$USER/development/opt/macports
      install: THE-LABrose: Invalid argument
      make[1]: *** [install] Error 67
      make: *** [install] Error 1
      ```
    --
    **Configure** MacPorts without root privileges. For example,

    ``` bash
      $ $MACPORTS/configure --prefix="/Users/$USER/development/opt/macports" --with-no-root-privileges --with-install-user="$USER" --with-install-group=rose
    ```

    --
    **Build and install**

    ``` bash
      $MACPORTS $ make -j4
      $MACPORTS $ make -j4 install
    ```

    --
    **$PATH** setup

    ``` bash
      $ export PATH="/Users/$USER/development/opt/macports/bin:$PATH"
    ```

    --
    **Update** MacPorts

    ``` bash
      $ port -v selfupdate
    ```

    If you are at LLNL, you first need to open your firewall before doing this
    step. You can do so at https://cspservices.llnl.gov/eor.

    --
    **Install ports** necessary for ROSE to compile:

    ``` bash
      $ port install git-core wget graphviz libtool doxygen texlive texlive-latex-extra boost gcc44
    ```

    Recommended ports: `ccache`, `graphviz-gui`

    --
    **Link libtool to glibtool**

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

### Configure ROSE

``` bash
  $ $ROSE/configure --with-CXX_DEBUG=-ggdb3 --with-CXX_WARNINGS=-Wall --with-boost="/Users/$USER/development/opt/macports" --with-gfortran="/Users/$USER/development/opt/macports/bin/gfortran-mp-4.4" --with-alternate_backend_fortran_compiler=gfortran-mp-4.4 GFORTRAN_PATH="/Users/$USER/development/opt/macports/bin/gfortran-mp-4.4"
```

