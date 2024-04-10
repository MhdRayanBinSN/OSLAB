#include <stdio.h>
void main(){
	int pno,bno,bsize[10],psize[10],i,j,optn,flag[10],ob[10],rs[10],bso[10],pso[10];
	int allocation[10];
	for(i=0;i<10;i++){
		flag[i] = 0;
		allocation[i]=-1;
	}
	printf("Enter no of block: ");
	scanf("%d",&bno);
	printf("Enter size of each block: ");
	for(i=0;i<bno;i++){
		scanf("%d",&bso[i]);
	}
	printf("Enter no of process: ");
	scanf("%d",&pno);
	printf("Enter size of each process: ");
	for(i=0;i<pno;i++){
		scanf("%d",&psize[i]);
	}
	do{
		printf("\n    Menu\n1.First_Fit\n2.Best_Fit\n3.Worst_Fit\n4.Exit");
		printf("\nChoose the option:");
		scanf("%d",&optn);
		switch(optn){
			case 1:
				for(i=0;i<bno;i++){
					bsize[i] = bso[i];
				}
				printf("\nFirst Fit");
				for(i=0;i<pno;i++){
					for(j=0;j<bno;j++){
						if(bsize[j]>=psize[i]){
							allocation[i] = j;
							bsize[j] -= psize[i];	
							break;
						}
					}
				}
				printf("\nProcess No\tProcess Size\tBlock No\t");
				for(i=0;i<pno;i++){
					printf("\n%d\t\t%d\t\t",i+1,psize[i]);
					if(allocation[i]!=-1){
						printf("%d\t\t",allocation[i] +1);
					}else{
						printf("Not Allocated\t");
					}
				}
				printf("\nProcess No\tRemaining Space");
				for(i=0;i<bno;i++){
					printf("\n%d\t\t%d",i+1,bsize[i]);
				}
				break;
			case 2: 
			for(i=0;i<bno;i++){
					bsize[i] = bso[i];
				}
			printf("\nBest Fit");
				for(i=0;i<pno;i++){
					int best_fit = -1;
					for(j=0;j<bno;j++){
						if(bsize[j]>=psize[i]){
							if(best_fit==-1||bsize[j]<bsize[best_fit]){
							best_fit = j;
							}
						}
					}
					if(best_fit!=-1){
						allocation[i] = best_fit;
						bsize[best_fit] = psize[i];
					}else{
						allocation[i] = -1;
					}
				}
				printf("\nProcess No\tProcess Size\tBlock No");
				for(i=0;i<pno;i++){
					printf("\n%d\t\t%d\t\t",i+1,psize[i]);
					if(allocation[i]!=-1){
						printf("%d\t\t",allocation[i] +1);
					}else{
						printf("Not Allocated");
					}
				}
				printf("\nProcess No\tRemaining Space");
				for(i=0;i<bno;i++){
					printf("\n%d\t\t%d",i+1,bsize[i]);
				}
				break;
			case 3: 
			for(i=0;i<bno;i++){
					bsize[i] = bso[i];
				}
			printf("\nWorst Fit");
			for(i=0;i<pno;i++){
			int worst_fit = -1;
			for(j=0;j<bno;j++){
				if(bsize[j]>=psize[i]){
					if(worst_fit==-1){
						worst_fit = j;
					}else if(bsize[worst_fit]<bsize[j]){
						worst_fit = j;
					}
				}
			}
			if(worst_fit!=-1){
				allocation[i] = worst_fit;
				bsize[worst_fit] -= psize[i];
			}else{
				allocation[i] = -1;
			}
		}
		printf("\nProcess No\tProcess Size\tBlock No\t");
		for(i=0;i<pno;i++){
			printf("\n%d\t\t%d\t\t",i+1,psize[i]);
			if(allocation[i]!=-1){
				printf("%d\t\t",allocation[i] +1);
			}else{
				printf("Not Allocated\t");
			}
			
		}printf("\nProcess No\tRemaining Space");
				for(i=0;i<bno;i++){
					printf("\n%d\t\t%d",i+1,bsize[i]);
				}
				break;
			case 4: 
				break;
			default: 
				printf("Invalid Entry!");
				
		}
	}while(optn!=4);
	
}