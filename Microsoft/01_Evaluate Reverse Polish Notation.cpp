//https://leetcode.com/problems/evaluate-reverse-polish-notation/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int cnt;
        cnt = stoi(tokens[0]);
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                cnt = s.top();
                s.pop();
                cnt+=s.top();
                s.pop();
                s.push(cnt);
            }
            else if(tokens[i]=="-"){
                cnt = s.top();
                s.pop();
                cnt=s.top() - cnt;
                s.pop();
                s.push(cnt);
            }
            else if(tokens[i]=="*"){
                cnt = s.top();
                s.pop();
                cnt*=s.top();
                s.pop();
                s.push(cnt);
            }
            else if(tokens[i]=="/"){
                cnt = s.top();
                s.pop();
                cnt= s.top() / cnt;
                s.pop();
                s.push(cnt);
            }
            else{
                int a;
                a = stoi(tokens[i]);
                s.push(a);
            }
        }
        return cnt;
    }
};
//submission link
//https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/872045124/
