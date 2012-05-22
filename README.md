rose-docs
=========

**User** documentation for the ROSE compiler project.

*This is a work in progress.*

The purpose of this documentation is to make it easy for users to get up and running with ROSE.

Please check out the full documentation [http://rosecompiler.org/documents.html](http://rosecompiler.org/documents.html)

## Google is your friend

Use Google to search the [rose-public@nersc.gov](https://mailman.nersc.gov/mailman/listinfo/rose-public) mailing list.

For example, to get help with "Array Dimensions" in ROSE:

  [`site:https://mailman.nersc.gov/pipermail/rose-public array dimensions`](http://www.google.com/search?client=safari&rls=en&q=site:https://mailman.nersc.gov/pipermail/rose-public+array+dimension&ie=UTF-8&oe=UTF-8#hl=en&client=safari&rls=en&sclient=psy-ab&q=site:https%3A%2F%2Fmailman.nersc.gov%2Fpipermail%2Frose-public+array+dimensions&oq=site:https%3A%2F%2Fmailman.nersc.gov%2Fpipermail%2Frose-public+array+dimensions&aq=f&aqi=&aql=1&gs_l=serp.3...1669712.1669712.0.1670080.2.2.0.0.0.0.173.338.0j2.2.0.eqn%2Cfixedpos%3Dfalse%2Cboost_normal%3D40%2Cboost_high%3D40%2Ccconf%3D0-95%2Cmin_length%3D2%2Crate_low%3D0-015%2Crate_high%3D0-015.1.0.0.SMLRHUX6MK0&pbx=1&bav=on.2,or.r_gc.r_pw.r_cp.r_qf.,cf.osb&fp=17c6eb2a8dc3e7bb&biw=1629&bih=1008)

## CONTRIBUTING:

Please share your nifty ROSE tips, tricks, and recipes with us!

### General guidelines

All documentation must be written in **[Markdown](http://daringfireball.net/projects/markdown/)** (not in GitHub Flavored Markdown).
Please use the `.md` extension only.

* Fork [rose-compiler/rose-docs](https://github.com/rose-compiler/rose-docs)
* Develop on the master branch (default after `git-clone`)
* Rebase your branch so that all your changes are reflected in one
  commit
* Push to your GitHub repository - `git push origin master`
* Create a Pull Request from your GitHub repository, include as much
  as you can in the commit message/pull request, following these
[guidelines on writing a good commit message](http://spheredev.org/wiki/Git_for_the_lazy#Writing_good_commit_messages)
* That's it!

### Coding standards

* Please follow some standard coding guidelines, such as those used by Google-originated
open-source projects [http://code.google.com/p/google-styleguide/](http://code.google.com/p/google-styleguide/)

* Use underscores `_` instead of hyphens `-` in file and directory names (e.g. `loop_processing`, not `loop-processing`)

* Annotate source code clearly. Make it helpful!

### Tutorial guidelines

Each tutorial should be:

1. logically grouped

2. fully-contained in its own directory

   a. containing an in-depth explanation

   b. containing example code that
      * fully demonstrates the tutorial's content, (a)
      * actually works (with minor adjustments to the `Makefile`)

```
rose-docs/
  |
  |-- tutorials/
  |   |
  |   |--ast-traversals          (1)
  |   |  |
  |   |  |--hello                (2)
  |   |  |  |
  |   |  |  |--README.md         (a)
  |   |  |  |
  |   |  |  |--example1/         (b)
  |   |  |  |  |--Makefile
  |   |  |  |  `--main.cpp
  |   |  |  |
  |   |  |  |--example2/
  |   |  |  |  |--Makefile
  |   |  |  |  |--header.h
  |   |  |  |  `--main.cpp
  |   |  |  |
  |   |  |  `--example3/
  |   |  |  |  ...
  |   |  |  ...
  |   |  |
  |   |  |
  |   |--ast-rewrites
  |   |  |
  |   |  |--foo ...
  |   |  |
  ... ...  ...
```

## Submitting Issues

Please refer to [submitting_issues.md](https://github.com/rose-compiler/rose-docs/blob/master/submitting_issues.md)
for guidelines on submitting an Issue (request/bug/enhancement).

## TODO

In the future, documentation components may be separated out into their own GitHub repositories
to make use of independent issue tracking, etc.

Documentation may be converted to other formats as necessary. Therefore, the portability
of our documentation is critical. This is one reason why we want to make sure we're conforming
to *standard* practices and technologies.