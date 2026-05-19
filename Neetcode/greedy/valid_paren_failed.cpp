class Solution {
public:
    bool checkValidString(string s) {
        int mystery_cnt = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') left++;
            else if (s[i] == ')') right++;
            else mystery_cnt++;
            if (right > left) {
                if (mystery_cnt == 0) return false;
                else {
                    mystery_cnt--;
                    right--;
                }
            }
        }
        // now we could have too many lefts
        if (left > right + mystery_cnt) return false;
        return true;
    }
};

