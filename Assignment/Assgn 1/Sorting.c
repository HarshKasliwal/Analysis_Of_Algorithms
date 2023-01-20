#include<stdio.h>
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//***************Insertion Sort(Tn=n^2 & Tn=n)***************
void insertion (int a[],int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
        a[j+1]=a[j];
        j--;
        }
        a[j+1]=temp;
    }
}

//***************Selection Sort(Tn=n^2)*********************
void select(int a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[j]<a[i])
            swap(&a[i],&a[j]);
        }
    }
}

//************** Bubble Sort *****************
void Bubble(int a[], int n){
    int counter=1;
    while(counter<n){
        for(int i=0;i<n-counter; i++){
            if(a[i+1]<a[i])
            swap(&a[i],&a[i+1]);
        }
    counter++;
    }
}
//************** QUICK SORT(Tn=n^2 & Tn=nlogn) ******************
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
        if(i<j)
        swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return (j);
}
void quick(int a[],int l, int h){
    if(l<h){
        int j=partition(a,l,h);
        quick(a,l,j);
        quick(a,j+1,h);
    }
}
//************** Merge Sort(Tn=nlogn) ****************

void merge(int a[],int l,int mid, int h){
    int i=l, j=mid+1, k=l;
    int b[h];
    while(i<=mid && j<=h){
        if(a[i]<=a[j]){
        b[k]=a[i];
        i++,k++;
        }
        else{
        b[k]=a[j];
        j++,k++;
        }
    }
    if(i>mid){
        while(j<=h){
            b[k]=a[j];
            j++,k++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            i++,k++;
        }
    }
    for(int k=l;k<=h;k++){
        a[k]=b[k];
    }
}
void mergesort(int a[],int l, int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
void Array(int a[], int n){
    printf("[");
    for (int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("]\n\n");
}

int main(){
    int n, c,d;
    do{
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    printf("\nUnsorted array: ");
    Array(a,n);
    printf("\nSelect the sorting: \n1.Insertion Sort\n2.Selection Sort\n3.Bubble Sort\n4.Quick Sort\n5.Merge Sort\n-->");
    scanf("%d",&c);
    if(c==1){
        insertion(a,n);
        printf("\nSorted Array by Insertion: ");
        Array(a,n);
    }
    else if(c==2){
        select(a,n);
        printf("\nSorted Array by Selection: ");
        Array(a,n);
    }
    else if(c==3){
        Bubble(a,n);
        printf("\nSorted Array by Bubble: ");
        Array(a,n);
    }
     else if(c==4){
        quick(a,0,n);
        printf("\nSorted Array by QuickSort: ");
        Array(a,n);
    }
    else if(c==5){
        mergesort(a,0,n-1);
        printf("\nSorted Array by MergeSort: ");
        Array(a,n);
    }
    else
        printf("\nInvalid Option!");

        printf("Wanna Continue?\nYes --> 1\nNo --> 0\n");
        scanf("%d", &d);
    }while(d!=0);
}