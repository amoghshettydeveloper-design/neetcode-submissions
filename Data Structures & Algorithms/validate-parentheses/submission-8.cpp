// Optimal
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> pairs = {{')','('}, {']','['}, {'}','{'}};
        for (char c : s) {
            if (pairs.count(c)) {          // closing bracket
                if (st.empty() || st.top() != pairs[c]) return false;
                st.pop();
            } else {                        // opening bracket
                st.push(c);
            }
        }
        return st.empty();
    }
};