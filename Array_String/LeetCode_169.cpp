class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int, int>hash;
            int majority = nums.size() / 2;
    
            for (int i = 0; i < nums.size(); ++i) {
                ++hash[nums[i]];
                if (hash[nums[i]] > majority) {
                    return nums[i];
                }
            }
    
            return -1;
        }
};