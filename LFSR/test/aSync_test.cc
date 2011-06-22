#include "aSyncLFSR.hh"

#include <iostream>

int main() {
    LFSR l1(4, MASK2 | MASK1, 0x0000000D);
    LFSR l2(4, MASK2 | MASK1, 0x0000000E);
    LFSR l3(4, MASK2 | MASK1, 0x0000000F);

    aSyncLFSR async(l1, 3);
    async.addLFSR(l2, 2, l3, 1);

    std::string output;
    for(int i = 0; i < 100; i++) {
        output += (async.getValue() ? "1" : "0");
    }

    std::cout << output << std::endl;
}
