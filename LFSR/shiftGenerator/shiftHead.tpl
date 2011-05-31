void LFSR::shift() {
    /* Mask all the int, then XOR shifting */
    unsigned int workValue = registerValue & mask;

    /* XORing 
     *
     * Masking gives us 0 for unused bits, and X for tapped bits
     * A XOR 0 = A so it does not matter how many 0 we XOR
     * */
    int bit = 
