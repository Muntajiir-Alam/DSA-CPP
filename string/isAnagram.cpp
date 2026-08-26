#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;
bool isAnagram(string s, string t)
{
    if(s.length() != t.length()) return false;
    unordered_map<char, int> mp;
    for (auto &&i : s)
    {
        mp[i]++;
    }
    for (auto &&i : t)
    {
        mp[i]--;
        if(mp[i]<0) return false;
    }
    return true;
}

int main()
{
    string s{"rat"}, t{"car"};
    cout << isAnagram(s, t) << endl;
}