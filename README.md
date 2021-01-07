# cpp_coding
Random practise cpp

library linking

Compiler flags:
-L is to show where libraries of particular library are placed
-l is for linking the libraries those are usually in following format libfmt.a and they are linked as -lfmt
-I is for include directory

example: 

  "-LC:\\Users\\tomva\\Documents\\1links\\Git\\Git\\cpp_libs\\fmt\\Build",
  "-I",
  "C:\\Users\\tomva\\Documents\\1links\\Git\\Git\\cpp_libs\\fmt\\include",
  "-lfmt",

this is working example of how fmt library is linked

if library includes dlls, those must usually be placed to the project root (or to the place where compiler can find them)
Atleast I haven't found any other way yet.

Building the libraries:

usually when cloned from the git or similar, is cmake used to generate the build files to a build directory.
cmake flags can be set from the cmake gui most conveniently.

when build files are generated you can build the library by running mingw32-make -j24 from the build directory
where the makefile etc. are placed.

IMPORTANT

if something does not work check that dlls are placed in the correct place
