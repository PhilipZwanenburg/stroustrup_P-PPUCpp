# Learning C++

This project contains sample solutions to the drills (and some exercises) of the 2nd edition (2014) of [Programming - Principles and Practice Using C++](http://www.stroustrup.com/programming.html) by Bjarne Stroustrup.

## Running the codes

Compile the codes using the Makefiles in the 'drills' and 'exercises' directories after modifying the src directory path.

The following external libraries are used:
	- [FLTK](http://www.fltk.org/) (tested with version 1.3.4)

To get the code from chapter 12.3 to compile (still with a few warnings), several [modifications](include/graphics) of the [original source](http://stroustrup.com/Programming/PPP2code/) files were necessary. All modifications have a 'PZwan_modified' string in a comment explaining the change. The required modifications were obtained from [this webpage](https://watashigaseigida.blogspot.ca/2016/06/getting-stroustrups-fltk-code-to-work.html).



## Installing libraries

### FLTK

After installing the FLTK library, test that all is working correctly using the [hello world program](drills/ch12/hello_fltk/hello_fltk.cpp) by setting the appropriate folder path in the [drills Makefile](drills/Makefile).
The include and library flags can be obtained by running:
```sh
$ /full_path_to_fltk_root/fltk-config --compile /full_path_to_hello_fltk/hello_fltk.cpp
```
