class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::stack<char> st;
        for (char c : s) st.push(c);
        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }
    }
};
