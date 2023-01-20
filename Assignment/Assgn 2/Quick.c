#include <stdio.h>
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[low];
  int i = low;
  int j = high;
  while(i<j){
  do{
      i++;
  }while(array[i]<=pivot);
  do{
      j--;
  }while(array[j]>pivot);
  if(i<j)
  swap(&array[i], &array[j]);
  }
  swap(&array[low], &array[j]);
  return (j);
}

void quickSort(int array[], int low, int high){
  if (low < high) {
    int j=partition(array, low, high);
    quickSort(array, low, j);
    quickSort(array, j + 1, high);
  }
}

void Array(int array[], int size){
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main(){
int n;
printf("How many elements you want: ");
scanf("%d", &n);
int arr[n];
printf("Enter the elements: ");
for(int i=0; i<n; i++){
scanf("%d", &arr[i]);
}
printf("Unsorted Array is \n");
Array(arr, n);
quickSort(arr, 0, n);
printf("Sorted array in ascending order is \n");
Array(arr, n);
}