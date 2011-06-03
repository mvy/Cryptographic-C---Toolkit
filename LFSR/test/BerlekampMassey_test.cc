#include "BerlekampMassey.hh"
#include "LFSR.hh"
#include <string>
#include <iostream>

int main(void) {
    LFSR* l = new LFSR(32, TAP32 | TAP7 | TAP5 | TAP3 | TAP2 | TAP1 , 0x6C9AC645);

    std::string input;

    for(int i = 0; i < 100; i++) {
        input += l->getValue();
    }

    std::cout << "Berlekamp Massey l = " << CCTkAlgorithm::BerlekampMassey(input);

}
