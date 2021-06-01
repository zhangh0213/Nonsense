#include <vector>

using namespace std;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + candiesCount[i - 1];
        }
        vector<bool> ans;
        for (auto& querie : queries ){
            long long mins = querie[1] + 1;
            long long maxs = (querie[1] + 1) * (long long)(querie[2]);
            int kind = querie[0]; //the type of the candy
            if(mins <= sum[kind + 1] && maxs > sum[kind]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};