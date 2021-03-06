/*
 * CS:APP Data Lab
 *
 * <Please put your name and userid here>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
// 1
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
  // return ~(~x&~y)&(~(x&y));//right
  return ~(~(~x & y) & (~(x & ~y))); // right
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return 0x1 << 31;
}
// 2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
  int isMax = (x + 1) ^ (~x); // a is 0 if x is max or -1
  int xEqualNeg1 = (~x) ^ 0;  // b is 0 if x is -1
  return (!isMax) & (!!xEqualNeg1);
}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
  int mask_8 = 0xAA;
  int mask_16 = (mask_8 << 8) | mask_8;
  int mask_32 = (mask_16 << 16) | mask_16;
  return !((mask_32 & x) ^ mask_32);
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return ~x + 1;
}
// 3
/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
  int diff_val1 = x + (~0x30) + 1; // let diff_v1 return negative if x<0x30(first bit is 1)
  int diff_val2 = 0x39 + (~x) + 1; // let diff_v2 return negative if x>0x39
  return !(diff_val1 >> 31) & !(diff_val2 >> 31);
}
/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
  x = !!x;
  // if x==1 then let x=0xFFFFFFFF
  // if x==0 then let x=0x00000000
  x = ~x + 1;
  return (x & y) | (~x & z);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  int sign = y + (~x) + 1; // y-x>=0, sign>>31=0

  int s_x = x >> 31;
  int s_y = y >> 31;
  int of_1 = (!s_x) & s_y; // case1:y<0,x>0 overflow y-x>0 : x>>31==0,y>>31==1
  int of_2 = s_x & (!s_y); // case2:y>0,x<0 overflow y-x<0 : x>>31==1,y>>31==0

  return of_2 | ((!(sign >> 31)) & (!of_1));
}
// 4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x)
{
  int neg_x = ~x + 1;
  int sign = neg_x | x;    // make neg_x and x's highest bit 1
  return (sign >> 31) + 1; // logical bitwise -1>>31 -> 0xFFFFFFFF
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
  int flag;
  int cnt_16, cnt_8, cnt_4, cnt_2, cnt_1, cnt_0;
  int sign_neg = x >> 31;
  x = (~sign_neg & x) | (sign_neg & (~x)); // make x's highest bit 1

  flag = !!(x >> 16);
  cnt_16 = flag << 4;
  x = x >> cnt_16;

  flag = !!(x >> 8);
  cnt_8 = flag << 3;
  x = x >> cnt_8;

  flag = !!(x >> 4);
  cnt_4 = flag << 2;
  x = x >> cnt_4;

  flag = !!(x >> 2);
  cnt_2 = flag << 1;
  x = x >> cnt_2;

  flag = !!(x >> 1);
  cnt_1 = flag;
  x = x >> cnt_1;

  cnt_0 = x;
  return cnt_16 + cnt_8 + cnt_4 + cnt_2 + cnt_1 + cnt_0 + 1;
}
// float
/*
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
  unsigned sign_exp = uf & 0x7F800000; // exp = uf & 011111111000...000
  unsigned exp = sign_exp >> 23;
  unsigned frac = uf & 0x7FFFFF;
  unsigned s = uf & 0x80000000;
  unsigned inf = s | (0xFF << 23);

  if (exp == 0xFF)
  { // not a number
    return uf;
  }

  if (exp == 0)
  {
    if (frac == 0)
    { // exp is all 0 and frac is all zero is interpreted as 0
      return uf;
    }
    return s | (exp << 23) | (frac << 1);
  }

  exp = exp + 1;
  if (exp == 0xFF)
  { // exp is all 1 and frac is all zero uf is interpreted as inf
    return inf;
  }

  return s | (exp << 23) | frac;
}
/*
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  unsigned sign_exp = uf & 0x7F800000;
  unsigned exp = sign_exp >> 23;
  unsigned frac = uf & 0x7FFFFF;
  unsigned F = frac | 0x800000; // F = frac + 1
  int E = exp - 0x7F;           // E = exp - 127(0x7F)
  unsigned s = uf >> 31;
  int ret = 0;

  if (E < 0)
  {
    return 0;
  }

  if (E > 0x1F)
  { // E is bigger than 31 then the float is out range of int(-2^31 - 2^31-1)
    return 0x80000000u;
  }

  if ((E == 0x1F) && (s == 0))
  {
    return 0x80000000u;
  }

  if (E > 0x17)
  {
    ret = F << (E - 0x17); // E > 23 then F should move E-23
  }

  if (E <= 0x17)
  {
    ret = F >> (0x17 - E);
  }

  if (s == 1)
  {
    ret = ~ret + 1;
  }

  return ret;
}
/*
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 *
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
 unsigned sign_exp = x & 0x7F800000;
 unsigned exp = sign_exp >> 23;
 
 if(x > 127){
	return 0x7F800000;
 }

 if(x < -149){//the minmium of the float is 0x00000001 also is 2^-149
	 return 0;
 }

 if(x <= -127){//x is in (-149, -127)
	 return 0x1 << (149 + x);
 }

  //normalizod
  exp = 127 + x;//x = E = exp -127
  return exp << 23;//when float is normalizod, the frac is interapted to be plus 1
}
