#ifndef TRAJET_H
#define TRAJET_H
#include <istream>
#include <cstring>

class Trajet {
protected:
    const char* villeDep;
    const char* villeArr;
public:
    Trajet(const char* pVilleDep, const char* pVilleArr);
    virtual ~Trajet();
    void afficher();
};
#endif