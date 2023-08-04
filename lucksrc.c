#include <stdio.h>                                        
#include <stdlib.h>                                       
#include <errno.h>                                        
#include <string.h>                                       
                                                          
FILE *luckyFile;                                          
char buffer[81];                                          
unsigned char lucky[15000];                               
int bytesWritten;     

 int isLucky(int);                                        
 int isPower2(int);                                       
 void setupLucky(int);   
 int isAbundant(int);
 int sumOfFactors(int);      
 int isPrime(int);    
 int myInt(int);
 int isMersennePrime(int);
                                                          
int main() {                                                  
                                 
 int i,j;                                                 
 int len = 15000;         
                        
                                                          
 /*************************************/                  
 /*     Open file to write output     */                  
 /*************************************/        
 printf("Kieren's Abundant and Lucky Numbers and Mersenne Primes\n\n"); 
 
 luckyFile = fopen("DD:OUTPUT1", "w");       
 if (luckyFile == NULL) {                                          
  printf("open error:   %d/%s\n", errno, strerror(errno));         
  exit(99);                                                        
 }                                                                 
                                                                   
 /*************************************/                           
 /*     Run program                   */                           
 /*************************************/                           
 bytesWritten = sprintf(buffer, "This will be used later\n");      
 fwrite(buffer, 1, bytesWritten, luckyFile);                       
                                                                   
 /*************************************/                           
 /*        DO NOT DELETE THIS         */                           
 /*       SETUP THE LUCKY ARRAY       */                           
 /*************************************/                           
 setupLucky(len);                                                  
                                                                   
 /*************************************/                           
 /*           Run the loop            */                           
 /*************************************/                           
 for (i = 1; i < len; i++) {                                       
    if(isLucky(i) == 1 && isAbundant(i) == 1) {                                            
      printf("%d is abundantly lucky!  \n", i);                                    
    }    
    if(isPrime(i) == 1 && isPower2(i+1) == 1) {
      printf("%d is a Mersenne prime!   \n", i); 
    }                                                            
  }                                                                  
                                                                     
  /*************************************/                            
  /*     Close output file             */                            
  /*************************************/                            
  fclose(luckyFile);                                                 
  return 0;                                                          
 }                                                                   
                                                                     
 /*************************************/                             
 /*    Determine if myInt is lucky    */                             
 /*************************************/                             
                                                                     
 int isLucky (int myInt) {                                           
  return (lucky[myInt-1] == 1);                                      
 }                                                                   
                                                                     
 /*************************************/                             
/*   Determine if myInt is power 2   */                             
/*************************************/                             
                                                                    
int isPower2 (int number) {                                          
  return !(myInt>>31) & !!myInt & !(myInt & (myInt+(~1+1)));  
   if(number && !(number&(number-1))){
        int power = 0;
        while(number > 1){
            number >>= 1;
            power++;
        }
        return power;
    } else {
        return -1;
    }      
}                                                                   
                                                                    
/*************************************/                             
/*     Setup lucky number array      */                             
/*************************************/                             
                                                                    
void setupLucky (int len) {                                         
  int i;                                                            
  for(i = 0; i < len; i++) {                                        
   lucky[i] = 1;                                                    
  }                                                                 
  int nth = 2;                                                      
  int count = 0;                                                    
  while (nth < len) {                                               
   int count = 0;                                                   
   i = 0;                                                           
    while (i < len) {                                         
     if(lucky[i]==1) {                                        
      count++;                                                
      if(count == nth) {                                      
       lucky[i] = 0;                                          
       count = 0;                                             
      }                                                       
     }                                                        
     i++;                                                     
    }                                                         
    i = nth;                                                  
    while (i < len && lucky[i]==0) {                          
     i++;                                                     
    }                                                         
    nth = i+1;                                                
   }          
}
   // Methods  from croutine file

/*if the the sum of factors is greater then 2 times the number*/
 int isAbundant(int number){                                    
   int i = sumOfFactors(number);                                 
   if (i > (2*number)) {                                         
     return 1;                                                   
   }                                                             
   else                                                          
     return 0;                                                   
 }   


 int sumOfFactors(int number) {                                  
   int factor = 0, sum = 0;                                      
   for (int i = 1; i <= number; i++) {                           
     if (!(number % i)) {                                        
       factor = i;                                               
       sum += factor;                                            
     }                                                           
   }                                                             
   return sum;                                                   
 }    


 int isPrime(int number) {                                       
   int flag = 1;     
   if (number <= 1)     /*true prime numbers are greater than 1*/     
     flag = 0;                                                        
   else {                                                             
     for (int i=2 ; i <=number/2 ; i++) {                             
       if(number % i ==0) {                                           
         flag = 0;                                                    
         break;                                                       
       }                                                              
     }                                                                
   }                                                                  
   return flag;                                                       
 }                                                                                                                                                         
                                                     


// int isMersennePrime(int number){
//     int power = isPower2(number+1);
//     if(power != -1){
//         return isPrime(power) && isPrime(number);
//     } else {
//         return 0;
//     }
// } 





