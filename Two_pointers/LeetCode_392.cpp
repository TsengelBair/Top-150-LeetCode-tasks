#include <iostream>
#include <string>

using std::string;

bool isSubsequence(string s, string t) {
    int sP = 0;
    int tP = 0;

    while (tP < t.size()) {
        if (s[sP] == t[tP]) {
            ++sP;
            ++tP;
        } else {
            ++tP;
        }
    }

    if (sP == s.size()) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    string s = "axc";
    string t = "ahbgdc";

    bool res = isSubsequence(s, t);
    std::cout << res << std::endl;

    return 0;
}