#include<stdio.h>
#define max 100

int main()
{
    int a[max];
    int n = 10;
    int c = 0;
    
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int n = a[i]; 

    
        while(n > 0)
        {
            int rem = n % 10; 
            if(rem == 1)
            {
                c++; 
            }
            n = n / 10;
        }
    }

    printf("Count of 1s is: %d", c);
    return 0;
}
