#include <iostream>
#include <string>
#include "catalogue.h"
#include "trajet.h"
#include "trajetSimple.h"
#include "trajetCompose.h"
using namespace std;

void afficherMenu() {
    cout << "\n=== Menu Catalogue ===" << "\r\n";
    cout << "1. Ajouter un trajet simple" << "\r\n";
    cout << "2. Ajouter un trajet compose" << "\r\n";
    cout << "3. Supprimer un trajet" << "\r\n";
    cout << "4. Afficher le catalogue" << "\r\n";
    cout << "5. Rechercher un trajet" << "\r\n";
    cout << "6. Quitter" << "\r\n";
    cout << "Choisissez une option : ";
}

int main() {
    Catalogue catalogue;
    int choix;

    do {
        afficherMenu();
        cin >> choix;

        switch (choix) {

        // Ajouter un trajet simple
        case 1: { 
            string villeDep, villeArr, moyen;
            cout << "Ville de depart : ";
            cin >> villeDep;
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cout << "Moyen de transport : ";
            cin >> moyen;
            catalogue.ajouterTrajetSimple(new TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str()));
            cout << "Trajet simple ajoute !" << "\r\n";
            break;
        }

        // Ajouter un trajet compose
        case 2: { 
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

            catalogue.ajouterTrajetCompose(new TrajetCompose(villeDepPrincipale.c_str(), villeArrPrincipale.c_str(), sousTrajets, nbSousTrajets));
            cout << "Trajet compose ajoute !" << "\r\n";
            break;
        }

        // Supprimer un trajet
        case 3: { 
            int index;
            cout << "Index du trajet a supprimer (les numeros de trajets sont ceux du catalogue) : ";
            cin >> index;
            if (catalogue.supprimerTrajet(index)) {
                cout << "Trajet supprime avec succes." << "\r\n";
            } else {
                cout << "Erreur : index invalide." << "\r\n";
            }
            break;
        }

        // Afficher le catalogue
        case 4: { 
            cout << "Catalogue actuel :" << "\r\n";
            catalogue.afficher();
            break;
        }

        // Rechercher un trajet
        case 5: { 
            string villeDep, villeArr;
            cout << "Ville de depart : ";
            cin >> villeDep;
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cout << "Resultats de la recherche :" << "\r\n";
            catalogue.rechercher(villeDep.c_str(), villeArr.c_str());
            break;
        }

        // Quitter
        case 6: 
            cout << "Au revoir !" << "\r\n";
            break;

        default:
            cout << "Option invalide. Veuillez reessayer." << "\r\n";
            break;
        }
    } while (choix != 6);

    return 0;
}
