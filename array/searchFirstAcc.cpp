#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int search(int arr[], int n, int x) {
    for (int i=0; i<n; i++){
        if (arr[i]==x){
            return i;
        }
    }
    return -1;
}

int main(){

    int arr[] = {10, 8, 30, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 5;
    cout << search(arr, n, x);
}