//https://leetcode.com/problems/split-array-into-consecutive-subsequences/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>m;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int num = 0;
        int j = 0;
        int maxi = m[nums[0]];
        int k = nums[0];
        if(m.size()<3)
            return false;
        map<int,int>::iterator index = m.begin();
        bool first = true;
        for (auto i = m.begin(); i != m.end(); i++){
            if(num==0 && m[nums[0]]>0){
                i = m.begin();
                k = nums[0];
            }
            if(i->second==0)
                return 0;
            if(k!=i->first){
                if(num>=3){
                    num=0;
                    k=i->first;
                    maxi = 1;
                    if(!first){
                        num=0;
                        i=index;
                        maxi=1;
                        k=i->first;
                        first = true;
                        i--;
                        k--;
                    }
                }
                else
                    return 0;
            }
            if(maxi<=i->second){
                num++;  

                if(maxi<i->second && first){
                    index = i;
                    first = false;
                }
                maxi = max(maxi,i->second);
                m[i->first]--;
                map<int,int>::iterator it = i;
                it++;
                if(it==m.end() and !first){
                    num=0;
                    i=index;
                    maxi=1;
                    k=i->first;
                    first = true;
                    i--;
                    k--;
                }
            }
            else if(maxi>i->second){
                if(num>=3){
                    num=0;
                    i=index;
                    maxi=1;
                    k=i->first;
                    first = true;
                    i--;
                    k--;
                }
                else
                    return false;
            }
            k++;
        }
        if(num<3)
            return false;
        return true;
    }
};
//submission link
//https://leetcode.com/problems/split-array-into-consecutive-subsequences/submissions/874246290/
