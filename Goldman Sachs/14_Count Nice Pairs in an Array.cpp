//https://leetcode.com/problems/count-nice-pairs-in-an-array/
class Solution {
public:
    int rev(int n){
        int num = 0;
        while(n>0){
            int a = n%10;
            num = (num*10)+a;
            n/=10;
        }
        return num;
    }
    int countNicePairs(vector<int>& nums) {
      unordered_map<int,int>m;
      int n = nums.size();
      for(int i=0;i<n;i++){
          if(m[nums[i]]==0){
              int c = rev(nums[i]);
              m[nums[i]]=c;
            }
        }
        unordered_map<int,int>mp;
        int count = 0;
        int  mod = 1e9 + 7;
        for(int i=n-1;i>=0;i--){
            if(mp[nums[i]-m[nums[i]]] != 0){
                count = (count + mp[nums[i]-m[nums[i]]])%mod;
            }
            mp[nums[i]-m[nums[i]]]++;
        }
        return count; 
    }
};
//submission link
//https://leetcode.com/problems/count-nice-pairs-in-an-array/submissions/874782983/
