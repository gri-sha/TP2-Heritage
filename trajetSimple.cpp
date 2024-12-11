#include <iostream>
#include <cstring>
#include "trajetSimple.h"
using namespace std;

TrajetSimple::TrajetSimple(const char *villeDep, const char *villeArr, const char *moyenTransport) : Trajet(villeDep, villeArr)
{
#ifdef MAP
    cout << "Appel de constructeur : TrajetSimple" << endl;
#endif
    moyen = new char[strlen(moyenTransport) + 1];
    strcpy(moyen, moyenTransport);
}

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
    cout << "Appel de destructeur : TrajetSimple" << endl;
#endif
    delete[] moyen;
}

void TrajetSimple::afficher() const
{
    Trajet::afficher();
    cout << "en " << moyen;
}