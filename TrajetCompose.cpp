#include <iostream>
#include "TrajetCompose.h"
using namespace std;

TrajetCompose::TrajetCompose(Trajet pListTrajets[], int pNbTrajets) {
    longeur = pNbTrajets;
    listTrajets = new Trajet[longeur]; 

    for (int i = 0; i < longeur; ++i) {
        listTrajets[i] = pListTrajets[i];
    }

    villeDep = listTrajets[0].getVilleDep();
    villeDep = listTrajets[longeur-1].getVilleArr();

    cout << "Construction TrajetComposee" << "\r\n";
}

TrajetCompose::~TrajetCompose() {
    for (int i = 0; i < longeur; ++i) {
        delete listTrajets[i]; 
    }
    delete[] listTrajets; 
    cout << "Destruction TrajetComposee" << "\r\n";
}

void TrajetCompose::afficher() const {
    for (int i=0; i<longeur-1, i++) {
        Trajet::afficher(); 
        cout << " en " << moyen << " -";
    }
    Trajet::afficher(); 
    cout << " en " << moyen << endl;
    
}