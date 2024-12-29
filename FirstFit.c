#include<stdio.h>
void main(){
     int m,p,i,j;
     printf("Enter the number of memory block : ");
     scanf("%d",&m);
     printf("Enter the number of process : ");
     scanf("%d",&p);
     struct mem{
         int size;
         int alloc;
     }M[m];
     struct pro{
         int process;
         int flag;
     }P[p];
     printf("Enter the size of each memory block\n");
     for(i=0;i<m;i++){
         scanf("%d",&M[i].size);
         M[i].alloc=0;
     }
     printf("Enter the process\n");
     for(i=0;i<p;i++){
         scanf("%d",&P[i].process);
         P[i].flag=0;
     }
     
     for(i=0;i<p;i++){
        for(j=0;j<m;j++){
           if(P[i].process<=M[j].size){
              if(M[j].alloc==1)
                 continue;
              else{
                 M[j].alloc=1;
                 P[i].flag=1;
                 printf("Process %d is allocated at %d memory \n",P[i].process,M[j].size);
                 break;
              }
            }
         }
      }
      for(i=0;i<p;i++){
         if(P[i].flag==0){
             printf("No memory space for %d process \n",P[i].process);
         }
      }
}      

    
	
