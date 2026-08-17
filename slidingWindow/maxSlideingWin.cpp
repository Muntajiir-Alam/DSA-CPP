#include <iostream>
#include <vector>
#include <climits>
#include <deque>
using namespace std;
// 239

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> res;
    deque<int> dq;
    // 1st window
    for (int i = 0; i < k; i++)
    {
        while (dq.size() > 0 && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    int i = 1, j = k;
    while (j < n)
    {
        res.push_back(nums[dq.front()]);

        // remove not part of the windos
        while (dq.size() > 0 && dq.front() < i)
        {
            dq.pop_front();
        }

        // remove smaller value from curent
        while (dq.size() > 0 && nums[dq.back()] <= nums[j])
        {
            dq.pop_back();
        }
        dq.push_back(j);
        i++;
        j++;
    }
    res.push_back(nums[dq.front()]);
    return res;
}
int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> res = maxSlidingWindow(nums, k);

    cout << "Max sliding window: ";
    for (int num : res)
    {
        cout << num << " ";
    }
    cout << endl;
}