#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[],int size)
{
    int min_index;
    for(int i=0;i<size;i++)
    {
        i=min_index;
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]<arr[min_index])
            {
                min_index=j;
            }
            swap( &arr[i] , &arr[min_index]);
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
    for(int i=0;i<n;i++)
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