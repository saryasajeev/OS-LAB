#include<stdio.h>
void main(){
     int mlimit,plimit,i,j,temp;
     printf("Enter the number of memory block : ");
     scanf("%d",&mlimit);
     printf("Enter the number of process : ");
     scanf("%d",&plimit);
     struct mem{
         int size;
         int alloc;
     }m[mlimit];
     struct pro{
         int process;
         int flag;
     }p[plimit];
     printf("Enter the size of each memory block\n");
     for(i=0;i<mlimit;i++){
         scanf("%d",&m[i].size);
         m[i].alloc=0;
     }
     for(i=0;i<mlimit;i++)
     {
     for(j=i+1;j<mlimit;j++)
     {
     if(m[j].size<m[i].size)
     {
     temp=m[i].size;
     m[i].size=m[j].size;
     m[j].size=temp;
     }
     }
     }
     printf("Enter the process\n");
     for(i=0;i<plimit;i++){
         scanf("%d",&p[i].process);
         p[i].flag=0;
     }
      for(i=0;i<plimit;i++)
     {
     for(j=i+1;j<plimit;j++)
     {
     if(p[j].process<p[i].process)
     {
     temp=p[i].process;
     p[i].process=p[j].process;
     p[j].process=temp;
     }
     }
     }
     for(i=0;i<plimit;i++){
        for(j=0;j<mlimit;j++){
           if(p[i].process<=m[j].size){
              if(m[j].alloc==1)
                 continue;
              else{
                 m[j].alloc=1;
                 p[i].flag=1;
                 printf("Process %d is allocated at %d memory \n",p[i].process,m[j].size);
                 break;
              }
            }
         }
      }
       for(i=0;i<plimit;i++){
         if(p[i].flag==0){
             printf("No memory space for %d process \n",p[i].process);
         }
      }
      }
