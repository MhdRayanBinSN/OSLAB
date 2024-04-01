#include <stdio.h>
void main(){
    int fragment[10],bsize[20],psize[20],i,j,bno,pno,temp,lowest=9999;
    int barray[20],parray[20];
    printf("Enter the no of block: ");
    scanf("%d",&bno);
    printf("\nEnter the size of each block: ");
    for(i=0;i<bno;i++){
        scanf("%d",&bsize[i]);
    }
    printf("Enter the no of process: ");
    scanf("%d",&pno);
    printf("\nEnter the size of each process: ");
    for(i=0;i<pno;i++){
        scanf("%d",&psize[i]);
    }
    for(i=1;i<=bno;i++){
        for(j=1;j<=pno;j++){
            if(barray[j]!=1){
                temp = bsize[j]-psize[i];
                if(temp>=0){
                    if(lowest>temp){
                        parray[i]=j;
                        lowest = temp;
                    }
                }
                fragment[i] = lowest;
                barray[parray[i]]=1;
                lowest = 10000;
            }
        }
    }
    printf("\nProcess\tprocessSize\tBlocksize\tFragment");
    for(i=1;i<=bno&&parray[i]!=0;i++){
        printf("\n%d\t\t%d\t\t%d\t\t%d",psize[i],parray[i],bsize[parray[i]],fragment[i]);
        
    }

}