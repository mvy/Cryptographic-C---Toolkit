#include "LFSR.hh"
#include <iostream>
#include <cassert>

int main(int argc, char *argv[]) {
    LFSR* l = new LFSR(4, MASK2 | MASK1 , 0x0000000D);

    std::cout << "LFSR:";
    std::string output;
    for(int i = 0; i < 15; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    std::cout << output << std::endl;

    std::cout << "Resu:101111000100110" << std::endl;

    assert(output == "101111000100110");
}
