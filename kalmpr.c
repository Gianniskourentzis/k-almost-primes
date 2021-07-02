/* File: kalmpr.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MINNUM 2100000000
#define MAXNUM 2101000000
#define MAXK 5
#define COMPUTATIONS 20


int main(){
printf("Checking numbers in [%d,%d]\n\n",MINNUM, MAXNUM);
int n , divisor , count , sumsemiprimes , sumkalmost , temp , t , a , b , prime , div; 
// Initialization of sumsemiprimes and sumkalmost
sumsemiprimes=0;
sumkalmost=0;

    for(n = MINNUM; n <= MAXNUM ; n++){
        // In variable temp assign the n, which is the number that check in every repetition
        temp = n;
        count=0;
        
   
        // Starting by, check if n is a prime number
        // First setting a integer variable (prime ) as 1. This variable used as boolean variable
        // Supposing that 1 represents true
        prime = 1;
        
        if ( n != 2 && n % 2 == 0 ){
        prime=0;
        } 
        else if ( n != 3 && n % 3 == 0 ) {
        prime = 0;
        }
        else{
        div = 5;
            while ( prime == 1 && div * div <= n ){
                if ((n % div ==0) || (n % (div + 2) == 0)){
                    prime = 0;
                }   
                div += 6;
            }
        }
        // If n isn't prime , start the proccess of factorization
            if (prime == 0){
                // First check the amount of times that the number divides with 2 and put it in the variable count
                while (temp % 2 == 0 && count < MAXK +1){
                    count++;
                    temp = temp / 2;
                }
                // Then check the amount of times that the number divides with 3 and put it in the variable count
                while (temp % 3 == 0 && count < MAXK +1){
                    count ++;
                    temp = temp /3;
                }
                // Now if the search has meaning, namely the count is less than MAXK + 1, start finding out the other factors
                // In for loop the check should be until the square root of the number 
                // In a for loop assign the divisor with 5 and increase it with 6
                // Probable factors would be divisor and divisor + 2
                // Every time the temp modulo divisor is zeroing , temp renewed with the division of the divisor or (divisor + 2 )
                // The while loop has meaning if count is less than MAXK + 1
                // For finiding if number is an interesting semiprime , programm needs to have the two different factors.
                // So when count is 1 programm keeps the divisor (or divisor + 2) in an integer variable a.
                if (count < MAXK + 1){
                    for (divisor = 5 ; divisor * divisor < n ;  divisor = divisor + 6){
                            if (temp % divisor == 0 && count < MAXK + 1){
                                while (temp % divisor == 0 && count < MAXK + 1){
                                    count ++;
                                    temp= temp / divisor;   
                                }
                                if (count == 1){
                                    a = divisor;
                                } 
                            }
                            if (temp % (divisor + 2)==0 && count < MAXK + 1){
                                while (temp % (divisor + 2)== 0 && count < MAXK + 1){
                                    count ++;
                                    temp= temp / (divisor + 2);  
                                }
                                if (count == 1){
                                    a = divisor + 2;
                                }
                            }                          
                    }
                }
                    // If number is perfect square count increases by 2
                    if (count < MAXK + 1 && temp != 1){
                        if ( divisor * divisor == n || (divisor + 2) * (divisor + 2) == n){
                            count += 2;
                        }
                    }

                    // If temp is different from 1 and count less than MAXK + 1 , the programm continues to find the last factors
                    // To do this, it searches if temp is a prime number 
                    // First setting a integer variable (prime 2) as 1. This variable used as boolean variable
                    // Supposing that 1 represents true
                    // After the search if temp is prime, count increases by 1

                    int prime2 , div;
                    prime2 = 1;

                    if (count < MAXK + 1){
                        if (temp != 1){
                            if (temp != 2 && temp % 2 == 0){
                            prime2 = 0;
                            }
                            else if (temp != 3 && temp % 3 == 0) {
                                prime2 = 0;
                            }
                            else{
                                div = 5;
                                while (prime2 == 1 && div * div <= temp){
                                    if ((temp % div == 0) || (temp % (div + 2) == 0)){
                                        prime2 = 0;
                                    }
                                    div += 6;
                                }
                            }
                            if (prime2 == 1){
                                count++;
                            }
                        }
                    }   
                
                // If count is 2 programm starts the procedure of searching if number is an interesting semiprime. 
                // Finding the second factor by applying the identity of division

                if (count == 2){
                    b= (n - (n % a) ) / ((double)a);
                    // Sort a and b with a being the smallest
                    if (b < a){
                        t = a;
                        a = b;
                        b = t;
                    }
                    // Increasing the amount of semiprimes with 1
                    sumsemiprimes++;
                    // If a is diferrent than b and their distance is less than b / 100 , programm prints the following message
                    if ( a != b ){
                        if ((b - a) <= (b / 100)){
                            printf("%5d * %5d = %d is an interesting semiprime\n\n",a, b, n);
                        }
                    }
                }

                // sumkalmost increases by checking if count is between the correct borders (2 <= count <= MAXK)
                if (count <= MAXK && count >= 2){
                    sumkalmost++;
                }
            }

        // In the end of for loop setting a and b a diferrent value to avoid duplicated prints
        a = 1000;
        b = 0;    
    }

// After the for loop and via the time function of C programm gives in curtime variable the current UNIX time      
long curtime;
curtime=time(NULL);
srand((unsigned int) curtime);

// Prints the result
printf("Found %d k-almost prime numbers (2 <= k <= %d)\n",sumkalmost, MAXK);
printf("Found %d semiprimes\n\n",sumsemiprimes);
printf("Current time is %ld\n\n", curtime); 
printf("Checking %d random numbers\n\n",COMPUTATIONS);


int j , y , z , x;
int prime3;

    // Start the repetition for the 20 (COMPUTATIONS) random numbers
    for (j = 1; j <= COMPUTATIONS; j++){
            // y and z getting random values through the rand() function. Then programm makes the number that have to peer with the following equation
            y = rand();
            z = rand();
            x =  ((y % 32768) + 1) * ((z % 32768) + 1) + 1;
            // Initialization of count and make a new temp with x. Also make a new divisor
            count = 0;
            temp = x;
            divisor = 2;

            
            // Search if x is prime number 
            // First setting a integer variable (prime3) as 1. This variable used as boolean variable
            // Supposing that 1 represents true
            // After the search if x is prime, prints the following message
            prime3 = 1;
            if (x != 2 && x % 2 == 0){
                prime3 = 0;
            }
            else if (x != 3 && x % 3 == 0) {
                prime3 = 0;
            }
            else{
                div = 5;
                while (prime3 == 1 && div * div <= x){
                    if ((x % div == 0) || (x % (div + 2) ==0)){
                        prime3 = 0;
                    }
                    div+=6;
                }
            }
            if (prime3 == 1){
                printf("%10d is a %d-almost prime number\n",x,count);
            }
            else{
            // If x isn't prime programm starts the same proccess as before, and finds out what almost-prime the x is
            // After that prints the suitable message
                while(temp != 1 ){
                        if(temp % divisor == 0 ){
                            while(temp % divisor == 0 ){
                                count++;
                                temp= temp / divisor;
                            }
                        }

                    if (divisor == 2){
                        divisor++;
                    }
                    else{
                            divisor+=2;
                    }
                }
                    printf("%10d is a %d-almost prime number\n",x,count);
            }
    }
}