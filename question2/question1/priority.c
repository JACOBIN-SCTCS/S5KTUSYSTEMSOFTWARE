#include <stdio.h>

void main() {
    
   
    int P[20],BT[20] ,WT[20] , TT[20] ,PR[20];
    int total_tt =0 , total_wt =0;
    int i ,j, n,temp,pos ;
    
    double avg_wt , avg_tt;


    printf("Enter the number of processes ");
    scanf("%d",&n);

    for(i=0 ; i<n;++i) {
     printf("Enter the burst time and priority for process   %d :" , i+1);
     
      scanf("%d%d" , &BT[i],&PR[i]); 
     
      P[i]=i+1;
     } 

    
     for(i=0;i<n;++i){
       pos=i;
       for(j=i+1;j<n;++j) {
           
          if(PR[j]<PR[pos])
                  {
                     pos =j;
                  }
      }
      
      temp = PR[i]; 
      PR[i]=PR[pos];
      PR[pos]=temp;

      temp = BT[i]; 
      BT[i]=BT[pos];
      BT[pos]=temp;
    
      temp = P[i]; 
      P[i]=P[pos];
      P[pos]=temp;
   }






 
    WT[0]=0;
    for(i=0 ;i<n;++i)
      {        WT[i]=0;
               for (j=0;j<i;j++)
                {
                    WT[i] = WT[i] +BT[j];

                }
               total_wt += WT[i];
      }
   
     for(i=0;i<n;++i)
    { 
         TT[i]= BT[i] +WT[i];
         total_tt +=TT[i]; 
     }

    printf(" \n\n\t PRIORITY SCHEDULING \n");
    printf("\tPROCESS INFORMATION \n");
    printf("_________________________\n");
    printf(" PID  | PRIORITY |  BURST TIME  |  WAITING TIME  | TURNAROUND TIME \n");
    for(i=0;i<n;++i)
    {
      printf("%d\t %d\t\t %d\t\t %d\t\t %d\t \n" , P[i] ,PR[i],BT[i] ,WT[i] ,TT[i]);
     }
  
    avg_wt =total_wt/n;
    avg_tt =total_tt/n;

    printf ("\nAverage  waiting time  =%f \n " ,avg_wt );
    printf ("\nAverage turnaround time  =%f \n " ,avg_tt );

           


}












    




