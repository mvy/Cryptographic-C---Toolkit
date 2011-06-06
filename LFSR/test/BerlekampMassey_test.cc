#include "BerlekampMassey.hh"
#include "LFSR.hh"
#include <string>
#include <iostream>
#include <cassert>

int main(void) {

    std::string input = "0111010";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 3);

    input = "0110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110110";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 2);

    input = "011011011";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 2);

    input = "0111100";
    assert(CCTkAlgorithm::BerlekampMassey(input) == 4);

}
