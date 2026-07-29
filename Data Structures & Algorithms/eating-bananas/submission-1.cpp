class Solution {
private:
    bool isSolution(vector<int>& piles, int h, int k) {
        int currHours = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (currHours > h) return false;
            currHours += (int) ceil((double)piles[i] / k);
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
