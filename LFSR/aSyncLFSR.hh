/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */

#ifndef __ASYNCLFSR_HH__
#define __ASYNCLFSR_HH__

#include "LFSR.hh"

class aSyncLFSR {
private:
    /* Current LFSR */
    std::vector<LFSR> list;
    std::vector<int> masterBits;
    
    /* Adding two LFSR */
    void addLFSR(const LFSR& a, int aM);
    /* Shift */
    void shift();
    
public:
    void addLFSR(const LFSR&, int, const LFSR&, int);
    
    /* Get value, do the shift */
    bool getValue();
    
    /* getSize */
    int getSize();
    
    /* 
     * Reinitialisation 
     * */
    void reinit();
    
    aSyncLFSR(const LFSR&, int);
    virtual ~aSyncLFSR();
};
#endif //__ASYNCLFSR_HH__
