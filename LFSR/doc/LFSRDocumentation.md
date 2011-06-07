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

### LFSR Representation

Since many article and tutorials are using differents words and representation
for LFSR, here is our terminology.

At the moment our LFSR only deal with binary values.

Here is a representation of a LFSR of 32 bits

    -------------------------------------
    |     |     |     |     |     |     |
    | S32 | S31 | ... | S 3 | S 2 | S 1 |
    |     |     |     |     |     |     |
    -------------------------------------

it is stored as an int.

Each Si elements are called *stages*.

### Masks and Taps

#### Masks / Characteristic polynomial
A mask is a binary value used to acces some part of a LFSR or to set the
coefficient list which is used to shift the LSFR

Masks follow the same order as bit orientation. E.g: MASK1 is 0x00000001, MASK2
is 0x00000002, ..., MASK32 is 0x80000000. (For 32 bits systems)
In brief, MASKi has the ith bit set to 1.

Masks can be used to express a LFSR using its *characteristic polynomial*
[Canteau]

#### TAPS / Feedback polynomial
TAPS are dependent of the architecture (at the moment, but they should depend
the LFSR length in the future). They are like mask but in reverse order
(MASK1=TAP32)

TAPS can be used to express a LFSR using its *feedback/connection polynomial*
(only for 32 bits at the moment)


### Singularity
If the feedback polynomial of the LFSR has a degree equal to the length of the
LFSR, then this LFSR is *non-singular*.
Non-singular LFSR are periodic of period not exceeding `2^{L}-1`.
Singular LFSR are utimately periodic.


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

Berlekam Massey Algorithm
-------------------------



See Also
---------

- [Anne Canteaut's article][1]
- [Wikipedia][2]
- [Student project][3]

[2]: http://en.wikipedia.org/wiki/Linear_feedback_shift_register
[1]: http://www-roc.inria.fr/secret/Anne.Canteaut/encyclopedia.pdf
[3]: http://www.cayrel.net/IMG/pdf/enonceLFSR.pdf
