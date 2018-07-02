#ifndef REG32
#define REG32(x) (*(volatile unsigned int *)(x))
#endif

#ifndef _REG_FLD_OP_
#define _REG_FLD_OP_

//Register Field Mask
//s -- Start of Bit, e -- End of Bit
#define FLD_MASK(s, e) ((0xFFFFFFFF >> (31 - ((e) - (s)))) << (s))

//Register Field Mask Write Data
//s -- Start of Bit, e -- End of Bit, V -- Value
#define FLD_MWD(s, e, v) ((((v) << (s)) & FLD_MASK((s),(e))))

//Register Field Mask Read Data
//s -- Start of Bit, e -- End of Bit, V -- Value
#define FLD_MRD(s, e, v) (((v) & FLD_MASK((s),(e))) >> (s))

//Register Field Read Operation
//a -- Address, s -- Start of Bit, e -- End of Bit, V -- Value
#define OP_FLD_WR(a, s, e, v) (REG32((a)) = FLD_MWD((s),(e),(v)) | (REG32((a)) & ~FLD_MASK((s),(e))))
#define OP_FLD_WR_EXC(a, s, e, v) (REG32((a)) = FLD_MWD((s),(e),(v)))

//Register Field Read Operation
//a -- Address, s -- Start of Bit, e -- End of Bit, V -- Value
#define OP_FLD_RD(a, s, e) FLD_MRD((s), (e), REG32((a)))

#endif