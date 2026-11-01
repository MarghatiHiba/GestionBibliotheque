#pragma once
#include "Livre.h"
#include <iostream >
using namespace biblio;
using namespace std;
class Bibliotheque
{
private:
	string nom;
	Livre** Livres;
	int capacite;
	int nbLivres;

	static int nbBibliotheque;
public:
	Bibliotheque(string, int);
	Bibliotheque(const Bibliotheque&);
	Bibliotheque operator=(const Bibliotheque&);
	void ajouterlivre(const Livre& L);
	Bibliotheque operator+=(const Livre&);
	bool rechercher(string)const;
	bool rechercher(int)const;
	void afficher()const;
	~Bibliotheque();



};


