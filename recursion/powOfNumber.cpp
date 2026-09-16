#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int powOfNum (int x, int n) {
    if (n == 0)
        return 1;
    return x * powOfNum(x, n - 1);
}
int main(){
    cout << powOfNum(3, 4) << endl;
}