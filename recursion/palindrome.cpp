#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool checkPalindrome(string &s, int left, int right)
{
    if ( left > right)
        return true;
    if (s[left] != s[right])
        return false;
        
    return checkPalindrome(s, left + 1, right - 1);
}

int main()
{
    string s = "abca";
    int len = s.length();
    int left{0}, right{len - 1};
    cout << (checkPalindrome(s ,left ,right) ? "True" : "False") << endl;
}