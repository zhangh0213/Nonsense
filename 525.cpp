//给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。
//连续数组，采用前缀和
//感觉也可以用双指针

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> pre;
        int count = 0;
        pre[count] = -1;
        int maxlen = 0;
        for (int i = 0; i < n ; i++){
            count += nums[i] ? 1 : -1;
            if(pre.find(count) != pre.end()){
                maxlen = max(maxlen, i - pre[count]);
            }else{
                pre[count] = i;
            }
        }
        return maxlen;
    }
};
