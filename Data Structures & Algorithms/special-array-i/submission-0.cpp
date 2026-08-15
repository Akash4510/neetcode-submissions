class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size() - 1;
        for (int i = 0; i < n - 1; i++) {
            if (!((nums[i] + nums[i+1]) & 1)) return false;
        }
        return true;
    }
};
