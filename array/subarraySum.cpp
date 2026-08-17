#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
// 560
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    int currentSum = 0;
    int count = 0;

    // Empty prefix
    mp[0] = 1;

    for (int num : nums)
    {
        currentSum += num;
        int required = currentSum - k;
        if (mp.find(required) != mp.end())
        {
            count += mp[required];
        }
        mp[currentSum]++;
    }

    return count;
}
int main()
{
    vector<int> nums = {1,-1,0};
    int k = 0;
    cout << subarraySum(nums, k) << endl;
}