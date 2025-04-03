/* knapsack probelm with the help of recursion in exponsial time complexity*/
// #include<iostream>
// #include<vector>
// using namespace std;
// int knapsack(vector<int>&val , vector<int>&wt ,int w, int n)
// {
//     int itemwt=wt[n-1];
//     int itemval=val[n-1];

//     if(n==0 || w==0)
//     return 0;
//     if(itemwt<=w) // valid condition then if it will include and exclude 
//     {
//        int ans1= knapsack(val ,wt,w-itemwt,n-1)+itemval; // include

//        int ans2= knapsack(val ,wt,w,n-1); // exclude 
//        return max(ans1 , ans2);
       
//     }
//     else{
//         return knapsack(val ,wt,w,n-1); // exclude
//     }

// }
// int main()
// {
//     vector<int>val={15,14,10,45,30};
//     vector<int>wt={2,5,1,3,4};
//     int w=7;
//     int n=5;

//     cout<<knapsack(val ,wt, w, n);
// }


/* with the help of memozaition with complexity of 0(w*n)*/

// #include<iostream>
// #include<vector>
// using namespace std;
// int knapsack(vector<int>&val , vector<int>&wt ,int w, int n, vector<vector<int>>&dp)
// {
//     int itemwt=wt[n-1];
//     int itemval=val[n-1];

//     if(dp[n][w]!=-1)
//     {
//         return dp[n][w];
//     }

//     if(n==0 || w==0)
//     return 0;
//     if(itemwt<=w) // valid condition then if it will include and exclude 
//     {
//        int ans1= knapsack(val ,wt,w-itemwt,n-1,dp)+itemval; // include

//        int ans2= knapsack(val ,wt,w,n-1, dp); // exclude 
//        return dp[n][w]= max(ans1 , ans2);
       
//     }
//     else{
//         return  dp[n][w]=knapsack(val ,wt,w,n-1, dp); // exclude
//     }

// }
// int main()
// {
//     vector<int>val={15,14,10,45,30};
//     vector<int>wt={2,5,1,3,4};
//     int w=7;
//     int n=5;
//    vector<vector<int>>dp(n+1 , vector<int>(w+1  , -1));
//     cout<<knapsack(val ,wt, w, n, dp);
// }

/* with the help of tabulation having 0(n*w ) conmplexity */

// Online C++ compiler to run C++ program online
#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>&val , vector<int>&wt ,int w, int n)
{
    vector<vector<int>>dp(n+1 , vector<int>(w+1 , 0));
    
    for(int i=1;i<n+1;i++)
    {
        
        for(int j=1;j<w+1;j++)
        {
            int itemwt=wt[i-1];
             int itemval=val[i-1];
            if(itemwt<=j)
            {
                dp[i][j]=max((dp[i-1][j-itemwt]+itemval) , dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
         
         
         
        for(int i=0;i<n+1;i++)
    {
        
        for(int j=0;j<w+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][w];
}


int main()
{
    vector<int>val={15,14,10,45,30};
    vector<int>wt={2,5,1,3,4};
    int w=7;
    int n=5;
    cout<<knapsack(val ,wt, w, n);
}