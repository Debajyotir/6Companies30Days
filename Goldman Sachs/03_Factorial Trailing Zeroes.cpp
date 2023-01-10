//https://leetcode.com/problems/factorial-trailing-zeroes/
class Solution {
public:
    int trailingZeroes(int n) {
        int j = 5;
        int i = 0;
        while(j<=n){
            i+=n/j;
            j*=5;
        }
        return i;
    }
};
//submission link
//https://leetcode.com/problems/factorial-trailing-zeroes/submissions/873642735/
