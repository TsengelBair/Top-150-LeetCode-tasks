#include <iostream>
#include <vector>

using std::vector;

int removeDuplicates(vector<int>& nums) 
{
    auto it = nums.begin();
    int counter = 0;

    while (it != nums.end()) {
        auto next = it + 1;
        if (next != nums.end() && *it == *next) {
            nums.erase(next);
            ++counter;
        }
        else {
            ++it;
        }
    }

    return counter;
}

int main()
{
    vector<int> nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }; 

    int res = removeDuplicates(nums);
    std::cout << "Counter " << res << std::endl;

    for (const int& elem : nums) {
        std::cout << elem << " ";
    }
    

    return 0;
}

