/**
 * @file Bild.hpp
 * @brief Header Datei für die Klasse Bild
 * @author Joel Maximilian Seidel
*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/**
 * @fn Behebeendlosschleife
 * @brief leert Buffer von Eingabestrom und lässt das "Enter ignorieren um Endlosschleifen vorzubeugen"
*/
void Behebeendlosschleife();

/**
 * @class Bild
 * @brief Klasse für das Bild
*/
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
        /**
         * @fn Bild()
         * @brief leerer Konstruktor für die Klasse Bild
        */
        Bild();

        /**
         * @fn AbfrageKommentar()
         * @brief Lässt Benutzer Kommentar in Bild schreiben
        */
        void AbfrageKommentar();

        /**
         * @fn SetzeBildZusammen(int)
         * @brief Füllt einen Vektor in dem die Auflösung gespeichert ist, Füllt einen anderen Zweidimensionalen Vektor in dem die Helligkeiten der Pixel gespeichert werden
         * @param 1 int Entscheidet über welche Methode weitergerechnet werden soll
         * @pre param 1 muss entweder 1 oder 2 sein
        */
        void SetzeBildZusammen(int);

        /**
         * @fn fuelleBearbeitetrsBild()
         * @brief füllt einen Vektor mit den bearbeiteten Bilddaten
        */
        void fuelleBearbeitetesBild();

        /**
         * @fn SetzeBildanderszusammen(int)
         * @brief Wandelt ein eine-Zahl-pro-Zeile Bild in einen 2D-Vektor um
         * @param 1 int Entscheidet darüber ob Methode überhaupt ausgeführt werden muss
         * @pre param 1 muss 2 sein damit die Methode wirksam ist
        */
        void SetzeBildanderszusammen(int);

        /**
         * @fn TestetgroessevonDateialsString()
         * @brief Anhand der Anzahl der Eingelesenen Zeilen wird entschieden ob die eingelesenen Daten noch konvertiert werden müssen
         * @returns int 1 oder int 2
         * @see Bild::SetzeBildanderszusammen, Bild::SetzeBildZusammen
        */
        int TestetgroessevonDateialsString();

        /**
         * @fn SpeichertAufloesung();
         * 
         */
        void SpeichertAufloesung ();
        
        /**
         * @fn 
         * @brief
         * @param 1
         * @param 2
         * @pre
         * @pre
         * @returns Vektor der Eine Zeile der Matrix speichert
         * @see Bild::SetzeBildzusammen(int)
        */
        std::vector <unsigned char> SpeichertDaten (int, int);
        std::vector <std::vector <unsigned char>> Bildgeglaettet() const;
        std::vector <std::vector <unsigned char>> Bildkantenbild() const;

        /**
         * @fn operator>>
         * @brief Als friend gesetzt damit auf die Klasse zugegriffen werden kann
        */
        friend std::istream& operator>> (std::ifstream& in, Bild& Bild1);
        
        /**
         * @fn operator<<
         * @brief Als friend gesetzt damit auf die Klasse zugegriffen werden kann
        */
        friend std::ostream& operator<< (std::ostream& out, const Bild& Bild1);     

        /**
         * @fn operator<<
         * @brief Als friend gesetzt damit auf die Klasse zugegriffen werden kann
        */   
        friend std::ostream& operator<< (std::ofstream& out, const Bild& Bild1);

        
        

};

