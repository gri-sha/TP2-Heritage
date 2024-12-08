/*************************************************************************
                                   TrajetSimpleCompose
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetCompose::Afficher() const
// Affiche le trajet composé en parcourant le tableau dynamique de trajets
{   
    const int j = this->GetTableau().GetNbTrajetsCourant();

    for(int i = 0; i < j; i++)
    {   

        const Trajet * trajet_i = this->GetTableau().GetTrajet(i);
        if (i==0)
        {
            cout << " " << trajet_i->GetDepart() << " --- " << "( " << trajet_i->GetTransport() << " )"<< " ---> " << trajet_i->GetArrivee();
        }
        else
        {
            cout << " --- " << "( " << trajet_i->GetTransport() << " )"<< " ---> " << trajet_i->GetArrivee();
        }
        

    }
    cout<< endl;
} //----- Fin de la méthode Afficher


const TableauDynamique& TrajetCompose::GetTableau() const
// Renvoie le tableau dynamique de trajets associé à ce trajet composé
{   
    return this->tabDynamique;
} //----- Fin de méthode GetTableau


int TrajetCompose::GetNbEscales() const
 // Renvoie le nombre d'escales dans le trajet composé
{
    return this->nbEscales;
} //----- Fin de méthode GetNbEscales


const TrajetSimple* TrajetCompose::RechercheDansTrajetCompose(const char* VilleA, const char* VilleB) 
// Recherche un trajet simple dans le trajet composé en fonction des villes de départ et d'arrivée
{
        for (int i = 0; i < this->tabDynamique.GetNbTrajetsCourant(); i++) {
            TrajetSimple* trajet = (TrajetSimple*) this->tabDynamique.GetTrajet(i);
            if (!strcmp(trajet->GetArrivee(), VilleB) && !strcmp(trajet->GetDepart(), VilleA)) {
                return trajet;
            }
        }
        return nullptr;
} //----- Fin de méthode RechercheDansTrajetCompose



//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose(const TrajetCompose& autre) : Trajet(autre)
// Constructeur de copie de TrajetCompose
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
    #endif
    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    this->nbEscales = autre.GetNbEscales();
    this->tabDynamique = TableauDynamique(autre.GetTableau());
    
} //----- Fin du constructeur de copie de TrajetCompose


TrajetCompose::TrajetCompose()
// Constructeur par défaut de TrajetCompose
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    char final_end[50];
    cout << endl << "Quelle est la ville d'arrivee de votre trajet ? (du trajet dans son integralite)" << endl;
    cin >> final_end;
    this->nbEscales = 0;
    char start[50];
    char end[50]="";
    char mean[50];
    while(strcmp(end,final_end))
    {   
        if(this->nbEscales==0){
            cout << endl << "Quelle est la ville de depart de votre trajet ? " << endl;
            cin >> start;
            cout << endl << "Quelle est la ville de l'etape suivante ? " << endl;
            cin >> end;
            cout << endl<< "Quel est le mode de transport envisage pour cette etape ?" << endl;
            cin >> mean;
            TrajetSimple * TS = new  TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
            this->nbEscales++;
            strcpy(this->villeArrivee, final_end);
            strcpy(this->villeDepart, start);
        }
        else
        {
            strcpy(start,end);
            cout << endl << "Quelle est la ville de l'etape suivante ? " << endl;
            cin >> end;
            cout << endl<< "Quel est le mode de transport envisage pour cette etape ?" << endl;
            cin >> mean;
            TrajetSimple * TS = new TrajetSimple(start, end, mean);
            this->tabDynamique.Ajouter(TS);
        }
    }
} //----- Fin du constructeur par défaut de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Destructeur de TrajetCompose
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
} //----- Fin du destructeur de TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
