#ifndef TRAJET_H
#define TRAJET_H
#include <istream>
#include <cstring>

class Trajet {
protected:
    char* villeDep;
    char* villeArr;
    int longeur;
public:
    Trajet(const char* pVilleDep, const char* pVilleArr);
    virtual ~Trajet();
    void afficher() const;
    char* getVilleDep() const;
    char* getVilleArr() const;

};
#endif