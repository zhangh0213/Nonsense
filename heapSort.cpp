void adjustHeap(std::vector<int>& nums, int par, int len) {
    int son = par * 2 + 1;
    while(son < len) {
        if (son + 1 < len && nums[son + 1] > nums[son]) {
           ++son;
        }

        if (nums[par] < nums[son]) {
            std::swap(nums[par], nums[son]);
            par = son;
            son = son * 2 + 1;
        } else {
            return;
        }
    }
}

void heapSort(std::vector<int>& nums){
    for (int i = nums.size() / 2 - 1; i >= 0; --i) {
        adjustHeap(nums, i, nums.size());
    }

    for (int i = 0; i < nums.size(); ++i) {
        std::swap(nums[0], nums[nums.size() - 1 - i]);
        adjustHeap(nums, 0, nums.size() - i - 1);
    }
}
