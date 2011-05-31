    ;

    bit = bit & 1;

    /* shifting and updating */
    registerValue = (registerValue >> 1) | (bit << 31);
}
