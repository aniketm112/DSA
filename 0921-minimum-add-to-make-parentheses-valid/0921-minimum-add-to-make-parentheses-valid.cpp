class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, add = 0;
        for (char c : s) {
            if (c == '(') open++;
            else if (open > 0) open--;   // matches an earlier '('
            else add++;                  // unmatched ')', need a '(' inserted
        }
        return add + open;               // leftover '(' each need a ')'
    }
};