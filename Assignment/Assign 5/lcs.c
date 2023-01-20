#include <stdio.h>
#include <string.h>

#define UP 0
#define LEFT 1
#define TOPLEFT 2

void printSubsequence(int, int);

int C[100][100], B[100][100];
char str1[100], str2[100];
int m, n;

int main() {
    printf("Enter string 1 : ");
    scanf("%s", str1);
    printf("Enter string 2 : ");
    scanf("%s", str2);

    m = strlen(str1);
    n = strlen(str2);

    for(int i = 0; i <= m; i++)
        C[i][0] = 0;

    for(int j = 0; j <= n; j++)
        C[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) { //NOTE: i and j are 1-indexed, so we do i-1 and j-1
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = TOPLEFT;
            }
            else {
                if(C[i-1][j] >= C[i][j-1]) {
                    C[i][j] = C[i-1][j];
                    B[i][j] = UP;
                }
                else {
                    C[i][j] = C[i][j-1];
                    B[i][j] = LEFT;
                }
            }
        }
    }
    printf("\nTotal length of characters: %d\n",C[m][n]);
    printf("The longest common subsequence is : ");

    printSubsequence(m, n);
    return 0;
}

void printSubsequence(int i, int j) {
    if(i == 0 || j == 0)
        return;
    
    if(B[i][j] == LEFT)
        printSubsequence(i, j-1);
    else if(B[i][j] == UP)
        printSubsequence(i-1, j);
    else {
        printSubsequence(i-1, j-1);
        printf("%c", str1[i-1]); 
    }
}