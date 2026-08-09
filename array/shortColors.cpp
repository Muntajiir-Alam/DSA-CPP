#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = n - 1;
    int mid = 0;
    while (mid <= j)
    {
        if (nums[mid] == 0)
        {
            swap(nums[i++], nums[mid++]);
        }
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[j--]);
        }
        else
        {
            mid++;
        }
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
    for (auto &&i : nums)
    {
        cout << i << " ";
    }
    cout<< endl;
    
}