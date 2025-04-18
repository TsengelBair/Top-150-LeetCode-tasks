#include <iostream>
#include <vector>

using std::vector;

int removeElement(vector<int>& nums, int val) {
    int start = 0;
    int end = nums.size() - 1;

    while (start <= end) {
        if (nums[start] == val) {
            nums[start] = nums[end];
            --end;
        }
        else {
            ++start;
        }
    }

    return start;
}

int main()
{
    vector<int> nums = { 3, 2, 3, 2 };
    int m = 3;

    int res = removeElement(nums, m);
    std::cout << "res: " << res << std::endl;

    for (const int elem : nums) {
        std::cout << elem << " ";
    }
    

    return 0;
}

