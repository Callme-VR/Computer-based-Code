#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) (pow(x,3)-9*x-1)
#define g(x) (cbrt(9*x+1))

int main(){
    int c=0,n;
    float X0,X1,e;
    printf("Enter the initial guess :");
    scanf("%f" ,&X0);
    printf("Enter the error :");
    scanf("%f" ,&e); 
    printf("Enter the maximum iteration :");
    scanf("%d" ,&n);

    do{
        X1=g(X0);
        printf("%d\t%f\t%f\t%f\t%f",c,X0,f(X0),X1,f(X1));
        c=c+1;
        if(c>n){
            printf("not convergent :");
            exit (0);
        }
        X0=X1;
    }
    while (fabs(f(X1))>e);
    printf("Root of the equation is :%f\n",X1);
    return 0;


} 