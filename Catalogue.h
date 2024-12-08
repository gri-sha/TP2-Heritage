/*************************************************************************
                            Catalogue  
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

#define TAILLE_MAX_INIT 10


#include "TableauDynamique.h"
#include "TrajetCompose.h"

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
// La classe Catalogue permet d'ajouter, afficher et rechercher des trajets.
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Afficher (  );
    // Affiche les trajets du catalogue

    void RechercheSimple (char*, char*) const;
    // Effectue une recherche simple de trajets entre VilleA et VilleB

    void RechercheBruteForce (const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant, int tailleChemin, bool& found);


    void UneCombinaison(Trajet* startTrajet,const char* VilleA, const char* VilleB , TableauDynamique& cheminCourant);


    void RechercheAvancee (const char* VilleA, const char* VilleB);
    // Recherche avancée de trajets entre VilleA et VilleB

    virtual void Ajouter ( Trajet * ptTrajet );
    // Ajoute un trajet au catalogue


//-------------------------------------------- Constructeurs - destructeur

    Catalogue ( );
    // Constructeur par défaut

    virtual ~Catalogue ( );
    // Destructeur

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    TableauDynamique tabDynamique = TableauDynamique(TAILLE_MAX_INIT);
    // Tableau dynamique de trajets dans le catalogue
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H