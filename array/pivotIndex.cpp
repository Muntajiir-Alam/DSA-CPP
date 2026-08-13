#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int leftSum = 0;
    for (int i = 0; i < n; i++)
    {
        int rightSum = sum - leftSum - nums[i];
        if (rightSum == leftSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}

int main()
{
    vector<int> nums ={1,7,3,6,5,6};
    cout << pivotIndex(nums) << endl;
}