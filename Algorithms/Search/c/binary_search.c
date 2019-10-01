#include<stdio.h>
 
int main()
{
    int ar[50],a,n,b,flag=0,first,last,mid;
 
    printf("Enter size of the array:");
    scanf("%d",&n);
    printf("\nEnter elements of array in ascending order\n");
 
    for(a=0;a<n;++a)
        scanf("%d",&ar[a]);
 
    printf("\nEnter the element to search:");
    scanf("%d",&b);
 
    first=0;
    last=n-1;
 
    while(first<=last)
    {
        mid=(first+last)/2;
 
        if(b==ar[mid]){
            flag=1;
            break;
        }
        else
            if(b>ar[mid])
                first=mid+1;
            else
                last=mid-1;
    }
 
    if(flag==1)
        printf("\nElement found at position %d",mid+1);
    else
        printf("\nElement not found");
 
    return 0;
}
