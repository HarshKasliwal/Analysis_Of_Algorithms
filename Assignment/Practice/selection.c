#include <stdio.h>
#include <stdlib.h>

void selection_sort(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min_index;
        min_index=i;
        for(int j=i+1;j<size;j++)
        {
            if(a[j]<a[min_index])
            {
                min_index=j;
            }
            int temp=a[i];
            a[i]=a[min_index];
            a[min_index]=temp;
            // swap( &arr[i] , &arr[min_index]);
        }
    }
}

int main()
{
    int n,a[n];
    printf("Enter the total number of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("--------------Before sorting---------------");
    for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
    {
        printf("%d\t",a[i]);
    }
    selection_sort(a,n);
    printf("------------After sorting the array -------------");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}