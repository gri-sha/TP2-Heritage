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

void Catalogue::ajouterTrajetSimple(TrajetSimple* trajet) {
    // gestion de la memoire 
    if (nbTrajets == capacite) {
        capacite *= 2;
        Trajet** tmp = new Trajet*[capacite];
        for (int i = 0; i < nbTrajets; ++i) {
            tmp[i] = catalogue[i];
        }
        delete[] catalogue;
        catalogue = tmp;
    }
    // ajout du trajet
    catalogue[nbTrajets++] = trajet;
}

void Catalogue::ajouterTrajetCompose(TrajetCompose* trajet) {
    // gestion de la memoire 
    if (nbTrajets == capacite) {
        capacite *= 2;
        Trajet** tmp = new Trajet*[capacite];
        for (int i = 0; i < nbTrajets; ++i) {
            tmp[i] = catalogue[i];
        }
        delete[] catalogue;
        catalogue = tmp;
    }
    // ajout du trajet
    catalogue[nbTrajets++] = trajet;
}

void Catalogue::afficher() const {
    for (int i = 0; i < nbTrajets; ++i) {
        cout << i+1 << " : ";
        catalogue[i]->afficher();
        cout<<"\r\n";
    }
}

bool Catalogue::supprimerTrajet(int index) {
    index-=1;
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


void Catalogue::rechercher(const char* villeDepart, const char* villeArrivee) const {
    cout << "Recherche de trajets de " << villeDepart << " a " << villeArrivee << ":" << "\r\n";
    bool trajetTrouve = false;

    for (int i = 0; i < nbTrajets; ++i) {
        if (strcmp(catalogue[i]->getVilleDepart(), villeDepart) == 0 && 
            strcmp(catalogue[i]->getVilleArrivee(), villeArrivee) == 0) {
            trajetTrouve = true;
            catalogue[i]->afficher(); 
        }
    }

    if (!trajetTrouve) {
        cout << "Aucun trajet trouve pour cette recherche." << "\r\n";
    }
}

