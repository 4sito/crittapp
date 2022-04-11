#include <stdio.h>

void get_message(char *messaggio){
   
   fflush(stdin); // we need to flush stdin otherwise it 
                  // will take the previous outputs as input
   scanf("%[^\n]%*c", messaggio);
                  // we take the string as input with [^\n] to take
                  // a string as input until a newline input is given

}


void get_key(int *key_pointer){

      printf("Specifica la chaive di cifratura\n");
      scanf("%d", &*key_pointer);

     if (*key_pointer == 0){ 
        
        printf("!!!!!!\n");
        printf("Specificare una chiave di cifratura diversa da 0\n");
        printf("!!!!!!\n");

     }

}


void calculate_key(int k, int *num_pointer, int *alpha_pointer){
   
   int temp_k = k;


   if(k < 0){
      k = k+10;
   }
   *num_pointer = k % 10;   // as the digits we need to crypt/decrypte
                            // are 10 we can 'shuffle' between them
                            // simply calculating the module of any 
                            // k divided by the number of digits (10)
                            // from 0 to 9
   if (temp_k < 0){
   temp_k = temp_k+26;
   }                         
   *alpha_pointer = temp_k % 26; // the same reasoning can be done with 
                            // alphabetic key, we are shuffling
                            // through 26 different letters so there
                            // are just 26 different keys that are
                            // periodically repetead in an interval
                            // of 26.

}


void print_message(char *messaggio){

int i = 0;

while (messaggio[i] != '\0') { // until the string hits its last
                               // character the cycle is repeated 

   printf("%c", messaggio[i]);
   i++;
}
   printf("\n");
}


