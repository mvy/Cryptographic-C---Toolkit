ToDo List for CCTk:LFSR
=======================

Developement
------------

- Detect 32 vs 64 bits via CMake
- Document the LFSR code
- Review `TODO`s in the LFSR code

- Implement the Courtois Meier test
- Implement a way to counter this (see Anne&quote;s article?)

- Implement the generator for LFSR classes (OS 32/64; legnth of LFSR). It must
take care of optimisation depending on the length of the LFSR.
    - Do not XOR all bits if l < 8
    - Create intermediate values of chars

Validation
----------
- We need to validate the Berlekamp-Massey algorithm
    - Need an input
    - Need test
