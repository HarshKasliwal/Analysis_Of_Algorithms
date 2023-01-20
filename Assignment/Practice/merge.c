#include<stdio.h>
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int a[], int l, int mid, int h){
    int i=l;
    int j=mid+1;
    int k=l;
    int b[h];
    while(i<=mid && j<=h){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
    }
     while(j<=h){
            b[k]=a[j];
            j++;
            k++;
        }
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    for(k=1; k<=h;k++){
        a[k]=b[k];
    }
}
void Array(int a[], int size){
  for (int i = 0; i < size; ++i) {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
void mergesort(int a[], int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a, l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }

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
    printf("UnSorted array: ");
    Array(a,n);
    mergesort(a,0,n);
    printf("Sorted array: ");
    Array(a,n);

}