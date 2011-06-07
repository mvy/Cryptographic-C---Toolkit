#include "LFSR.hh"
#include <string>
#include <cassert>
#include "BerlekampMassey.hh"
#include <iostream>

int main(int argc, char *argv[]) {
    LFSR* l = new LFSR(32, TAP32 | TAP7 | TAP5 | TAP3 | TAP2 | TAP1 , 0x6C9AC645);

    std::string output;
    for(int i = 0; i < 100; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    std::cout << "1: " << CCTkAlgorithm::BerlekampMassey(output) << std::endl;

    delete l;

    output = "";
    l = new LFSR(32, TAP32 | TAP22 | TAP2 | TAP1, 0x00000001);
    for(int i = 0; i < 100; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    std::cout << "2: " << CCTkAlgorithm::BerlekampMassey(output) << std::endl;

}
