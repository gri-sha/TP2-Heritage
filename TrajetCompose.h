#ifndef TRAJET_COMPOSE_H
#define TRAJET_COMPOSE_H
#include <istream>
#include <cstring>
#include "trajet.h"
#include "trajetSimple.h"

class TrajetCompose: public Trajet {
protected:
    TrajetSimple** listTrajets;
    int nbTrajets;
public:
    TrajetCompose(const char* villeDep, const char* villeArr, TrajetSimple* listTrajets[], int nbTrajets);
    virtual ~TrajetCompose();
    virtual void afficher() const;
    int getNbTrajets() const;
    TrajetSimple** getListTrajets() const;
};
#endif