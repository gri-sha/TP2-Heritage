#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "trajetSimple.h"
#include "trajetCompose.h"

class Catalogue {
public:
    Catalogue();
    ~Catalogue();

    void AjouterTrajetSimple(TrajetSimple* trajet);
    void AjouterTrajetCompose(TrajetCompose* trajet);
    void Afficher() const;
    bool SupprimerTrajet(int index);

private:
    Trajet** catalogue;
    int capacite;
    int nbTrajets;
};

#endif
