#ifndef TRAJET_COMPOSE_H
#define TRAJET_COMPOSE_H

#include "trajet.h"
#include "trajetSimple.h"

// Role de la classe TrajetCompose :
//     Cette classe represente un trajet compose.
//     C'est-a-dire un ensemble de trajets simples relies ensemble
//     formant un trajet global de A a B avec des arrets intermediaires.
class TrajetCompose : public Trajet
{

public:
    TrajetCompose(const char *villeDep, const char *villeArr, TrajetSimple *listTrajets[], int nbTrajets);
    // Mode d'emploi :
    //     const char *villeDep - la ville de depart du trajet compose
    //     const char *villeArr - la ville d'arrivee du trajet compose
    //     TrajetSimple *listTrajets[] - tableau contenant les trajets simples constituant le trajet compose
    //     int nbTrajets - nombre de trajets simples dans la liste
    //     C'est le constructeur de la classe TrajetCompose.
    // Contrat :
    //     Les parametres villeDep et villeArr doivent etre des cstrings, c'est-a-dire que le dernier caractere doit etre '\0'.
    //     listTrajets doit etre un tableau valide de pointeurs vers des objets TrajetSimple. (listTrajest != NULL)
    //     nbTrajets doit correspondre au nombre d'elements dans listTrajets. (nbTrajets > 0)

    virtual ~TrajetCompose();
    // Mode d'emploi :
    //     C'est le destructeur de la classe. Il libere la memoire utilisee pour la liste des trajets.

    virtual void afficher() const;
    // Mode d'emploi :
    //     Cette fonction affiche les informations sur le trajet compose,
    //     en listant chaque trajet simple qui le constitue.

protected:
    TrajetSimple **listTrajets; // Liste des trajets simples qui composent ce trajet
    int nbTrajets;              // Nombre de trajets simples dans la liste
};
#endif
