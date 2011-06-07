Cryptographic C++ Toolkit: Linear Feedback Shift Register
=========================================================

Testing
-------

Run the cmake installation : 
- cmake .
- make
- make test

The tests programs will then run and check against know behaviour if everything
goes well.

Usage
-----
TODO

Developement
------------

To control the version number, use CMakeLists.txt.
To change the compilation flag, change CMAKE_CXX_FLAGS and
CMAKE_CXX_FLAGS_Debug in the CMakeLists.txt.

By default cmake will run in release configuration. To switch between Release
and Debug mode use : 

    cmake -DCMAKE_BUILD_TYPE=Debug .
    cmake -DCMAKE_BUILD_TYPE=Release .
