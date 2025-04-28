class Solution {
    public:
        // поиск стартового target эл-та
        int findFirst(vector<int>& nums, int target){
            int startIndex = -1;
    
            int left = 0;
            int right = nums.size() - 1;
    
            int mid = 0; // чтобы не создавать переменную в цикле
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    startIndex = mid;
                    right = mid - 1; // продолжаем поиск стартового индекса в левом подмассивве
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                }
            }
    
            return startIndex;
        }
    
        // поиск конечного target эл-та
        int findLast(vector<int>& nums, int target){
            int lastIndex = -1;
    
            int left = 0;
            int right = nums.size() - 1;
    
            int mid = 0; 
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    lastIndex = mid;
                    left = mid + 1; // продолжаем поиск конечного индекса в правом подмассивве
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else if (nums[mid] > target) {
                    right = mid - 1;
                }
            }
    
            return lastIndex;
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> res(2);
    
            res[0] = findFirst(nums, target);
            res[1] = findLast(nums, target);
            
            return res;
        }
    };