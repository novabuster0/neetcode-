#include <iostream>
#include <algorithm>
// #include <cstring>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (c <= 90 && c >= 65)
            {
                s[i] += 32;
            }
            if (!isalnum(c))
            {
                s.erase(s.begin() + i);
            }
        }
        string reversed_string = s;
        reverse(reversed_string.begin(), reversed_string.end());
        return reversed_string == s;
    }
};

int main()
{
    Solution s;
    cout << s.isPalindrome("0P");
    return 0;
}