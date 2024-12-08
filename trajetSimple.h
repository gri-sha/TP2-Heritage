/*************************************************************************
                                   TrajetSimple
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if ! defined ( TRAJETSIMPLE_H )
#define TRAJETSIMPLE_H

#include "Trajet.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// La classe TrajetSimple permet de créer et manipuler des trajets simples.
// Elle hérite de la classe Trajet.
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Afficher ( ) const; 
    // Méthode pour afficher un trajet simple 

    const char* GetTransport ( ) const; 
    // Méthode pour obtenir le moyen de transport d'un trajet

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const TrajetSimple& autre);
    // Constructeur de copie

    TrajetSimple();
    // Constructeur par défaut

    TrajetSimple ( char A[50], char B[50],char T[50] );
    // Constructeur paramétré de TrajetSimple 

    ~TrajetSimple ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char moyenTransport[50];
    // Attribut protégé correspondant au moyen de transport du trajet
    
};

//-------------------------------- Autres définitions dépendantes de <TrajetSimple>

#endif // TRAJETSIMPLE_H