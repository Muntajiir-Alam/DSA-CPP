#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

bool searchMatrix(vector<vector<int>> &nums, int k)
{
    int rows = nums.size(), cols = nums[0].size();
    int i{0}, j{(rows * cols) - 1};
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        int r = mid / cols;
        int c = mid % cols;
        if (nums[r][c] == k)
            return true;
        else if (nums[r][c] > k)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return false;
}

int main()
{
    vector<vector<int>> nums = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int k{13};
    cout << searchMatrix(nums, k) << endl;
}