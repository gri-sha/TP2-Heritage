#include <iostream>
#include <cstring>
#include "TrajetSimple.h"
using namespace std;


TrajetSimple::TrajetSimple(const char* villeDep, const char* villeArr, const char* moyenTransport) : Trajet(villeDep, villeArr) {
    moyen = new char[strlen(moyenTransport) + 1];
    strcpy(moyen, moyenTransport);
    cout << "Construction TrajetSimple" << "\r\n";
}

TrajetSimple::~TrajetSimple() {
    delete[] moyen; 
    cout << "Destruction TrajetSimple" << "\r\n";
}

void TrajetSimple::afficher() const {
    Trajet::afficher(); 
    cout << " en " << moyen << endl;
}