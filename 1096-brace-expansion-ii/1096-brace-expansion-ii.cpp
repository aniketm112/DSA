class Solution {
public:
    string s;
    int idx = 0;
    
    set<string> parseExpr() {
        set<string> result = parseTerm();
        while (idx < s.size() && s[idx] == ',') {
            idx++;
            set<string> term2 = parseTerm();
            for (auto &w : term2) result.insert(w);
        }
        return result;
    }
    
    set<string> parseTerm() {
        vector<set<string>> factors;
        while (idx < s.size() && s[idx] != ',' && s[idx] != '}') {
            factors.push_back(parseFactor());
        }
        set<string> result = {""};
        for (auto &f : factors) {
            set<string> newResult;
            for (auto &prefix : result)
                for (auto &w : f)
                    newResult.insert(prefix + w);
            result = newResult;
        }
        return result;
    }
    
    set<string> parseFactor() {
        if (s[idx] == '{') {
            idx++;
            set<string> res = parseExpr();
            idx++; // skip '}'
            return res;
        } else {
            int start = idx;
            while (idx < s.size() && islower(s[idx])) idx++;
            return {s.substr(start, idx - start)};
        }
    }
    
    vector<string> braceExpansionII(string expression) {
        s = expression;
        idx = 0;
        set<string> result = parseExpr();
        return vector<string>(result.begin(), result.end());
    }
};