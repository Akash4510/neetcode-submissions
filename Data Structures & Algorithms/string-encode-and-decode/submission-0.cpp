class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.size());
            encoded += "*";
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;

        while (i < s.size()) {
            string charCountStr;
            string word;
            while (s[i] != '*') {
                charCountStr += s[i++];
            }

            int charCount = stoi(charCountStr);
            i++;

            for (int j = i; j < i + charCount; j++) {
                word += s[j];
            }

            decoded.push_back(word);
            i += charCount;
        }

        return decoded;
    }
};
