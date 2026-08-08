#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n,0);
    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos+=2;
        }
        else
        {
            ans[neg] = nums[i];
            neg+=2;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> res = rearrangeArray(nums);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}