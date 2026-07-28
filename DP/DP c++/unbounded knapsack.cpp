#include<iostream>
#include<vector>
using namespace std;
int unbounded(vector<int>&val , vector<int>&wt , int n, int w)
{
    vector<vector<int>>dp(n+1  , vector<int>(w+1, 0));
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            int itemwt=wt[i-1];
            int itemval=val[i-1];
            if(itemwt<=j)
            {
                dp[i][j]=max(itemval+dp[i][j-itemwt] ,dp[i-1][j] );
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
       
    }
    return dp[n][w];
}
 int main()
 {
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int n=5;
    int w=7;
    cout<<unbounded(val ,wt , n, w);
 }
// TOP-DOWN APPROACH
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dp[1001][1001];

int solve(vector<int>& wt, vector<int>& val, int i, int W, int n)
{
    // Base case
    if(i == n || W == 0)
        return 0;

    if(dp[i][W] != -1)
        return dp[i][W];

    // Skip current item
    int skip = solve(wt, val, i + 1, W, n);

    // Take current item (stay at same index)
    int take = 0;
    if(wt[i] <= W)
    {
        take = val[i] + solve(wt, val, i, W - wt[i], n);
    }

    return dp[i][W] = max(take, skip);
}

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt)
{
    memset(dp, -1, sizeof(dp));
    return solve(wt, val, 0, W, n);
}

int main()
{
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int W = 8;

    cout << unboundedKnapsack(val.size(), W, val, wt);

    return 0;
}
