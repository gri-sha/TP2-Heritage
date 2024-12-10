#include <iostream>
#include <cstring>
#include "catalogue.h"
#include "trajet.h"
#include "trajetSimple.h"
#include "trajetCompose.h"
using namespace std;

#define SMALL_INPUT 3
#define VILLE_MAX 50
#define MOYEN_MAX 30
#define MAX_NUM_LENGTH 10 // length of max int value if 32 bit
#define STREAM_SIZE 2048

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
    char buffer[SMALL_INPUT];
    int status = 1;

    do
    {
        afficherMenu(status);
        cin >> buffer;
        cin.ignore(STREAM_SIZE, '\n');
        choix = buffer[0];
        if (buffer[1] != '\0')
        {
            choix = 'A';  // there is no case for this value
        }

        switch (choix)
        {
        // Ajouter un trajet simple
        case '1':
        {
            char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
            cout << "Ville de depart : ";
            cin >> villeDep;
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Moyen de transport : ";
            cin >> moyen;
            cin.ignore(STREAM_SIZE, '\n');
            catalogue.ajouterTrajet(new TrajetSimple(villeDep, villeArr, moyen));
            cout << "Trajet simple ajoute !" << "\r\n";
            status = 1;
            break;
        }

        // Ajouter un trajet compose
        case '2':
        {
            char buffer[MAX_NUM_LENGTH];
        enter_nombre:
            cout << "Nombre de sous-trajets : ";
            cin >> buffer;
            cin.ignore(STREAM_SIZE, '\n');
            int nbSousTrajets = 0;
            int ord = 1;
            for (int i = strlen(buffer) - 1; i >= 0; i--)
            {
                if (buffer[i] - '0' <= 9)
                {
                    nbSousTrajets += (buffer[i] - '0') * ord;
                    ord *= 10;
                }
                else
                {
                    nbSousTrajets = 0;
                    break;
                }
            }

            if (nbSousTrajets <= 1)
            {
                cout << "Valeur Invalide! Tapez un nombre > 1" << endl;
                goto enter_nombre;
            }

            if (nbSousTrajets > 10)
            {
                char reponse;
            validate:
                cout << "Etes vous sur(e)? (y/n)" << endl;
                cin >> reponse;
                cin.ignore(STREAM_SIZE, '\n');
                if (reponse == 'n' or reponse == 'N')
                {
                    goto enter_nombre;
                }
                else if (reponse == 'y' or reponse == 'Y')
                {
                }
                else
                {
                    goto validate;
                }
            }

            char villeDepPrincipale[VILLE_MAX], villeArrPrincipale[VILLE_MAX];
            TrajetSimple **sousTrajets = new TrajetSimple *[nbSousTrajets];
            for (int i = 0; i < nbSousTrajets; ++i)
            {
                char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
            rewrite:
                cout << "Sous-trajet " << i + 1 << " - Ville de depart : ";
                cin >> villeDep;
                cin.ignore(STREAM_SIZE, '\n');
                if (i == 0)
                    strcpy(villeDepPrincipale, villeDep);

                cout << "Sous-trajet " << i + 1 << " - Ville d'arrivee : ";
                cin >> villeArr;
                cin.ignore(STREAM_SIZE, '\n');
                if (i == nbSousTrajets - 1)
                    strcpy(villeArrPrincipale, villeArr);

                cout << "Sous-trajet " << i + 1 << " - Moyen de transport : ";
                cin >> moyen;
                cin.ignore(STREAM_SIZE, '\n');

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
            if (catalogue.getNbTrajets() == 0)
            {
                cout << "Le catalogue est vide. Il n'est pas possible de supprimer un trajet." << endl;
                break;
            }
            char buffer[MAX_NUM_LENGTH];
        enter_index:
            cout << "Index du trajet a supprimer (les numeros de trajets sont ceux du catalogue) : ";
            cin >> buffer;
            cin.ignore(STREAM_SIZE, '\n');

            int index = 0;
            int ord = 1;
            for (int i = strlen(buffer) - 1; i >= 0; i--)
            {
                if (buffer[i] - '0' <= 9)
                {
                    index += (buffer[i] - '0') * ord;
                    ord *= 10;
                }
            }

            if (catalogue.supprimerTrajet(index))
            {
                cout << "Trajet supprime avec succes." << "\r\n";
            }
            else
            {
                cout << "Erreur : index invalide." << "\r\n";
                goto enter_index;
            }
            status = 1;
            break;
        }

        // Afficher le catalogue
        case '4':
        {
            if (catalogue.getNbTrajets() == 0)
            {
                cout << "Le catalogue est vide. Il n'est pas possible de supprimer un trajet." << endl;
                break;
            }
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
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Ville d'arrivee : ";
            cin >> villeArr;
            cin.ignore(STREAM_SIZE, '\n');
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
