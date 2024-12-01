#include <iostream>
#include <cstring>
#include "trajet.h"
#include "trajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"
using namespace std;

bool trajet = false;
bool trajetSimple = false;
bool trajetCompose = false;
bool catalogue = true;

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

        TrajetCompose tc = TrajetCompose(villeDepPrincipale.c_str(), villeArrPrincipale.c_str(), sousTrajets, nbSousTrajets);
        tc.afficher();
        cout << "Trajet compose ajoute !" << endl;
    }


    if (catalogue){
        // Construction catalogue
        Catalogue cat = Catalogue();

        // trajet simple
        string villeDep, villeArr, moyen;
        cout << "Ville de depart : ";
        cin >> villeDep;
        cout << "Ville d'arrivee : ";
        cin >> villeArr;
        cout << "Moyen de transport : ";
        cin >> moyen;
        TrajetSimple ts = TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str());
        cout << "Trajet simple ajoute !" << endl;
        cat.ajouterTrajetSimple(&ts);

        // trajet composé
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
        TrajetCompose tc = TrajetCompose(villeDepPrincipale.c_str(), villeArrPrincipale.c_str(), sousTrajets, nbSousTrajets);
        cout << "Trajet compose ajoute !" << endl;
        cat.ajouterTrajetCompose(&tc);

        cat.afficher();
    
        // cat.ajouterTrajetCompose(new TrajetCompose(villeDep.c_str(), villeArr.c_str(), sousTrajets));
    }
    return 0;
}
