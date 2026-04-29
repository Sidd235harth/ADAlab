#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printArray(int a[],int n){
	for(int i=0;i<n;i++){
printf("%d ",a[i]);
}
printf("\n");
}

int main(){
int n;
clock_t start ,end;
printf("enter number of elements");
scanf("%d",&n);
int a[n];
srand(time(NULL));

for (int i=0;i<n;i++)
	a[i]=rand()%1000;
printf("\nArray before sorting:\n");
printArray(a,n);
start=clock();
for(int i=0;i<n-1;i++){
	int min=i;
	for(int j=i+1;j<n;j++)
		if(a[j]<a[min])
			min=j;
	int t=a[i];
	a[i]=a[min];
	a[min]=t;
}
end=clock();

printf("\n Array after sorting:\n");
printArray(a,n);

printf("\n Time taken=%lf seconds \n",(double)(end-start)/CLOCKS_PER_SEC);

return 0;
}
