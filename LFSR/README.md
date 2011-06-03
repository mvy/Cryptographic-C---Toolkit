The Cryptographic C++ Toolkit: Linear Feedback Shift Register
=============================================================

Linear Feedback Shift Register
------------------------------

> Linear Feedback Shift Registers (LFSRs) are the basic components of many
running-key generators for stream cipher applications, because they are
appropriate to hardware implementation and they produce sequences with good
statistical properties. LFSR refers to a feedback shift register with a linear
function.
Anne Canteaut  -- Encyclopedia of Cryptography and Security, H. van Tilborg,
ed, Springer, 2005

(See copy here: [1])

LFSR as running key
-------------------

In order to be used as a running key in a stream cipher, LSFRs need to comply
to a certain level of robustness.
It has been proven (*add source please*) that with a sufficient length of LFSR
output, one could determine the initial state of the register. If the feedback
taps are parts of the key, the can be determine using the Berlekamp-Massey
algorithm.

## Filtered LFSR

Filtered LFSR are LFSR wher the output is not provide by the last bit which is
dismissed from the register at each step. Instead it is computed by a
combination of bits of the register. (_e.g._ (TAP1 and TAP2) OR (TAP12 AND
TAP11) )

Courtois and Meier proposed a method that can break filtered LFSR with high
degree level. 
*so we will need to check other parameters... see Anne's article to elaborate a
todo*

See Also
---------

- [1]
- [2]

[2]: http://en.wikipedia.org/wiki/Linear_feedback_shift_register
[1]: http://www-roc.inria.fr/secret/Anne.Canteaut/encyclopedia.pdf
