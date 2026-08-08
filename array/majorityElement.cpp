#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int curEle = nums[0], count = 1;
    for (int i = 1; i < n; i++)
    {
        if (count == 0)
        {
            curEle = nums[i];
            count = 1;
        }
        else if (nums[i] == curEle)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return curEle;
}

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << majorityElement(nums) << endl;
}