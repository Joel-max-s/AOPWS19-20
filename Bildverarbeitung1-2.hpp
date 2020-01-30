#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Bild
{
    private:
        std::vector <std::vector <unsigned char>> Bildfertig;
        std::vector <std::string> DateialsString;
        std::vector <std::vector <unsigned char>> BearbeitetesBild;
        std::string Dateiname;
        std::vector <unsigned char> Aufloesung;
        std::vector <unsigned char> EineZeile;
    public:
        Bild();
        std::vector <unsigned char> SpeichertDaten (int);
        void SetzeBildZusammen();
        void Druckebildfertig();
        void fuelleBearbeitetesBild();
        std::vector <std::vector <unsigned char>> Bildgeglaettet() const;
        std::vector <std::vector <unsigned char>> Bildkantenbild() const;
        friend std::istream& operator>> (std::ifstream& in, Bild& Bild1);
        friend std::ostream& operator<< (std::ofstream& out, const Bild& Bild1);
        friend std::ostream& operator<< (std::ostream& out, const Bild& Bild1);
};

//Leerer Konstruktor
Bild::Bild () {}

//wandelt die Zahlen die als String gespeichert sind in int's um
std::vector <unsigned char> Bild::SpeichertDaten (int i)
{
    std::istringstream test(DateialsString.at(i));
    std::vector <unsigned char> Speichertest;
    int Wertalsint;
    unsigned char c;
    unsigned char Wertalschar;                
    while (test)
    {
        test >> Wertalsint;
        c = Wertalsint;
        Wertalschar = c;
    	Speichertest.push_back(Wertalschar);
        std::cout <<+Wertalschar <<std::endl;
    }
    return Speichertest;
}

//Füllt einen Vektor in dem die Auflösung von dem Bild gespeichert ist
//Füllt einen Vektor bestehen aus Vektoren in denen die Helligkeit der Pixel gespeichert ist
void Bild::SetzeBildZusammen()
{
    for (int i = 0; i < DateialsString.size(); i++)
    {
        if (i == 0)
            Aufloesung = SpeichertDaten(i);
        else
        {
            EineZeile = SpeichertDaten(i);
            Bildfertig.push_back(EineZeile);
        }
    }
}

//Druckt den zweidimensionalen Vektor auf die Konsole
void Bild::Druckebildfertig()
{
    for (int i = 0; i < Bildfertig.size(); i++)
    {
        for (int j = 0; j < Bildfertig.at(i).size() - 1; j++)
        {
            std::cout <<+Bildfertig.at(i).at(j) <<" ";
        }
        std::cout <<std::endl;
    }
}

//kann Bild glaetten
std::vector <std::vector <unsigned char>> Bild::Bildgeglaettet() const
{
    std::vector <std::vector <unsigned char>> neuesBild;
    neuesBild.resize(Aufloesung.at(1));
    for(int i = 0; i < neuesBild.size(); i++)
    {
        neuesBild.at(i).resize(Aufloesung.at(0));
    }

    std::cout <<neuesBild.at(1).size() <<"    " <<neuesBild.size() <<std::endl;

    for (int i = 0; i < Bildfertig.size(); i++)
    {
        for (int j = 0; j < Bildfertig.at(i).size() -1; j++)
        {
            if (i == 0 || i == Aufloesung.at(1) - 1 || j == 0 || j == Aufloesung.at(0) - 1)
            {
                neuesBild.at(i).at(j) = Bildfertig.at(i).at(j);
                std::cout <<+neuesBild.at(i).at(j) <<"  ";
            }
            else
            {
                neuesBild.at(i).at(j) = 0.125*(Bildfertig.at(i-1).at(j) + Bildfertig.at(i+1).at(j) + Bildfertig.at(i).at(j-1) + Bildfertig.at(i).at(j+1) + 4*(Bildfertig.at(i).at(j)));
                std::cout <<+neuesBild.at(i).at(j) <<"  ";
            }
        }
        std::cout <<std::endl;
    }
    return neuesBild;
}

//kann Kanten hervorheben
std::vector <std::vector <unsigned char>> Bild::Bildkantenbild() const
{
    std::vector <std::vector <unsigned char>> neuesBild;
    neuesBild.resize(Bildfertig.size()-1);
    for(int i = 0; i < neuesBild.size(); i++)
    {
        neuesBild.at(i).resize(Bildfertig.at(i).size()-1);
    }

    for (int i = 0; i < Bildfertig.size(); i++)
    {
        for (int j = 0; j < Bildfertig.at(i).size() -1; j++)
        {
            if (i == 0 || i == Aufloesung.at(1) - 1 || j == 0 || j == Aufloesung.at(0) - 1)
            {
                neuesBild.at(i).at(j) = 0;
                std::cout <<+neuesBild.at(i).at(j) <<"  ";
            }
            else
            {
                neuesBild.at(i).at(j) = 0.125*(Bildfertig.at(i-1).at(j) + Bildfertig.at(i+1).at(j) + Bildfertig.at(i).at(j-1) + Bildfertig.at(i).at(j+1) - 4*(Bildfertig.at(i).at(j)));
                std::cout <<+neuesBild.at(i).at(j) <<"  ";
            }
        }
        std::cout<< std::endl;
    }
    return neuesBild;
}

void Bild::fuelleBearbeitetesBild()
{
    unsigned int i;
    do
    {
        std::cout <<"1: Bild glaetten" <<std::endl;
        std::cout <<"2: Kanten vom Bild hervorheben" <<std::endl;
        std::cin >>i;
    }
    while (i != 1 && i != 2);
    if (i == 1)
        BearbeitetesBild = Bild::Bildgeglaettet();
        
    else if (i == 2)
        BearbeitetesBild = Bild::Bildkantenbild();
}
