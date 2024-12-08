/*************************************************************************
                                   TrajetSimple
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


const char * TrajetSimple::GetTransport () const
// Méthode constante pour obtenir le moyen de transport du trajet
{
    return this->moyenTransport; 
} //----- Fin de la méthode GetTransport


void TrajetSimple::Afficher (  ) const
// Méthode pour afficher un trajet simple
{   
    cout << " " << this->villeDepart << " --- " << "( " << this->moyenTransport << " )"<< " ---> " <<this->villeArrivee << endl;
} //----- Fin de la méthode Afficher



//-------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const TrajetSimple& autre) : Trajet(autre)
// Constructeur par copie de TrajetSimple
{   
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TrajetSimple>" << endl;
    #endif

    strcpy(this->villeDepart, autre.GetDepart());
    strcpy(this->villeArrivee, autre.GetArrivee());
    strcpy(this->moyenTransport, autre.GetTransport());
} //-------- Fin constructeur par copie TrajetSimple


TrajetSimple::TrajetSimple (  )
// Constructeur par défaut de TrajetSimple
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif
    cout << endl << "Quelle est la ville de depart de votre trajet ? " << endl;
    cin >> this->villeDepart;
    cout << endl << "Quelle est la ville d'arrivee de votre trajet ?" << endl;
    cin >> this->villeArrivee;
    cout << endl<< "Quel est le moyen de transport envisage pour ce trajet ? " << endl;
    cin >> this->moyenTransport;

} //----- Fin du constructeur par défaut de TrajetSimple

TrajetSimple::TrajetSimple ( char A[50], char B[50],char T[50] )
// Constructeur paramétré de TrajetSimple
{
    strcpy(this->villeDepart,A);
    strcpy(this->villeArrivee,B);
    strcpy(moyenTransport,T);
} //----- Fin du constructeur paramétré de TrajetSimple 


TrajetSimple::~TrajetSimple ( )
// Destructeur de TrajetSimple
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
} //----- Fin du destructeur de TrajetSimple


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées