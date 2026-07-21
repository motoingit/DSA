

class Solution{
  public:
   vector<vector<int>> shiftGrid(vector<vector<int>> &nums, int k){
      int row = nums.size(), col = nums[0].size();
      int nEle = row * col;
      k = k % nEle;
      
      vector<vector<int>> ans(row, vector<int>(col));

for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {

        int idx = i * col + j;

        int newIdx = (idx + k) % (row * col);

        ans[newIdx / col][newIdx % col] = nums[i][j];
    }
}
return ans;
    }

};
