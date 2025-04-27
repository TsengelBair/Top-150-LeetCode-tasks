class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int counter = 0;
            for (const auto& array : grid) {
    
                int left = 0;
                int right = array.size() - 1;
    
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (array[mid] < 0) {
                        counter += right - mid + 1;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
            }
    
            return counter;
        }
    };