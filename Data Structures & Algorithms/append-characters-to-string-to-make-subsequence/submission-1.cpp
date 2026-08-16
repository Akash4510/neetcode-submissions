class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        for (char c : s) {
            if (t[i] == c) i++;
            if (i >= t.size()) break;
        }
        return t.size() - i;
    }
};
