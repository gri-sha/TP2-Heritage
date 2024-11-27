#include <iostream>
#include "trajetCompose.h"
using namespace std;

TrajetCompose::TrajetCompose(const char* villeDep, const char* villeArr, Trajet** pListTrajets, int pNbTrajets)
    : Trajet(villeDep, villeArr) 
{
    nbTrajets = pNbTrajets;
    listTrajets = new Trajet*[nbTrajets]; 

    for (int i = 0; i < nbTrajets; ++i) {
        listTrajets[i] = pListTrajets[i];
    }
}

TrajetCompose::~TrajetCompose() {
    for (int i = 0; i < nbTrajets; ++i) {
        delete listTrajets[i]; 
    }
    delete[] listTrajets; 
}

void TrajetCompose::afficher() const {
    for (int i=0; i<nbTrajets-1, i++)
    {
        Trajet::afficher(); 
        cout << " en " << moyen << " -";
    }
    Trajet::afficher(); 
    cout << " en " << moyen << endl;
        
}