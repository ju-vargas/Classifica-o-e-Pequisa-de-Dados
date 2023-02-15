/*      
            
            |p|i| | | | | | | | | | |j|

            enquanto j é maior que i (i nao vai ate o final, j nao vai até o início)

                enquanto o array[i] for menor que array [pivo] e eu nao chegar no final, eu ando com i
                |p| | |i| | | | | | | | |j|
                       ->

                enquanto o array[j] for maior ou igual array [pivo] e eu nao chegar no inicio, eu ando com j
                |p| | |i| | | | | | |j| | |
                                    <-

                |p| | | |i| | | |j| | | | |
                  menores           maiores



                

                troco os dois de lugar

                |p| | | |i| | | |j| | | | |
                           *   *

                paro quando o valor de i nao eh menor
                depois paro quando o valor de j nao eh maior
                troco os dois e continuo a andar


            chego num ponto em que  
            |p| | | | |i|j| | | | | | | 
            menores        maiores


            por causa daquele ultimo j++
                agora j está no endereço do i 
                
                troco o endereço dos dois, pro pivo ficar no meio (no seu lugar)
                            
                |p com valor de j| | | | |j com valor de p| | | | | | | | 
                menores                     maiores

                return j (index pivo)


        PARA NÚMEROS ALEATÓRIOS
              | |i|p|j| | | | | |
                          
                        i    j





    */

    //esq = inicio -- dir = fim  
    //pivo escolhido é sempre o início

    // se eu mudar pivo preciso mudar i e j? 
     // Generate a random number in between
    // low .. high



    int particiona(array_t array, int esq, int dir, loginfo_t& loginfo){
    
    int i=esq, j=dir;
    int pivo;    

    srand(time(NULL));
    pivo = esq + rand() % (dir - esq);
 

    while(j>pivo && i<pivo){
         
         while(array[i]<array[pivo] && i<pivo) {  
             i++;
             get<1>(loginfo)++;
         }
         while(array[j]>=array[pivo] && j>pivo){   
             cout << "|" << array[j] << "|"; 
             j--;
             get<1>(loginfo)++;
         }
         if(i<pivo && array[i]>array[j]){
            swap(&array[i], &array[j]);
            get<0>(loginfo)++;
            get<1>(loginfo)++;
         }
  }
  //get<1>(loginfo)++;
  if(array[j]<array[pivo]){
	swap(&array[pivo], &array[j]);
    get<0>(loginfo)++;
    get<1>(loginfo)++;
  }
    return j; 
}