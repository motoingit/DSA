class Solution {
public:
    int hammingWeight(int number) {

        long long limit = 1;
        int nBits = 1;
        while(number >= limit){
            limit *= 2;
            nBits++;
        }
        nBits--;

        int nSetBits = 0, n = 0;
        while(nBits--){
            if(number & (1 << (n++))) nSetBits++;
        }
        return nSetBits;
    }
};