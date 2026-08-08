#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ansPos;
    vector<int> ansNeg;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ansPos.push_back(nums[i]);
        }
        else
        {
            ansNeg.push_back(nums[i]);
        }
    }
    vector<int> ans;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            ans.push_back(ansPos[pos++]);
        }
        else
        {
            ans.push_back(ansNeg[neg++]);
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