#include "../src/LFSR.hh"
#include <iostream>

int main(int argc, char *argv[]) {
    LFSR* l = new LFSR(TAP32 | TAP7 | TAP5 | TAP3 | TAP2 | TAP1 , 0x6C9AC645);

    for(int i = 0; i < 100; i++) {
        std::cout << l->getValue() << " ";
    }

    std::cout << std::endl;

    std::cout << "1 0 1 0 0 0 1 0 0 1 1 0 0 0 1 1 0 1 0 1 1 0 0 1 0 0 1 1 0 1 1 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 1 1 0 1 0 1 0 0 1 0 1 0 1 0 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 1 0 1 1 1 0 1 0 1 0 0 0 0 1 1 0 0 0 0 0 0 0 1 0 0" << std::endl;
}
