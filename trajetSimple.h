#ifndef TRAJET_SIMPLE_H
#define TRAJET_SIMPLE_H

#include "trajet.h"

// Role de la classe TrajetSimple :
//     Cette classe represente un trajet simple.
//     C'est-a-dire un trajet de A a B sans arrets avec un moyen de transport.
class TrajetSimple : public Trajet
{
public:
    TrajetSimple(const char *pVilleDep, const char *pVilleArr, const char *pMoyen);
    // Mode d'emploi :
    //     const char *pVilleDep - la ville de depart
    //     const char *pVilleArr - la ville d'arrivee
    //     const char *pMoyen - moyen de transport de ce trajet
    //     C'est le constructeur de la classe TrajetSimple
    // Contrat :
    //     Les parametres doivent etre des cstrings, c'est-a-dire que le dernier caractere doit etre '\0'.

    virtual ~TrajetSimple();
    // Mode d'emploi :
    //     C'est le destructeur de la classe

    virtual void afficher() const;
    // Mode d'emploi :
    //     Cette fonction affiche les informations sur le trajet sous la forme : de A a B en Moyen
    
protected:
    char *moyen; // Moyen de transport de ce trajet
};
#endif
