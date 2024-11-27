#ifndef TRAJET_COMPOSEE_H
#define TRAJET_COMPOSEE_H
#include <istream>
#include <cstring>
#include "trajet.h"

class TrajetComposee: public Trajet {
protected:
    Trajet** trajets;
    char* moyens[];
public:
    TrajetComposee(const char* pVilleDep, const char* pVilleArr, const char* pMoyen);
    virtual ~TrajetComposee();
    virtual void afficher();
};
#endif