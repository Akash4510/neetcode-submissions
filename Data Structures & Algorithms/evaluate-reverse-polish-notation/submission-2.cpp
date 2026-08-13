class Solution {
private:
    bool isInteger(const string& s) {
        return !(s == "+" || s == "-" || s == "*" || s == "/");
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& t : tokens) {
            if (isInteger(t)) {
                st.push(stoi(t));
            } else {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result = 0;

                if (t == "+") {
                    result = a + b;
                } else if (t == "-") {
                    result = a - b;
                } else if (t == "*") {
                    result = a * b;
                } else if (t == "/") {
                    result = a / b;
                }

                st.push(result);
            }
        }

        return st.top();
    }
};
