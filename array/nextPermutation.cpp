#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int pivot = -1;
    int nextEle = n - 1;

    // find pivot
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // if not find
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // find next gerter value form pivot
    for (int i = n - 1; i >= pivot + 1; i--)
    {
        if (nums[i] > nums[pivot])
        {
            nextEle = i;
            break;
        }
    }

    swap(nums[pivot], nums[nextEle]);
    reverse(nums.begin() + (pivot + 1), nums.end());
}

int main()
{
    vector<int> nums = {2, 3, 1};
    nextPermutation(nums);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}