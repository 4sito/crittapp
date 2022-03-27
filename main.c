
#include <stdio.h>

#include "crypt.h"    // the header file where the crypt and
                      // decrypt functions are defined

#define MAX_LEN 100   // maximum length the message can be

void print_message(char *messaggio);
void get_message(char *messaggio);
void calculate_key(int k, int *num_pointer, int *alpha_pointer);

int main(){

   int choice = 0, num_key = 0, alfa_key = 0, k;
   int *num_pointer = &num_key, *alpha_pointer = &alfa_key;
      
   char messaggio[MAX_LEN];

      while (choice != 4) {
      
      printf("-----------\n");
      printf("Benvenuto in Crittapp\n");
      printf("-----------\n");
      
      printf("1) Specificare la chiave di cifratura, \t (chiave attuale %d)\n", k);
      printf("2) Codifica un messaggio, \t\t (messaggio attuale: %s)\n", messaggio);
      printf("3) Decodifica un messaggio:\n");
      printf("4) Esci dall'applicazione\n");

      scanf("%d", &choice);

      if (choice == 1) {
         
         printf("Specifica la chaive di cifratura\n");
         scanf("%d", &k);
         calculate_key(k, num_pointer, alpha_pointer);
      
      }

      else if (choice == 2){
      
         printf("Il messaggio che vuoi criptare:\n");
         
         get_message(messaggio);

         printf("\n\n\n");
         printf("Messaggio non criptato: \t");
         
         print_message(messaggio); 
         printf("Messaggio Criptato:\t\t");
         crypt(messaggio, num_key, alfa_key);
         print_message(messaggio);

         printf("\n\n\n");

      }

      else if (choice == 3){
        
         printf("Messaggio criptato:\t");
         print_message(messaggio);      
         decrypt(messaggio, num_key, alfa_key);
         printf("Messaggio decriptato:\t");
         print_message(messaggio);
      
         printf("\n\n\n");
      }

   }


   
   
   

   
   return 0;
}

void get_message(char *messaggio){
   
   fflush(stdin); // we need to flush stdin otherwise it 
                  // will take the previous outputs as input
   scanf("%[^\n]%*c", messaggio);
                  // we take the string as input with [^\n] to take
                  // a string as input until a newline input is given

}

void calculate_key(int k, int *num_pointer, int *alpha_pointer){

   *num_pointer = k % 10;   // as the digits we need to crypt/decrypte
                            // are 10 we can 'shuffle' between them
                            // simply calculating the module of any 
                            // k divided by the number of digits (10)
                            // from 0 to 9
                            
   *alpha_pointer = k % 26; // the same reasoning can be done with 
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
