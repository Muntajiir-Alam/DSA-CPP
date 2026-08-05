#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int insert = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[insert] == 0 && (nums[i]>0 || nums[i]<0))
        {
            swap(nums[insert], nums[i]);
            insert++;
        }
        else if (nums[insert] > 0 || nums[insert] < 0)
        {
            insert++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    
}

int main()
{
    vector<int> nums = {45192,27382,-659,-52359,-99225,-75991,81209,-15155,64648,59818,0,-30645,-17025,0,887,0};
    moveZeroes(nums);
}