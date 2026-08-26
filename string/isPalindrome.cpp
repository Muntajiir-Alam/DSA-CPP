#include <iostream>
#include <vector>
#include <climits>
using namespace std;
bool isPalindrome(string s)
{
    int n = s.length();
    int i{0}, j{n - 1};
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
            i++;
        while (i < j && !isalnum(s[j]))
            j--;
        if (tolower(s[i++]) != tolower(s[j--]))
            return false;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << isPalindrome(s) << endl;
}