#ifndef BIT_MATH_H_  
#define BIT_MATH_H_

#define SET_MASK(REG, MASK)           ((REG) |= (MASK))
#define CLEAR_MASK(REG, MASK)         ((REG) &= ~(MASK))
#define TOGGLE_MASK(REG, MASK)        ((REG) ^= (MASK))
#define IS_MASK_SET(REG, MASK)        (((REG) & (MASK)) != 0)
#define IS_MASK_CLEAR(REG, MASK)      (((REG) & (MASK)) == 0)
#define SET_FIELD(REG, MASK, VALUE)    ((REG) = ((REG) & ~(MASK)) | ((VALUE) & (MASK)))


/*#define SET_HIGH_NIB(var)      (var |= 0xF0)
#define CLR_HIGH_NIB(var)      (var &= 0x0F)
#define GET_HIGH_NIB(var)      ((var >> 4) & 0x0F)
#define TGL_HIGH_NIB(var)      (var ^= 0xF0)

#define SET_LOW_NIB(var)       (var |= 0x0F)
#define CLR_LOW_NIB(var)       (var &= 0xF0)
#define GET_LOW_NIB(var)       (var & 0x0F)
#define TGL_LOW_NIB(var)       (var ^= 0x0F)

#define ASSIGN_REG(var, value)      (var = value)
#define ASSIGN_HIGH_NIB(var, value) (var = (var & 0x0F) | ((value & 0x0F) << 4))
#define ASSIGN_LOW_NIB(var, value)  (var = (var & 0xF0) | (value & 0x0F))

#define RSHIFT_REG(var, no)    (var >>= no)
#define LSHIFT_REG(var, no)    (var <<= no)

#define CRSHIFT_REG(var, no)   (var = (var >> no) | (var << (sizeof(var) * 8 - no)))
#define CLSHIFT_REG(var, no)   (var = (var << no) | (var >> (sizeof(var) * 8 - no)))
*/


#endif
