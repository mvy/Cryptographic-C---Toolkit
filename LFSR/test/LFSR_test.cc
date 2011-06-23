#include "LFSR.hh"
#include <string>
#include <cassert>
#include <iostream>

int main(int argc, char *argv[]) {
    LFSR* l = new LFSR(32, TAP32 | TAP7 | TAP5 | TAP3 | TAP2 | TAP1 , 0x6C9AC645);

    std::string output;
    for(int i = 0; i < 100; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    std::cout << output << std::endl;

    assert(output == "1010001001100011010110010011011000100010100000110101001010101111111111000001011101010000110000000100");
}
