#include "Bibliotheque.h"

int Bibliotheque::nbBibliotheque = 0;

Bibliotheque::Bibliotheque(string nom, int capacite)
{
	this->nom = nom;
	this->capacite = capacite;
	this->nbLivres = 0;
	this->Livres = new Livre * [this->capacite];
	for (int i = 0; i < capacite; i++)
	{
		this->Livres[i] = nullptr;

	}
	nbBibliotheque++;
}

Bibliotheque::Bibliotheque(const Bibliotheque& C) 
{
	this->nom = C.nom;
	this->capacite = C.capacite;
	this->nbLivres = C.nbLivres;
	this->Livres = new Livre * [C.capacite];
	for (int i = 0; i < C.nbLivres; i++)
	{
		this->Livres[i] = new Livre(*C.Livres[i]);


	}
	nbBibliotheque++;

}

Bibliotheque Bibliotheque::operator=(const Bibliotheque& C)
{
	if (this != &C) {
		for (int i = 0; i < capacite; i++)
		{
			delete Livres[i];
		}
		delete[]Livres;
		this->nom = C.nom;
		this->capacite = C.capacite;
		this->nbLivres = C.nbLivres;
		this->Livres = new Livre * [C.capacite];
		for (int i = 0; i < C.capacite; i++)
		{
		
			this->Livres[i] = new Livre(*C.Livres[i]);
		}
		return *this;
	}
}

void Bibliotheque::ajouterlivre(const Livre& L)
{
	if (this->nbLivres < this->capacite) {
		Livres[nbLivres] = new Livre(L);
		nbLivres++;
	}
}

Bibliotheque Bibliotheque::operator+=(const Livre& L)
{
	ajouterlivre(L);
	return*this;
}

bool Bibliotheque::rechercher(string titre) const
{
	for (int i = 0; i < nbLivres; i++)
	{
		if (*Livres[i] == titre)
		{
			cout << "le livre existe dans la bibliotheque" << endl;
			return true;
		}
	}
	cout << "le livre nexiste  pas dans la bibliotheque" << endl;
	return false;
}

bool Bibliotheque::rechercher(int a) const
{
	for (int i = 0; i < nbLivres; i++)
	{
		if (*Livres[i] == a)
		{
			cout << "le livre existe dans la bibliotheque" << endl;
			return true;
		}
	}
	cout << "le livre nexiste  pas dans la bibliotheque" << endl;
	return false;
}
void Bibliotheque::afficher() const {
	cout << " le nom de la bibliotheque: " << this->nom << endl;
	cout << " le nombre des  bibliotheques: " << this->nbBibliotheque << endl;
	cout << "\nla liste des livres:" << endl;
	for (int i = 0; i < nbLivres; i++)
	{
		if (this->Livres[i] != nullptr) {
			cout << "\n le livre" << i + 1 << ":" << endl;
			this->Livres[i]->afficher();

		}
	}
	cout << " le nombre des  livres: " << this->nbLivres << endl;

}

Bibliotheque::~Bibliotheque()
{
	for (int i = 0; i < nbLivres; i++)
	{
		delete Livres[i];
	}
	delete Livres;
	nbBibliotheque--;
}
