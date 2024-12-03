#include <iostream>
using namespace std;

struct Degrau {
    int valor;
    Degrau* proximo;

    Degrau(int valor) : valor(valor), proximo(nullptr) {}
};

class Pilha {
private:
    Degrau* cabeca; // Existe, mas não armazena valor útil.

public:
    Pilha() {
        cabeca = new Degrau(0); 
        cabeca->proximo = nullptr;
    }

    ~Pilha() {
        while (cabeca->proximo != nullptr) {
            descer();
        }
        delete cabeca;
    }

    void subir(int valor) {
        Degrau* novo = new Degrau(valor);
        novo->proximo = cabeca->proximo; // Novo nó aponta para o antigo "topo".
        cabeca->proximo = novo;          // Cabeça agora aponta para o novo topo.

        cout << "Degrau atual: " << novo->valor << endl;
    }

    void descer() {
        if (cabeca->proximo == nullptr) {
            cout << "A pilha está vazia" << endl;
            return;
        }

        Degrau* removido = cabeca->proximo;
        cabeca->proximo = removido->proximo; 
        
        cout << "Desceu o degrau: " << removido->valor;
        if (cabeca->proximo != nullptr) {
            cout << " Degrau atual: " << cabeca->proximo->valor << endl;
        } else {
            cout << " Degrau atual: nenhum" << endl;
        }

        delete removido; // Liberar a memória do nó removido.
    }
};

int main() {
    Pilha pilha;
    pilha.subir(1);
    pilha.subir(2);
    pilha.subir(3);
    // pilha.subir(4);
    // pilha.subir(5);
    // ...

    pilha.descer();
    pilha.descer();
    pilha.descer();
    pilha.descer();

    return 0;
}
