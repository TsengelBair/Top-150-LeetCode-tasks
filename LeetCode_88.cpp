#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int indexToWrite = nums1.size() - 1;
    while (m > 0 && n > 0) {
        if (nums1[m - 1] <= nums2[n - 1]) {
            nums1[indexToWrite] = nums2[n - 1];
            --n;
        } else {
            nums1[indexToWrite] = nums1[m - 1];
            --m;
        }

        --indexToWrite;
    }

    while (n > 0) {
        nums1[indexToWrite] = nums2[n - 1];
        --n;
        --indexToWrite;
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;

    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    merge(nums1, m, nums2, n);

    for (const int elem : nums1) {
        std::cout << elem << " ";
    }

    return 0;
}

