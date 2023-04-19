#include "../include/bib.h"


using namespace std;

void calcForSize(array_t fullRandom, array_t fullOrder, array_t fullInverse, array_size_t size){


    //VARIAVEIS ***************************************************************************************************************
    auto start = std::chrono::steady_clock::now();
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    //CRIANDO OS LOGINFOS PARA CADA ALGORITMOS
    loginfo_t logISBLR, logISBLO, logISBLI; 
    loginfo_t logISBBR, logISBBO, logISBBI;
    loginfo_t logSheSR, logSheSO, logSheSI;
    loginfo_t logBubSR, logBubSO, logBubSI; 
    loginfo_t logQukSR, logQukSO, logQukSI; 
    loginfo_t logSelSR, logSelSO, logSelSI;
    loginfo_t logHepSR, logHepSO, logHepSI;
    loginfo_t logtimSR, logtimSO, logtimSI; 
    loginfo_t logMerSR, logMerSO, logMerSI; 


    //CRIANDO OS ARRAYS QUE SERÃO USADOS**************************************************************************************
  
    //declaro os arrays que serao criados 
    array_t inRandom = new int[size]; 
    array_t inOrder = new int[size]; 
    array_t inInverse = new int[size]; 

    //RANDOM
    //preencho o array random
    copyArray(fullRandom, inRandom, size); 

    //ORDENADOS
    copyArray(fullOrder, inOrder, size); 

    //INVERTIDOS
    copyArray(fullInverse, inInverse, size); 


    //TESTE *************************************************************************************
    
    //-----INSERTION SORT LINEAR
    
    //*RANDOM
    array_t RandomAux = new int[size]; 
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logISBLR);

    start = std::chrono::steady_clock::now();
    logISBLR = insertion_sort(RandomAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBLR) = elapsed_seconds;  
   
    nameLoginfo(logISBLR, "ISBL, R, "); 
    writeTxt(logISBLR, size); 

 

    //*ORDENADO
    array_t OrderAux = new int[size]; 
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logISBLO);

    start = std::chrono::steady_clock::now(); 
    logISBLO = insertion_sort(OrderAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBLO) = elapsed_seconds; 

    nameLoginfo(logISBLO, "ISBL, O, "); 
    writeTxt(logISBLO, size); 


    //*INVERTIDO
    array_t InverseAux = new int[size];
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logISBLI);

    start = std::chrono::steady_clock::now();
    logISBLI = insertion_sort(InverseAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBLI) = elapsed_seconds; 

    nameLoginfo(logISBLI, "ISBL, I, "); 
    writeTxt(logISBLI, size); 


    //-----INSERTION SORT BINARIO
    //*RANDOM
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logISBBR);

    start = std::chrono::steady_clock::now();
    logISBBR = insertion_sortBB(RandomAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBBR) = elapsed_seconds; 

    nameLoginfo(logISBBR, "ISBB, R, "); 
    writeTxt(logISBBR, size); 


    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logISBBO);

    start = std::chrono::steady_clock::now();
    logISBBO = insertion_sortBB(OrderAux, size);
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBBO) = elapsed_seconds; 

    nameLoginfo(logISBBO, "ISBB, O, "); 
    writeTxt(logISBBO, size); 


    //*INVERTIDO
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logISBBI);

    start = std::chrono::steady_clock::now();
    logISBBI = insertion_sortBB(InverseAux, size);
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logISBBI) = elapsed_seconds; 

    nameLoginfo(logISBBI, "ISBB, I, "); 
    writeTxt(logISBBI, size); 
    

    //-----SHELLSORT
    //*RANDOM
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logSheSR);

    start = std::chrono::steady_clock::now();
    logSheSR = shellsort(RandomAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSheSR) = elapsed_seconds; 
    
    nameLoginfo(logSheSR, "SheS, R, "); 
    writeTxt(logSheSR, size); 


    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logSheSO);

    start = std::chrono::steady_clock::now();
    logSheSO = shellsort(OrderAux, size);
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSheSO) = elapsed_seconds; 

    nameLoginfo(logSheSO, "SheS, O, "); 
    writeTxt(logSheSO, size); 


    //*INVERTIDO
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logSheSI);

    start = std::chrono::steady_clock::now();
    logSheSI = shellsort(InverseAux, size); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSheSI) = elapsed_seconds; 
    
    nameLoginfo(logSheSI, "SheS, I, "); 
    writeTxt(logSheSI, size); 
    

    //-----BUBBLE SORT
    //*RANDOM
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logBubSR);
    
    start = std::chrono::steady_clock::now();
    bubblesort(RandomAux, size, logBubSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logBubSR) = elapsed_seconds;     
    
    nameLoginfo(logBubSR, "BubS, R, "); 
    writeTxt(logBubSR, size); 


    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logBubSO);
    
    start = std::chrono::steady_clock::now();
    bubblesort(OrderAux, size, logBubSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logBubSO) = elapsed_seconds;      
    
    nameLoginfo(logBubSO, "BubS, O, "); 
    writeTxt(logBubSO, size); 


    //*INVERTIDO
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logBubSI);

    start = std::chrono::steady_clock::now();
    bubblesort(InverseAux, size, logBubSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logBubSI) = elapsed_seconds;      
    
    nameLoginfo(logBubSI, "BubS, I, "); 
    writeTxt(logBubSI, size); 
    
    //-----QUICKSORT RANDOM
    //*RANDOM
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logQukSR);

    start = std::chrono::steady_clock::now();
    randomquicksort(RandomAux, 0, size-1, logQukSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logQukSR) = elapsed_seconds;   
    
    nameLoginfo(logQukSR, "Quk, R, "); 
    writeTxt(logQukSR, size); 


    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logQukSO);

    start = std::chrono::steady_clock::now();
    randomquicksort(RandomAux, 0, size-1, logQukSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logQukSO) = elapsed_seconds;   
    
    nameLoginfo(logQukSO, "Quk, O, "); 
    writeTxt(logQukSO, size); 


    //*INVERTIDO
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logQukSI);

    start = std::chrono::steady_clock::now();
    randomquicksort(RandomAux, 0, size-1, logQukSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logQukSI) = elapsed_seconds;   
    
    nameLoginfo(logQukSI, "Quk, I, "); 
    writeTxt(logQukSI, size); 


    //-----SELECTION SORT
    //*RANDOM
    //criando vector
    vector_array_t auxVectorS; 
    auxVectorS = arrayToVector(inRandom, size); 
    iniLoginfo(logSelSR);

    start = std::chrono::steady_clock::now();
    selectionsort(auxVectorS, logSelSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSelSR) = elapsed_seconds;  
    
    nameLoginfo(logSelSR, "Sel, R, "); 
    writeTxt(logSelSR, size); 


    //*ORDENADO
    auxVectorS = arrayToVector(inOrder, size); 
    iniLoginfo(logSelSO);
    
    start = std::chrono::steady_clock::now();
    selectionsort(auxVectorS, logSelSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSelSO) = elapsed_seconds;      
    
    nameLoginfo(logSelSO, "Sel, O, "); 
    writeTxt(logSelSO, size); 


    //*INVERTIDO
    auxVectorS = arrayToVector(inInverse, size); 
    iniLoginfo(logSelSI);

    start = std::chrono::steady_clock::now();
    selectionsort(auxVectorS, logSelSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logSelSI) = elapsed_seconds;  
    
    nameLoginfo(logSelSI, "Sel, I, "); 
    writeTxt(logSelSI, size); 


    
    //-----HEAP SORT
    //*RANDOM
    //criando vector
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logHepSR);

    start = std::chrono::steady_clock::now();
    heapSort(inRandom, size, logHepSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logHepSR) = elapsed_seconds;  
    
    nameLoginfo(logHepSR, "Hep, R, "); 
    writeTxt(logHepSR, size); 

    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logHepSO);

    start = std::chrono::steady_clock::now();
    heapSort(inOrder, size, logHepSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logHepSO) = elapsed_seconds; 

    nameLoginfo(logHepSO, "Hep, O, "); 
    writeTxt(logHepSO, size); 

    //*INVERTIDO
    
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logHepSI);

    start = std::chrono::steady_clock::now();
    heapSort(inOrder, size, logHepSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logHepSI) = elapsed_seconds; 

    nameLoginfo(logHepSI, "Hep, I, "); 
    writeTxt(logHepSI, size); 

    //-----TIMSORT
    //*RANDOM
    copyArray(inRandom, RandomAux, size);
    iniLoginfo(logtimSR);

    start = std::chrono::steady_clock::now();
    timSort(RandomAux,size, logtimSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logtimSR) = elapsed_seconds;  
    
    nameLoginfo(logtimSR, "TimS, R, "); 
    writeTxt(logtimSR, size); 


    //*ORDENADO
    copyArray(inOrder, OrderAux, size);
    iniLoginfo(logtimSO);

    start = std::chrono::steady_clock::now();
    timSort(OrderAux, size, logtimSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logtimSO) = elapsed_seconds;  
    
    nameLoginfo(logtimSO, "TimS, O, "); 
    writeTxt(logtimSO, size); 


    //*INVERTIDO
    copyArray(inInverse, InverseAux, size);
    iniLoginfo(logtimSI);

    start = std::chrono::steady_clock::now();
    timSort(InverseAux, size, logtimSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logtimSI) = elapsed_seconds;  
    
    nameLoginfo(logtimSI, "TimS, I, "); 
    writeTxt(logtimSI, size); 
    
    
    //-----MERGESORT
    //*RANDOM
    //criando vector
    vector_array_t auxVectorM; 
    auxVectorM = arrayToVector(inRandom, size); 
    iniLoginfo(logMerSR);

    start = std::chrono::steady_clock::now();
    mergesort(auxVectorM, logMerSR); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logMerSR) = elapsed_seconds;  
    
    nameLoginfo(logMerSR, "Mer, R, "); 
    writeTxt(logMerSR, size); 


    //*ORDENADO
    auxVectorM = arrayToVector(inOrder, size); 
    iniLoginfo(logMerSO);
    
    start = std::chrono::steady_clock::now();
    mergesort(auxVectorM, logMerSO); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logMerSO) = elapsed_seconds;      
    
    nameLoginfo(logMerSO, "Mer, O, "); 
    writeTxt(logMerSO, size); 


    //*INVERTIDO
    auxVectorM = arrayToVector(inInverse, size); 
    iniLoginfo(logMerSI);

    start = std::chrono::steady_clock::now();
    mergesort(auxVectorM, logMerSI); 
    finish = std::chrono::steady_clock::now();
    elapsed_seconds = finish - start;
    get<2>(logMerSI) = elapsed_seconds;  
    
    nameLoginfo(logMerSI, "Mer, I, "); 
    writeTxt(logMerSI, size); 
}