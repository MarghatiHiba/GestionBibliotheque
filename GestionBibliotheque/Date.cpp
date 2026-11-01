#include "Date.h"
#include <iostream >
using namespace biblio;
using namespace std;


biblio::Date::Date(int j, int m, int a) :jour(j), mois(m), annee(a)
{

}

bool biblio::Date::estBissextile(int a)
{
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {


		return true;
	}
	else
	{
		return false;
	}
}

bool biblio::Date::estValide(int j, int m, int a)
{
	if (j < 1 || m < 1 || m>12 || a < 1) {
		cout << "date invalid" << endl;

		return false;
	}
	int jourmoi[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (estBissextile(a)) {
		jourmoi[1] = 29;

	}
	if (j > jourmoi[m - 1]) {
		cout << "date invalid" << endl;
		return false;
	}

	return true;

}

bool biblio::Date::operator==(const Date& d) const
{
	if (this->annee == d.annee && this->jour == d.jour && this->mois == d.mois) {
		cout << "les dates sont egeaux" << endl;
		return true;
	}
	else
	{
		cout << " les dates sont deffirents" << endl;
		return false;
	}
}

bool biblio::Date::operator<(const Date& d) const
{
	if (this->annee < d.annee) {
		return true;
	}
	else if (this->annee == d.annee && this->mois < d.mois) {
		return true;
	}
	else if (this->annee == d.annee && this->mois == d.mois && this->jour < d.jour) {
		return true;
	}

	return false;
}

void biblio::Date::afficher() const
{
	if (estValide(this->jour, this->mois, this->annee))

		cout << "la date de parution est:" << this->jour << "/" << this->mois << "/" << this->annee << endl;
}




