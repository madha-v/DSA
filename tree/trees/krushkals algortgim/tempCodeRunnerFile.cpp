#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int>&arr,int key)
{
    int n=arr.size();
    int l=0, r=n-1;
    
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(arr[mid]==key)
        {
            cout<"found";
            return mid;

        }
        else if(arr[mid]<key)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[5]={1 ,2 ,3,20,45};
    int key=20;
    binary(arr,key);
    return 0;
}