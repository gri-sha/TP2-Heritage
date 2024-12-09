#ifndef TRAJET_H
#define TRAJET_H

// Role de la classe Trajet :
//     Cette classe est une classe de base
//     pour les classes TrajetSimple et TrajetComposee.
class Trajet
{
public:
    Trajet(const char *pVilleDep, const char *pVilleArr);
    // Mode d'emploi :
    //     const char *pVilleDep - la ville de depart
    //     const char *pVilleArr - la ville d'arrivee
    //     C'est un constructeur utilisant un tableau
    // Contrat :
    //     Les parametres doivent etre des cstrings, c'est-a-dire que le dernier caractere doit etre '\0'.

    virtual ~Trajet();
    // Mode d'emploi :
    //     C'est le destructeur de la classe

    virtual void afficher() const;
    // Mode d'emploi :
    //     Cette fonction affiche les informations sur le trajet sous la forme : de A a B

    const char *getVilleDepart() const;
    // Mode d'emploi :
    //     Cette methode donne l'acces au parametre protege char *villeDep

    const char *getVilleArrivee() const;
    // Mode d'emploi :
    //     Cette methode donne l'acces au parametre protege char *villeArr

protected:
    char *villeDep; // La ville de depart
    char *villeArr; // La ville d'arrivee
};
#endif
