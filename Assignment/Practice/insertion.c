#include<stdio.h>
void insertion(int arr[], int n){
    int i, j , k, temp;
    int cswap=0;
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while((j>=0) && (arr[j]>temp)){
            arr[j+1]=arr[j];
            cswap++;
            j--;
        }
        arr[j+1]=temp;
    printf("\n");  
    }
    printf("Sorted Array: ");
    for(k=0;k<n;k++){
        printf("%d ", arr[k]);
    } 
    printf("\nNumber of swaps: %d",cswap);
}
void main(){
    int n;
    printf("Enter the size of array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    insertion(arr,n);
}