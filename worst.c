#include <stdio.h>
void main(){
    int bsize[20],psize[20];
    int all[20],bno, pno, i, j;

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);
    printf("Enter the size of each block: ");
    for (i = 0; i < bno; i++) {
        scanf("%d", &bsize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pno);
    printf("Enter the size of each process: ");
    for (i = 0; i < pno; i++) {
        scanf("%d", &psize[i]);
        all[i]=-1;
    }
    for(i=0;i<pno;i++){
        int worstplace = -1;
        for(j=0;j<bno;j++){
            if(bsize[j]>=psize[i]){
                if(worstplace==-1){
                    worstplace=j;
                }else if(bsize[worstplace]<bsize[j]){
                    worstplace=j;
                }
            }
        }
        if(worstplace!=-1){
            all[i]=worstplace;
            bsize[worstplace]-=psize[i];
        }
    }
    printf("\nProcess \tProcess Size\tBlock No\n");
    for( i = 0;i<pno;i++){
        printf("%d\t\t%d\t\t",i+1,psize[i]);
        if(all[i]!=-1){
            printf("%d\n",all[i]+1);
        }else{
            printf("Not Allocated");
        }
    }

}