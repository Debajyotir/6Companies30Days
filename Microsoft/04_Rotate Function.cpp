//https://leetcode.com/problems/rotate-function/
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long int n = nums.size();
        long long int mainSum = 0;
        long long int sum = 0;
        for(int i=0;i<n;i++){
            mainSum += (nums[i] * i);
            sum += nums[i];
        }
        long long int maxi = mainSum;
        for(long long int i=1; i<n; i++){
            long long int m = mainSum - ((n-1)*nums[n-i]) + sum - nums[n-i];
            maxi = max(maxi,m);
            mainSum = m;
        }
        return maxi;
    }
};
//submission link
//https://leetcode.com/problems/rotate-function/submissions/872716802/
