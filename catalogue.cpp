#include <iostream>
#include <cstring>
#include "catalogue.h"
using namespace std;

Catalogue::Catalogue() : capacite(2), nbTrajets(0)
{
#ifdef MAP
    cout << "Appel de constructeur : Catalogue" << endl;
#endif
    catalogue = new Trajet *[capacite];
}

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel de destructeur : Catalague" << endl;
#endif
    for (int i = 0; i < nbTrajets; ++i)
    {
        delete catalogue[i];
    }
    delete[] catalogue;
}

void Catalogue::ajouterTrajet(Trajet *trajet)
{
    // gestion de la memoire
    if (nbTrajets == capacite)
    {
        capacite *= 2;
        Trajet **tmp = new Trajet *[capacite];
        for (int i = 0; i < nbTrajets; ++i)
        {
            tmp[i] = catalogue[i];
        }
        delete[] catalogue;
        catalogue = tmp;
    }
    // ajout du trajet
    catalogue[nbTrajets++] = trajet;
}

void Catalogue::afficher() const
{
    for (int i = 0; i < nbTrajets; ++i)
    {
        cout << i + 1 << " : ";
        catalogue[i]->afficher();
        cout << "\r\n";
    }
}

bool Catalogue::supprimerTrajet(int index)
{
    index -= 1;
    if (index < 0 || index >= nbTrajets)
    {
        return false;
    }
    delete catalogue[index];
    for (int i = index; i < nbTrajets - 1; ++i)
    {
        catalogue[i] = catalogue[i + 1];
    }
    nbTrajets--;
    return true;
}

void Catalogue::rechercher(const char *villeDepart, const char *villeArrivee) const
{
    // This algorithm is implemented considering that the graph of the possible trips is tree-type
    // i.e. without cycles
    cout << "Recherche de trajets de " << villeDepart << " a " << villeArrivee << ":" << "\r\n";
    if (catalogue == nullptr)
    {
        cout << "Le catalogue est vide.\r\n";
    }
    bool StartFound = false;
    bool EndFound = false;

    for (int i = 0; i < nbTrajets; i++)
    {
        if (strcmp(catalogue[i]->getVilleDepart(), villeDepart) == 0)
        {
            StartFound = true;
        }

        if (strcmp(catalogue[i]->getVilleArrivee(), villeArrivee) == 0)
        {
            EndFound = true;
        }
    }

    if (!(StartFound && EndFound))
    {
        cout << "Aucun trajet trouve pour cette recherche." << "\r\n";
        return;
    }
    // ! The space for each path will be the same
    Trajet **currentPath = new Trajet *[nbTrajets]; // * list of pointers (to class Trajet)
    int length = 0;
    int *lengths = new int[nbTrajets];
    // ! THE SPACE FOR ARRAY CONTAINING ALL PATHS WILL BE ALLOCATED DYNAMIACALLY
    Trajet ***allPaths = nullptr; // * pointer to list of pointers (to class Trajet)
    int amount = 0;

    findPaths(villeDepart, villeArrivee, currentPath, &length, allPaths, &amount, lengths);

    if (amount == 0)
    {
        cout << "Aucun trajet trouve pour cette recherche." << "\r\n";
    }
    else
    {
        cout << "Trajets trouves: " << amount << "\r\n";
        for (int i = 0; i < amount; ++i)
        {
            cout << "Trajet " << i + 1 << " (" << lengths[i] << " etapes) : ";

            for (int j = 0; j < lengths[i]; ++j)
            {
                allPaths[i][j]->afficher();

                if (j < lengths[i] - 1)
                {
                    cout << " -> ";
                }
            }
            cout << "\r\n";
        }
    }

    delete[] currentPath;
    for (int i = 0; i < amount; ++i)
    {
        delete[] allPaths[i];
    }
    delete[] allPaths;
    delete[] lengths;
}

void Catalogue::findPaths(const char *currentCity, const char *destinationCity, Trajet **&currentPath, int *length, Trajet ***&allPaths, int *amount, int *&lengths) const
{

    if (strcmp(currentCity, destinationCity) == 0)
    {
        if (*amount == 0)
        {
            allPaths = new Trajet **[1]; // Allocate space for the first path
        }
        else
        {
            Trajet ***temp = new Trajet **[*amount + 1];
            for (int i = 0; i < *amount; ++i)
            {
                temp[i] = allPaths[i];
            }
            delete[] allPaths;
            allPaths = temp;
        }
        allPaths[*amount] = new Trajet *[*length];
        lengths[*amount] = *length;
        for (int i = 0; i < *length; ++i)
        {
            allPaths[*amount][i] = currentPath[i];
        }
        (*amount)++;
        return;
    }

    for (int i = 0; i < nbTrajets; ++i)
    {
        if (strcmp(catalogue[i]->getVilleDepart(), currentCity) == 0)
        {

            currentPath[*length] = catalogue[i];
            (*length)++;
            findPaths(catalogue[i]->getVilleArrivee(), destinationCity, currentPath, length, allPaths, amount, lengths);
            (*length)--; //! IT IS VERY IMPORTANT TO DECREMENT THE LENGTH FOR THE NEXT ITERATIONS
        }
    }
}

int Catalogue::getNbTrajets() const {
    return nbTrajets;
}
