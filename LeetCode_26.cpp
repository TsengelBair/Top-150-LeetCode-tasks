class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int indexForUniqueElem = 1; // because nums[0] is always unique
            // compare cure and previous
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] != nums[i - 1]) {
                    nums[indexForUniqueElem] = nums[i];
                    ++indexForUniqueElem;
                }
            }
    
            return indexForUniqueElem;
        }
};