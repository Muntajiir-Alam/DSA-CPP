#include <iostream>
#include <vector>
using namespace std;

void getAllPermutations(
    vector<int> &nums,
    vector<int> &current,
    vector<bool> &used,
    vector<vector<int>> &result)
{
    // Base case
    if (current.size() == nums.size())
    {
        result.push_back(current);
        return;
    }

    // Try every element
    for (int i = 0; i < nums.size(); i++)
    {

        // Already used
        if (used[i])
            continue;

        // Choose
        current.push_back(nums[i]);
        used[i] = true;

        // Recurse
        getAllPermutations(nums, current, used, result);

        // Backtrack
        used[i] = false;
        current.pop_back();
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);

    getAllPermutations(nums, current, used, result);

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = permute(nums);

    for (auto &permutation : result)
    {
        for (int num : permutation)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}