void quick(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left, j = right;
    int key = nums[i];
    while (i < j) {
        while (nums[j] >= key && i < j) {
            --j;
        }
        nums[i] = nums[j];
        while (nums[i] <= key && i < j) {
            ++i;
        }
        nums[j] = nums[i];
    }
    nums[i] = key;
    quick(nums, left, i - 1);
    quick(nums, i + 1, right);
}

void quickSort(std::vector<int>& nums) {
    quick(nums, 0, nums.size());
}
