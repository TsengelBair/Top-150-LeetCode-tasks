class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currentLastPos = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= currentLastPos) {
                currentLastPos = i;
            }
        }
    
        return currentLastPos == 0;
    }
};