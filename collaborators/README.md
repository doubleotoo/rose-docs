collaborators
=============

A collection of useful *assets* for collaborators working on `ROSE`.

**Table of Contents**:

1. [Dashboard](#1-dashboard)
2. [Fetching `ROSE`](#2-fetching-rose)
3. [Installing `ROSE`](#3-installing-rose)
4. [Developing `ROSE`](#4-developing-rose)
5. [Contributing to `ROSE`](#5-contributing-to-rose)
6. [SSH to Remote Machines](#6-ssh-to-remote-machines)
7. [Getting Help](#7-getting-help)
8. [Contributing](#8-contributing)

---

## 1. Dashboard

The dashboard is a work in progress [https://hudson-rose-30:8443/](https://hudson-rose-30:8443/)

## 2. Fetching `ROSE`

* Internal repository:

  ```bash
   $ git clone ssh://<machine>/nfs/casc/overture/ROSE/git/ROSE.git
  ```

* External repository (mirror):

  ```bash
   $ git clone https://github.com/rose-compiler/rose.git
  ```

  **Note**: If the proxy machine does not have Git in it's path (e.g. `~/.bashrc`),
  you will encounter the following error message:

  ``` bash
  $USER@<machine>'s password:
  bash: git-upload-pack: command not found
  fatal: The remote end hung up unexpectedly
  ```

  You can add the following line to your `~/.bashrc` (sourced for a non-interactive shell):

  > ```bash
    source /nfs/apps/git/latest/setup.sh`
    ```

## 3. Installing `ROSE`

* Mac: [rose-docs/installation/macports.md](installation/macports.md)
* Linux: http://rosecompiler.org/ROSE_InstallationInstructions.pdf

**Note**: if you'd like to work on a Linux (RHEL5) machine, please ask. You will
(more than likely) need to have your account setup. This includes allocating
local diskspace `/export/tmp.<your-oun>` for you on that particular machine.

## 4. Developing `ROSE`

### Validate that you're in the correct POSIX groups
``` bash
  $ id --groups --name
  <your-oun> casc overture rose ...
```

**Note**: Linux users should be developing in their local disk space allocation
`/export/tmp.<your-oun>` (created upon request). This space is local to the machine,
whereas your `$HOME` directory is mounted on the Network Filesystem (NFS). It's important
to remember that this local space is **not** backed up and should be considered
more-or-less temporary build space.

### Subscribe to the mailing lists!

* [rose-public@nersc.gov](https://mailman.nersc.gov/mailman/listinfo/rose-public) - for general questions

* [rose-developer@nersc.gov](https://mailman.nersc.gov/mailman/listinfo/rose-developer) - for "internal" communications

### Tool chain

* Mac: https://github.com/rose-compiler/rose/wiki/Installing-ROSE
* Linux: `<linux-machine>:/nfs/apps` contains a handful of useful tools (e.g. `gcc`).
  However, you will have to install the `Boost C++ Libraries` by yourself.

## 5. Contributing to `ROSE`

### Submit Code **every 2-3 weeks**

You are expected to submit code for testing and integration on a regular basis.

The rule of thumb is **every 2-3 weeks**.

> **Summer 2012**: code review is required. Please push to a `-review` branch and then notify either Dan, Leo,
> or Justin.

> For example,

> ```bash
>   $ git push origin HEAD:refs/heads/too1-bugfix-review
> ```

> This policy will be in effect until we switch to using an internally hosted GitHub for the central `rose` repository.

### Useful Definitions

**Incremental development**: developing new functionality in small steps, where the resulting code 
at each step is a useful improvement over the previous state. Contrast to developing an entire feature 
fully elaborated, with no points along the way at which it's externally usable.

**Continuous integration**: incorporating changes from work in progress into a shared mainline as
frequently as possible, in order to identify incompatible changes and introduced bugs as early as
possible. The integrated changes need not be particular increments of functionality as far as the
rest of the system is concerned.

In other words, incremental development is about making one's work valuable as early as possible,
and potentially about getting a better sense of what direction it should take, while continuous
integration is about reducing the risks that result from codebase divergence as multiple people do
development in parallel.

*The question of whether to conditionalize new code is an interesting one. By doing so, one narrows
the scope of continuous integration to just checking for surface incompatibilities in merging the
changed code. Without actually running the new code against the existing tests, the early detection
of introduced bugs is lost. In exchange, multiple people working in the same part of the codebase
become less likely to step on each other's toes, because the relevant code changes are distributed
more rapidly.*

--Thanks to Phil Miller (summer 2011) for contributing this.

## 6. SSH to Remote Machines
Connecting to machines outside of LLNL (through SSH) requires you to open the firewall for your machine.

**Firewall web form**: https://cspservices.llnl.gov/eor -- login with your OUN and PAC

#### SSH Key Pairs (passwordless authentication)
SSH can be set up with public/private key pairs so that you don't have to type your password each time
you SSH into a machine.

1. Generate the SSH key-pair on your machine: (the passphrase is optional)

    ``` bash
    $ ssh-keygen -t rsa
    Generating public/private rsa key pair.
    Enter file in which to save the key (/Users/$USER/.ssh/id_rsa): <enter>
    Enter passphrase (empty for no passphrase): <enter>
    Enter same passphrase again: <enter>
    ```

2. Use `ssh` to create a directory `~/.ssh` on your remote machine:

    ``` bash
    $ ssh <username>@<remote_machine> mkdir -p ~/.ssh
    <username>@<remote_machine>'s password: 
    ```
    
3. Append your SSH public key `id_rsa.pub` to your remote machine's `~/.ssh/authorized_keys` file:

    ``` bash
    $ cat ~/.ssh/id_rsa.pub | ssh <username>@<remote_machine> 'cat >> ~/.ssh/authorized_keys'
    <username>@<remote_machine>'s password:
    ```

4. **That's it!** Now you can login to your remote machine without typing your password.

## 7. Getting Help

Justin (too1) should be your first point of contact for any questions/concerns.

## 8. Contributing

Please fork this repository and send us a pull request with useful tips, tricks, or insights
that you come across during your collaboration with us. We would like to eliminate as many
headaches as possible and remove any barriers that keep you from focusing on the *good stuff*.
