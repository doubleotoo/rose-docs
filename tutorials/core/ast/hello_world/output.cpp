#include <iostream>

int main(int argc,char *argv[])
{
  ( *(&std::cout)<<"Hello, World!") << std::endl< char  , std::char_traits< char  >  > ;
  return 0;
}
