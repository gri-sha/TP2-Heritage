/*************************************************************************
                                   Trajet
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const char* Trajet::GetDepart() const 
// Méthode constante pour obtenir la ville de départ du trajet
{ 
    return this->villeDepart; 
} //----- Fin de la méthode GetDepart

const char* Trajet::GetArrivee() const 
// Méthode constante pour obtenir la ville d'arrivée du trajet
{
    return this->villeArrivee; 
} //----- Fin de la méthode GetArrivee

const char* Trajet::GetTransport() const 
// Méthode virtuelle constante pour obtenir le moyen de transport du trajet
{
    return nullptr; 
} //----- Fin de la méthode GetTransport

int Trajet::GetNbEscales() const 
// Méthode virtuelle pour obtenir le nombre d'escales du trajet
{
    return 0; 
} //----- Fin de la méthode GetNbEscales

void Trajet::Afficher() const 
// Méthode virtuelle pure pour afficher le trajet
{
    #ifdef MAP
    cout << "Entree dans Afficher de Trajet" << endl;
    #endif
    // cout << "de " << villeDep << " a " << villeArr << " ";
} //----- Fin de la méthode Afficher



//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet ( const Trajet& autre)
// Constructeur de copie de Trajet
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::Trajet() 
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
} //----- Fin de Trajet


Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées