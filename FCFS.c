#include<stdio.h>
#include<stdlib.h>

struct SchedulingPoliciesProcesses{
    int start ;
    int at ;
    int bt ;
    int end ;
} p[3] ;

void sort () {
    int a = 0 , max = -1 , awt , atat ;
    while (a<3)
    {
        for(int i = 0 ; i < 3 ; i++){
            if(p[a].at <= p[i].at ) {
                p[i].end += p[a].bt;
            }
        }
        a++;
    }
    a = 0 ;
    while (a<3)
    {
         p[a].start = p[a].end - p[a].bt;
         a++;
    }
}

void main(){
    int a = 0 ;
    float  awt = 0 ,atat = 0 ;
    while (a<3)
    {
        printf("Enter a AT BT of P%d (Seperated by comma): ",a+1);
        scanf("%d,%d",&p[a].at,&p[a].bt);
        a++;
    }
    sort();
    a = 0 ;
    printf("AT\tBT\tSt\tE\n");
    while (a<3)
    {
        printf("%d\t%d\t%d\t%d\t==> P%d\n",p[a].at,p[a].bt,p[a].start,p[a].end,a+1);
        a++;
    }
    a = 0 ;
    while (a<3)
    {
        awt += (float)p[a].start - (float)p[a].at ;
        atat += (float)p[a].end - (float)p[a].at ;
        a++;
    }
    
    printf("Average waiting time= %fms \nAverage turn around time= %fms",awt/3 , atat/3);   
    
}
