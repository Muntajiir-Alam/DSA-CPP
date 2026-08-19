#include <iostream>
#include <vector>
#include <climits>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;
    double m1 = 0, m2 = 0;
    for (int count = 0; count <= (n + m) / 2; count++)
    {
        m2 = m1;
        if (i != n && j != m)
        {
            if (nums1[i] > nums2[j])
                m1 = nums2[j++];
            else
                m1 = nums1[i++];
        }
        else if (i < n)
        {
            m1 = nums1[i++];
        }
        else
        {
            m1 = nums2[j++];
        }
    }
    if ((n + m) % 2 == 1)
    {
        return m1;
    }
    else
    {
        return (m1 + m2) / 2.0;
    }
    return 0;
}

int main()
{
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
}