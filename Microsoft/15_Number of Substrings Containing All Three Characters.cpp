//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>v(3,0);
        int n = s.size();
        int start = 0;
        long long int size = 0;
        for(int i=0;i<n;i++){
            int a = s[i] - 'a';
            v[a]++;
            if(v[0]>=1 and v[1]>=1 and v[2]>=1){
                size+=n-i;
                for(int j=start; j<i;j++){
                    a=s[j]-'a';
                    v[a]--;
                    if(v[0]>=1 and v[1]>=1 and v[2]>=1){
                        size+=n-i;
                    }
                    else{
                        start = j+1;
                        break;
                    }
                }
            }
        }
        return size;
    }
};
//submission link
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/872886904/
