#include <map>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]] = 1;
        }

        for(int i = 0; i <= n; i++){
            if(mp.find(i) == mp.end()){
                return i;
            }
        }
        return -1;
    }
};