//https://leetcode.com/problems/number-of-people-aware-of-a-secret/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long int>v(n,0);
        long long int cons = 1e9 + 7;
        long long int curr = 0;
        v[0]=1;
        for(int i=1;i<n;i++){
            long long int late = 0;
            long long int gone = 0;
            if(i-delay>=0){
                late = v[i-delay];
            }
            if(i-forget>=0){
                gone = v[i-forget];
            }
            curr = (curr + late - gone);
            //curr = curr%con;
            v[i] = curr;
            v[i]=v[i]%cons;
        }
        long long int ans = curr;
        for(int i=n-delay;i<n;i++){
            ans=(ans + v[i])%cons;
        }
        return ans;
    }
};
//submission link
//https://leetcode.com/problems/number-of-people-aware-of-a-secret/submissions/874606097/
