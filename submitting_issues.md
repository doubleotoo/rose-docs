Submitting Issues
=================

Please follow the style and structure of [rose-compiler/rose-docs/issues/2](https://github.com/rose-compiler/rose-docs/issues/2).

Here is the **[Markdown](http://daringfireball.net/projects/markdown/)** for that issue:

    ### Problem

    Currently, there is no clear or definitive *recipe* on how to access **array dimension information** using ROSE.

    As a result, the [rose-public](https://mailman.nersc.gov/mailman/listinfo/rose-public) mailing list contains [many separate threads](https://www.google.com/search?client=safari&rls=en&q=site:https://mailman.nersc.gov/pipermail/rose-public+array+dimension&ie=UTF-8&oe=UTF-8#hl=en&client=safari&rls=en&sclient=psy-ab&q=site:https%3A%2F%2Fmailman.nersc.gov%2Fpipermail%2Frose-public+array+dimensions&oq=site:https%3A%2F%2Fmailman.nersc.gov%2Fpipermail%2Frose-public+array+dimensions&aq=f&aqi=&aql=1&gs_l=serp.3...1669712.1669712.0.1670080.2.2.0.0.0.0.173.338.0j2.2.0.eqn%2Cfixedpos%3Dfalse%2Cboost_normal%3D40%2Cboost_high%3D40%2Ccconf%3D0-95%2Cmin_length%3D2%2Crate_low%3D0-015%2Crate_high%3D0-015.1.0.0.SMLRHUX6MK0&pbx=1&fp=1&biw=1629&bih=1008&bav=on.2,or.r_gc.r_pw.r_cp.r_qf.,cf.osb&cad=b) concerning the same topic--in this case, *how to access array dimension information*. 

    ##### Examples

    1. If there is a reference `a[i][j]`, i want to know that `a` is a 2-D array. [[link]](https://mailman.nersc.gov/pipermail/rose-public/2011-February/000734.html)

    2. If i have a reference to `a[i][j]` in a subtree and the array `a` is declared to have 100 rows and 100 columns elsewhere, i want to get these values. [[link]](https://mailman.nersc.gov/pipermail/rose-public/2011-February/000768.html)

    ---

    ### Solution

    * Write a `FAQ` entry that links to a `Tutorial`.

    ---

    #### Notes

    * [`SageInterface`](http://rosecompiler.org/ROSE_HTML_Reference/index.html) contains a helper function `SageInterface::isArrayReference` in `$ROSE/src/forntend/SageIII/sageInterface/sageInterface.h` (implemented by @chunhualiao).

      ``` C++
      // Check if an expression is an array access (SgPntrArrRefExp). If so, return its
      // name expression and subscripts if requested. Users can use convertRefToInitializedName()
      // to get the possible name. It does not check if the expression is a top level SgPntrArrRefExp.
      bool 	SageInterface::isArrayReference (
          SgExpression *ref,
          SgExpression **arrayNameExp=NULL,
          std::vector< SgExpression * > **subscripts=NULL)
      ```

    * Multi-dimensional C++ arrays are represented as array of array.

    * For code that gathers all dimensions of a C array, you can look at the
       function `populateDimensions` in `$ROSE/projects/RTED/RtedTransf_array.cpp`

Please note these conventions:

* General headings (e.g. `Problem`, `Solution`, `Notes`) are level-3 headings `<h3>`
* Sub-headings (e.g. `Examples`) are level-5 headings `<h5>`
* Sections are divided by a horizontal ruler `<hr>` using three dashes `---`
