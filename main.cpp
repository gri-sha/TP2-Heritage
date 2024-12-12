#include <iostream>
#include <cstring>
#include "catalogue.h"
#include "trajet.h"
#include "trajetSimple.h"
#include "trajetCompose.h"
using namespace std;

// Input constants
#define SMALL_INPUT 3     // because we need to see input of improper length
#define MAX_NUM_LENGTH 11 // length of max int value if 32 bit (we could use small input instead, but we leave it for future)
#define VILLE_MAX 50      // max length of city name
#define MOYEN_MAX 30      // max length of transport name
#define STREAM_SIZE 2048  // standert max length of line input (better to use numeric limits, but its not allowed)

// Catalogue constants
#define START_AMOUNT_TR 30 // max number of sub trips in a trip (rewrite fully dynamically)

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
        cin.get(buffer, SMALL_INPUT);
        cin.ignore(STREAM_SIZE, '\n');
        choix = buffer[0];
        if (strlen(buffer) != 1)
        {
            choix = 'A'; // there is no case for this value
        }

        switch (choix)
        {
        // Ajouter un trajet simple
        case '1':
        {
            char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
            cout << "Ville de depart : ";
            cin.get(villeDep, VILLE_MAX);
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Ville d'arrivee : ";
            cin.get(villeArr, VILLE_MAX);
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Moyen de transport : ";
            cin.get(moyen, MOYEN_MAX);
            cin.ignore(STREAM_SIZE, '\n');
            catalogue.ajouterTrajet(new TrajetSimple(villeDep, villeArr, moyen));
            cout << "Trajet simple ajoute !" << "\r\n";
            status = 1;
            break;
        }

        // Ajouter un trajet compose
        case '2':
        {

            char villeDep[VILLE_MAX], villeArr[VILLE_MAX];
            char villeDep_sousTrajet[VILLE_MAX], villeArr_sousTrajet[VILLE_MAX], moyen_sousTrajet[MOYEN_MAX];
            int nbTrajets = 0;
            TrajetSimple **listeTrajetsSimples = new TrajetSimple *[START_AMOUNT_TR];

            cout << "Entrez la ville de depart : ";
            cin.get(villeDep_sousTrajet, VILLE_MAX);
            cin.ignore(STREAM_SIZE, '\n');
            strcpy(villeDep, villeDep_sousTrajet);

            bool stop_saisie = false;
            char reponse[SMALL_INPUT];
            while (!stop_saisie)
            {
                cout << "Entrez la ville de l'etape suivante : ";
                cin.get(villeArr_sousTrajet, VILLE_MAX);
                cin.ignore(STREAM_SIZE, '\n');
                cout << "Entrez le moyen de transport envisage pour cette etape : ";
                cin.get(moyen_sousTrajet, MOYEN_MAX);
                cin.ignore(STREAM_SIZE, '\n');
                cout << "Voulez-vous ajouter une etape ? (y/n)";
                cin.get(reponse, SMALL_INPUT);
                cin.ignore(STREAM_SIZE, '\n');
                if (strlen(reponse) == 1 && (reponse[0] == 'n' || reponse[0] == 'N'))
                {
                    strcpy(villeArr, villeArr_sousTrajet);
                    stop_saisie = true;
                }
                listeTrajetsSimples[nbTrajets] = new TrajetSimple(villeDep_sousTrajet, villeArr_sousTrajet, moyen_sousTrajet);
                ++nbTrajets;
                strcpy(villeDep_sousTrajet, villeArr_sousTrajet);
            }

            TrajetCompose *trajetCompose = new TrajetCompose(villeDep, villeArr, listeTrajetsSimples, nbTrajets);

#ifdef MAP
            cout << trajetCompose->getVilleDepart() << endl;
            cout << trajetCompose->getVilleArrivee() << endl;
#endif

            catalogue.ajouterTrajet(trajetCompose);
            delete[] listeTrajetsSimples;
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
            bool suppressionReussie = false;

            while (!suppressionReussie)
            {
                cout << "Index du trajet a supprimer (les numeros de trajets sont ceux du catalogue) : ";
                cin.get(buffer, MAX_NUM_LENGTH);
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
                    suppressionReussie = true;
                }
                else
                {
                    cout << "Erreur : index invalide." << "\r\n";
                }
            }
            status = 1;
            break;
        }

        // Afficher le catalogue
        case '4':
        {
            if (catalogue.getNbTrajets() == 0)
            {
                cout << "Le catalogue est vide." << endl;
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
            cin.get(villeDep, VILLE_MAX);
            cin.ignore(STREAM_SIZE, '\n');
            cout << "Ville d'arrivee : ";
            cin.get(villeArr, VILLE_MAX);
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
