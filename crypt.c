
void crypt(char *messaggio, int num_key, int alfa_key){

   int i = 0, ascii_int, sum;

   while (messaggio[i] != '\0') {

      ascii_int = (int) messaggio[i];
      // possiamo converire velocemente il valore
      // in ASCII di un carattere in questo modo;
      
      // se è una lettera gli somma la chiave alfa_key

      if ( ( ascii_int >= 65 && ascii_int <= 90  ) ||
           ( ascii_int >= 97 && ascii_int <= 122 ) ){
         
         sum = ascii_int + alfa_key;
      
         if( ( (ascii_int >= 65 && ascii_int <= 90 ) && sum > 90)
         || (( ascii_int >= 97 && ascii_int <= 122 ) && sum > 122) ){
         
         *(messaggio+i) = sum - 26;
         }
         else{
         *(messaggio+i) = sum;
         }
      }
      
      // se è un valore numerico gli sommo il valore numerico

      else if ( ascii_int >= 48 && ascii_int <= 57 ){
         
         sum = ascii_int + num_key;
         
         if ( (ascii_int >= 48 && ascii_int <= 57) && sum > 57 ){

         *(messaggio+i) = sum - 10;
         
         }

         else{
         *(messaggio+i) = sum;
         }

      } 


      i++;
   }

}

void decrypt(char *messaggio, int num_key, int alfa_key){

   int i = 0, ascii_int, diff;

   while (messaggio[i] != '\0') {

      ascii_int = (int) messaggio[i];
      // possiamo converire velocemente il valore
      // in ASCII di un carattere in questo modo;

      if ( ( ascii_int >= 65 && ascii_int <= 90  ) ||
           ( ascii_int >= 97 && ascii_int <= 122 ) ) {
      
      diff = ascii_int - alfa_key;
      
         if ( (( ascii_int >= 65 && ascii_int <= 90  ) && diff < 65 )
         || (( ascii_int >= 97 && ascii_int <= 122 )&& diff < 97 )) {
         
         *(messaggio+i) = diff + 26;
      
         }
         else{
         *(messaggio+i) = diff; 
         }
      }   
      
      else if( ascii_int >= 48 && ascii_int <= 57 ){
      
      diff = ascii_int - num_key;
      
      if( (ascii_int >= 48 && ascii_int <= 57 ) && diff < 48 ){
         
      *(messaggio+i) = diff + 10;

      }
      else{
      *(messaggio+i) = diff;
         }
      }

      i++;
   }

}

