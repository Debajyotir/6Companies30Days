//https://leetcode.com/problems/combination-sum-iii/
class Solution {
    void sol(int k, int n, int j, vector<vector<int>> &v, vector<int>&arr){
        if(k>0){
            for(int i=j;i<10;i++){
                if(n-i>0){
                    arr.push_back(i);
                    sol(k-1,n-i,i+1,v,arr);
                    arr.pop_back();

                }
                else if(n-i==0 && k==1){
                    arr.push_back(i);
                    v.push_back(arr);
                    arr.pop_back();
                    return;
                    
                }
                else{
                    return ;
                }
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>::iterator it;
        vector<vector<int>>v;
        vector<int>arr;
        sol(k,n,1,v,arr);

        return v;
    }
};
//submission link
//https://leetcode.com/problems/combination-sum-iii/submissions/872075725/
