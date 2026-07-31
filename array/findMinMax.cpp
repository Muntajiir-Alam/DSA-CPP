#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<int> findMinMax (vector<int> arr){
    int n = arr.size();
    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = 0; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
    return {minVal, maxVal};
}

int main() {
    vector<int> arr = {3, 5, 4, 1, 9};
    vector<int> result = findMinMax(arr);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}