class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            if (n == 0) return;
            k = k % n; 
    
            std::vector<int> tmp;
            tmp.reserve(n); 
    
            for (int i = n - k; i < n; ++i) {
                tmp.push_back(nums[i]); 
            }
    
            for (int i = 0; i < n - k; ++i) {
                tmp.push_back(nums[i]); 
            }
    
            nums = tmp; 
        }
};
