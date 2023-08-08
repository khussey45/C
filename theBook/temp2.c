#include <stdio.h>
   /* Print Fahrenheit-Celsius table for fahr =0, 20,..., 300*/ 
   int main(){   

   // Heading   
   printf("    Celsius to Fahrenheit!\n");   
   printf("------------------------------\n"); 

  // Declaring Variables  
   float fahr, celsius;
   int lower, upper, step;

   lower = 0; /* lower limit of temp table */
   upper = 300;/* uppper limit */
   step = 20; /* step size */


   celsius = lower;
   while (celsius <= upper) {
     fahr = (celsius * 9.0/5.0) + 32;
     printf("%3.0f %6.1f\n", celsius, fahr);
     celsius = celsius + step;
   }
 }