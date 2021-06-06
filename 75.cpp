// 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色
//双指针，一个用来交换0，一个用来交换2

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size();
        for(int i = 0; i < right; ){
            if(nums[i] == 0){
                swap(nums[i], nums[left++]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[--right]);
                continue;
            }
            i++;
        }
    }
};
