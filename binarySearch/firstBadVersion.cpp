#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// check bad version
int badVersion = 2;
bool isBadVersion(int version)
{
    return version >= badVersion;
}

int firstBadVersion(int n)
{
    int i = 1;
    int j = n;

    while (i < j)
    {
        int mid = i + (j - i) / 2;

        if (isBadVersion(mid))
        {
            j = mid;
        }
        else
        {
            i = mid + 1;
        }
    }
    return i;
}

int main()
{
    cout << firstBadVersion (3) << endl;
}