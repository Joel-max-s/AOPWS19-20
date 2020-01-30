#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Bild.hpp"
#include "Funktionen.hpp"


int main()
{
    int Programmwiederholen = 1;
    do
    {
        std::string Importname = AbfrageImportierName();
        std::cout <<"Je nach Bildgroesse kann das Importieren ein wenig daueren..." <<std::endl <<std::endl <<std::endl;
        std::ifstream test(Importname);
        Bild Bild1;
        test >> Bild1;
        Bild1.SpeichertAufloesung();
        //Bild1.BerechneAufloesung();
        int Bildart = Bild1.TestetgroessevonDateialsString();
        Bild1.SetzeBildanderszusammen(Bildart);
        Bild1.SetzeBildZusammen(Bildart);
        try
        {
            Bild1.fuelleBearbeitetesBild();
            std::string Exportname = AbfrageExportierName();
            Bild1.AbfrageKommentar();
            std::ofstream raus(Exportname);
            raus << Bild1;
            int AufKonsoleAusgeben = AbfrageBildaufKonsoleAusgeben();
            if (AufKonsoleAusgeben == 2)
                std::cout << Bild1;
        }
        catch(const std::out_of_range& o)
        {
            std::cout <<"Die angegebne Datei ist beschaedigt!" <<std::endl <<std::endl <<std::endl;
        }
        
        std::cout <<"Moechten sie ein weiteres Bild bearbeiten?" <<std::endl;
        std::cout <<"(1)    ja" <<std::endl;
        std::cout <<"(2)    nein" <<std::endl;
        std::cin >>Programmwiederholen;
        std::cout <<std::endl <<std::endl;
    } 
    while (Programmwiederholen == 1);
    
    return 0;
}