// 给你一个整数数组 nums 和一个整数 target 。

// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

// 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目

//solution1 dfs
class Solution {
private:
    int cnt;
public:
    void dfs(vector<int>& nums, int target, int sum, int i){
        if(i == nums.size() - 1){
            if(sum + nums[i] == target)
                cnt++;
            if(sum - nums[i] == target)
                cnt++;
            return;
        }
        dfs(nums, target, sum + nums[i], i + 1);
        dfs(nums, target, sum - nums[i], i + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        cnt = 0;
        dfs(nums, target, 0, 0);
        return cnt;
    }
};

