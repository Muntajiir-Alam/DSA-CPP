#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> answer(n, 1);

    // Prefix products
    int prefix = 1;
    for (int i = 0; i < n; i++)
    {
        answer[i] = prefix;
        prefix *= nums[i];
    }

    // Suffix products
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        answer[i] *= suffix;
        suffix *= nums[i];
    }

    return answer;
}

int main()
{
    vector<int> nums = {-1, 1, 0, -3, 3};
    vector<int> answer = productExceptSelf(nums);
    for (auto &&i : answer)
    {
        cout << i << " ";
    }
    cout << endl;
}