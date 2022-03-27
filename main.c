
#include <stdio.h>

#include "crypt.h"
#include "key.h"

#define MAX_LEN 100   // maximum length the message can be


int main(){

   int choice = 0, num_key = 0, alfa_key = 0, k;
   int *key_pointer = &k, 
       *num_pointer = &num_key, 
       *alpha_pointer = &alfa_key;
      
   char messaggio[MAX_LEN];

      while (choice != 4) {
      
      printf("-----------\n");
      printf("Benvenuto in Crittapp\n");
      printf("-----------\n\n");
      
      printf("Scegliere una delle seguenti opzioni:\n\n");

      
      printf("1) Specificare la chiave di cifratura:\n");

      printf("2) Codifica un messaggio:\n");

      printf("3) Decodifica un messaggio:\n");
      
      printf("4) Esci dall'applicazione\n");

      scanf("%d", &choice);

      if (choice == 1) {
         while (k == 0){
            
            get_key(key_pointer);
         
         }

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
         
         printf("Il messaggio che vuoi decriptare:\n");

         get_message(messaggio);

         printf("\n\n\n");
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


