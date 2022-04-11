
void crypt(char *messaggio, int num_key, int alfa_key){

   int i = 0, ascii_int, sum;

   while (messaggio[i] != '\0') {

      ascii_int = (int) messaggio[i];
      // possiamo converire velocemente il valore
      // in ASCII di un carattere in questo modo;
      
      // se è una lettera gli somma la chiave alfa_key
      
      // ASCII: 65 - 90 lettere maiuscole, 
      // 97 - 122 lettere minuscole, se il carattere ascii converito
      // è compreso ad uno di questi due range la condizione dell'if
      // è verificata

      if ( ( ascii_int >= 65 && ascii_int <= 90  ) ||
           ( ascii_int >= 97 && ascii_int <= 122 ) ){
         
         sum = ascii_int + alfa_key; // sommiamo alfa key che è un 
                                     // valore fra 0 e 26
      
         if( ( (ascii_int >= 65 && ascii_int <= 90 ) &&  sum > 90)
         || (( ascii_int >= 97 && ascii_int <= 122 ) && sum > 122 ) )  {
         
         // se il risultato fra il valore ascii convertito e la chiave 
         // supera il range delle lettere togliamo 26, il numero dei 
         // caratteri così 'ricomincia dall'inzio.
         //
         // Esempio se la chiave è k = 1  e la lettera è z minuscola
         // ASCII = 122, la somma sarebbe 123, numero non compreso fra
         // le lettere ASCII, quindi sottraendo 26 otteniamo il valore
         // 97 che corrisponde alla lettere minuscola 'a'

         *(messaggio+i) = sum - 26;
         }

         else{
         *(messaggio+i) = sum; // se non supera il range fa 
                               // una semplice somma

         }
      }
      
      // se è un valore numerico gli sommo il valore numerico
      // ASCII numeric digits: 48 - 57 = 0 - 9

      else if ( ascii_int >= 48 && ascii_int <= 57 ){
         
         sum = ascii_int + num_key; // è lo stesso 
                                    // ragionamento dei caratteri
                                    // dell'alfabeto con la differenza
                                    // che il 'ciclo' è di 10 caratteri

         
         if ( (ascii_int >= 48 && ascii_int <= 57) && sum > 57){

         *(messaggio+i) = sum - 10; // se supera il range
                                    // ricomincio il ciclo dalla
                                    // prima cifra sottraendo il numero
                                    // delle cifre
         
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
      
      diff = ascii_int - alfa_key; // lo stesso ragionamento con la
                                   // differenza che 'sottraiamo'
                                   // la chiave per decriptare
         
      
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
      
      if( (ascii_int >= 48 && ascii_int <= 57 ) &&  diff < 48  ){
         
      *(messaggio+i) = diff + 10;

      }
      else{
      *(messaggio+i) = diff;
         }
      }

      i++;
   }

}

