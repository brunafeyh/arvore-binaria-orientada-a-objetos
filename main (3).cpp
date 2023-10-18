#include <iostream>

using namespace std;

class ArvoreBinaria {
public:
    ArvoreBinaria(int n) : n(n), esq(nullptr), dir(nullptr) {}

    static void insere(ArvoreBinaria* &r, int n);
    static int remove_maior(ArvoreBinaria* &r);
    static void remove(ArvoreBinaria* &r, int n);
    void mostrar();
    void clear();
    ~ArvoreBinaria();

private:
    int n;
    ArvoreBinaria* esq;
    ArvoreBinaria* dir;
};

void ArvoreBinaria::insere(ArvoreBinaria* &r, int n) {
    if (r == nullptr) {
        r = new ArvoreBinaria(n);
    } else {
        if (n < r->n) {
            insere(r->esq, n);
        } else {
            insere(r->dir, n);
        }
    }
}

int ArvoreBinaria::remove_maior(ArvoreBinaria* &r) {
    if (r->dir) {
        return remove_maior(r->dir);
    }
    int aux = r->n;
    ArvoreBinaria* e = r->esq;
    delete r;
    r = e;
    return aux;
}

void ArvoreBinaria::remove(ArvoreBinaria* &r, int n) {
    if (r == nullptr) return;

    if (r->n == n) {
        if (r->esq) {
            r->n = remove_maior(r->esq);
        } else {
            ArvoreBinaria* e = r->dir;
            delete r;
            r = e;
        }
    } else {
        if (n < r->n) {
            remove(r->esq, n);
        } else {
            remove(r->dir, n);
        }
    }
}

void ArvoreBinaria::mostrar() {
    if (esq) esq->mostrar();
    cout << n << endl;
    if (dir) dir->mostrar();
}

void ArvoreBinaria::clear() {
    if (esq) delete esq;
    if (dir) delete dir;
}

ArvoreBinaria::~ArvoreBinaria() {
}

int main() {
    ArvoreBinaria *r = nullptr;
    ArvoreBinaria::insere(r, 7);
    ArvoreBinaria::insere(r, 6);
    ArvoreBinaria::insere(r, 8);
    ArvoreBinaria::insere(r, 8);
    ArvoreBinaria::insere(r, 5);

    cout << "Árvore original:" << endl;
    r->mostrar();

    ArvoreBinaria::remove(r, 7);

    cout << "Árvore após a remoção do valor 7:" << endl;
    r->mostrar();

    r->clear();

    return 0;
}