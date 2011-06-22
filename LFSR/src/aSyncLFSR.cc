/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */

#include "aSyncLFSR.hh"

void aSyncLFSR::reinit() {
    for(std::vector<LFSR>::iterator lIt = list.begin(); lIt != list.end(); lIt++) {
        /* TODO: COMMENT Loop */
        (*lIt).reinit();
    }
}

bool aSyncLFSR::getValue() {
    /* XOR of the inner LFSR getValue */
    char result = 0;
    for(std::vector<LFSR>::iterator lIt = list.begin(); lIt != list.end(); lIt++) {
        /* TODO: COMMENT Loop */
        result ^= (*lIt).getBitAt(1);
    }

    shift();

    return (result & 1) == 1;
}

void aSyncLFSR::shift() {
    /* The shifting process randomise a 0 or 1 called r
     * Then shift every LFSR whose master bit is equal to r
     * */
    int countZero = 0;
    int countOne = 0;
    std::vector<LFSR>::iterator lIt;
    std::vector<int>::iterator mIt;
    for(lIt = list.begin(), mIt = masterBits.begin();
        lIt != list.end(); 
        lIt++, mIt++) {
        /* TODO: COMMENT Loop */

        if((*lIt).getBitAt(*mIt)) {
            countOne++;
        } else {
            countZero++;
        }
    }

    bool maj = countZero < countOne;

    /* Odd numbers so can't be equal, we shift the selected by majority */
    for(lIt = list.begin(), mIt = masterBits.begin(); lIt != list.end(); lIt++, mIt++) {
        /* TODO: COMMENT Loop */
        if((*lIt).getBitAt(*mIt) == maj) {
            (*lIt).shift();
        }
    }
}

void aSyncLFSR::addLFSR(const LFSR& a, int aM) {
    list.push_back(a);
    masterBits.push_back(aM);
}


void aSyncLFSR::addLFSR(const LFSR& a, int aM, const LFSR& b, int bM) {
    /* Always two they are (in fact they are an even number) */
    addLFSR(a, aM);
    addLFSR(b, bM);
}

int aSyncLFSR::getSize() {
    return list.size();
}

/**
 * Register the a LFSR in the asynchronous structure, with master bit aM
 */
aSyncLFSR::aSyncLFSR(const LFSR& a, int aM) {
    addLFSR(a, aM);
}

aSyncLFSR::~aSyncLFSR() {
}
