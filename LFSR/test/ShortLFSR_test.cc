#include "LFSR.hh"
#include <string>
#include <cassert>
#include <iostream>

int main(int argc, char *argv[]) {
    LFSR* l = new LFSR(4, MASK2 | MASK1 , 0x0000000D);

    std::string output;
    for(int i = 0; i < 16; i++) {
        output += (l->getValue() ? "1" : "0");
    }

    std::cout << output << std::endl;

    assert(output == "1011110001001101");
}
