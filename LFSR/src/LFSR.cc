/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */

#include "LFSR.hh"

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

unsigned char LFSR::getChar() { 
	unsigned char result = 0;
	for (char i = 0; i < 8; i++)
		result |= (this->getValue() << i);
	return result;
}

unsigned short LFSR::getShort() { 
	unsigned short result = 0;
	for (unsigned char i = 0; i < sizeof(unsigned short); i++)
		result |= (this->getChar() << i*8);
	return result;
}

unsigned int LFSR::getInt() {
	unsigned int result = 0;
	for (unsigned char i = 0; i < sizeof(unsigned int); i++) 
		result |= (this->getChar() << i*8);
	return result;
}

unsigned long LFSR::getLong() {
	unsigned long result = 0;
	for (unsigned char i = 0; i < sizeof(unsigned long); i++) 
		result |= (this->getChar() << i*8);
	return result;
}

void LFSR::shift() {
    /* Mask all the int, then XOR shifting */
    unsigned int workValue = registerValue & mask;

    /* We now applie 8bits masks to workValue */
    unsigned int least32   = (workValue & LEAST32) >> 0; //Least signficants 8 bits
    unsigned int low32     = (workValue & LOW32)   >> 8; //Lower significants 8 bits
    unsigned int high32    = (workValue & HIGH32)  >> 16; //Higher significants 8 bits
    unsigned int most32    = (workValue & MOST32)  >> 24; //Most significants 8 bits

#ifdef LFSR64BITS
     /* We now applie 8bits masks to workValue */
    unsigned int least64   = (workValue & LEAST64) >> 32; //Least signficants 8 bits
    unsigned int low64     = (workValue & LOW64)   >> 40; //Lower significants 8 bits
    unsigned int high64    = (workValue & HIGH64)  >> 48; //Higher significants 8 bits
    unsigned int most64    = (workValue & MOST64)  >> 56; //Most significants 8 bits
#endif

    /* XORing 
     *
     * Masking gives us 0 for unused bits, and X for tapped bits
     * A XOR 0 = A so it does not matter how many 0 we XOR
     * */

    /* First of all we XOR the char to each other */
    unsigned char intermediateXOR = (unsigned char) least32 ^
                            low32   ^
                            high32  ^
                            most32
#ifdef LFSR64BITS
                          ^ least64 ^
                            low64   ^
                            high64  ^
                            most64
#endif
                            ;

    /* Now we XOR bit to bit the intermediate XOR */
    unsigned char bit = (intermediateXOR >>  0) ^
    (intermediateXOR >>  1) ^
    (intermediateXOR >>  2) ^
    (intermediateXOR >>  3) ^
    (intermediateXOR >>  4) ^
    (intermediateXOR >>  5) ^
    (intermediateXOR >>  6) ^
    (intermediateXOR >>  7) ^
    (intermediateXOR >>  8);

    bit = bit & 1;

    /* shifting and updating */
    registerValue = (registerValue >> 1) | (bit << 
#ifdef LFSR32BITS 
            31
#else
#   ifdef LFSR64BITS
            63
#   endif
#endif
            );
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

