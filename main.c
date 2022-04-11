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
      
      printf("\t\t|---------------------|\n");
      printf("\t\t|Benvenuto in Crittapp|\n");
      printf("\t\t|_____________________|\n\n");
      
      printf("Scegliere una delle seguenti opzioni:\n\n");

      printf("1) Specificare la chiave di cifratura:\n");
      printf("2) Codifica un messaggio:\n");
      printf("3) Decodifica un messaggio:\n");
      printf("4) Esci dall'applicazione\n");

      scanf("%d", &choice);
      
      switch (choice) {
         case 1:
            k = 0;
            while (k == 0){

            get_key(key_pointer);

            }

            calculate_key(k, num_pointer, alpha_pointer);
            
            break;

         case 2:
            printf("Il messaggio che vuoi criptare:\n");

            get_message(messaggio);

            printf("\n\n\n");
            printf("Messaggio non criptato: \t");
            print_message(messaggio);

            printf("Messaggio Criptato:\t\t");
            crypt(messaggio, num_key, alfa_key);
            print_message(messaggio);

            printf("\n\n\n");
            break;
         
         case 3:
            printf("Il messaggio che vuoi decriptare:\n");

            get_message(messaggio);

            printf("\n\n\n");
            printf("Messaggio criptato:\t");
            print_message(messaggio);

            decrypt(messaggio, num_key, alfa_key);
            printf("Messaggio decriptato:\t");
            print_message(messaggio);

            printf("\n\n\n");
            break;
         
         case 4:
            break;

         default:
            printf("\n\n\n\n!!! Scegli un'opzione valida !!!\n\n\n\n");
            
      }
         printf("Premi [Invio] per continuare.\n");
         fflush(stdin);
         getchar();
   }
  
   return 0;
}


