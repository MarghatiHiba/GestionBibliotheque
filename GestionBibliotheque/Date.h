#pragma once
namespace biblio {
class Date
{

	private:
		int jour;
		int mois;
		int annee;
	public:
		Date(int, int, int);
		static bool estBissextile(int);
		static bool estValide(int, int, int);
		bool operator==(const Date& d) const;
		bool operator<(const Date& d) const;
		void afficher()const;


	};
}



