#include <stdio.h>

struct sjf{
  int pno,at,bt,ct,tat,wt;
};
int  main(){
  int n,i,j;
  printf("enter number of processes : ");
  scanf("%d",&n);
  struct sjf arr[n];
  printf("\n");
  for(i=0;i<n;i++){
    printf("Enter at,bt for process %d : ",i+1);
    scanf("%d%d",&arr[i].at,&arr[i].bt);
    arr[i].pno = i+1;
  }
  for(i=0;i<n;i++){
    for(j=0;j<n-1;j++){
      if(arr[j].bt>arr[j+1].bt){
        int temp = arr[j].bt;
        arr[j].bt = arr[j+1].bt;
        arr[j+1].bt = temp;
      }
    }
  }
   int time = arr[0].at;
    for(i=0;i<n;i++){
      time+=arr[i].bt;
      arr[i].ct = time;
      arr[i].tat = time - arr[i].at;
    }
    printf("PT  AT  BT  CT  TAT  WT\n");
    for(i=0;i<n;i++){
      printf("%d   %d   %d   %d   %d    %d\n",arr[i].pno,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].tat-arr[i].bt);
    }
}