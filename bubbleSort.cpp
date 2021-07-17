//冒泡排序
void bubbleSort(std::vector<int>& nums){
    for(int j = nums.size() - 1; j > 0; --j){
        for(int i = 0; i < j; ++i){
            if(nums[i] > nums[i + 1]){
                std::swap(nums[i], nums[i + 1]);
            }
        }
    }
}

// 改进

void bubbleSort(std::vector<int>& nums){
    bool flag = false;
    for(int j = nums.size() - 1; j > 0 && !flag; --j){
        flag = true;
        for(int i = 0; i < j; ++i){
            if(nums[i] > nums[i + 1]){
                flag = false;
                std::swap(nums[i], nums[i + 1]);
            }
        }
    }
}
