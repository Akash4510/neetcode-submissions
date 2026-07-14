class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;

        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int curr = min(heights[left], heights[right]) * (right - left);

            area = max(area, curr);

            if (heights[left] < heights[right]) left++;
            else right--;
        }

        return area;
    }
};
