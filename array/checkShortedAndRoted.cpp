// leetcode (1752)
#include <iostream>
#include <vector>
using namespace std;
bool check(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i] )
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0]) count++;

    if (count > 1){
        return false;
    }
    return true;
};

int main()
{
    vector<int> arr = {3, 4, 5, 1, 2};
    cout << check(arr) << endl;
}
