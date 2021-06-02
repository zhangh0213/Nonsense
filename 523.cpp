//利用前缀和以及同余
//如果nums[i,j]满足条件，那么(sum[j] = sum[i - 1]) % k (边界)

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum[i] = sum[i - 1] + nums[i];
        }
        unordered_map<int, int> rest;
        rest[0] = -1;
        for(int i = 0; i < sum.size(); i++){
            int temp = sum[i] % k;
            if(rest.count(temp)){
                int pre = rest[temp];
                if(i - pre >= 2){
                    return true;
                }
            }else{
                rest[temp] = i;
            }
        }
        return false;
    }
};
