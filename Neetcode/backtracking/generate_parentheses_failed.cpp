class Solution {
public:
    void backtrack(vector<string>& result, string& curr, int n) {
        if (n == 0) {
            result.push_back(curr);
            return;
        }
        // we have two options:
        //   either add () to the back
        //   or surround all of the current stuff in parentheses:
        // we have to try the two options:
        curr += "()";
        string new_curr = curr;
        backtrack(result, curr, n - 1);
        curr.pop_back();
        curr.pop_back();
        // then we want to try the other possibilitiy which 
        // is we add one parenthese to the back and one to the front
        // and then we backtrack on that
        // we need some check to make sure that we 
        curr = "(" + curr + ")";
        string new_new_curr = curr;
        if (new_curr != curr) {
            backtrack(result, curr, n - 1);
        }
        curr = curr.substr(1, curr.size() - 2);

        // the last case is adding at the front
        curr = "()" + curr;
        if (curr != new_curr && curr != new_new_curr) {
            backtrack(result, curr, n - 1);
        }
        curr = curr.substr(2, curr.size());
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        backtrack(result, curr, n);
        return result;
    }
};

