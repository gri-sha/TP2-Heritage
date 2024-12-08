#include <iostream>
#include "trajetCompose.h"
using namespace std;

TrajetCompose::TrajetCompose(const char *villeDep, const char *villeArr, TrajetSimple *pListTrajets[], int pNbTrajets) : Trajet(villeDep, villeArr)
{
    nbTrajets = pNbTrajets;
    listTrajets = new TrajetSimple *[nbTrajets];

    for (int i = 0; i < nbTrajets; ++i)
    {
        listTrajets[i] = pListTrajets[i];
    }
}

TrajetCompose::~TrajetCompose()
{
    for (int i = 0; i < nbTrajets; ++i)
    {
        delete listTrajets[i];
    }
    delete[] listTrajets;
}

void TrajetCompose::afficher() const
{
    for (int i = 0; i < nbTrajets; ++i)
    {
        if (listTrajets[i] != nullptr)
        {
            listTrajets[i]->afficher();
            if (i < nbTrajets - 1)
            {
                cout << " - ";
            }
        }
        else
        {
            cout << "Sous-trajet null trouve!" << "\r\n";
        }
    }

    cout << "\r\n";
}