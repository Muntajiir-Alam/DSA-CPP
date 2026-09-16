#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int factorial (int num){
    if (num == 1 || num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main(){
    cout << factorial(4) << endl;
}