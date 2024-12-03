
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

#define   SIZE   10

int main(){
	float a[SIZE][SIZE],x[SIZE],ratio;
	int i,j,k,n;
	printf("Enter the number of argument :: \n");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<n+1;j++){
			printf("matrix a[%d][%d]=",i,j);
			scanf("%f",&a[i][j]);
		}
	}

	// for cofficient divisible by 0
	for(int i=1;i<n-1;i++){
		if(a[i][j]==0.0){
			printf("mathematical error:");
			exit (0);
		}
		for(int j=i+1;j<n;j++){
			ratio=a[j][i]/a[i][i];
			for(int k=1;k<=n+1;k++){
				a[j][k]=a[j][k]-ratio*a[i][k];
			}
		}
	}
	x[n]=a[n][n+1]/a[n][n];
	for(int i=n-1;i>=1;i--){
		x[i]=a[i][n+1];
		for(int j=i+1;j<=n;j++){
			x[i]=x[i]-a[i][j]*x[j];
		}
		x[i]=x[i]/a[i][i];
	}
	// displaying the solution 
	printf("\n solution of the equation::\n");
	for(int i=1;i<=n;i++){
		printf("x[%d]= %0.3f\n :",i,x[i]);
	}
	getch();
	return 0;

}

// #include<stdio.h>
// #include<conio.h>
// #include<math.h>
// #include<stdlib.h>

// #define   SIZE   10

// int main()
// {
// 	 float a[SIZE][SIZE], x[SIZE], ratio;
// 	 int i,j,k,n;
// 	 printf("Enter number of unknowns: ");
// 	 scanf("%d", &n);
// 	 for(i=1;i<=n;i++)
// 	 {
// 		  for(j=1;j<=n+1;j++)
// 		  {
// 			   printf("a[%d][%d] = ",i,j);
// 			   scanf("%f", &a[i][j]);
// 		  }
// 	 }
// 	 for(i=1;i<=n-1;i++)
// 	 {
// 		  if(a[i][i] == 0.0)
// 		  {
// 			   printf("Mathematical Error!");
// 			   exit(0);
// 		  }
// 		  for(j=i+1;j<=n;j++)
// 		  {
// 			   ratio = a[j][i]/a[i][i];
			   
// 			   for(k=1;k<=n+1;k++)
// 			   {
// 			  		a[j][k] = a[j][k] - ratio*a[i][k];
// 			   }
// 		  }
// 	 }
// 	 x[n] = a[n][n+1]/a[n][n];
	
// 	 for(i=n-1;i>=1;i--)
// 	 {
// 		  x[i] = a[i][n+1];
// 		  for(j=i+1;j<=n;j++)
// 		  {
// 		  		x[i] = x[i] - a[i][j]*x[j];
// 		  }
// 		  x[i] = x[i]/a[i][i];
// 	 }
// 	 /* Displaying Solution */ 
// 	 printf("\n tha values of x1,x2,x3 :::::\n");
// 	 for(i=1;i<=n;i++)
// 	 {
// 	  	printf("x[%d] = %0.3f\n",i, x[i]);
// 	 }
// 	 getch();
// 	 return(0);
// }