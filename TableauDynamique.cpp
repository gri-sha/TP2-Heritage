/*************************************************************************
                                   TableauDynamique
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TableauDynamique> (fichier TableauDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TableauDynamique.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TableauDynamique::Ajouter ( Trajet * ptTrajet )
// Ajoute un trajet au tableau dynamique
{
    if(this->nbTrajetsCourant == this->nbTrajetsMax-1)
    {   
        this->nbTrajetsMax *= 2;
        Trajet ** newTab = new Trajet*[this->nbTrajetsMax];
        memcpy(newTab, this->tabDynamique, this->nbTrajetsMax*sizeof(Trajet*));
        delete[] this->tabDynamique;
        this->tabDynamique = newTab;
    }

    this->tabDynamique[this->nbTrajetsCourant] = ptTrajet;
    this->nbTrajetsCourant++;

} //----- Fin de la méthode Ajouter


Trajet* TableauDynamique::GetTrajet ( int i ) const
// Renvoie le trajet à l'indice i dans le tableau dynamique
{   
    return this->tabDynamique[i];
} //----- Fin de la méthode GetTrajet


int TableauDynamique::GetNbTrajetsCourant ( ) const
// Renvoie le nombre de trajets actuellement dans le tableau dynamique
{   
    return this->nbTrajetsCourant;
}  //----- Fin de la méthode GetNbTrajetsCourant


void TableauDynamique::Supprimer(int i)
// Supprime le trajet d'indice i dans le tableau dynamique
{   
    if(i < 0 || i > this->nbTrajetsCourant)
    {
        return;
    }
    delete this->tabDynamique[i];
    this->tabDynamique[i] = nullptr;
    this->nbTrajetsCourant--;
}  //----- Fin de la méthode Supprimer


void TableauDynamique::SetNbTrajetsCourant(int i)
// Ajuste le nombre de trajets actuellement dans le tableau dynamique
{
    this->nbTrajetsCourant = i;
}  //----- Fin de la méthode SetNbTrajetsCourant


void TableauDynamique::Modif(int i, Trajet* t)
// Modifie le trajet à l'indice i dans le tableau dynamique
{
    this->tabDynamique[i] = t;
}  //----- Fin de la méthode Modif






//-------------------------------------------- Constructeurs - destructeur

TableauDynamique::TableauDynamique ( const TableauDynamique & autre )
// Constructeur de copie de TableauDynamique 
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <TableauDynamique>" << endl;
    #endif

    // Copie des attributs de l'autre tableau
    this->nbTrajetsCourant = autre.nbTrajetsCourant;
    this->nbTrajetsMax = autre.nbTrajetsMax;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];

    // Copie des trajets
    for (int i = 0; i < this->nbTrajetsCourant; ++i) {
        this->tabDynamique[i] = new Trajet(*autre.tabDynamique[i]);
    }
}  //----- Fin du constructeur de copie de TableauDynamique 



TableauDynamique::TableauDynamique()
// Constructeur par défaut de TableauDynamique
{
    this->nbTrajetsCourant = 0;
    this->nbTrajetsMax = 10;
    this->tabDynamique = new Trajet*[this->nbTrajetsMax];
} //----- Fin du constructeur par défaut de TableauDynamique


TableauDynamique::TableauDynamique(int tabSizeInit) 
 // Constructeur paramétré de TableauDynamique
{
#ifdef MAP
    cout << "Appel au constructeur de <TableauDynamique>" << endl;
#endif

this->nbTrajetsCourant = 0;
this->nbTrajetsMax = tabSizeInit;
this->tabDynamique = new Trajet*[this->nbTrajetsMax];

} //----- Fin du constructeur paramétré de TableauDynamique

TableauDynamique::~TableauDynamique ()
// Destructeur de TableauDynamique
{
#ifdef MAP
    cout << "Appel au destructeur de <TableauDynamique>" << endl;
#endif

for(int i = 0; i < this->nbTrajetsCourant; i++)
{
    delete this->tabDynamique[i];
}
delete[] this->tabDynamique;

} //----- Fin du destructeur de TableauDynamique


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

