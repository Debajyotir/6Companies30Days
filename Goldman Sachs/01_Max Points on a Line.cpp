//https://leetcode.com/problems/max-points-on-a-line/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2)
            return n;
        int maxi = 2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int slop = 2;
                for(int k=0;k<n;k++){
                    if(k!=j && k!=i){
                        if((points[i][1]-points[j][1])*(points[i][0]-points[k][0])==(points[i][0]-points[j][0])*(points[i][1]-points[k][1])){
                            slop++;
                        }
                    }
                }
                maxi = max(maxi,slop);
                if(maxi > n/2)
                    break;
            }
        }
        return maxi;
    }
};
//submission link
//https://leetcode.com/problems/max-points-on-a-line/submissions/873655354/
