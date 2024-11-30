#include <iostream>
#include "TrajetCompose.h"
using namespace std;

TrajetCompose::TrajetCompose(const char* villeDep, const char* villeArr, TrajetSimple* pListTrajets[], int pNbTrajets) 
    : Trajet(villeDep, villeArr) {

    nbTrajets = pNbTrajets;
    listTrajets = new TrajetSimple*[nbTrajets]; 

    for (int i = 0; i < longeur; ++i) {
        listTrajets[i] = pListTrajets[i];
    }

    cout << "Construction TrajetComposee" << "\r\n";
}

TrajetCompose::~TrajetCompose() {
    for (int i = 0; i < nbTrajets; ++i) {
        delete listTrajets[i]; 
    }
    delete[] listTrajets; 
    cout << "Destruction TrajetComposee" << "\r\n";
}

void TrajetCompose::afficher() const 
{
    for (int i = 0; i < nbTrajets; ++i) {
        listTrajets[i]->afficher(); 
        if (i < nbTrajets - 1) {
            cout << " - ";
        }
    }
    cout << endl;
}