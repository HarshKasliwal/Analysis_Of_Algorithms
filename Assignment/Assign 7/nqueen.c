#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, count = 0;
int x[100];

void printsoln() {
    for(int itr = 0; itr < n; itr++) {
        printf("%d ", x[itr]);
    }
    printf("\n");
}

bool place(int k, int i) {
    for(int j = 0; j < k; j++) {
        if(x[j] == i || abs(x[j]-i) == abs(j-k))
            return false;
    }
    return true;
}

void nqueens(int k) {
    for(int i = 0; i < n; i++) {
        if(place(k, i)) {
            x[k] = i;
            if(k == n-1) {
                printf("Solution %d : ", count);
                printsoln();
                count++;
            }
            else
                nqueens(k+1);
        }
    }
}

int main() {
    printf("Enter the value of n : ");
    scanf("%d", &n);
    nqueens(0);
    return 0;
}