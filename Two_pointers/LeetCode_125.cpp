class Solution {
    public:
        std::string processString(const std::string& input) {
            std::string result;
            for (char ch : input) {
                if (std::isalnum(ch)) { 
                    result += std::tolower(ch); 
                }
            }
            return result;
        }
    
        bool isPalindrome(string s) {
            if (s.empty()) return true;
            string str = processString(s);
    
            int start = 0;
            int end = str.size() - 1;
    
            while (start < end) {
                if (str[start] != str[end]) {
                    return false;
                } else {
                    ++start;
                    --end;
                }
            }
    
            return true;
        }
    };