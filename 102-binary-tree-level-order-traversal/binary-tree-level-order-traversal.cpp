class Solution {
public:
  void helper(TreeNode* root, vector<vector<int>>& ans, int level){
    if(root == nullptr) return;

    if(level >= ans.size()){
      ans.resize(ans.size()+1);
    }

    ans[level].push_back(root->val);
    helper(root->left, ans, level+1);
    helper(root->right, ans, level+1);
  }

  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    helper(root, ans, 0);
    return ans;
  }
};
