//单词拆分，动态规划
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wdict;
        for(auto word : wordDict){
            wdict.insert(word);
        }
        vector<bool> dp(s.length() + 1);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wdict.find(s.substr(j, i - j))!= wdict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
