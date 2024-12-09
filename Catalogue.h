#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "trajetSimple.h"
#include "trajetCompose.h"
#include "trajet.h"

// Role de la classe Catalogue :
//     Cette classe permet de gerer un catalogue de trajets (simples ou composes).
//     Elle fournit des fonctionnalites pour ajouter, supprimer, afficher et rechercher des trajets.
class Catalogue
{
public:
    Catalogue();
    // Mode d'emploi :
    //     C'est le constructeur par defaut. Il initialise un catalogue vide, prevoit un espace de stockage initial pour les trajets.

    ~Catalogue();
    // Mode d'emploi :
    //     C'est le destructeur de la classe. Il libere la memoire allouee pour les trajets stockes dans le catalogue.

    void ajouterTrajet(Trajet *trajet);
    // Mode d'emploi :
    //     Ajoute un trajet (simple ou compose) au catalogue.
    //     Trajet* trajet - un pointeur vers un trajet a ajouter.
    // Contrat :
    //     Le pointeur doit etre valide, et la memoire de l'objet reste geree par l'utilisateur.

    void afficher() const;
    // Mode d'emploi :
    //     Affiche tous les trajets contenus dans le catalogue sous forme d'une liste numerotee.

    bool supprimerTrajet(int index);
    // Mode d'emploi :
    //     Supprime le trajet a l'index specifie dans le catalogue.
    //     int index - l'index du trajet a supprimer (base 1).
    // Contrat :
    //     L'index doit etre valide (0 <= index < nbTrajets).

    void rechercher(const char *villeDepart, const char *villeArrivee) const;
    // Mode d'emploi :
    //     Recherche tous les trajets possibles entre deux villes donnees, en considerant que
    //     le graphe des trajets est de type arbre (sans cycles).
    //     const char* villeDepart - la ville de depart.
    //     const char* villeArrivee - la ville d'arrivee.
    //     Affiche tous les chemins trouves, avec le nombre d'etapes pour chaque chemin.
    // Contrat :
    //     Les noms des villes doivent etre des cstrings (dernier caractere '\0').

    int getNbTrajets() const;
    // Mode d'emploi :
    //     Cette methode donne l'acces au parametre protege int nbTragets

private:
    Trajet **catalogue; // Liste de pointeurs vers des trajets stockes dans le catalogue
    int capacite;       // Capacite actuelle de la memoire pour stocker les trajets
    int nbTrajets;      // Nombre de trajets actuellement dans le catalogue

    void findPaths(const char *currentCity, const char *destinationCity, Trajet **&currentPath, int *length, Trajet ***&allPaths, int *amount, int *&lengths) const;
    // Mode d'emploi :
    //     const char* currentCity - la ville actuelle dans le chemin en construction.
    //     const char* destinationCity - la ville cible pour laquelle les chemins sont recherches.
    //     Trajet**& currentPath - tableau temporaire pour stocker le chemin actuel.
    //     int* length - longueur du chemin actuel.
    //     Trajet***& allPaths - tableau dynamique contenant tous les chemins trouves.
    //     int* amount - nombre total de chemins trouves.
    //     int*& lengths - tableau contenant la longueur de chaque chemin trouve.
    //     Cette fonction est recursive et explore tous les chemins possibles en utilisant une approche DFS (Depth-First Search).
    // Contrat :
    //     Les noms des villes doivent etre des cstrings (dernier caractere '\0').
    //     length >= 0, amount >= 0.
};
#endif
