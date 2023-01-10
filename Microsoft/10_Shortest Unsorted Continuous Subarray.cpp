//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        int i;
        for(i=0; i<nums.size(); i++){
            if(nums[i]!=v[i])
                break;
        }
        if(i == nums.size())
            return 0;
        int j;
        for(j = nums.size()-1; j>=0; j--){
            if(nums[j]!=v[j])
                break;
        }
        return j+1-i;
    }
};
//submission link
//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/submissions/872767606/
