class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int ans = 1;
        sort(nums.begin(), nums.end());

        int c = 1;
        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i], prev = nums[i-1];
            if (curr == prev || curr == prev + 1) {
                if (curr != prev) c++;
                ans = max(c, ans);
            } else {
                c = 1;
            }
        }

        return ans;
    }
};
