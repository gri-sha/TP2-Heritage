#include "catalogue.h"
#include "trajet.h"
#include "trajetCompose.h"
#include "trajetSimple.h"
#include <cstring>
#include <iostream>
#include <limits>
using namespace std;

// Input constants
#define SMALL_INPUT 3                                 // because we need to see input of improper length
#define MAX_NUM_LENGTH 11                             // length of max int value if 32 bit (we could use small input instead, but we leave it for future)
#define VILLE_MAX 50                                  // max length of city name
#define MOYEN_MAX 30                                  // max length of transport name
#define STREAM_SIZE numeric_limits<streamsize>::max() // standert max length of line input

// Catalogue constants
#define START_AMOUNT_TR 30 // max number of sub trips in a trip (rewrite fully dynamically)

void readName(char *str, size_t maxVal, const char *inputPhrase, const char *errorPhrase)
{
	bool propre = true;
	do
	{
		cout << inputPhrase;
		if (!(cin.get(str, maxVal)))
		{
			cin.clear();
			cout << errorPhrase << endl;
			propre = false;
		}
		else
		{
			propre = true;
		}
		cin.ignore(STREAM_SIZE, '\n');
	} while (!propre);
}

void readNumber(int *num, const char *inputPhrase, const char *errorPhrase) {
    bool propre = true;
    do
    {
        cout << inputPhrase;
        if (!(cin >> *num))
		{
			cin.clear(); // remove error messages
            cout << errorPhrase << endl;
			propre = false;
		}
		else
		{
			propre = true;
		}
		cin.ignore(STREAM_SIZE, '\n');
    } while(!propre);
}

void afficherMenu(int status)
{
	if (status)
	{
		cout << endl;
		cout << "=== Menu Catalogue ===" << "\r\n";
		cout << "1. Ajouter un trajet simple" << "\r\n";
		cout << "2. Ajouter un trajet compose" << "\r\n";
		cout << "3. Supprimer un trajet" << "\r\n";
		cout << "4. Afficher le catalogue" << "\r\n";
		cout << "5. Rechercher un trajet" << "\r\n";
		cout << "6. Quitter" << "\r\n";
	}
}

int main()
{
	Catalogue catalogue;
	int choix;
	int status = 1;

	do
	{
		afficherMenu(status);
        readNumber(&choix, "Choisissez une option : ", "Option invalide.");

		switch (choix)
		{
		// Ajouter un trajet simple
		case 1:
		{
			char villeDep[VILLE_MAX], villeArr[VILLE_MAX], moyen[MOYEN_MAX];
			readName(villeDep, VILLE_MAX, "Ville de depart : ", "Input Invalide. Veuillez reessayer. ");
			readName(villeArr, VILLE_MAX, "Ville d'arrivee : ", "Input Invalide. Veuillez reessayer. ");
			readName(moyen, MOYEN_MAX, "Moyen de transport : ", "Input Invalide. Veuillez reessayer. ");
			catalogue.ajouterTrajet(new TrajetSimple(villeDep, villeArr, moyen));
			cout << "Trajet simple ajoute !" << "\r\n";
			status = 1;
			break;
		}

		// Ajouter un trajet compose
		case 2:
		{
			char villeDep[VILLE_MAX], villeArr[VILLE_MAX];
			char villeDep_sousTrajet[VILLE_MAX], villeArr_sousTrajet[VILLE_MAX], moyen_sousTrajet[MOYEN_MAX];
			int  nbTrajets = 0;

			TrajetSimple **listeTrajetsSimples = new TrajetSimple *[START_AMOUNT_TR];
			int maxNbTrajets = START_AMOUNT_TR;

			readName(villeDep_sousTrajet, VILLE_MAX, "Entrez la ville de depart : ", "Input Invalide. Veuillez reessayer. ");
			strcpy(villeDep, villeDep_sousTrajet);

			bool stop_saisie = false;
			char reponse[SMALL_INPUT];
			while (!stop_saisie)
			{
				if (nbTrajets == maxNbTrajets)
				{
#ifdef MAP
					cout << "Start reallocation" << endl;
#endif
					maxNbTrajets *= 2;
					TrajetSimple **newListTrajetsSimples = new TrajetSimple *[maxNbTrajets];
					for (int i = 0; i < nbTrajets; ++i)
					{
						newListTrajetsSimples[i] = listeTrajetsSimples[i];
#ifdef MAP
						cout << "Sous trajet : " << i << endl;
#endif
					}
					delete[] listeTrajetsSimples;
					listeTrajetsSimples = newListTrajetsSimples;
				}

				readName(villeArr_sousTrajet, VILLE_MAX, "Entrez la ville de l'etape suivante : ", "Input Invalide. Veuillez reessayer. ");
				readName(moyen_sousTrajet, MOYEN_MAX, "Entrez le moyen de transport envisage pour cette etape : ", "Input Invalide. Veuillez reessayer. ");
				readName(reponse, SMALL_INPUT, "Voulez-vous ajouter une etape ? (y/n) : ", "Input Invalide. Veuillez reessayer. ");

				if (strlen(reponse) <= 1 && (reponse[0] == 'n' || reponse[0] == 'N'))
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
		case 3:
		{
			if (catalogue.getNbTrajets() == 0)
			{
				cout << "Le catalogue est vide. Il n'est pas possible de supprimer un trajet." << endl;
				break;
			}
            int index;
            readNumber(&index, "Index du trajet a supprimer (les numeros de trajets sont ceux du catalogue) : ", "Input Invalide. Veuillez reessayer.");

            if (catalogue.supprimerTrajet(index))
            {
                cout << "Trajet supprime avec succes." << endl;
            }
            else
            {
                cout << "Erreur : index invalide." << endl;
            }
			status = 1;
			break;
		}

		// Afficher le catalogue
		case 4:
		{
			if (catalogue.getNbTrajets() == 0)
			{
				cout << endl << "Le catalogue est vide." << endl;
				break;
			}
			cout << "Catalogue actuel :" << endl;
			catalogue.afficher();
			status = 1;
			break;
		}

		// Rechercher un trajet
		case 5:
		{
			char villeDep[VILLE_MAX], villeArr[VILLE_MAX];
			readName(villeDep, VILLE_MAX, "Ville de depart : ", "Input Invalide. Veuillez reessayer : ");
			readName(villeArr, VILLE_MAX, "Ville d'arrivee : ", "Input Invalide. Veuillez reessayer : ");
			cout << "Resultats de la recherche :" << endl;
			catalogue.rechercher(villeDep, villeArr);
			status = 1;
			break;
		}

		// Quitter
		case 6:
			cout << "Au revoir !" << endl;
			status = 1;
			break;

		default:
			cout << "Option invalide." << endl;
			status = 0;
			break;
		}
	} while (choix != 6);

	return 0;
}
