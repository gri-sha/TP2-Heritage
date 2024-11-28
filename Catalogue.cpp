#include <iostream>
#include "catalogue.h"
using namespace std;

Catalogue::Catalogue() 
    : capacite(10), nbTrajets(0) {
    catalogue = new Trajet*[capacite];
}

Catalogue::~Catalogue() {
    for (int i = 0; i < nbTrajets; ++i) {
        delete catalogue[i];
    }
    delete[] catalogue;
}

void Catalogue::AjouterTrajetSimple(TrajetSimple* trajet) {
    if (nbTrajets == capacite) {
        capacite *= 2;
        Trajet** tmp = new Trajet*[capacite];
        for (int i = 0; i < nbTrajets; ++i) {
            tmp[i] = catalogue[i];
        }
        delete[] catalogue;
        catalogue = tmp;
    }
    catalogue[nbTrajets++] = trajet;
}

void Catalogue::AjouterTrajetCompose(TrajetCompose* trajet) {
    AjouterTrajetSimple(trajet);
}

void Catalogue::Afficher() const {
    for (int i = 0; i < nbTrajets; ++i) {
        cout << i+1 << " : ";
        catalogue[i]->Afficher();
    }
}

bool Catalogue::SupprimerTrajet(int index) {
    if (index < 0 || index >= nbTrajets) {
        return false;
    }
    delete catalogue[index];
    for (int i = index; i < nbTrajets - 1; ++i) {
        catalogue[i] = catalogue[i + 1];
    }
    nbTrajets--;
    return true;
}
