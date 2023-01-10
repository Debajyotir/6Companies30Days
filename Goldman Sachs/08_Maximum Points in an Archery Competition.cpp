//https://leetcode.com/problems/maximum-points-in-an-archery-competition/
class Solution {
public:
    void sol(int i,int &numArrows,vector<int>&aliceArrows,vector<int>&v,int &total,vector<int>&bob,int &maxi,int &remain){
        if(i<0)
            return;
        if(numArrows<0)
            return;
        if(total>maxi){
            maxi=total;
            bob=v;
            remain=numArrows;
        }
        v[i]=aliceArrows[i]+1;
        numArrows -= (aliceArrows[i]+1);
        total += i;
        sol(i-1,numArrows,aliceArrows,v,total,bob,maxi,remain);
        v[i]=0;
        numArrows += (aliceArrows[i]+1);
        total -= i;
        sol(i-1,numArrows,aliceArrows,v,total,bob,maxi,remain);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>v(12,0);
        vector<int>bob;
        bool f = true;
        int total = 0;
        int remain = 0;
        int maxi = INT_MIN;
        sol(11,numArrows,aliceArrows,v,total,bob,maxi,remain);
        bob[0]+=remain;
        return bob;
    }
};
//submission link
//https://leetcode.com/problems/maximum-points-in-an-archery-competition/submissions/875628685/
