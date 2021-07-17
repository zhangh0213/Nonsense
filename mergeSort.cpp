void merge(std::vector<int>& nums, int left, int right, int mid) {
    std::vector<int> temp(right - left + 1);
    int pos = left, r = mid + 1;
    int i = 0;
    while (left <= mid && r <= right) {
        if (nums[left] <= nums[r]) {
            temp[i++] = nums[left++];
        } else {
            temp[i++] = nums[r++];
        }
    }
    while (left <= mid) {
        temp[i++] = nums[left++];
    }
    while (r <= right) {
        temp[i++] = nums[r++];
    }

    for (i = pos; i <= right; ++i) {
        nums[i] = temp[i - pos];
    }
}

void merge_sort(std::vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) >> 1;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, right, mid);
}

void mergeSort(std::vector<int>& num) {
    merge_sort(num, 0, num.size() - 1);
}
