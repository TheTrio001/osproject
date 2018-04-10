
#include<stdio.h>
#include<conio.h>
int p[10];
int rr(int x, int y);
int fcfs(int x, int y);
int priority(int x , int y);
int holding[20];
int main()
{
	
	printf("                                                OPERaING SYSTEM PROJECT                                  \n\n\n");
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




	if (a[0]<a[1]&&a[0]<a[2])
	{
		rr(p[0],1);
		if(a[1]<a[2])
		{
			priority(p[1],2);
			fcfs(p[2],3);
		}
		else
		{
			priority(p[2],3);
			fcfs(p[1],2);
		}
	}
	else if(a[1]<a[0]&&a[1]<a[2])
	{
		rr(p[1],2);
		if(a[0]<a[2])
		{
			priority(p[0],1);
			fcfs(p[2],3);
		}
		else
		{
			priority(p[2],3);
			fcfs(p[0],1);
		}
	}
	else
	{
		rr(p[2],3);
		if(a[0]<a[1])
		{
			priority(p[0],1);
			fcfs(p[1],2);
		}
		else
		{
			priority(p[1],2);
			fcfs(p[0],1);
		}
	}
}


int priority(int a,int b)
{
	int bt[20], process[20], tt[20], priority[20];
      int i, j, extent, sum = 0, location, temp;
      float awt, att;
      printf("APPLY PRIORITY SCHEDULING ALGORITHM ON QUEUE %d",b);
      extent=a;
      int value=1;
      printf("\nEnter Burst Time and Priority For %d Processes\n", extent);
      if(value=1)
      {
      	for(i = 0; i < extent; i++)
      {
            printf("\nProcess[%d]\n", i + 1);
            printf("Process Burst Time:\t");
            scanf("%d", &bt[i]);
            printf("Process Priority:\t");
            scanf("%d", &priority[i]);
            process[i] = i + 1;
      }
      value=0;
	  }
      for(i = 0; i < extent; i++)
      {
            location = i;
            for(j = i + 1; j < extent; j++)
            {
                  if(priority[j] < priority[location])
                  {
                        location = j;
                  }
            }
            temp = priority[i];
            priority[i] = priority[location];
            priority[location] = temp; 
            temp = bt[i];
            bt[i] = bt[location];
            bt[location] = temp;
            temp = process[i];
            process[i] = process[location];
            process[location] = temp;
      }
      holding[0] = 0;
      for(i = 1; i < extent; i++)
      {
            holding[i] = 0;
            for(j = 0; j < i; j++)
            {
                  holding[i] = holding[i] + bt[j];
            }
            sum = sum + holding[i];
      }
      awt = sum / extent;
      sum = 0;
      printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");
      for(i = 0; i < extent; i++)
      {
            tt[i] = bt[i] + holding[i];
            sum = sum + tt[i];
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n", process[i], bt[i], holding[i], tt[i]);
      }
      att = sum / extent;
      printf("\nAverage Waiting Time:\t%f", awt);
      printf("\nAverage Turnaround Time:\t%f\n", att);
      return 0;
}

