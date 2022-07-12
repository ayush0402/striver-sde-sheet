class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty())return false;

                char check;
                if (s[i] == ')')check = '(';
                else if (s[i] == '}')check = '{';
                else check = '[';

                if (st.top() != check)return false;
                else st.pop();
            }
        }
        return st.empty();
    }
};
