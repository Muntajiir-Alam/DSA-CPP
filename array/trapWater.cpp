#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int trapWater = 0;
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);
    int curMax = height[0];
    for (int i = 0; i < n; i++)
    {
        if (height[i] > curMax)
        {
            curMax = height[i];
        }
        leftMax[i] = curMax;
    }

    curMax = height[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (height[i] > curMax)
        {
            curMax = height[i];
        }
        rightMax[i] = curMax;
    }

    for (int i = 0; i < n; i++)
    {
        trapWater += min(leftMax[i], rightMax[i]) - height[i];
    }

    return trapWater;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl; 
}