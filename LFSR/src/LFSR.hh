/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */


#ifndef __LFSR_HH__
#define __LFSR_HH__

#include "CCTkConfig.hh"
#include<vector>

/**
 * Linear Feedback Shift Register
 *
 * More information on :
 * http://en.wikipedia.org/wiki/Linear_feedback_shift_register
 */

/* Handling 32 bits / 64 bits formats */

#ifdef LFSR32BITS
#   include "maskntap32.hh"
#else
#   ifdef LFSR64BITS
#       include "maskntap64.hh"
#   else
#       warning "You did not define any of LFSR32BITS and LFSR64BITS. The build will prooceed assuming LFSR32BITS"
#       include "maskntap32.hh"
#   endif
#endif


/* Forward declaration */
class LFSR;

class LFSR {
private:
    /* 
     * The value of the register
     * The capacity depends on the system implementation of int.
     */
    unsigned int registerValue;
    /* Initial vector of the LFSR, must be set by constructor in the
     * same time registerValue is first set */
    unsigned int initialVector;

    /* Mask, polynomial */
    unsigned int mask;

public:
    /* Get the value, do the shift */
    bool getValue();
    /* Get position i */
    bool getBitAt(int);
    /* Apply a shift operation based on the polynomial */
    void shift();

    /*
     * Reinitialisatio
     * */
    void reinit();

    LFSR(unsigned int mask, unsigned int);
    LFSR(const LFSR&);
    virtual ~LFSR();
};

#endif
