#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

bool searchMatrix(vector<vector<int>> &nums, int k)
{
    int rows = nums.size() , cols = nums[0].size();
    int i{0}, j{cols - 1};
    while (i < rows && j >= 0)
    {
        if (nums[i][j] == k)
            return true;
        else if (nums[i][j] < k)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    vector<vector<int>> nums = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
    int k{5};
    cout << searchMatrix(nums, k) << endl;
}