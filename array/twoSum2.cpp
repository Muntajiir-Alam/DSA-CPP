#include <iostream>
#include <vector>
#include <climits>
#include <array>
using namespace std;
vector<int> twoSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int> ans(2, 0);
    int i = 0, j = n-1;
    while (i<j)
    {
        if (arr[i] + arr[j] == target)
        {
            ans[0] = i + 1;
            ans[1] = j + 1;
            return ans;
        }
        else if (arr[i] + arr[j] < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,3,4};
    int target = 6;
    vector<int> res = twoSum(arr, target);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}