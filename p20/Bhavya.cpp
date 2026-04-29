class Solution {
private: 
    bool isValidClosing (char b1, char b2) {
        if (b1 == '[') return b2 == ']';
        if (b1 == '{') return b2 == '}';
        if (b1 == '(') return b2 == ')';
        return false;
    }
public:
    bool isValid(string s) {
        stack<char> stck;
        int i = 0;
        while (i < s.length()) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stck.push(c);
            } else {
                if (stck.empty()) return false;
                if (isValidClosing (stck.top(), c)) {
                    stck.pop();
                }
                else {
                    return false;
                }
            }
            i++;
        }
        return stck.empty();
    }
};