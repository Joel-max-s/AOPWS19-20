#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Bild
{
    private:
        std::string Kommentar;
        std::vector <unsigned int> Aufloesung;
        std::vector <unsigned char> EineZeile;
        std::vector <std::string> DateialsString;
        std::vector <std::string> AndereDateialsString;
        std::vector <std::vector <unsigned char>> Bildfertig;
        std::vector <std::vector <unsigned char>> BearbeitetesBild;
        
    public:
        Bild();
        void AbfrageKommentar();
        void SetzeBildZusammen(int);
        void fuelleBearbeitetesBild();
        void SetzeBildanderszusammen(int);
        std::vector <unsigned int> SpeichertAufloesung (int);
        std::vector <unsigned char> SpeichertDaten (int, int);
        std::vector <std::vector <unsigned char>> Bildgeglaettet() const;
        std::vector <std::vector <unsigned char>> Bildkantenbild() const;
        friend std::istream& operator>> (std::ifstream& in, Bild& Bild1);
        friend std::ostream& operator<< (std::ostream& out, const Bild& Bild1);        
        friend std::ostream& operator<< (std::ofstream& out, const Bild& Bild1);

        int TestetgroessevonDateialsString();
        void BerechneAufloesung();

};

//Leerer Konstruktor
Bild::Bild() {}

//wandelt die Zahlen die als String gespeichert sind in int's um
std::vector <unsigned char> Bild::SpeichertDaten (int i, int j)
{
    std::vector <unsigned char> Speichertest;
    int Wertalsint;
    unsigned char c;
    unsigned char Wertalschar;
    
    if (j == 1)
    {
        std::istringstream test(DateialsString.at(i));
        while (test)
        {
            test >> Wertalsint;
            c = Wertalsint;
            Wertalschar = c;
    	    Speichertest.push_back(Wertalschar);
        } 
    }

    if (j == 2)
    {
        std::istringstream test(AndereDateialsString.at(i));
        while (test)
        {
            test >> Wertalsint;
            c = Wertalsint;
            Wertalschar = c;
    	    Speichertest.push_back(Wertalschar);
        }
    }        
    
    return Speichertest;
}

std::vector <unsigned int> Bild::SpeichertAufloesung (int i)
{
    std::istringstream test(DateialsString.at(i));
    std::vector <unsigned int> Speichertest;
    int Wertalsint;              
    while (test)
    {
        test >> Wertalsint;
        Speichertest.push_back(Wertalsint);
    }
    return Speichertest;
}

//Füllt einen Vektor in dem die Auflösung von dem Bild gespeichert ist
//Füllt einen Vektor bestehen aus Vektoren in denen die Helligkeit der Pixel gespeichert ist
void Bild::SetzeBildZusammen(int Abfrage)
{
    if (Abfrage == 1)
    {
        for (int i = 1; i < DateialsString.size(); i++)
        {
            EineZeile = SpeichertDaten(i, 1);
            Bildfertig.push_back(EineZeile);
        }
    }
    if (Abfrage == 2)
    {
        for (int i = 0; i < AndereDateialsString.size(); i++)
        {
            EineZeile = SpeichertDaten(i, 2);
            Bildfertig.push_back(EineZeile);
        }
    }
}

void Bild::SetzeBildanderszusammen(int Abfrage)
{
    if (Abfrage == 2)
    {
        DateialsString.erase(DateialsString.begin());
        for (int i = 1; i < Aufloesung.at(1) +1; i++)
        {
            std::string Zusammengefasst;
            for (int j = 0; j < Aufloesung.at(0); j++)
            {
                Zusammengefasst += " " + DateialsString.at(Aufloesung.at(0)*(i-1) + j);
            }
            AndereDateialsString.push_back(Zusammengefasst);
        }
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

    for (int i = 0; i < Bildfertig.size(); i++)
    {
        for (int j = 0; j < Bildfertig.at(i).size() -1; j++)
        {
            if (i == 0 || i == Aufloesung.at(1) - 1 || j == 0 || j == Aufloesung.at(0) - 1)
            {
                neuesBild.at(i).at(j) = Bildfertig.at(i).at(j);
            }
            else
            {
                neuesBild.at(i).at(j) = 0.125*(Bildfertig.at(i-1).at(j) + Bildfertig.at(i+1).at(j) + Bildfertig.at(i).at(j-1) + Bildfertig.at(i).at(j+1) + 4*(Bildfertig.at(i).at(j)));
            }
        }
    }
    return neuesBild;
}

//kann Kanten hervorheben
std::vector <std::vector <unsigned char>> Bild::Bildkantenbild() const
{
    std::vector <std::vector <unsigned char>> neuesBild;
    neuesBild.resize(Aufloesung.at(1));
    for(int i = 0; i < neuesBild.size(); i++)
    {
        neuesBild.at(i).resize(Aufloesung.at(0));
    }

    for (int i = 0; i < Bildfertig.size(); i++)
    {
        for (int j = 0; j < Bildfertig.at(i).size() -1; j++)
        {
            if (i == 0 || i == Aufloesung.at(1) - 1 || j == 0 || j == Aufloesung.at(0) - 1)
            {
                neuesBild.at(i).at(j) = 0;
            }
            else
            {
                neuesBild.at(i).at(j) = 0.125*(Bildfertig.at(i-1).at(j) + Bildfertig.at(i+1).at(j) + Bildfertig.at(i).at(j-1) + Bildfertig.at(i).at(j+1) - 4*(Bildfertig.at(i).at(j)));
            }
        }
    }
    return neuesBild;
}

void Bild::fuelleBearbeitetesBild()
{
    unsigned int i;
    do
    {
        std::cout <<"Soll das Bild geglaettet werden oder die Kanten vom Bild hervorgehoben werden?" <<std::endl;
        std::cout <<"(1)    Bild glaetten" <<std::endl;
        std::cout <<"(2)    Kanten vom Bild hervorheben" <<std::endl;
        std::cin >>i;
        std::cout <<std::endl <<std::endl;
    }
    while (i != 1 && i != 2);
    if (i == 1)
        BearbeitetesBild = Bild::Bildgeglaettet();
        
    else if (i == 2)
        BearbeitetesBild = Bild::Bildkantenbild();
}

int Bild::TestetgroessevonDateialsString()
{
    unsigned long int a = DateialsString.size();
    if (Aufloesung.at(0) == 1)
        return 1;
    else if (a < Aufloesung.at(0)*Aufloesung.at(1))
        return 1;
    else
        return 2;
    
}

void Bild::BerechneAufloesung()
{
    Aufloesung = SpeichertAufloesung(0);
}

void Bild::AbfrageKommentar()
{
    int Abfrage;
    do
    {
        std::cout <<"Moechten sie einen Kommentar hinzufuegen?" <<std::endl;
        std::cout <<"(1)    ja" <<std::endl;
        std::cout <<"(2)    nein" <<std::endl;
        std::cin >>Abfrage;
        std::cout <<std::endl;
    } while (Abfrage != 1 && Abfrage != 2);

    if (Abfrage == 1)
    {
        std::cout <<"Bitte schreiben sie ihren Kommentar:" <<std::endl;
        std::cin >>Kommentar;
        std::cin.clear();
        std::cout <<std::endl <<std::endl;
    }

    else
    {
        std::cout <<std::endl;
        Kommentar = " ";
    }
}