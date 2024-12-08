#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "trajetSimple.h"
#include "trajetCompose.h"
#include "trajet.h"

class Catalogue {
public:
    Catalogue();
    ~Catalogue();

    void ajouterTrajet(Trajet* trajet);
    void afficher() const;
    bool supprimerTrajet(int index);
    void rechercher(const char* villeDepart, const char* villeArrivee) const;
    

private:
    Trajet** catalogue;
    int capacite;
    int nbTrajets;

    void findPaths(const char* currentCity, const char* destinationCity, Trajet**& currentPath, int* length, Trajet***& allPaths, int* amount, int*& lengths) const;
};

#endif
