#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int n = nums1.size(), m = nums2.size();
    int total = n + m;
    int half = (total + 1) / 2;

    int lo = 0, hi = n;
    while (lo <= hi)
    {
        int i = lo + (hi - lo) / 2;
        int j = half - i;

        int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
        int right1 = (i == n) ? INT_MAX : nums1[i];
        int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
        int right2 = (j == m) ? INT_MAX : nums2[j];

        if (left1 <= right2 && left2 <= right1)
        {
            if (total % 2 == 0)
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            else
                return max(left1, left2);
        }
        else if (left1 > right2)
        {
            hi = i - 1;
        }
        else
        {
            lo = i + 1;
        }
    }
    return -1.0; 
}

int main()
{
    vector<int> nums1 = {7, 12, 14, 15};
    vector<int> nums2 = {1, 2, 3, 4, 9, 11};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}