//https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>v(10,0);
        for(int i=0;i<secret.size();i++){
            int a = secret[i] - '0';
            v[a]++;
        }
        int cow = 0;
        int bull= 0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                bull++;
                int a = guess[i] - '0';
                v[a]--;
            }
        }
        for(int i=0;i<guess.size();i++){
            if(secret[i]!=guess[i]){
                int a = guess[i] - '0';
                if(v[a]>0){
                    v[a]--;
                    cow++;
                }
            }
        }
        
        
        string s = to_string(bull);
        s.push_back('A');
        s = s + to_string(cow);
        s.push_back('B');
        return s;


    }
};
//submission link
//https://leetcode.com/problems/bulls-and-cows/submissions/872420891/
