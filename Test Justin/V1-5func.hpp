#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>


int AbfrageBildart();
std::string AbfrageImportierName();
std::string AbfrageExportierName();
int AbfrageBildaufKonsoleAusgeben();
std::istream& operator>> (std::ifstream&, Bild&);
std::ostream& operator<< (std::ostream&, const Bild&);
std::ostream& operator<< (std::ofstream&, const Bild&);


std::istream& operator>> (std::ifstream& in, Bild& Bild1)
{
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
    out <<"#" + Bild1.Kommentar <<"\n";
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
   for (int i = 0; i < Bild1.BearbeitetesBild.size(); i++)
    {
    	for (int j = 0; j < Bild1.BearbeitetesBild.at(i).size(); j++)
        {
            out <<+Bild1.BearbeitetesBild.at(i).at(j) << "  ";
        }
        out <<"\n";
	}
    out <<"\n\n";
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
    std::ifstream Testobdateiexistiert;

    do
    {
        std::cout <<"Wie heisst die Datei die Importiert werden soll?" <<std::endl;
        std::cout <<"(Bitte .pgm am Ende nicht vergessen)" <<std::endl;
        std::cin >>Dateiname;
        Testobdateiexistiert.open(Dateiname);
        std::cout <<std::endl;
    } while (!Testobdateiexistiert);
    
    Testobdateiexistiert.close();
    std::cout <<std::endl;
    return Dateiname;

}

std::string AbfrageExportierName()
{
    std::string Dateiname;
    std::cout <<"Wie soll die zu exportierende Datei heissen?" <<std::endl;
    std::cout <<"(Bitte .pgm am Ende nicht vergessen)" <<std::endl;
    std::cin >>Dateiname;
    std::cout <<std::endl <<std::endl;
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
        std::cout <<std::endl <<std::endl;
    } while (Abfrage != 1 and Abfrage != 2);
    return Abfrage;
}