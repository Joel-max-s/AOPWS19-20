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
 * @class Bild
 * @brief Klasse für das Bild
*/
class Bild
{
    private:
        std::string Kommentar; /**< enthält den vom Benutzer eingegebenen Kommentar */
        std::vector <unsigned int> Aufloesung; /**< enthält die Auflösung vom pgm-Bild */
        std::vector <unsigned char> EineZeile; /**< Zwischenspeicher für eine Zeile von der Matrix */
        std::vector <std::string> DateialsString; /**< enthält die eingelesenen Daten vom pgm-Bild als strings */
        std::vector <std::string> AndereDateialsString; /**< enthält umgewandelte Daten vom pgm-Bild als string, wird nur benötigt wenn das PGM im "1-Pixel-pro-Zeile" Format importiert wird */
        std::vector <std::vector <unsigned char>> Bildfertig; /**< enthät die Daten vom eingelesenen pgm-Bild als unsigned chars */
        std::vector <std::vector <unsigned char>> BearbeitetesBild; /**< enthält die Daten vom bearbeiteten pgm-Bild als unsigned chars */
        
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
         * @fn fuelleBearbeitetesBild()
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
         * @fn SpeichertAufloesung()
         * @brief Liest die Aufloesung und Speichert sie in einen Vektor
         * @see Bild::DateialsString
         */
        void SpeichertAufloesung ();
        
        /**
         * @fn SpeichertDaten(int, int)
         * @brief Wandelt eine als String gespeicherte Bildzeil in unsigned chars um
         * @param 1 int Gibt an welcher Stelle die Datei in unsigned chars konvertiert werden soll
         * @param 2 int Gibt an aus welchem Vektor die Inhalte konvertiert werden sollen
         * @pre param 1 muss eine Zahl größer als 0 sein
         * @pre param 2 muss entweder 1 oder 2 sein
         * @returns Vektor der Eine Zeile der Matrix speichert
         * @see Bild::SetzeBildzusammen(int), Bild::DateialsString, Bild::AndereDateialsString
        */
        std::vector <unsigned char> SpeichertDaten (int, int);

        /**
         * @fn Bildgeglaettet() const
         * @brief Glaettet das pgm-Bild
         * @returns 2-Dimensionalen Vektor der die Pixeldaten des Bildes als unsigned chars enthält
        */
        std::vector <std::vector <unsigned char>> Bildgeglaettet() const;

        /**
         * @fn Bildkantenbild() const
         * @brief Hebt die Kanten vom pgm-Bild hervor
         * @returns 2-Dimensionalen Vektor der die Pixeldaten des Bildes als unsigned chars enthät
        */
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
