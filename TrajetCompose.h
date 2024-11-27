#ifndef TRAJET_COMPOSE_H
#define TRAJET_COMPOSE_H
#include <istream>
#include <cstring>
#include "Trajet.h"

class TrajetCompose: public Trajet {
protected:
    Trajet* listTrajets;
    char* moyens[];
public:
    TrajetCompose(const char* pVilleDep, const char* pVilleArr, const char* pMoyen);
    virtual ~TrajetCompose();
    virtual void afficher() const;
};
#endif