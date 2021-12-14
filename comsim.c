//Aaron S. Basco
//Computer Simulation
//BSCS 3A
/*
       Write a program to generate the desired output for the model of single-server queueing system.
Use it to estimate the average time that a customer spends in the system and the
average amount of overtime put in by the server, in the case where the arrival
process is a Poisson process with the rate 10, the service time density is
        g(x) = 20 e^-40x (40x)^2, x > 0
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

#define Pp 10
#define T 9
#define term2 exp((-40)*x)
#define term3 pow((40*x), 2)

int gen_Y(){
   int x = rand();
   int Y = 20 * term2 * term3;
   
   return Y;
}

int main(){
    srand(time(NULL));
    int num_run;
    printf("Enter number of runs: ");
    scanf("%d", &num_run);
    num_run += 1;
    
    int t, T0, Tt, Na, Nd, SS, n, tA, tD, eos=0, Y, sum;
    double Tp, avg_time;
    int min_tA_tD, max_tminT_0;
    int A[num_run], D[num_run];
    
    t = Na = Nd = 0;
    SS = sum = n = 0;
    Tt = (float) rand() / (float) LONG_MAX; tA = T0; tD = LONG_MAX;
    
    while(!eos){
                if(tA < tD) min_tA_tD = tA;
                else min_tA_tD = tD;
                
                //CASE 1
                if((tA <= tD) && (tA <= T)){
                       t = tA;
                       Na = Na + 1;
                       n = n + 1;
                       Tt = rand(); tA = Tt;
                       if(n == 1){
                            Y = gen_Y();
                            sum = sum + Y;
                            tD = t + Y;
                            A[Na] = t;
                       }
                printf("CASE 1 %d \n", t);
                }
                
                //CASE 2
                else if((tD < tA) && (tD <= T)){
                     t = tD;
                     n = n - 1;
                     Nd = Nd + 1;
                     if(n == 0){
                          tD = LONG_MAX;
                     }
                     else{
                          Y = gen_Y();
                          sum = sum + Y;
                          tD = t + Y;
                          D[Nd] = t;
                     }
                printf("CASE 2 %d \n", t);
                }
                
                //CASE 3
                else if((min_tA_tD > T) && (n>0)){
                     t = tD;
                     n = n - 1;
                     Nd = Nd + 1;
                     if(n > 0){
                          Y = gen_Y();
                          sum = sum + Y;
                          tD = t + Y;
                          D[Nd] = t;
                     }
                printf("CASE 3 \n");
                }
                
                //CASE 4
                else if((min_tA_tD > T) && (n == 0)){
                     if((t-T) > 0) max_tminT_0 = t-T;
                     else max_tminT_0 = 0;
                     
                     Tp = max_tminT_0;
                     eos = 1;
                printf("CASE 4 %d \n", max_tminT_0);
                }
                SS = SS + 1;
    }
    
    avg_time = sum / (num_run-1);
    Tp = Tp / (num_run-1);
    
    printf("Average time that a customer spends in the system: %f\n", avg_time);
    printf("Average amount of overtime put in by the server: %f\n", Tp);
    
    getch();
    return 0;
}
