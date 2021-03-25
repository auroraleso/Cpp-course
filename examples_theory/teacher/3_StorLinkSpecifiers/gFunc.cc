#include <iostream>

extern
int i;     // defined in another translation unit
int j = 0; // no conflict with "static j" in main file
void g() {
  std::cout << "g:i=" << i << std::endl;
  std::cout << "g:j=" << j << std::endl;
  std::cout << "=========" << std::endl;
}

/*
--------------------------INTERNAL AND EXTERNAL LINKAGE DEF-----------------------------------
        Internal linkage refers to everything only in scope of a translation unit.

        External linkage refers to things that exist beyond a particular translation unit.
        In other words, accessible through the whole program,
        which is the combination of all translation units (or object files).
*/