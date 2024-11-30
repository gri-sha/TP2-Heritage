#include <iostream>
#include <cstring>
#include "trajet.h"
#include "trajetSimple.h"
#include "TrajetCompose.h"
using namespace std;

bool trajet = false;
bool trajetSimple = false;
bool trajetCompose = true;

int main(){

    if (trajet)
    {
        string villeDep, villeArr, moyen;

        cout << "Ville de depart : ";
        cin >> villeDep;

        cout << "Ville d'arrivee : ";
        cin >> villeArr;
        
        Trajet tj = Trajet(villeDep.c_str(), villeArr.c_str());
        tj.afficher();
        cout << "Trajet ajoute !" << endl;
    }
    
    if (trajetSimple) 
    {
        string villeDep, villeArr, moyen;

        cout << "Ville de depart : ";
        cin >> villeDep;

        cout << "Ville d'arrivee : ";
        cin >> villeArr;

        cout << "Moyen de transport : ";
        cin >> moyen;
        
        TrajetSimple ts = TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str());
        ts.afficher();
        cout << "Trajet simple ajoute !" << endl;
    }
    
    if (trajetCompose)
    {
        int nbSousTrajets;
        cout << "Nombre de sous-trajets : ";
        cin >> nbSousTrajets;

        string villeDepPrincipale, villeArrPrincipale;
        TrajetSimple** sousTrajets = new TrajetSimple*[nbSousTrajets];

        for (int i = 0; i < nbSousTrajets; ++i) {

            string villeDep, villeArr, moyen;
        
            cout << "Sous-trajet " << i + 1 << " - Ville de depart : ";
            cin >> villeDep;
            if (i==0) villeDepPrincipale = villeDep;

            cout << "Sous-trajet " << i + 1 << " - Ville d'arrivee : ";
            cin >> villeArr;
            if (i==nbSousTrajets-1) villeArrPrincipale = villeArr;

            cout << "Sous-trajet " << i + 1 << " - Moyen de transport : ";
            cin >> moyen;

            sousTrajets[i] = new TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str());
        }

        // catalogue.AjouterTrajetCompose(new TrajetCompose(villeDep.c_str(), villeArr.c_str(), sousTrajets));

        TrajetCompose tc = TrajetCompose(villeDepPrincipale.c_str(), villeArrPrincipale.c_str(), sousTrajets, nbSousTrajets);
        tc.afficher();
        cout << "Trajet compose ajoute !" << endl;
        delete[] sousTrajets; // Les sous-trajets sont déjà gérés par TrajetCompose
    }

    return 0;
}
