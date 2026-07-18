//quick sorting
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void quick(int a[] ,int low ,int high){
	if(low<high){
		int p=a[high],i=low-1;
		for(int j=low;j<high;j++)
			if(a[j]<p){
				int t=a[++i];
				a[i]=a[j];
				a[j]=t;
			}
		int t=a[i+1];
		a[i+1]=a[high];
		a[high]=t;
		quick(a,low,i);
		quick(a,i+2,high);
}
}

void printArray(int a[],int n){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main(){
	int n;
	printf("Enter the number of element");
	scanf("%d",&n);
	int *a=malloc(n*sizeof(int));
	srand(time(NULL));
	for(int i=0;i<n;i++)
		a[i]=rand()%1000;
	printf("\n Array before sorting:\n");
	printArray(a,n);
	clock_t start=clock();
	quick(a,0,n-1);
	clock_t end=clock();
	printf("\n Array after sorting:\n");
	printArray(a,n);
	printf("\n time=%fseconds\n",(double )(end-start)/CLOCKS_PER_SEC) ;
	free(a);
	return 0;
}

