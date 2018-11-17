#include <stdio.h>

struct sjf{
  int pno,at,bt,ct,tat,wt,pri,rt;
};
int  main(){
  int n,i,j;
  printf("enter number of processes : ");
  scanf("%d",&n);
  struct sjf arr[n];
  printf("\n");
  for(i=0;i<n;i++){
    printf("Enter at,bt,priority for process %d : ",i+1);
    scanf("%d%d%d",&arr[i].at,&arr[i].bt,&arr[i].pri);
    arr[i].pno = i+1;
    arr[i].rt = arr[i].bt;
  }
  int time=0,x=1;
  while(x){
    int srt = 0,rt=0,nn=-1;
    for(i=0;i<n;i++){
      rt += arr[i].rt;
      if(arr[i].at<=time && arr[i].rt != 0 && arr[i].pri>srt){
        srt = arr[i].pri;
        nn = i;
      }
    }
    if(rt == 0){
      x=0;
    }
    else if(srt == 0){
      time++;
    }
    else{
      arr[nn].rt--;
      time++;
      if(arr[nn].rt == 0){
        arr[nn].ct = time;
        arr[nn].tat = arr[nn].ct - arr[nn].at;
        arr[nn].wt = arr[nn].wt -arr[nn].bt;
      }
    }
  }
  printf("PT  AT  BT  CT  TAT  WT\n");
    for(i=0;i<n;i++){
      printf("%d   %d   %d   %d   %d    %d\n",arr[i].pno,arr[i].at,arr[i].bt,arr[i].ct,arr[i].tat,arr[i].tat-arr[i].bt);
    }
}