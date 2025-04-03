/* recursion solution same logic as fibonacci have to find the ways to climb the stairs*/
// #include<iostream>
// using namespace std;
// int climb(int n)
// {
//     if(n==0|| n==1)
//     {
//         return 1;
//     }
//     return climb(n-1)+climb(n-2);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int ans=climb(n);
//     cout<<ans;
// }

/* memozaition with optimised time complexity*/

// #include<iostream>
// #include<vector>
// using namespace std;
// int climb(int n, vector<int>&dp)
// {
//     if(n==0|| n==1)
//     {
//         return 1;
//     }
//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]= climb(n-1, dp)+climb(n-2, dp);


// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>dp(n+1 , -1);
//     int ans=climb(n, dp);
//     cout<<ans;
// }

/* tabulation method to solve the qstnn*/
#include<iostream>
#include<vector>
using namespace std;
int climb(int n)
{
    if(n==0|| n==1)
    {
        return 1;
    }
    vector<int>dp(n+1 , 0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}
int main()
{
    int n;
    cin>>n;
    int ans=climb(n);
    cout<<ans;
}