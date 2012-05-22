students
========

A collection of useful *assets* for student interns working on ROSE.

## Installing ROSE

* Mac: https://github.com/rose-compiler/rose/wiki/Installing-ROSE
* Linux: http://rosecompiler.org/ROSE_InstallationInstructions.pdf

**Note**: if you'd like to work on a Linux (RHEL5) machine, please ask. You will
(more than likely) need to have your account setup. This includes allocating
local diskspace `/export/tmp.<your-oun>` for you on that particular machine.

## Developing ROSE

### Validate that you're in the correct POSIX groups
``` bash
  $ id --groups --name
  <your-oun> casc overture rose ...
```

**Note**: Linux users should be developing in their local disk space allocation
`/export/tmp.<your-oun>`. This space is local to the machine, whereas your
`$HOME` directory is mounted on the Network Filesystem (NFS). It's important
to remember that this local space is **not** backed up and should be considered
more-or-less temporary build space.

### Tool chain

* Mac: https://github.com/rose-compiler/rose/wiki/Installing-ROSE
* Linux: `<linux-machine>:/nfs/apps` contains a handful of useful tools (e.g. `gcc`).
  However, you will have to install the `Boost C++ Libraries` by yourself.

## Submitting Code **every 2-3 weeks**

You are expected to submit code for testing and integration on a regular basis.

The rule of thumb is **every 2-3 weeks**.

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

Thanks to Phil Miller (summer 2011) for contributing this.

## Getting Help

Justin should be your first point of contact for any questions/concerns.

## Contributing

Please fork this repository and send us a pull request with useful tips, tricks, or insights
that you come across during your internship with us. We would like to eliminate as many
headaches as possible and remove any barriers that keep you from focusing on the *good stuff*.
