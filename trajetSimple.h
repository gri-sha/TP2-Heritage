#ifndef TRAJET_SIMPLE_H
#define TRAJET_SIMPLE_H
#include <istream>
#include <cstring>
#include "trajet.h"

class TrajetSimple: public Trajet {
protected:
    char* villeDep;
    char* villeArr;
    char* moyen;
public:
    TrajetSimple(const char* pVilleDep, const char* pVilleArr, const char* pMoyen);
    virtual ~TrajetSimple();
    virtual void afficher();
};
#endif