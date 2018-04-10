
#include<stdio.h>
#include <dos.h>
#include <dir.h>
#include<windows.h>
#include<conio.h>
int p[10];
int rr(int x, int y);
int fcfs(int x, int y);
int priority(int x , int y);
int holding[20];
int main()
{
	system("color 5f");
	printf("                                                OPERaING SYSTEM PROJECT                                  \n\n\n");
	printf("                                     IN THIS PROJECT WE WILL BE USING THREE QUEUES:->\n\n");
	
	
     for(int i=0;i<3;i++)
     {
     	printf("ENTER THE PROCESSES IN QUEUE%d:->",(i+1),"\n");
     	scanf("%d",&p[i]);
     	system("color 3f");
     	
     	printf("\n");
	 }
	int a[10];  //priority
		char name[3];
		printf("---------------------------------------------------------------------------------------------------------");
		printf("\n\n\t");
printf("PRIORITY SHOULD NOT BE SAME\n");
system("color 1f");
 for(int i=0;i<3;i++)
     {
     	printf("ENTER THE PRIORITY OF QUEUES%d:->",(i+1),"\t");
     	scanf("%d",&a[i]);
     	system("color 2f");
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
      printf("\n\nAPPLY PRIORITY SCHEDULING ALGORITHM ON QUEUE %d:->",b);
      extent=a;
      int value=1;
      printf("\nENTER BURST TIME AND PRIORITY FOR %d PROCESSES\n", extent);
      if(value=1)
      {
      	for(i = 0; i < extent; i++)
      {
            printf("\n\nPROCESS:->[%d]\n\n", i + 1);
            printf("\n\nPROCESS BURST TIME:\t\n");
            scanf("%d", &bt[i]);
            system("color 3f");
            printf("PROCESS PRIORITY:\t");
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
      printf("\nPROCESS ID\t\tBURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
      for(i = 0; i < extent; i++)
      {
            tt[i] = bt[i] + holding[i];
            sum = sum + tt[i];
            printf("\nPROCESS[%d]\t\t%d\t\t %d\t\t %d\n", process[i], bt[i], holding[i], tt[i]);
      }
      att = sum / extent;
      system("color 5f");
      printf("\nAVERAGE WAITING TIME:\t%f", awt);
      printf("\nAVERAGE TURNAROUND TIME:\t%f\n", att);
      return 0;
}

int fcfs(int c, int d)
{
	float bt[30], holding[30], tt[30];
        float aholding = 0.0, att = 0.0;
        int count, j, total_process;
        printf("APPLYING FCFS ON QUEUE . %d",d);
        /*printf("Enter The Number of Processes To Execute:\t");
        scanf("%d", &total_process);*/
        total_process=c;
        printf("\ENTER THE BURST TIME OF THE PROCESS:\n\n");
        for(count = 0; count < total_process; count++)
        {
                printf("PROCESS [%d]:", count + 1);
                scanf("%f", &bt[count]);
                system("color 5c");
        }
        holding[0] = 0;   
        for(count = 1; count < total_process; count++)
        {
                holding[count] = 0;
                for(j = 0; j < count; j++)
                {
                        holding[count] = holding[count] + bt[j];
                }
        }
        printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
        for(count = 0; count < total_process; count++)
        {
                tt[count] = bt[count] + holding[count];
                aholding = aholding + holding[count];
                att = att + tt[count];
                system("color 2f");
                printf("\nProcess [%d]\t\t%.2f\t\t%.2f\t\t%.2f", count + 1, bt[count], holding[count], tt[count]);
        }
        printf("\n");
        aholding = aholding / count;
        att = att / count;
        system("color 3f");
        printf("\nAverage Waiting Time = %f", aholding);
        printf("\nAverage Turnaround Time = %f", att);
        printf("\n");
        return 0;
}
