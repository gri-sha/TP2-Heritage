#include <iostream>
#include <string>
#include "catalogue.h"
#include "trajet.h"
#include "trajetSimple.h"
#include "trajetCompose.h"
using namespace std;

#define VILLE_MAX 50
#define MOYEN_MAX 30

void afficherMenu(int status)
{
    if (status)
    {
        cout << "\n=== Menu Catalogue ===" << "\r\n";
        cout << "1. Ajouter un trajet simple" << "\r\n";
        cout << "2. Ajouter un trajet compose" << "\r\n";
        cout << "3. Supprimer un trajet" << "\r\n";
        cout << "4. Afficher le catalogue" << "\r\n";
        cout << "5. Rechercher un trajet" << "\r\n";
        cout << "6. Quitter" << "\r\n";
        cout << "Choisissez une option : ";
    }
}

int main()
{
    Catalogue catalogue;
    char choix;
    int status = 1;

    do
    {
        afficherMenu(status);
        cin >> choix;

        switch (choix)
        {

        // Ajouter un trajet simple
        case '1':
        {
            char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
            cout << "Ville de depart : ";
            cin >> villeDep;
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cout << "Moyen de transport : ";
            cin >> moyen;
            catalogue.ajouterTrajet(new TrajetSimple(villeDep, villeArr, moyen));
            cout << "Trajet simple ajoute !" << "\r\n";
            status = 1;
            break;
        }

        // Ajouter un trajet compose
        case '2':
        {
            int nbSousTrajets;
            cout << "Nombre de sous-trajets : ";
            cin >> nbSousTrajets;

            char villeDepPrincipale[VILLE_MAX], villeArrPrincipale[VILLE_MAX];
            TrajetSimple **sousTrajets = new TrajetSimple *[nbSousTrajets];
            for (int i = 0; i < nbSousTrajets; ++i)
            {
                char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
            rewrite:
                cout << "Sous-trajet " << i + 1 << " - Ville de depart : ";
                cin >> villeDep;
                if (i == 0)
                    strcpy(villeDepPrincipale, villeDep);

                cout << "Sous-trajet " << i + 1 << " - Ville d'arrivee : ";
                cin >> villeArr;
                if (i == nbSousTrajets - 1)
                    strcpy(villeArrPrincipale, villeArr);

                cout << "Sous-trajet " << i + 1 << " - Moyen de transport : ";
                cin >> moyen;

                if (i > 0 and strcmp(sousTrajets[i - 1]->getVilleArrivee(), villeDep) != 0)
                {
                    cout << "Ville d'arrivee et ville de depart non coherents!" << endl;
                    goto rewrite;
                }
                
                sousTrajets[i] = new TrajetSimple(villeDep, villeArr, moyen);
            }

            catalogue.ajouterTrajet(new TrajetCompose(villeDepPrincipale, villeArrPrincipale, sousTrajets, nbSousTrajets));
            cout << "Trajet compose ajoute !" << "\r\n";
            status = 1;
            break;
        }

        // Supprimer un trajet
        case '3':
        {
            int index;
            cout << "Index du trajet a supprimer (les numeros de trajets sont ceux du catalogue) : ";
            cin >> index;
            if (catalogue.supprimerTrajet(index))
            {
                cout << "Trajet supprime avec succes." << "\r\n";
            }
            else
            {
                cout << "Erreur : index invalide." << "\r\n";
            }
            status = 1;
            break;
        }

        // Afficher le catalogue
        case '4':
        {
            cout << "Catalogue actuel :" << "\r\n";
            catalogue.afficher();
            status = 1;
            break;
        }

        // Rechercher un trajet
        case '5':
        {
            char villeDep[VILLE_MAX], villeArr[VILLE_MAX];
            cout << "Ville de depart : ";
            cin >> villeDep;
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cout << "Resultats de la recherche :" << "\r\n";
            catalogue.rechercher(villeDep, villeArr);
            status = 1;
            break;
        }

        // Quitter
        case '6':
            cout << "Au revoir !" << "\r\n";
            status = 1;
            break;

        default:
            cout << "Option invalide. Veuillez reessayer : ";
            status = 0;
            break;
        }
    } while (choix != '6');

    return 0;
}
