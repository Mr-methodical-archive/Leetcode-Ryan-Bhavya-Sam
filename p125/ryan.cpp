class Solution {
public:
    bool isPalindrome(string s) {
        string k;
        for (int i = 0; i < s.length(); ++i) {
            if (isalnum(s[i])) {
                k += tolower(s[i]);
            }
        }
        int right = k.length() - 1;
        int left = 0;
        while (left < right) {
            if (k[left] != k[right]) {
                return false;
            }
            --right;
            ++left;
        }
        return true;
    }
};
