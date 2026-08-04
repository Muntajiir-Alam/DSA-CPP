#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int getSecondLargest(int *arr, int n)
{
    int max = arr[0], secMax = -1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            secMax = max;
            max = arr[i];
        }
        else if (arr[i] < max && arr[i] > secMax)
        {
            secMax = arr[i];
        }
    }

    return secMax;
};
int main()
{
    int arr[] = {10,5,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getSecondLargest(arr, n) << endl;
}