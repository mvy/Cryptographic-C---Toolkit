#include "BerlekampMassey.hh"
#include "LFSR.hh"
#include <string>
#include <cassert>
#include <iostream>

void assertConstruction(unsigned int length, unsigned int mask, int value) {
    std::cout << "Testing: " << length << " " << mask << " " << value << std::endl;
     LFSR* l = new LFSR(length, mask, 1);
     //Default 1 seed... never mind it's mseq;

    std::string output;
    for(int i = 0; i < 100; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    int res = CCTkAlgorithm::BerlekampMassey(output);
    std::cout << "Res: " << output << "[" << res << "]" << std::endl;
    assert(res == value);

    delete l;
}

int main(void) {

    std::string input = "0111010";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 3);

    input = "0110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 2);

    input = "011011011";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 2);

    input = "0111100";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 4);


    /* More complicated tests with m-sequences */
    assertConstruction(32, TAP32 | TAP7 | TAP5 | TAP3 | TAP2 | TAP1 , 32);

    assertConstruction(32, TAP32 | TAP22 | TAP2 | TAP1, 32);

    assertConstruction(3, MASK2 | MASK1, 3);

    assertConstruction(4, MASK1 | MASK2, 4);
}
