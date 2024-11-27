#include <iostream>
#include <cstring>
#include "trajetSimple.h"
using namespace std;


TrajetSimple::TrajetSimple(const char* villeDep, const char* villeArr, const char* moyenTransport)
    : Trajet(villeDep, villeArr)
{
    moyen = new char[strlen(moyenTransport) + 1];
    strcpy(moyen, moyenTransport);
}

TrajetSimple::~TrajetSimple() {
    delete[] moyen; 
}

void TrajetSimple::afficher() const {
    Trajet::afficher(); 
    cout << " en " << moyen << endl;
}