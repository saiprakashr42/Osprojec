#include<stdio.h>
#include<conio.h>

void round_r(int num,int remt[20],int Curr_t[20],int bst[20]);

main(){
int Proc_num,
int j,num,Curt,RemProc,indicator,time_quan,wait,tut,art[20],bst[20],remt[10],x=1;
int indicator=0;
int wait=0;
int tut=0;
printf("Enter the total number of processes: ");
scanf("%d",&num);
RemProc=num;

printf("\nEnter the arrival time and Burst time of the processes\n");
for(Proc_num=0;Proc_num<num;Proc_num++)
 {
    printf("\nProcess P%d\n",Proc_num+1);
    printf("Arrival time =  "); 
    scanf("%d",&art[Proc_num]);
    printf("BurstTime = "); 
    scanf("%d",&bst[Proc_num]); 
    remt[Proc_num]=bst[Proc_num]; 
	
} 
  
  
  //The time quantum for first is 6
  //Time quantum for second is 10
time_quan=3;
Curt=0;
	
for(Proc_num=0;RemProc!=0;){
	
	if(remt[Proc_num]<=time_quan && remt[Proc_no]>0)
		{ 
			Curt+=remt[Proc_num]; 
			remt[Proc_num]=0; 
			indicator=1; 
		} 
	else if(remt[Proc_num]>0)
		{ 
			remt[Proc_num]-=time_quan; 
			Curt+=time_quan; 
		}
	
	if(remt[Proc_num]==0 && indicator==1)			
		{ 	
			printf("%d",Proc_num);
			RemProc--;				
			printf("P %d",Proc_num+1); 
			printf("\t\t\t%d",Curt-art[Proc_num]);
			printf("\t\t\t%d\n",Curt-bst[Proc_num]-art[Proc_num]);
			wait+=Curt-art[Proc_num]-bst[Proc_num]; 
			tut+=Curt-art[Proc_num]; 
			indicator=0; 
                       
		}
		if(Proc_num==num-1){
			x++;
			if(x==2){
				Proc_num=0;
				time_quan=10;
				
				printf("The time Quantum for second  is 10. \n");
			}
			else{
				break;
			}
		}
		else if(Curt >= art[Proc_num+1]){
			Proc_num++;
		}
		else{
			Proc_num=0;
		}
	}
	
	rr(num,remt,Curt,art,bst);
	
	return 0;
}




//declaring and providing the definition of function void


void round_r(int num,int remt[20],Curt,int art[20],int bst[10])
{
	float average_wait,average_tut;
	int i,j,n=num,Proc_num[30],w_time[30],tut_t[30],btime[30],total=0,loc,temp;
	
	 printf("Third round with least Burst time.\n");
	
	for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        w_time[i]=Curt-art[i]-btime[i];
	Proc_num[i]=i+1;
    }
	
	
	for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
	temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=Proc_num[i];
        Proc_num[i]=Proc_num[loc];
        Proc_num[loc]=temp;
    }
	
	
	for(i=1;i<n;i++)
    {
		
        for(j=0;j<i;j++)
	{
		
        	w_time[i]+=btime[j];
        }
		
        	total+=w_time[i];
    }
	
    	averageg_wait=(float)total/n;
    	total=0;
    	printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnAround Time");
	for(i=0;i<n;i++)
    {
        tut_t[i]=btime[i]+w_time[i];
        total=total + tut_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Proc_num[i],btime[i],w_time[i],tut_t[i]);
    }
	
	
    averageg_tut=(float)total/n;
    printf("\n\nAverage Waiting time = %f",averageg_wait);
    printf("\n Average Turnaround time = %f\n",average_tut);
		
}
	
	
	
	

	
		     
		     
		     
		     
  
  
  
  
    
