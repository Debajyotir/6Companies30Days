//https://leetcode.com/problems/ipo/
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<pair<int,int>>m;
        priority_queue<int>pq;
        for (int i = 0; i < n; i++) {
            m.emplace_back(capital[i], profits[i]);
        }
        int count = 0;
        sort(m.begin(),m.end());
        for(int i=0;i<k;i++){
            while(count<n and w>=m[count].first){
                pq.push(m[count].second);
                count++;
            }
            if(pq.empty())
                break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
//submission link
//https://leetcode.com/problems/ipo/submissions/874369380/
