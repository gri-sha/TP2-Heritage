#include <iostream>
#include <cstring>
#include "trajet.h"
using namespace std;

Trajet::Trajet(const char *pVilleDep, const char *pVilleArr)
{
#ifdef MAP
    cout << "Appel de constructeur : Trajet" << endl;
#endif
    villeDep = new char[strlen(pVilleDep) + 1];
    strcpy(villeDep, pVilleDep);
    villeArr = new char[strlen(pVilleArr) + 1];
    strcpy(villeArr, pVilleArr);
}

Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel de destructeur : Trajet" << endl;
#endif
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