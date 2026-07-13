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
            int asteriskPos = s.find('*', i);

            string charCountStr = s.substr(i, asteriskPos - i);
            int charCount = stoi(charCountStr);

            i = asteriskPos + 1;

            string word = s.substr(i, charCount);
            decoded.push_back(word);

            i += charCount;
        }

        return decoded;
    }
};
