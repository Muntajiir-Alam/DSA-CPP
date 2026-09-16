#include <iostream>
#include <vector>
#include <climits>
using namespace std;
string reverseString(string &s, int left, int right)
{
    if (left > right)
        return s;
    swap(s[left], s[right]);
    return reverseString(s, left + 1, right - 1);
}

int main()
{
    string s = "alam";
    int len = s.length();
    int left{0}, right{len - 1};
    cout << reverseString(s, left, right) << endl;
}