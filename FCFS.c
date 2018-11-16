#include <stdio.h>
int n,i,j;
float avgtat=0,avgwt=0;

struct fcfs
  {
    int at,st,ct,tat,wt,pno;
    char pname[20];
    int ntat;
  };

int main()
  {
    printf("enter the number of processes\n");
    scanf("%d",&n);
    struct fcfs pr[n];
    for(i=0;i<n;i++){
      printf("\nenter at,st of process : %d",i+1);
      scanf("%d%d",&pr[i].at,&pr[i].st);
      pr[i].pno = i+1;
    }
    for(i=0;i<n;i++){
      for(j=0;j<n-1;j++){
        if(pr[j].at>pr[j+1].at){
          int temp = pr[j].at;
          pr[j].at = pr[j+1].at;
          pr[j+1].at = temp;
        }
      }
    }
    int time = pr[0].at;
    for(i=0;i<n;i++){
      time+=pr[i].st;
      pr[i].ct = time;
      pr[i].ntat = time - pr[i].at;
    }
    printf("PT  AT  BT  CT  TAT  WT\n");
    for(i=0;i<n;i++){
      printf("%d   %d   %d   %d   %d    %d\n",pr[i].pno,pr[i].at,pr[i].st,pr[i].ct,pr[i].ntat,pr[i].ntat-pr[i].st);
    }
  }