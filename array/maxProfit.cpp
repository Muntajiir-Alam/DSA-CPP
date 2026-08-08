#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxProfit = 0;
    int n = prices.size();
    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else if (prices[i] > minPrice)
        {
            int curProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, curProfit);
        }
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}