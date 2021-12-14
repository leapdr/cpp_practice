/*
    Write a program to generate the desired output for the model of single-server queueing system.
Use it to estimate the average time that a customer spends in the system and the
average amount of overtime put in by the server, in the case where the arrival
process is a Poisson process with the rate 10, the service time density is
        g(x) = 20 e^-40x (40x)^2, x > 0
and T = 9. First try 100 runs and then 1000.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//poisson process rate == 10
#define pp_rate 10.0
#define T 9
// e ^ -40x
#define BLog exp((-40)*(x))
// (40x)^2
#define expo pow((40 * x), 2)

/*
Acronym(s):
        
  Tn = time of the first arrival after time n
  U = random number 
  t = amount of (simulated) time that has elapsed
  N_A = number of arrivals (by time t)
  N_D = number of departures (by time t)
  n = the number of customers in the system (at time t)
  SS = system state (at time t)
  t_A = time of the next arrival (after t)
  t_D = service completion time of the customer presently being served
  Y = generated service time
  Tp = the time past T that the last customer departs
*/

//generate random number for U
double generate_U()
{
    double U = (double) rand() / (double) RAND_MAX;
    return U;    
}

// find the value for Tn
double generate_Tn(double t)
{
   double U;
   
   regenerate:   
   U = generate_U();  
   t = t - (1/pp_rate) * log(U);
   U = generate_U();
// check whether new generated U == t
   if(U<=((pp_rate * t) / pp_rate))
   {
       double Tn = t;
       return Tn;
   }
   else
   {
       goto regenerate;
   }
}

// generate value for Y
double generate_Y()
{
   double x = (double)rand() / (double) RAND_MAX;
   double Y = 20 * BLog * expo;
   
   return Y;
}

int main() {
  srand(time(NULL));
  
  double t, Tn;
  double  t_A, t_D, min_btwn_t_AandD, Y, max_btwn_tminusTand0, Tp, avg_time, sum;
  int n, N_A, N_D, SS, serving, run;
 
  t = N_A = N_D = 0;
  SS = n = 0;
  Tn = generate_Tn(t);
  t_A = Tn;
  //t_D is set to infinity
 t_D = LONG_MAX;

//User provide the number of runs
  printf("Enter number of runs: ");
  scanf("%d", &run);
  run+=1;
  double A[run], D[run];
  sum = 0;
  
  serving = 1;
  while(serving)
  {
      // get the minimum value between t_A and t_D
      if(t_D < t_A)
      {
         min_btwn_t_AandD = t_D;       
      }
      else
      {
          min_btwn_t_AandD = t_A;
      }
      
      //case 1:
      if((t_A <= t_D) && (t_A <= T))
      {
         t = t_A;
         N_A += 1;
         n += 1;
         Tn = generate_Tn(t);
         t_A = Tn;
         
         if(n==1)
         {
            Y = generate_Y();
            sum += Y;
            t_D = t + Y;
            A[N_A] = t;
         }
      }
      
      //case 2:
      else if((t_D < t_A) && (t_D <= T))
      {
         t = t_D;
         n = n-1;
         N_D = N_D + 1;
         
         if(n == 0)
         {
            t_D = LONG_MAX;     
         }     
         else
         {
             Y = generate_Y();
             sum += Y;
             t_D = t + Y;
             D[N_D] = t;
         }
      }
      
      //case 3:
      else if((min_btwn_t_AandD > T) && (n > 0))
      {
           t = t_D;
           n = n - 1;
           N_D = N_D + 1;
           
           if(n > 0)
           {
                Y = generate_Y();
                sum += Y;
                t_D = t + Y;
                D[N_D] = t;
           }
      }
      
      //case 4:
      else if((min_btwn_t_AandD > T) && (n == 0))
      {
           //get the maximum value between (t - Tn) and 0
           if((t - Tn) > 0)
           {
              max_btwn_tminusTand0 = t - Tn;
           }
           else
           {
               max_btwn_tminusTand0 = 0;
           }
           
           Tp = max_btwn_tminusTand0;
           
           serving = 0;
      }
      SS++;
  }

// Compute for the Average time customer spent in the system
  avg_time = sum/(run-1);
//Compute for the Average overtime put in by the server
  Tp /= (run-1);

//Display the: 
//        (a)Average time customer spent in the system
//        (b)Average amount of overtime put in by the server
printf("\nAverage time customer spent in the system: %f", avg_time);
printf("\nAverage overtime put in by the server: %f\n", Tp);

//return 0;
getch();
}

/*
Emar John P. Nuda
BS Computer Science 3A
*/
