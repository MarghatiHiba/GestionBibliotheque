#pragma once
#include <iostream>
#include "Date.h"
using namespace std;
using namespace biblio;
class Livre
{
private:
    const int id;
    string auteur;
    string titre;
    Date* parution;
    int* notes;
    int nbNotes;
    int capacite;
    static int compteurid;
public:
    Livre(string, string, Date*, int);
    Livre(const Livre& c);
    void ajouternote(int a);
    Livre operator=(const Livre& c);
    static bool estvalid(int a);
    int calculermoy()const;
    void afficher() const;
    //pour la class bibliotheque
    bool operator==(string tit) const;
    bool operator==(int num) const;
    ~Livre();

};


