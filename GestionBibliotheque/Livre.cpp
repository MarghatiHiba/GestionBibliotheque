#include "Livre.h"
using namespace std;
using namespace biblio;
#include <iostream>
int Livre::compteurid = 0;
Livre::Livre(string aut, string tit, Date* p, int cap) :id(++compteurid) {
	this->auteur = aut;
	this->titre = tit;
	this->parution = new Date(*p);
	this->capacite = cap;
	this->nbNotes = 0;
	this->notes = new int[this->capacite];

}
Livre::Livre(const Livre& C) :id(C.id) {
	this->auteur = C.auteur;
	this->titre = C.titre;
	this->parution = new Date(*C.parution);
	this->capacite = C.capacite;
	this->nbNotes = C.nbNotes;
	this->notes = new int[C.capacite];
	for (int i = 0; i < C.nbNotes; i++)
	{
		this->notes[i] = C.notes[i];

	}

}
void Livre::ajouternote(int a)
{
	if (estvalid(a)) {
		if (nbNotes < capacite) {
			notes[nbNotes] = a;
			nbNotes++;
		}
		else {
			cout << " le tableau de notes est plein" << endl;
		}
	}
}
Livre Livre::operator=(const Livre& C) {
	if (this != &C) {
		this->auteur = C.auteur;
		this->titre = C.titre;
		delete parution;
		this->parution = new Date(*C.parution);
		this->capacite = C.capacite;
		this->nbNotes = C.nbNotes;
		delete[] notes;
		this->notes = new int[C.capacite];
		for (int i = 0; i < C.nbNotes; i++)
		{
			this->notes[i] = C.notes[i];

		}
	}
	return*this;

}

bool Livre::estvalid(int a)
{
	if (a < 1 || a>20) {
		cout << "la note est invalide:entrer une note etre1est 20." << endl;
		return false;
	}
	return true;
}

int Livre::calculermoy() const
{
	int somme = 0;
	if (nbNotes != 0) {
		for (int i = 0; i < nbNotes; i++)
		{
			somme += notes[i];

		}
		return somme / nbNotes;
	}

	cout << " le tableau est vide" << endl;
	return 0;
}
void Livre::afficher() const
{
	cout << "Lenemero de livre:" << this->id << endl;
	cout << "Lauteur de livre:" << this->auteur << endl;
	cout << "Le titre de livre:" << this->titre << endl;
	this->parution->afficher();
	cout << "Le moyenne des notes de livre:" << this->calculermoy() << endl;

}

bool Livre::operator==(string tit) const
{
	if (this->titre == tit)
		return true;
	return false;
}

bool Livre::operator==(int num) const
{
	if (this->id == num)
		return true;
	return false;
}

Livre::~Livre()
{
	delete parution;
	delete[]notes;
}



