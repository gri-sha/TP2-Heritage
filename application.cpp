/*************************************************************************
            Code principal de l'application (fichier main.cpp)
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "TableauDynamique.h"


int main()
{   
    Catalogue catalogue;
    
    int choix=0;
    while (choix != 4)
    {   

        cout << "Comment puis-je vous aider ?" << endl << endl << "\t Je souhaite ajouter un trajet au catalogue => tapez 1" << endl
        << "\t Je souhaite afficher le contenu du catalogue => tapez 2" << endl << "\t Je souhaite rechercher un trajet => tapez 3" << endl << "\t Je souhaite quittez l'application => tapez 4" << endl << endl;

        cin >> choix;
        cout << endl;

        if (choix !=1 && choix !=2 && choix !=3 && choix !=4)
        //----------------------------------  Choix invalide
        {
            cout << endl << "Désolé, je n'ai pas compris votre choix. Veuillez entrer à nouveau un chiffre entre 1 et 4." << endl << endl;
            cin >> choix;
            cout << endl;
        }

        switch (choix)
        {
            // --------------  Ajouter un trajet --------------
            case 1: 
            {   
                cout << "Quel type de trajet souhaitez vous ajouter ? " << endl << endl << "\t Je souhaite ajouter un trajet simple => tapez 1" << endl
                << "\t Je souhaite ajouter un trajet compose => tapez 2" << endl << "\t Je souhaite revenir au menu precedent => tapez 3" << endl << endl;
                int choixAjout;
                cin >> choixAjout;
                
                // ----------- Ajouter un trajet simple
                if (choixAjout == 1)
                {
                    TrajetSimple * t = new TrajetSimple();
                    catalogue.Ajouter(t);
                    cout << endl << "Votre trajet a bien ete ajoute !" << endl << endl;
                }

                // ----------- Ajouter un trajet compose
                else if (choixAjout == 2)
                {
                    TrajetCompose * t = new TrajetCompose();
                    catalogue.Ajouter(t);
                    cout << endl << "Votre trajet a bien ete ajoute !" << endl << endl;
                }

                // ----------- Retour au menu
                else if (choixAjout==3)
                    break;

                else 
                {   
                    cout << endl << "Désolé, je n'ai pas compris votre choix. Je vous renvoie vers le menu principal." << endl << endl;
                }
                break;
            }

            // --------------  Afficher le catalogue --------------
            case 2:
            {
                catalogue.Afficher();
                break;
            }

            // --------------  Rechercher un trajet --------------
            case 3 :
            {   
                cout << "Quel type de trajet souhaitez-vous rechercher ? " << endl << endl << "\t Je souhaite effectuer une recherche simple => tapez 1" << endl
                << "\t Je souhaite effectuer une recherche avancee => tapez 2 " << endl << "\t Je souhaite revenir au menu precedent => tapez 3 " << endl << endl;
                int choixrecherche;
                cin >> choixrecherche;

                
                // ----------- Recherche simple
                if (choixrecherche == 1)
                {
                    cout << "Quelle est votre ville de depart ? " << endl;
                    char villeDepart[50], villeArrivee[50];
                    cin >> villeDepart;
                    cout << endl << "Quelle est votre ville d'arrivee ? " << endl;
                    cin >> villeArrivee;
                    
                    catalogue.RechercheSimple(villeDepart, villeArrivee);

                    cout << endl << endl << endl;
                    break;
                }

                // ----------- Rechercher un trajet avancee
                else if (choixrecherche == 2)
                {
                    cout << "Quelle est votre ville de depart ? " << endl;
                    char villeDepart[50], villeArrivee[50];
                    cin >> villeDepart;
                    cout << endl << "Quelle est votre ville d'arrivee ? " << endl;
                    cin >> villeArrivee;
                    
                    catalogue.RechercheAvancee(villeDepart, villeArrivee);

                    cout << endl << endl << endl;
                    break;
                }

                // ----------- Retour au menu principal
                else if (choixrecherche==3)
                    break;

                else 
                {   
                    cout << endl << "Désolé, je n'ai pas compris votre choix. Veuillez entrer à nouveau un chiffre entre 1 et 4." << endl << endl;
                }
                break;
            }
        }
    }

    // ----------- Quitter l'application
    cout << "Merci et a bientot !" << endl;

    return 0;
}