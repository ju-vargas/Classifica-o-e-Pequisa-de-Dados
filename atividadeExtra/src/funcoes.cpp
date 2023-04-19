#include "../include/bib.h"


using namespace std;


int readInt(array_t array, array_size_t size) {

    int auxInt;
    ifstream random_arq("../data/randomnumbers.bin", ios::binary); 

    if (!random_arq.is_open()) {
        cout << "deu ruim";
        return 1;  
    }
    
    int i = 0; 
    while (random_arq.read((char*)&auxInt, sizeof(int)) && i<size){
        //cout << auxInt << endl;
        array[i] = auxInt; 
        i++; 
    }

    random_arq.close(); 
    return 0; 
}

void swap(int *n1, int *n2){
   int troca = *n1;
	 *n1 = *n2;
	 *n2 = troca;
}

vector_array_t arrayToVector(int *array, int tamanho) {
    // Cria um vector com os elementos do array
    vector_array_t meuVector(array, array + tamanho);    
    return meuVector;
}

int writeTxt(loginfo_t loginfo, int tam) {
    
    string label; 
    double trocas; 
    double comparacoes;

    ofstream txtOutput("../data/R00337553.txt", ios::app); 

    if (!txtOutput) {
        cout << "deu ruim"; 
        return 1; 
    }

    //<int, int, std::chrono::duration<double>,std::string>
    label = get<3>(loginfo);
    txtOutput << label;

    txtOutput << tam << ", "; 
    
    trocas = get<0>(loginfo); 
    txtOutput << setprecision(20) << trocas << ", "; 

    comparacoes = get<1>(loginfo); 
    txtOutput << setprecision(20) << comparacoes << ", ";

    txtOutput <<setprecision(2) << get<2>(loginfo).count() << ".";  

    txtOutput << endl;

    txtOutput.close(); 

    return 0; 


}

int iniLoginfo (loginfo_t& loginfo){ 

    //zerando trocas, comparacoes e tempo
    get<0>(loginfo) = 0; 
    get<1>(loginfo) = 0; 
    get<2>(loginfo) = std::chrono::duration<double>(0);

    return 0; 
}

int nameLoginfo (loginfo_t& loginfo, string label){

    get<3>(loginfo) = label; 

    return 0; 
}

int copyArray(array_t originArr, array_t copyArr, int tam) {

    for (auto i = 0; i < tam; i++){
        copyArr[i] = originArr[i]; 
        //cout << copyArr[i] << " "; 
    }

    return 0; 
}