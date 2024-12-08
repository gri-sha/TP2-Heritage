/*************************************************************************
                                   Trajet
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
// La classe Trajet permet de créer et de manipuler des trajets.
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher (  ) const ;
    // Méthode virtuelle pour afficher les détails du trajet (simple ou composé)

    virtual const char * GetTransport () const;
    // Méthode virtuelle constante pour obtenir le moyen de transport du trajet

    virtual int GetNbEscales (  ) const;
    // Méthode virtuelle constante pour obtenir le nombre d'escales dans le trajet
    
    const char* GetArrivee () const;
    // Méthode constante pour obtenir la ville d'arrivée du trajet

    const char* GetDepart ()const ;
    // Méthode constante pour obtenir la ville de départ du trajet


//-------------------------------------------- Constructeurs - destructeur

    Trajet ( const Trajet& autre ) ;
    // Constructeur de copie


    Trajet( );
    // Constructeur par défaut

    virtual ~Trajet ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char villeDepart[50];
    char villeArrivee[50];
    // Attributs protégés représentant les villes de départ et d'arrivée du trajet
    
};

#endif // TRAJET_H