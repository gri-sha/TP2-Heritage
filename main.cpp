#include <iostream>
#include <string>
#include "catalogue.h"
#include "trajetSimple.h"
#include "trajetCompose.h"
using namespace std;

void AfficherMenu() {
    cout << "\n=== Menu Catalogue ===" << endl;
    cout << "1. Ajouter un trajet simple" << endl;
    cout << "2. Ajouter un trajet composé" << endl;
    cout << "3. Supprimer un trajet" << endl;
    cout << "4. Afficher le catalogue" << endl;
    cout << "5. Rechercher un trajet" << endl;
    cout << "6. Quitter" << endl;
    cout << "Choisissez une option : ";
}

int main() {
    Catalogue catalogue;
    int choix;

    do {
        AfficherMenu();
        cin >> choix;

        switch (choix) {
        case 1: { // Ajouter un trajet simple
            string villeDep, villeArr, moyen;
            cout << "Ville de départ : ";
            cin >> villeDep;
            cout << "Ville d'arrivée : ";
            cin >> villeArr;
            cout << "Moyen de transport : ";
            cin >> moyen;
            catalogue.AjouterTrajetSimple(new TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str()));
            cout << "Trajet simple ajouté !" << endl;
            break;
        }
        case 2: { // Ajouter un trajet composé
            int nbSousTrajets;
            cout << "Nombre de sous-trajets : ";
            cin >> nbSousTrajets;

            TrajetSimple** sousTrajets = new TrajetSimple*[nbSousTrajets];
            for (int i = 0; i < nbSousTrajets; ++i) {
                string villeDep, villeArr, moyen;
                cout << "Sous-trajet " << i + 1 << " - Ville de départ : ";
                cin >> villeDep;
                cout << "Sous-trajet " << i + 1 << " - Ville d'arrivée : ";
                cin >> villeArr;
                cout << "Sous-trajet " << i + 1 << " - Moyen de transport : ";
                cin >> moyen;
                sousTrajets[i] = new TrajetSimple(villeDep.c_str(), villeArr.c_str(), moyen.c_str());
            }

            string villeDep, villeArr;
            cout << "Ville de départ du trajet composé : ";
            cin >> villeDep;
            cout << "Ville d'arrivée du trajet composé : ";
            cin >> villeArr;
            catalogue.AjouterTrajetCompose(new TrajetCompose(villeDep.c_str(), villeArr.c_str(), sousTrajets, nbSousTrajets));
            cout << "Trajet composé ajouté !" << endl;
            delete[] sousTrajets; // Les sous-trajets sont déjà gérés par TrajetCompose
            break;
        }
        case 3: { // Supprimer un trajet
            int index;
            cout << "Index du trajet à supprimer (commence à 0) : ";
            cin >> index;
            if (catalogue.SupprimerTrajet(index)) {
                cout << "Trajet supprimé avec succès." << endl;
            } else {
                cout << "Erreur : index invalide." << endl;
            }
            break;
        }
        case 4: { // Afficher le catalogue
            cout << "Catalogue actuel :" << endl;
            catalogue.Afficher();
            break;
        }
        case 5: { // Rechercher un trajet
            string villeDep, villeArr;
            cout << "Ville de départ : ";
            cin >> villeDep;
            cout << "Ville d'arrivée : ";
            cin >> villeArr;
            cout << "Résultats de la recherche :" << endl;
            catalogue.Rechercher(villeDep.c_str(), villeArr.c_str());
            break;
        }
        case 6: // Quitter
            cout << "Au revoir !" << endl;
            break;
        default:
            cout << "Option invalide. Veuillez réessayer." << endl;
            break;
        }
    } while (choix != 6);

    return 0;
}
