#include <rose.h>

int main(int argc, char* argv[])
{
    // Build the AST
    SgProject* sage_project = frontend(argc, argv);

    // Run AST consistency tests
    AstTests::runAllTests(sage_project);

    // Manipulate the AST...

    // Generate source code from the AST and then compile it
    return backend(sage_project);
}
