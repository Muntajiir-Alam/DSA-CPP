#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void getAllSubsets(vector<int> &nums, vector<int> &ans, int index, vector<vector<int>> &allSubset)
{
    if (index == nums.size())
    {
        allSubset.push_back({ans});
        return;
    }
    // include
    ans.push_back(nums[index]);
    getAllSubsets(nums, ans, index + 1, allSubset);
    ans.pop_back();

    // exclude
    getAllSubsets(nums, ans, index + 1, allSubset);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> ans;
    vector<vector<int>> allSubset;

    getAllSubsets(nums, ans, 0, allSubset);

    return allSubset;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> ans;

    vector<vector<int>> res = subsets(nums);

    for (auto &subset : res)
    {
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
}