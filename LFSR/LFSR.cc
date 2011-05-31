/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */

#include "lfsr.h"

//TODO: add the error handling!!!

void LFSR::reinit() {
    /* Affects the initial vector to current value */
    this->registerValue = this->initialVector;
}

bool LFSR::getValue() {
    /* Get position ?? and shift */
    bool result = this->getBitAt(1);
    this->shift();
    return result;
}

bool LFSR::getBitAt(int i) {
    /* Shift the LSFR until finding the good bit as LSB, then mask */
    bool bit = (registerValue >> (i-1)) & 1;
    
    return bit;
}

void LFSR::shift() {
    /* Mask all the int, then XOR shifting */
    unsigned int workValue = registerValue & mask;
    
    /* XORing 
     *
     * Masking gives us 0 for unused bits, and X for tapped bits
     * A XOR 0 = A so it does not matter how many 0 we XOR
     * */
    int bit = 
    (workValue >>  0) ^
    (workValue >>  1) ^
    (workValue >>  2) ^
    (workValue >>  3) ^
    (workValue >>  4) ^
    (workValue >>  5) ^
    (workValue >>  6) ^
    (workValue >>  7) ^
    (workValue >>  8) ^
    (workValue >>  9) ^
    (workValue >> 10) ^
    (workValue >> 11) ^
    (workValue >> 12) ^
    (workValue >> 13) ^
    (workValue >> 14) ^
    (workValue >> 15) ^
    (workValue >> 16) ^
    (workValue >> 17) ^
    (workValue >> 18) ^
    (workValue >> 19) ^
    (workValue >> 20) ^
    (workValue >> 21) ^
    (workValue >> 22) ^
    (workValue >> 23) ^
    (workValue >> 24) ^
    (workValue >> 25) ^
    (workValue >> 26) ^
    (workValue >> 27) ^
    (workValue >> 28) ^
    (workValue >> 29) ^
    (workValue >> 30) ^
    (workValue >> 31);
    
    bit = bit & 1;
    
    /* shifting and updating */
    registerValue = (registerValue >> 1) | (bit << 31);
}

LFSR::LFSR(unsigned int mask, unsigned int seed) {
    /* Initialisation */
    this->initialVector = seed;
    this->registerValue = seed;
    this->mask = mask;
}

LFSR::LFSR(const LFSR& l) {
    this->initialVector =  l.initialVector;
    this->registerValue = l.registerValue;
    this->mask = l.mask;
}

LFSR::~LFSR() {
    /* Deletion */
    
}



//TODO TODO TO DO
//TODO TODO TO DO
//TODO TODO TODO TODO TODO TODO TODOOOOO TODODODODO
//TODO TODO TODO TODO TODO TODO TODOO-OO-OO
//TOTODO TODO TODO-OO-OO-OOO TODODODO DO TODODODO DO
