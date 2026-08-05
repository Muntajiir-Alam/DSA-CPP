#include <iostream>
#include <vector>
#include <climits>
// #include <algorithm>
using namespace std;

void reverse(vector<int> &nums, int start, int end)
{
    int j = end;
    int i = start;
    while (i < j)
    {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
}

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= nums.size();

    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    rotate(nums, k);
}