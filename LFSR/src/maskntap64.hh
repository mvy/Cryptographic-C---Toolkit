/*
 * Cryptographic C++ Toolkit (CCTk)
 * Martial Lienert, Yves Stadler
 */

#ifndef __MASKNTAP64_HH__
#define __MASKNTAP64_HH__

/* 
 * Masks for 64 bits LFSR
 */
enum MASKS {
    MASK0 = 0x0000000000000000,
    MASK1 = 0x0000000000000001,
    MASK2 = 0x0000000000000002,
    MASK3 = 0x0000000000000004,
    MASK4 = 0x0000000000000008,
    
    MASK5 = 0x0000000000000010,
    MASK6 = 0x0000000000000020,
    MASK7 = 0x0000000000000040,
    MASK8 = 0x0000000000000080,
    
    MASK9 = 0x0000000000000100,
    MASK10= 0x0000000000000200,
    MASK11= 0x0000000000000400,
    MASK12= 0x0000000000000800,
    
    MASK13= 0x0000000000001000,
    MASK14= 0x0000000000002000,
    MASK15= 0x0000000000004000,
    MASK16= 0x0000000000008000,
    
    MASK17= 0x0000000000010000,
    MASK18= 0x0000000000020000,
    MASK19= 0x0000000000040000,
    MASK20= 0x0000000000080000,
    
    MASK21= 0x0000000000100000,
    MASK22= 0x0000000000200000,
    MASK23= 0x0000000000400000,
    MASK24= 0x0000000000800000,
    
    MASK25= 0x0000000001000000,
    MASK26= 0x0000000002000000,
    MASK27= 0x0000000004000000,
    MASK28= 0x0000000008000000,
    
    MASK29= 0x0000000010000000,
    MASK30= 0x0000000020000000,
    MASK31= 0x0000000040000000,
    MASK32= 0x0000000080000000,

    MASK33= 0x0000000100000000,
    MASK34= 0x0000000200000000,
    MASK35= 0x0000000400000000,
    MASK36= 0x0000000800000000,
    
    MASK37= 0x0000001000000000,
    MASK38= 0x0000002000000000,
    MASK39= 0x0000004000000000,
    MASK40= 0x0000008000000000,
    
    MASK41= 0x0000010000000000,
    MASK42= 0x0000020000000000,
    MASK43= 0x0000040000000000,
    MASK44= 0x0000080000000000,
    
    MASK45= 0x0000100000000000,
    MASK46= 0x0000200000000000,
    MASK47= 0x0000400000000000,
    MASK48= 0x0000800000000000,
    
    MASK49= 0x0001000000000000,
    MASK50= 0x0002000000000000,
    MASK51= 0x0004000000000000,
    MASK52= 0x0008000000000000,
    
    MASK53= 0x0010000000000000,
    MASK54= 0x0020000000000000,
    MASK55= 0x0040000000000000,
    MASK56= 0x0080000000000000,
    
    MASK57= 0x0100000000000000,
    MASK58= 0x0200000000000000,
    MASK59= 0x0400000000000000,
    MASK60= 0x0800000000000000,
    
    MASK61= 0x1000000000000000,
    MASK62= 0x2000000000000000,
    MASK63= 0x4000000000000000,
    MASK64= 0x8000000000000000
};

/*
 * Taps for the 64 bits LFSR
 */
enum TAP {
    TAP64= 0x0000000000000001,
    TAP63= 0x0000000000000002,
    TAP62= 0x0000000000000004,
    TAP61= 0x0000000000000008,
    
    TAP60= 0x0000000000000010,
    TAP59= 0x0000000000000020,
    TAP58= 0x0000000000000040,
    TAP57= 0x0000000000000080,
    
    TAP56= 0x0000000000000100,
    TAP55= 0x0000000000000200,
    TAP54= 0x0000000000000400,
    TAP53= 0x0000000000000800,
    
    TAP52= 0x0000000000001000,
    TAP51= 0x0000000000002000,
    TAP50= 0x0000000000004000,
    TAP49= 0x0000000000008000,
    
    TAP48= 0x0000000000010000,
    TAP47= 0x0000000000020000,
    TAP46= 0x0000000000040000,
    TAP45= 0x0000000000080000,
    
    TAP44= 0x0000000000100000,
    TAP43= 0x0000000000200000,
    TAP42= 0x0000000000400000,
    TAP41= 0x0000000000800000,
    
    TAP40= 0x0000000001000000,
    TAP39= 0x0000000002000000,
    TAP38= 0x0000000004000000,
    TAP37= 0x0000000008000000,
    
    TAP36= 0x0000000010000000,
    TAP35= 0x0000000020000000,
    TAP34= 0x0000000040000000,
    TAP33= 0x0000000080000000

    TAP32= 0x0000000100000000,
    TAP31= 0x0000000200000000,
    TAP30= 0x0000000400000000,
    TAP29= 0x0000000800000000,
    
    TAP28= 0x0000001000000000,
    TAP27= 0x0000002000000000,
    TAP26= 0x0000004000000000,
    TAP25= 0x0000008000000000,
    
    TAP24= 0x0000010000000000,
    TAP23= 0x0000020000000000,
    TAP22= 0x0000040000000000,
    TAP21= 0x0000080000000000,
    
    TAP20= 0x0000100000000000,
    TAP19= 0x0000200000000000,
    TAP18= 0x0000400000000000,
    TAP17= 0x0000800000000000,
    
    TAP16= 0x0001000000000000,
    TAP15= 0x0002000000000000,
    TAP14= 0x0004000000000000,
    TAP13= 0x0008000000000000,
    
    TAP12= 0x0010000000000000,
    TAP11= 0x0020000000000000,
    TAP10= 0x0040000000000000,
    TAP9 = 0x0080000000000000,
    
    TAP8 = 0x0100000000000000,
    TAP7 = 0x0200000000000000,
    TAP6 = 0x0400000000000000,
    TAP5 = 0x0800000000000000,
    
    TAP4 = 0x1000000000000000,
    TAP3 = 0x2000000000000000,
    TAP2 = 0x4000000000000000,
    TAP1 = 0x8000000000000000
};
#endif //__MASKNTAP64_HH__