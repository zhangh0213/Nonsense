//选择排序
void selectSort(std::vector<int>& nums) {
    int min;
    for (int i = 0; i < nums.size() - 1; ++i) {
        min = i;
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        if (i != min) {
            std::swap(nums[i], nums[min]);
        }
    }
}
