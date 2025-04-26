class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            if (target > nums[nums.size() - 1]) {
            return nums.size();
            } else if (target < nums[0]) {
                return 0;
            }
    
            int indexToInsert = 0;
    
            int left = 0;
            int right = nums.size() - 1;
    
            int mid = 0;
            while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (mid < nums.size() - 1 && nums[mid + 1] > target) {
                    return mid + 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                if (mid > 0 && nums[mid - 1] < target) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            }
        }
        return indexToInsert;
        }
    };