//https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int>m;
        int n = cards.size();
        int mini = INT_MAX;
        int k = 0;
        for(int i=0;i<n;i++){
            m[cards[i]]++;
            if(m[cards[i]]==2){
                int a = i - k + 1;
                mini = min(mini,a);
                for(int j=k;j<i;j++){
                    m[cards[j]]--;
                    if(m[cards[i]]==1){
                        k=j+1;
                        a = i - j + 1;
                        mini = min(mini,a);
                        break;
                    }
                }
            }
        }
        if(mini == INT_MAX)
            return -1;
        return mini;
    }
};
//submission link
//https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/submissions/874307558/
