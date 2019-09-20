#include <iostream>
#include <new>
using namespace std;

template<typename T>
struct Deque{
  T*vetor;
  int tamanho,elementos,dir,esq;
};
 //esquerda e direita, são as extremidades da sequência na fila.

 
//inicialização e alocação do deque(double-ended-queue)
template <typename T>
bool inicializar(Deque<T> &D){
    D.vetor = new T[1];
    if (D.vetor == nullptr){
        return true;
    }
    D.esq =0;
    D.dir =0;
    D.tamanho =1;
    D.elementos =0;
    return false;
}

//Desalocamento do deque
template <typename T>
void terminar(Deque<T> &D){
    delete[] D.vetor;
}

//realocação dinâmica no deque
template <typename T>
bool redimensionar(int tam_vn,Deque<T> &D){
    T *v = new(nothrow)T[tam_vn];
    if(v == nullptr)return true;
    int j =D.esq;
    D.esq = (tam_vn - D.elementos)/2;
    D.dir = D.esq + D.elementos-1;
    for(int i=D.esq;i<=D.dir;i+=1){
        v[i] = D.vetor[j];
        j+=1;
    }
    delete[] D.vetor;D.vetor=v;
    D.tamanho = tam_vn;
    return false;
    //remoção do vetor antigo e adição do novo vetor=vn
}

//Checando se o deque está vazio;
template <typename T>
bool vazio(Deque<T> &D){
    if(D.elementos==0){
        return true;
    }
    return false;
}
//análise dos elementos da direita:inserção de elementos
template <typename T>
bool inserir_dir(Deque<T> &D, T e){
    if(D.dir==D.tamanho-1){
        if(redimensionar(D.tamanho*2,D))return true;
    }
    D.dir +=1;
    D.vetor[D.dir] = e;
    D.elementos +=1;
    return false;
    //e = elementos
}
//remoção de elementos na direita:
template <typename T>
T remover_dir(Deque<T> &D){
    T value = D.vetor[D.dir];
    D.dir -=1;
    D.elementos -=1;
    return value;
}

//análise dos  elementos da esquerda:inserção de elementos
template <typename T>
bool inserir_esq(Deque<T> &D, T e){
    if(D.esq==0){
        if(redimensionar(D.tamanho*2,D))return true;
    }
    D.esq-=1;
    D.vetor[D.esq] = e;
    D.elementos +=1;
    return false;
}
//remoção de elementos na esquerda:
template <typename T>
T remover_esq(Deque<T> &D){
    T value = D.vetor[D.esq];
    D.esq +=1;
    D.elementos -=1;
    return value;
}

template <typename T>
void print_deque(const Deque<T> &D){
    cout << "Deque: [";
    for(int i=0;i<D.tamanho;++i){
        cout << D.vetor[i] << " ";
    }
    cout << "];\n";
}

//Trabalho de Estrutura de Dados ;Aluno:Carlos Eduardo Pinheiro Santos ;Matrícula:475107