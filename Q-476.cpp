/*
476. Number Complement

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.


*/

class Solution {
public:
    int findComplement(int num) {
        int numberBit=(int)(log2(num))+1;
        unsigned int mask=(1U << numberBit)-1;
        return num^mask;
    }
};