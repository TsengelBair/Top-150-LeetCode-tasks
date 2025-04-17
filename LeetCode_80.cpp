#include <iostream>
#include <vector>

// Пока пропускаю

using std::vector;

void removeDuplicates(vector<int>& nums) {
        int indexToWrite = 2;
        for (int i = 2; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i - 1] || nums[i] != nums[i - 2]) {
                ++indexToWrite; // i = 2 -> indexToWrite = 3
                                // i = 3 -> indexToWrite = 4
            } else if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]) {
                nums[i] = nums[i + 1];
                indexToWrite = i + 1;
            }
        }
}

int main()
{
    vector<int> nums = {0,0,1,1,1,1,2,3,3};

    removeDuplicates(nums);

    // std::cout << res << std::endl;

    for (const int elem : nums) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;

    return 0;
}