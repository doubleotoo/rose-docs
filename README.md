rose-docs
=========

**User** documentation for the ROSE compiler project.

*This is a work in progress.*

The purpose of this documentation is to make it easy for users to get up and running with ROSE.

Please check out the full documentation [http://rosecompiler.org/documents.html](http://rosecompiler.org/documents.html)

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
