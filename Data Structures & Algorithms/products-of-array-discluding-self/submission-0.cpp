class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        vector<int> prefixProducts(n+1, 1);
        vector<int> postfixProducts(n+1, 1);

        int prefixProduct = 1;
        int postfixProduct = 1;

        int i = 0;
        int j = n - 1;

        while (i < n && j >= 0) {
            prefixProducts[i] = prefixProduct;
            postfixProducts[j+1] = postfixProduct;

            prefixProduct *= nums[i];
            postfixProduct *= nums[j];

            i++;
            j--;
        }

        for (int k = 0; k < n; k++) {
            ans[k] = prefixProducts[k] * postfixProducts[k+1];
        }

        return ans;
    }
};
