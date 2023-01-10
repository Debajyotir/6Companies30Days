//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void trav(TreeNode* root, vector<int>&m){
        if(root){
            trav(root->left,m);
            m.push_back(root->val);
            trav(root->right,m);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        vector<int>m;
        trav(root1,m);
        vector<int>first;
        first = m;
        m.clear();
        trav(root2,m);
        int i=0;
        int j=0;
        while(i<first.size() and j<m.size()){
            if(m[j]>=first[i]){
                v.push_back(first[i]);
                i++;
            }
            else{
                v.push_back(m[j]);
                j++;
            }
        }
        for(;i<first.size();i++){
            v.push_back(first[i]);
        }
        for(;j<m.size();j++){
            v.push_back(m[j]);
        }
        return v;
    }
};
//submission link
//https://leetcode.com/problems/all-elements-in-two-binary-search-trees/submissions/874951061/
