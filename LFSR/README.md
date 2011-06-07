The Cryptographic C++ Toolkit: Linear Feedback Shift Register
=============================================================

Content
-------

The LFSR contains the following sources:

- src/LFSR.hh : implementation of the LFSR
- src/aSyncLFSR.hh : implementation of asynchronous LFSR
- src/maskntapNN.hh : list of masks and taps for 32 and 64 implementations
- src/BerlekampMassey.hh : implementation of the Berlekamp Massey algorithm for
  linear complexity computation and LFSR polynomial reduction.
- test/BerlekampMassey_test.cc : test of the BerlekampMassey algorithm
- test/LFSR_test.cc : test of a 32 bits LFSR
- test/ReductionEquality_test.cc : test of LFSR reduction
- test/ShortLFSR_test.cc : test of short LFSR
- test/mseq_test.cc : test of maximum sequence LFSR
