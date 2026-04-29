class Solution {
public:
    bool isPalindrome(string s) {
       int i = 0;
       int j = s.length() - 1;
       for (int k = 0; k <= j; k++) s[k] = tolower(s[k]);
       while (i <= j) {
        if (!isalnum(s[i]) && !isalnum(s[j])) {
            i++;
            j--;
            continue;
        } else if (!isalnum(s[i])) {
            i++;
            continue;
        } else if (!isalnum(s[j])) {
            j--;
            continue;
        }
        if (s[i] != s[j]) return false;
        i++;
        j--;
       }
       return true;
    }
};