#line 144 "bits.c"
int bitXor(int x, int y)
{

  return ~(~(~x & y) &( ~(x & ~y)));
#line 31 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 148 "bits.c"
}
#line 155
int tmin(void)
{
  return 0x1 << 31;
}
#line 167
int isTmax(int x)
{
  int isMax=(  x + 1) ^( ~x);
  int xEqualNeg1=(  ~x) ^ 0;
  return (!isMax) &( !!xEqualNeg1);
}
#line 181
int allOddBits(int x)
{
  int mask_8=  0xAA;
  int mask_16=(  mask_8 << 8) | mask_8;
  int mask_32=(  mask_16 << 16) | mask_16;
  return !((mask_32 & x) ^ mask_32);
}
#line 195
int negate(int x)
{
  return ~x + 1;
}
#line 209
int isAsciiDigit(int x)
{
  int diff_val1=  x +( ~0x30) + 1;
  int diff_val2=  0x39 +( ~x) + 1;
  return !(diff_val1 >> 31) & !(diff_val2 >> 31);
}
#line 222
int conditional(int x, int y, int z)
{
  x = !!x;


  x = ~x + 1;
  return (x & y) |( ~x & z);
}
#line 237
int isLessOrEqual(int x, int y)
{
  int sign=  y +( ~x) + 1;

  int s_x=  x >> 31;
  int s_y=  y >> 31;
  int of_1=(  !s_x) & s_y;
  int of_2=  s_x &( !s_y);

  return of_2 |(( !(sign >> 31)) &( !of_1));
}
#line 257
int logicalNeg(int x)
{
  int neg_x=  ~x + 1;
  int sign=  neg_x | x;
  return (sign >> 31) + 1;
}
#line 275
int howManyBits(int x)
{
  int flag;
  int cnt_16;int cnt_8;int cnt_4;int cnt_2;int cnt_1;int cnt_0;
  int sign_neg=  x >> 31;
  x =( ~sign_neg & x) |( sign_neg &( ~x));

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
#line 317
unsigned floatScale2(unsigned uf)
{
 unsigned sign_exp= uf & 0x7F800000;
 unsigned exp=  sign_exp>>23;
 unsigned frac=  uf & 0x7FFFFF;
 unsigned s=  uf & 0x80000000;
 unsigned inf=  s|(0xFF<<23);

 if (exp==0xFF) {
  return uf;
 }

 if (exp==0) {
  if (frac==0) {
   return uf;
  }
  return s|(exp<<23)|(frac<<1);
 }

 exp = exp+1;
 if (exp==0xFF) {
  return inf;
 }

   return s|(exp<<23)|frac;
}
#line 355
int floatFloat2Int(unsigned uf)
{
  return 2;
}
#line 372
unsigned floatPower2(int x)
{
  return 2;
}
