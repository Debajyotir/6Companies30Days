//https://leetcode.com/problems/valid-square/
class Solution {
public:
    int func(vector<int> p1, vector<int> p2){
        return ((p2[0]-p1[0])*(p2[0]-p1[0]))+((p2[1]-p1[1])*(p2[1]-p1[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        unordered_set<int>u;
        u.insert (func(p1,p2));
        u.insert (func(p1,p3));
        u.insert (func(p1,p4));
        u.insert (func(p2,p3));
        u.insert (func(p2,p4));
        u.insert (func(p3,p4));
        if(u.size()==2 && !u.count(0))
            return true;
        return false;
    }
};
//submission link
//https://leetcode.com/problems/valid-square/submissions/873633913/
