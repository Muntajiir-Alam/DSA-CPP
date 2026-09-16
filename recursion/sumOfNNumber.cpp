#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int sumOfNnumbers(int num)
{
    if (num == 0)
        return 0;
    return num + sumOfNnumbers(num - 1);
}

int main()
{
    cout << sumOfNnumbers(4) << endl;
}