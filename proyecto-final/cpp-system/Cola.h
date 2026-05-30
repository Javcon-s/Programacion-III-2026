#ifndef COLA_H
#define COLA_H

#include <iostream>
using namespace std;

struct NodoCola {

    int senderID;
    int receiverID;

    NodoCola* siguiente;
};

class Cola {

private:

    NodoCola* frente;
    NodoCola* final;

public:

    Cola();

    ~Cola();

    bool vacia();

    void encolar(int sender, int receiver);

    void desencolar();

    void mostrar();
};

#endif