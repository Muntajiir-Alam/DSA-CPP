// leetcode (747)
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dominantIndex(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int idx = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
            idx = i;
        } 
        else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }

    if (max1 >= 2 * max2) return idx;

    return -1;
}

int main(){
    vector<int> nums = {1,0};
    cout << dominantIndex(nums) << endl;
    return 0;
}