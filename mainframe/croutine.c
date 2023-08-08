 /*if the the sum of factors is greater then 2 times the number*/
 int isAbundant(int number) {                                    
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