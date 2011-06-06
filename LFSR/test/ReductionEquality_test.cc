#include "LFSR.hh"
#include <string>
#include <iostream>
#include <cassert>

int main(void) {
    LFSR* l1 = new LFSR(10, MASK1 | MASK4 | MASK7 | MASK8 | MASK10 , 0x249);
    LFSR* l2 = new LFSR(3, MASK1, 0x1);

    std::string input1;
    std::string input2;

    for(int i = 0; i < 100; i++) {
        input1 += (l1->getValue() ? "0" : "1");
        input2 += (l2->getValue() ? "0" : "1");
    }

    std::cout << input1 << std::endl;
    std::cout << input2 << std::endl;

    assert(input1 == input2);

}
