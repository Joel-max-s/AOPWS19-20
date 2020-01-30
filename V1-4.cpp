#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "V1-4.hpp"

std::istream& operator>> (std::ifstream&, Bild&);
std::ostream& operator<< (std::ofstream&, const Bild&);
std::ostream& operator<< (std::ostream&, const Bild&);
int AbfrageBildart();
int AbfrageBildaufKonsoleAusgeben();
std::string AbfrageImportierName();
std::string AbfrageExportierName();

int main()
{
    std::string Importname = AbfrageImportierName();
    int Bildart = AbfrageBildart();
    std::ifstream test(Importname);
    Bild Bild1;
    test >> Bild1;
    Bild1.SetzeBildanderszusammen(Bildart);
    Bild1.SetzeBildZusammen(Bildart);
    Bild1.fuelleBearbeitetesBild();
    std::string Exportname = AbfrageExportierName();
    std::ofstream raus(Exportname);
    raus << Bild1;
    int AufKonsoleAusgeben = AbfrageBildaufKonsoleAusgeben();
    if (AufKonsoleAusgeben == 2)
        std::cout << Bild1;
    return 0;
}


std::istream& operator>> (std::ifstream& in, Bild& Bild1)
{
    //std::vector <std::string> Dateialsstring;
    std::ifstream& ifs (in);
    int i = 0;
	while( ifs )
    {
        std::string zeile;
    	std::getline(ifs, zeile);
        if (i == 2)
            Bild1.DateialsString.push_back(zeile);
        else if (i > 3)
            Bild1.DateialsString.push_back(zeile);
        i++;
    }
    return in;
}

std::ostream& operator<< (std::ofstream& out, const Bild& Bild1)
{
    out <<"P2 \n";
    out <<"#Fepp \n";
    out <<+Bild1.Aufloesung.at(0) <<" " <<+Bild1.Aufloesung.at(1) <<"\n";
    out <<"255\n";

    for (int i = 0; i < Bild1.BearbeitetesBild.size(); i++)
    {
        for (int j = 0; j < Bild1.BearbeitetesBild.at(i).size(); j++)
        {
            out << +Bild1.BearbeitetesBild.at(i).at(j) <<" ";
        }
        out <<"\n";

	}
    return out;
}

std::ostream& operator<< (std::ostream& out, const Bild& Bild1)
{
   int n = 0;
   while (n < Bild1.DateialsString.size()-1)
    {
    	out << Bild1.DateialsString.at(n) << "\n";
    	n++;
	}
   return out;
}

int AbfrageBildart()
{
    int Abfrage;
    do
    {
        std::cout <<"Liegt das das PGM-Bild als Matrix oder Zeilenweise vor?" <<std::endl;
        std::cout <<"(1)    Als Matrix (standart)" <<std::endl;
        std::cout <<"(2)    Zeilenweise (oft wenn von anderem Dateivormat zu PGM exportiert wurde)" <<std::endl;
        std::cin >>Abfrage;
    } while (Abfrage != 1 and Abfrage != 2);
    return Abfrage;
}

std::string AbfrageImportierName()
{
    std::string Dateiname;
    std::cout <<"Wie heißt die Datei die Importiert werden soll?" <<std::endl;
    std::cout <<"(Bitte .pgm am Ende nicht vergessen)" <<std::endl;
    std::cin >>Dateiname;
    return Dateiname;
}

std::string AbfrageExportierName()
{
    std::string Dateiname;
    std::cout <<"Wie heißt die Datei die Exportiert werden soll?" <<std::endl;
    std::cout <<"(Bitte .pgm am Ende nicht vergessen)" <<std::endl;
    std::cin >>Dateiname;
    return Dateiname;
}

int AbfrageBildaufKonsoleAusgeben()
{
    int Abfrage;
    do
    {
        std::cout <<"Soll das bearbeitete Bild auf der Konsole ausgegeben werden?" <<std::endl;
        std::cout <<"(1)    Bild nicht auf Konsole ausgeben (empfohlen bei Bildern hoher Aufloesung)" <<std::endl;
        std::cout <<"(2)    Bild auf Konsole ausgeben (nur wenn das Bild eine sehr geringe Aufloesung hat)" <<std::endl;
        std::cin >>Abfrage;
    } while (Abfrage != 1 and Abfrage != 2);
    return Abfrage;
}