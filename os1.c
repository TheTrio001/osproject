
#include<stdio.h>
#include<conio.h>
int p[10];
int rr(int x, int y);
int fcfs(int x, int y);
int priority(int x , int y);
int waiting_time[20];
int main()
{
	
	printf("                                                OPERATING SYSTEM PROJECT                                  \n\n\n");
	printf("                                     IN THIS PROJECT WE WILL BE USING THREE QUEUES:->\n\n");
	
	
     for(int i=0;i<3;i++)
     {
     	printf("ENTER THE PROCESSES IN QUEUE%d:->",(i+1),"\n");
     	scanf("%d",&p[i]);
     	printf("\n");
	 }
	int a[10];  //priority
		char name[3];
		printf("---------------------------------------------------------------------------------------------------------");
		printf("\n\n\t");
printf("PRIORITY SHOULD NOT BE SAME\n");
 for(int i=0;i<3;i++)
     {
     	printf("ENTER THE PRIORITY OF QUEUES%d:->",(i+1),"\t");
     	scanf("%d",&a[i]);
     	printf("\n");
     	printf("\t");
	 }

printf("------------------------------------------------------------------------------------------------------------\n");

}
