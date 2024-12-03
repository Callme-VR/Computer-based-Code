#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) ((x)*(x)*(x)-2*(x)-5)
#define g(x) (3*(x)*(x)-2)


void main(){
	float X0,X1,f0,f1,g0,e;
	int c=1,n;

	printf("\nEnter initial guess:\n");
    scanf("%f", &X0);
	printf("Enter tolerable error:\n");
	scanf("%f", &e);
	printf("Enter maximum iteration:\n"); 
	scanf("%d", &n);
	printf("\nc\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

	do{
		g0=g(X0);
		f0=f(X0);
		if(g(X0)==f(X0)){
			printf("mathematical error:\n");
			exit (0);
		}
		X1=X0-f0/g0;
		printf("%d\t\t%f\t%f\t%f\t%f\n",c,X0,f0,X1,f1);
		X0=X1;
		c=c+1;
		if(c>n){
			printf("not convergent:\n");
			exit (0);
		}
		f1=f(f1);
	}
	while (fabs(f1)>e);
	printf("root of the eqation is ::: %f \n \n",X1);
}