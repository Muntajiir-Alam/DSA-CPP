#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxArea = 0;
    int curLen = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        curLen = j-i;
        if (height[i] < height[j])
        {
            curLen *=height[i++];
            maxArea = max(maxArea,curLen);

        }
        else if (height[i] > height[j] || height[i] == height[j])
        {
            curLen *=height[j--];
            maxArea = max(maxArea,curLen);
        } 
    }
    return maxArea;
}

int main()
{
    vector<int> height = {2,2};
    cout << maxArea(height) << endl; 
}