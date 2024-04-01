#include <stdio.h>
void main()
{
	int n, j, b[10], t[10], w[10], i, temp, p[10];
	int twt = 0, ttt = 0;
	float avgtat, avgwt;
	printf("Enter the number of processes :");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter the burst time p%d", i + 1);
		scanf("%d", &b[i]);
		p[i] = i + 1;
	}
	w[0] = 0;
	for (i = 1; i < n; i++)
	{
		w[i] = w[i - 1] + b[i - 1];
	}
	t[0] = 0;
	for (i = 0; i < n; i++)
	{
		t[i] = w[i] + b[i];
		twt = twt + w[i];
		ttt = ttt + t[i];
	}
	printf("PROCESS\tBT\tWT\tTAT\t");
	for (i = 0; i < n; i++)
	{
		printf("\n%d\t%d\t%d\t%d\t", p[i], b[i], w[i], t[i]);
	}
	avgwt = twt / n;
	avgtat = ttt / n;
	printf("\nAverage waiting time=%f", avgwt);
	printf("\nAverage turn around time=%f", avgtat);
}