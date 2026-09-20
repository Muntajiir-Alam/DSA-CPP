#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int fibonacci(int n, vector<int> &memo)
{
    if (n == 0 || n == 1)
        return n;
    if (memo[n] != 0)
    {
        return memo[n];
    }
    return memo[n] = fibonacci(n - 2, memo) + fibonacci(n - 1, memo);
}

int main()
{
    int k = 6;
    vector<int> memo(k + 1, 0);
    cout << fibonacci(k, memo) << endl;
}