#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void reverseString(vector<char> &s)
{
    int n = s.size();
    int i{0}, j{n - 1};
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}
int main()
{
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for (char i : s)
    {
        cout << i;
    }
    cout << endl;
}