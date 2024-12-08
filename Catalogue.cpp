/*************************************************************************
                            Catalogue  
                             -------------------
    début                : 27/11/2024
    copyright            : (C) 2024 par PREVOST Claire, SAVCHENKO Grigory
    e-mail               : claire.prevost@insa-lyon.fr
                           grigory.savchenko@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"
//------------------------------------------------------------- Constantes
const int MAX_PATH_LENGTH = 3;


//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques

void Catalogue::Afficher()
// Affiche les trajets du catalogue
{   
    int nbTrajetsCourant = this->tabDynamique.GetNbTrajetsCourant();

    if (nbTrajetsCourant == 0)
    {
        cout << "Le catalogue est vide" << endl << endl;
    } else {
        cout << "Le catalogue contient les trajets suivants :" << endl <<endl;
        for(int i = 0; i < nbTrajetsCourant; i++)
        {
            cout << "Trajet numero " << i+1 << " : ";
            this->tabDynamique.GetTrajet(i)->Afficher();
        }
    }

} //----- Fin de la méthode Afficher



void Catalogue::Ajouter ( Trajet * ptTrajet )
// Ajoute un trajet au catalogue
{
    this->tabDynamique.Ajouter(ptTrajet);

} //----- Fin de la méthode Ajouter


void Catalogue::RechercheSimple (char* VilleA, char* VilleB) const
// Méthode pour rechercher un trajet (simple ou composé), de VilleA vers VilleB. 
{
    int nbTrajet = this->tabDynamique.GetNbTrajetsCourant();
    if(nbTrajet == 0)
    {
        cout << "Desole, il n'y a aucun trajet enregistre dans le catalogue. Revenez plus tard." << endl << endl;
        return;
    }

    bool trajetTrouve = false;
    cout << "Recherche de trajets de " << VilleA << " vers " << VilleB << ":" << "\r\n";

    for(int i= 0; i<nbTrajet; i++){
        Trajet * t = this->tabDynamique.GetTrajet(i);
        
        if (!strcmp(t->GetArrivee(), VilleB) && !strcmp(t->GetDepart(), VilleA)) {
            cout << endl << "Voici un trajet qui correspond à votre recherche :" << endl;
            t->Afficher();
            trajetTrouve = true;   
        }
    }

    if (!trajetTrouve) {
        cout << endl << "Aucun trajet dans le catalogue ne permet d'aller de " << VilleA << " a " << VilleB << ".";
    }
} //----- Fin de la méthode RechercheSimple



void Catalogue::RechercheBruteForce(const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant, int tailleChemin, bool& found) 
// Méthode pour trouver un chemin entre deux villes dans un catalogue de trajets
{
    if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), VilleB)) {
        found = true;
        return;
    }

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); ++i) {
        if(tabDynamique.GetTrajet(i) == cheminCourant.GetTrajet(tailleChemin - 1)) continue;
        Trajet* nextTrajet = tabDynamique.GetTrajet(i);

        bool alreadyExists = false;
        for(int j = 0; j < tailleChemin; j++) {
            if(nextTrajet == cheminCourant.GetTrajet(j)) {
                alreadyExists = true;
                break;
            }
        }
        
        if (alreadyExists) continue;

        if (!strcmp(cheminCourant.GetTrajet(tailleChemin - 1)->GetArrivee(), nextTrajet->GetDepart())) {
            cheminCourant.Ajouter(nextTrajet);
            RechercheBruteForce(VilleA, VilleB, cheminCourant, tailleChemin + 1, found);
            if (found) {
                break;
            } else {
                cheminCourant.Supprimer(tailleChemin - 1);
            }
        }
    }
    return;
} //----- Fin de la méthode RechercheBruteForce


void Catalogue::UneCombinaison(Trajet* startTrajet, const char* VilleA, const char* VilleB, TableauDynamique& cheminCourant)
// Méthode pour préparer et effectuer la recherche de trajet entre VilleA et VilleB
{
    bool found = false; 

    for(int i = 0; i < cheminCourant.GetNbTrajetsCourant(); i++)
    {
        cheminCourant.Modif(i, nullptr);
    }
    cheminCourant.SetNbTrajetsCourant(0);

    cheminCourant.Ajouter(startTrajet);
    RechercheBruteForce(VilleA, VilleB, cheminCourant, 1, found);

    return;
} //----- Fin de la méthode UneCombinaison


void Catalogue::RechercheAvancee(const char* VilleA, const char* VilleB) 
// Méthode pour la recherche de trajets entre VilleA et VilleB avec concaténation de trajets 
{
    int nbTrajet = this->tabDynamique.GetNbTrajetsCourant();
    if(nbTrajet == 0)
    {
        cout << "Desole, il n'y a aucun trajet enregistre dans le catalogue. Revenez plus tard." << endl << endl;
        return;
    }

    bool trajetTrouve = false;
    cout << "Recherche de trajets de " << VilleA << " vers " << VilleB << ":" << "\r\n";

    // Parcours tous les trajets pour stocker les trajets de départ
    TableauDynamique Departs(nbTrajet);
    int departsCount = 0;

    for (int i = 0; i < tabDynamique.GetNbTrajetsCourant(); i++) {
        Trajet* startTrajet = tabDynamique.GetTrajet(i);
        
        if(!strcmp(startTrajet->GetDepart(), VilleA)) {
            // Retrait des doublons
            bool alreadyExists = false;
            for (int j = 0; j < departsCount; j++) {
                if (!strcmp(startTrajet->GetDepart(), Departs.GetTrajet(j)->GetDepart()) && !strcmp(startTrajet->GetArrivee(), Departs.GetTrajet(j)->GetArrivee())) {
                    alreadyExists = true;
                    break;
                }
            }
            TrajetCompose* trajetCompose = dynamic_cast<TrajetCompose*>(startTrajet);
            if (!alreadyExists) {
                if(strcmp(startTrajet->GetArrivee(), VilleB) == 0) {
                    cout << endl << "Un trajet direct correspondant a votre recherche est :" << endl;
                    startTrajet->Afficher();
                    trajetTrouve = true;
                } else if(trajetCompose){
                    TrajetSimple* ts = (TrajetSimple*) trajetCompose->RechercheDansTrajetCompose(VilleA, VilleB);
                    if (ts != nullptr) {
                        cout << endl <<"Un trajet direct correspond à votre recherche est :" << endl;
                        ts->Afficher();
                        trajetTrouve = true;
                    }
                } else {
                    Departs.Ajouter(startTrajet);
                    departsCount++;
                }
            }
        }
    }

    // Parcours tous les trajets de départ pour trouver les chemins possibles
    TableauDynamique cheminCourant = TableauDynamique(MAX_PATH_LENGTH); // Tableau pour stocker le chemin actuel

    for(int j=0; j<departsCount; j++){
        Trajet* startTrajet = Departs.GetTrajet(j);
        UneCombinaison(startTrajet, VilleA, VilleB, cheminCourant);
        if (cheminCourant.GetNbTrajetsCourant()!=1) {
            cout << endl << "Voici des trajets qui correspondent à votre recherche :" << endl;
            for(int i=0; i<cheminCourant.GetNbTrajetsCourant(); i++){
                cout << "Trajet numero " << i+1 << " : ";
                cheminCourant.GetTrajet(i)->Afficher();
                cout << endl;
                trajetTrouve = true;
            }
        }
    }

    if(trajetTrouve) cout << endl << "Fin de la recherche avancee" << endl << endl;
    else cout << endl << "Désolé, aucun trajet allant de " << VilleA << " vers " << VilleB << "." << endl << endl;
    
    return ;
} //----- Fin de la méthode RechercheAvancee




//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
// Constructeur par défaut de Catalogue
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif

} //----- Fin du constructeur par défaut de Catalogue


Catalogue::~Catalogue ( )
// Destructeur de Catalogue
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin du destructeur de Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées