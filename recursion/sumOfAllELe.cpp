#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int sumOFArr(vector<int> &nums , int idx)
{
    if (nums.size() == idx)
        return 0;
    return nums[idx] + sumOFArr(nums, idx + 1);
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << sumOFArr(nums, 0) << endl;
}