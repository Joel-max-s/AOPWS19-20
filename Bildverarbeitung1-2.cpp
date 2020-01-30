#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Bildverarbeitung1-2.hpp"

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

int main()
{
    std::ifstream test("feep.pgm");
    Bild Bild1;
    test >> Bild1;
    Bild1.SetzeBildZusammen();
    Bild1.Druckebildfertig();
    std::ofstream raus("Gekantet.pgm");
    Bild1.fuelleBearbeitetesBild();
    std::cout << Bild1;
	raus << Bild1;
    return 0;
}

