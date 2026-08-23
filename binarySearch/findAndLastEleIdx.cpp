#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> searchRange(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 0)
        return {-1, -1};

    // 5,7,7,8,8,10
    // First occurrence: first index where nums[idx] >= target
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] >= target)
            j = mid - 1;
        else
            i = mid + 1;
    }
    int firstIdx = j + 1;
    // 5,7,7,8,8,10
    //  Last occurrence: last index where nums[idx] <= target
    i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (nums[mid] <= target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    int lastIdx = i - 1;

    // Validate target actually exists there
    if (firstIdx < 0 || firstIdx >= n || nums[firstIdx] != target)
        return {-1, -1};

    return {firstIdx, lastIdx};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int k = 8;
    vector<int> res = searchRange(nums, k);
    for (auto &&i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}