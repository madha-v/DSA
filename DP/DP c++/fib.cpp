// #include<iostream>
// using namespace std;
// int fib(int n)
// {
//     if(n<=1)
//     {
//         return n;
//     }
//     return fib(n-1)+fib(n-2);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     int ans=fib(n);
//     cout<<"fibbonacci is "<<ans;
// }

// with the help of dp having 0(n) complexity best optimised for the fibbonaachi series 

// #include<iostream>
// #include<vector>
// using namespace std;
// int fibdp(int n, vector<int>&dp)
// {
//     if(n<=1)
//     {
//         return n;
//     }

//     if(dp[n]!=-1)
//     {
//         return dp[n];
//     }
//     dp[n]=fibdp(n-1, dp)+fibdp(n-2, dp);
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>dp(n+1 , -1);
//     int ans=fibdp(n,dp);
//     cout<<"fibbonacci is "<<ans;
// }


/* tabulatuon method */


#include<iostream>
#include<vector>
using namespace std;
int fib(int n)
{
    if(n<=1)
    return n;
    vector<int>dp(n+1 , 0);
    dp[0]=0;
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
    int ans=fib(n);
    cout<<"fibbonacci is "<<ans;
}