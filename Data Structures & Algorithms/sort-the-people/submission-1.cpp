class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<pair<int, string>> temp;

        for (int i = 0; i < heights.size(); i++) {
            temp.push_back({ heights[i], names[i] });
        }

        sort(temp.begin(), temp.end(), [](pair<int, string> a, pair<int, string> b) {
            return a.first > b.first;
        });

        for (int i = 0; i < temp.size(); i++) {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};