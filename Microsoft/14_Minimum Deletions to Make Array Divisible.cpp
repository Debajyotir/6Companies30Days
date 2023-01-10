//https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
class Solution {
public:
    int GcdOfArray(vector<int>& numsDivide, int idx){
        if (idx == numsDivide.size() - 1) {
            return numsDivide[idx];
        }
        int a = numsDivide[idx];
        int b = GcdOfArray(numsDivide, idx + 1);
        return __gcd(a, b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g = GcdOfArray(numsDivide,0);
        int maxi = 1000000001;
        for(int i=0;i<nums.size();i++){
            if(g==nums[i] or (g%nums[i]==0 and g/nums[i]>=1)){
                maxi = min(maxi,nums[i]);
            }
        }
        int y = 0;
        for(int i=0;i<nums.size();i++){
            if(maxi>nums[i]){
                y++;
            }
        }
        if(y==nums.size()){
            return -1;
        }
        return y;
    }
};
//submission link
//https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/submissions/749085455/
