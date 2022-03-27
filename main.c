
#include <stdio.h>

#include "crypt.h"
#define MAX_LEN 100

void print_message(char *messaggio);
void get_message(char *messaggio);

void calculate_key(int k, int *first_pointer, int *second_pointer);

int main(){

   int choice = 0, num_key = 0, alfa_key = 0, k;
   char messaggio[MAX_LEN];

   int *first_pointer = &num_key, *second_pointer = &alfa_key;

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
         calculate_key(k, first_pointer, second_pointer);
      
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
   
   fflush(stdin);
   //scanf("%s", messaggio);
   //scanf("%[^\n]s", messaggio);
   //fgets(messaggio, MAX_LEN, stdin);
   //gets(messaggio);
   scanf("%[^\n]%*c", messaggio);

}

void calculate_key(int k, int *first_pointer, int *second_pointer){

   *first_pointer = k % 10;
   *second_pointer = k % 26;

}
void print_message(char *messaggio){

int i = 0;

while (messaggio[i] != '\0') {

   printf("%c", messaggio[i]);
   i++;
}
   printf("\n");
}
