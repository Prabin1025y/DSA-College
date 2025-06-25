#include<stdio.h>
#include<time.h>
#define MAX 100
long table[MAX] = {0};

int tailFact(int n, int a){
    if (n == 1)
        return a;
    else
        return tailFact(n-1, a*n);
}

long fiboM(int n){
    if(n==1 || n == 2)
        return 1;
    else{
        if(table[n] == 0){
            table[n]= fiboM(n-1) + fiboM(n-2);
        }
        return table[n];
    }
}

int sum(int n){
    if(n==1){
        return 1;
    }else{
        return n + sum(n-1);
    }
}

int GCD(int a, int b){
    if(b == 0)
        return a;
    else
     return GCD(b, a%b);
}

int stepsCount = 0;

void TOH(int n, int src, int dst, int tmp){
    if(n==1){
        stepsCount++;
        printf("Move disk %d from %c to %c\n", n, src, dst);
    }
    else{
        TOH(n-1, src, tmp, dst);
        printf("Move disk %d from %c to %c\n", n, src, dst);
        stepsCount++;
        TOH(n-1, tmp, dst, src);
    }
}



int main(){
    int n, a, b;
    // printf("Enter value of n: ");
    // scanf("%d", &n);
    // printf("The factorial of %d is %d:", n, tailFact(n,1));
    // printf("The %dnth term is %d",n, fiboM(n));
    // printf("The sum from 0 to %d is %d", n, sum(n));

    // printf("Enter the value of a and b:");
    // scanf("%d%d", &a, &b);
    // printf("The GCD of %d and %d is %d", a, b, GCD(a,b));

    clock_t start, end;
    double time;

    printf("Enter the number of discs: ");
    scanf("%d", &n);
    start = clock();
    TOH(n, 'A', 'C', 'B');
    end = clock();
    printf("Steps: %d\n", stepsCount);
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("TIme: %lf", time);


    return 0;
}