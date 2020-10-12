#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

// Return the bit value (0 or 1) at position pos of unsigned int n
// Note that the least significant bit position is 0.
int get_bit_at_pos(unsigned int n, int pos)
{
    // 10010010
  int mask = 1 << pos;              // 00010000
  int bit = (n & mask) >> pos;      // 00001001 -> 0000001
  return bit;
}

// Set the bit value to 1 at position pos of unsigned int n,
// while leaving other bits unchanged.
// Return the changed integer.
// Note that the least significant bit position is 0.
int set_bit_at_pos(unsigned int n, int pos)
{
    int mask = 1 << pos;
    int bit = (n | mask);
    return bit;
}

// Return the most significant byte of unsigned int n
char get_most_significant_byte(unsigned int n)
{
    char res = n >> (sizeof(unsigned int)*8-8);
    return res;
}

// Return true if n1+n2 causes overflow, return false otherwise
bool sum_overflowed(int n1, int n2)
{
    if (n1 > 0 && n2 > 0 && (n1+n2) < 0)
        return true;
    else if (n1 < 0 && n2 < 0 && (n1+n2) > 0)
        return true;
    else
        return false;
}

//Extract the 8-bit exponent field of single precision floating point number f
//and return it as an unsigned byte
unsigned char get_exponent_field(float f)
{
    unsigned int i = *(unsigned int *)&f;
  	i = (i << 1) >> 1;
  	i = i >> 23;
  	return i;
}
