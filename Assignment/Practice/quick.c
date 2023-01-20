#include<stdio.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int l, int h){
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j){
    do{
        i++;
    }while(a[i]<=pivot);
    do{
        j--;
    }while(a[j]>pivot);
    if(i<j){
        swap(&a[i],&a[j]);
    }
    }
    swap(&a[l],&a[j]);
    return j;
}

void quick(int a[], int l, int h){
    if(l<h){
        int j=partition(a,l,h);
        quick(a, l, j);
        quick(a, j+1, h);
    }
}

void Array(int a[], int size){
  for (int i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}

void main(){
    int n;
    printf("Enter the size of array: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    quick(a,0,n);
    printf("Sorted array: ");
    Array(a,n);

}