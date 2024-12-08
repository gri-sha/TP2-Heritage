#include <iostream>
#include <cstring>
#include "trajet.h"
using namespace std;

Trajet::Trajet(const char *pVilleDep, const char *pVilleArr)
{
    villeDep = new char[strlen(pVilleDep) + 1];
    strcpy(villeDep, pVilleDep);
    villeArr = new char[strlen(pVilleArr) + 1];
    strcpy(villeArr, pVilleArr);
}

Trajet::~Trajet()
{
    delete[] villeDep;
    delete[] villeArr;
}
void Trajet::afficher() const
{
    cout << "de " << villeDep << " a " << villeArr << " ";
}

char *Trajet::getVilleDepart() const
{
    return villeDep;
}

char *Trajet::getVilleArrivee() const
{
    return villeArr;
}