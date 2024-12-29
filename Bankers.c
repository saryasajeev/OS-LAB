#include<stdio.h>
#include<stdlib.h>

void main(){
 int n,i,j,r,flag,count=0,k=0,excecuted;
 
 printf("Enter the no. of processes:");
 scanf("%d",&n);
 printf("Enter the number of resources : ");
 scanf("%d", &r);
 
 int alloc[n][r],max[n][r],available[r],need[n][r],safeseq[n],visited[n];
 
 printf("Enter the available resources:");
 for(i=0;i<r;i++){
  scanf("%d",&available[i]);
 }
 
 for(i=0;i<n;i++){
 visited[i]=0;
  printf("Enter the allocation of process P[%d]:",i);
  for(j=0;j<r;j++){
   scanf("%d",&alloc[i][j]);
  }
  printf("Enter the max of processP[%d]:",i);
  for(j=0;j<r;j++){
   scanf("%d",&max[i][j]);
  }
 
  for(j=0;j<r;j++){
   need[i][j]=max[i][j]-alloc[i][j];
  }
 }
  printf("  \tAllocation\tMax\t\tNeed\tAvailable\n");
 for(i=0;i<n;i++){
 printf("P[%d]\t",i);
 for(j=0;j<r;j++){
  printf("%d ",alloc[i][j]);
 }
  printf("\t\t");
  for(j=0;j<r;j++){
   printf("%d ",max[i][j]);
  }
  printf("\t\t");
  for(j=0;j<r;j++){
   printf("%d ",need[i][j]);
  }
  if(i==0){
   printf("\t\t");
   for(j=0;j<r;j++){
   printf("%d",available[j]);
   }
  }
  printf("\n");
 }
 while(count<n){
  flag=0;
  for(i=0;i<n;i++){
  excecuted=0;
   for(j=0;j<r;j++){
     if(need[i][j]<=available[j]){
      excecuted++;
     }
    }
     if((excecuted==r)&&(visited[i]==0)){
       for(j=0;j<r;j++){
       available[j]+=alloc[i][j];
      }
      flag=1;
      visited[i]=1;
      safeseq[k++]=i;
      count++;
    }
   }
   if(flag==0){
    printf("No safe state\n");
    exit(0);
  }
 }
 printf("Safe sequence:");
 printf("<");
 for(i=0;i<n;i++){
  printf("P[%d]",safeseq[i]);
 }
 printf(">");
 printf("Safe state exist\n");
 
}
	
