#include "Funktionen.hpp"

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

    for (unsigned int i = 0; i < Bild1.BearbeitetesBild.size(); i++)
    {
        for (unsigned int j = 0; j < Bild1.BearbeitetesBild.at(i).size(); j++)
        {
            out << +Bild1.BearbeitetesBild.at(i).at(j) <<" ";
        }
        out <<"\n";

	}
    return out;
}

std::ostream& operator<< (std::ostream& out, const Bild& Bild1)
{
   for (unsigned int i = 0; i < Bild1.BearbeitetesBild.size(); i++)
    {
    	for (unsigned int j = 0; j < Bild1.BearbeitetesBild.at(i).size(); j++)
        {
            out <<+Bild1.BearbeitetesBild.at(i).at(j) << "  ";
        }
        out <<"\n";
	}
    out <<"\n\n";
    return out;
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
        Endlosschleifebeben();

        if (Abfrage == 2)
        {
            std::cout <<std::endl <<std::endl;
            std::cout <<"Sind sie sich wirklich sicher?" <<std::endl;
            std::cout <<"Wenn das Importierte Bild eine hohe Aufloesung hat, sollte dieses nicht auf der Konsole ausgegeben werden." <<std::endl;
            std::cout <<"Das Ausgeben des Bildes kann unter umstaenden mehrere Minuten dauern und kann nicht unterbrochen werden." <<std::endl;
            std::cout <<"(1)    Bild nicht auf Konsole ausgeben (meisten empfohlen)" <<std::endl;
            std::cout <<"(2)    Bild auf Konsole ausgeben (in den meinsten Faellen nicht empfohlen)" <<std::endl;
            std::cin >>Abfrage;
            Endlosschleifebeben();
        }

        std::cout <<std::endl <<std::endl;
    } while (Abfrage != 1 && Abfrage != 2);
    return Abfrage;
}

void Endlosschleifebeben()
{
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(INT8_MAX, '\n');
    }
}