#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

void bubble_sort(int A[], int n){
    int i, j, temp;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        
    } 
}

void display(int A[], int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n\n");
}

int main(){
    int i, n, A[MAX];

    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    // display(A,n);

    start = clock();
    bubble_sort(A, n);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // display(A, n);
    printf("Time taken is %lf seconds\n", time_taken);
    return 0;
    
}