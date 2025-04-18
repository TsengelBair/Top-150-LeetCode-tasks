#include <iostream>
#include <vector>

// задачу решает, но не проходит тест по времени
// текущая сложность N * logN (цикл + бинарный поиск)

using std::vector;

int binarySearch(vector<int> &nums, int target, int indexToMiss) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target && mid != indexToMiss) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (mid = indexToMiss) {
            ++left;
        } 
    } 

    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    for (int i = 0; i < numbers.size(); ++i) {
        int elemToFind = target - numbers[i];
        int find = binarySearch(numbers, elemToFind, i);
        if (find != - 1) {
            res.push_back(i + 1);
            res.push_back(find + 1);
            return res;
        }
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 4, 9, 56, 90};
    int target = 8;

    vector<int> res = twoSum(nums, target);
    for (const int elem : res) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}