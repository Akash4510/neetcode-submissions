class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int i = 1;

        while (n >= 0) {
            n -= i++;
            ans++;
        }

        return ans - 1;
    }
};
