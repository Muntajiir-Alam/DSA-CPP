#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int fibonacci (int n){
    if (n == 0 || n==1)
        return n;
    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(){
    cout << fibonacci(6) << endl;
}