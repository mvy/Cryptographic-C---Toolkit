LFSR Representation
===================

Since many article and tutorials are using differents words and representation
for LFSR, here is our terminology.

At the moment our LFSR only deal with binary values.

Here is a representation of a LFSR of 32 bits
<code>
-------------------------------------
|     |     |     |     |     |     |
| S32 | S31 | ... | S 3 | S 2 | S 1 |
|     |     |     |     |     |     |
-------------------------------------
</code>
it is stored as an int.

Each Si elements are called *stages*.

Masks and Taps
--------------

## Masks / Characteristic polynomial
A mask is a binary value used to acces some part of a LFSR or to set the
coefficient list which is used to shift the LSFR

Masks follow the same order as bit orientation. E.g: MASK1 is 0x00000001, MASK2
is 0x00000002, ..., MASK32 is 0x80000000. (For 32 bits systems)
In brief, MASKi has the ith bit set to 1.

Masks can be used to express a LFSR using its *characteristic polynomial*
[Canteau]

## TAPS / Feedback polynomial
TAPS are dependent of the architecture (at the moment, but they should depend
the LFSR length in the future). They are like mask but in reverse order
(MASK1=TAP32)

TAPS can be used to express a LFSR using its *feedback/connection polynomial*
(only for 32 bits at the moment)


## Singularity
If the feedback polynomial of the LFSR has a degree equal to the length of the
LFSR, then this LFSR is *non-singular*.
Non-singular LFSR are periodic of period not exceeding `2^{L}-1`.
Singular LFSR are utimately periodic.

Berlekam Massey
===============

TODO

    [Canteau]: Anne Canteaut -- Encyclopedia of Cryptography and Security, H.
van Tilborg, ed, Springer, 2005 -- Extracts on 
http://www-roc.inria.fr/secret/Anne.Canteaut/encyclopedia.pdf
