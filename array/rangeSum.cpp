#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class NumArray
{
    vector<int> nums;
public:
    NumArray(vector<int> &arr)
    {
        nums = arr;

        int n = nums.size();

        for (int i = 1; i < n; i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }
    }
    int sumRange(int left, int right)
    {

        if (left == 0)
        {
            return nums[right];
        }

        return nums[right] - nums[left - 1];
    }
};

int main()
{
    vector<int> arr = {1, 3, 5, 7, 9};
    NumArray numArray(arr);

    cout << "Sum range [0, 2]: " << numArray.sumRange(0, 2) << endl;
    cout << "Sum range [1, 3]: " << numArray.sumRange(1, 3) << endl;
    cout << "Sum range [2, 4]: " << numArray.sumRange(2, 4) << endl;

    return 0;
}