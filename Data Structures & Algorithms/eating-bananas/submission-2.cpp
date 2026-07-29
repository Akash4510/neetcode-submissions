class Solution {
private:
    bool isSolution(vector<int>& piles, int h, int k) {
        long long currHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (currHours > h) return false;

            // Performance trick -
            // Instead of: 
            // currHours += (int) ceil((double)piles[i] / k);'

            currHours += (piles[i] + k - 1) / k;

            // Why this works: If piles[i] is exactly divisible by k, adding k - 1 isn't enough to push it over to the next multiple, so the integer division stays exactly where it should be. If there is a remainder, adding k - 1 guarantees it rolls over to the next integer. It's a beautiful math trick!
        }

        return currHours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int left = 1, right = *max_element(piles.begin(), piles.end()), mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            if (isSolution(piles, h, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
