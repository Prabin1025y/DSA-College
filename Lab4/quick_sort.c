#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000

int partition(int A[], int l, int r)
{
    int x = l, y = r, pivot = A[l], temp;

    while (x < y)
    {
        while (A[x] <= pivot && x <= r)
            x++;
        while (A[y] > pivot && y >= l)
            y--;

        if (x < y)
        {
            temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
    A[l] = A[y];
    A[y] = pivot;
    return y;
}

void quick_sort(int A[], int l, int r)
{
    int  p;
    if(l < r){
        p = partition(A, l, r);
        quick_sort(A, l, p-1);
        quick_sort(A, p+1, r);
    }
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n\n\n");
}

int main()
{
    int i, n, A[MAX];

    clock_t start, end;
    double time_taken;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    // display(A, n);

    start = clock();
    quick_sort(A, 0, n-1);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // display(A, n);
    printf("Time taken is %lf seconds\n", time_taken);
    return 0;
}