/**
 * @file Funktionen.hpp
 * @brief Header Datei für Funktionen die in der main benötigt werden
 * @author Joel Maximilian Seidel
*/

#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Bild.hpp"

/**
 * Falls etwas bei einer Eingabe schiefgelaufen ist, behebt diese Funktion Endlosschleifen.
 * Dies geschieht indem der Buffer geleert und Enters ignoriert werden.
 * @fn Endlosschleifebeben()
 * @brief beugt Endlosschleifen vor
*/
void Endlosschleifebeben();

/**
 * Der Benutzer wird gefragt welche pgm-Datei importiert werden soll.
 * @fn AbfrageImportierName()
 * @brief Fragt Import-Datei ab
 * @returns den Dateinamen
*/
std::string AbfrageImportierName();

/**
 * Der Benutzer wird gefragt wie die zu exportierende pgm-Datei genannt werden soll.
 * @fn AbfrageExportierName()
 * @brief Fragt nach Export-Namen
 * @returns den Dateinamen
*/
std::string AbfrageExportierName();

/**
 * Der Benutzer wird gefragt ob das Bild auf der Konsole ausgegeben werden soll.
 * @fn AbfrageBildaufKonsoleAusgeben()
 * @brief Fragt nach Konsolenausgabe
 * @returns int der darüber entscheidet ob das Bild auf der Konsole ausgegeben werden soll
 * @see operator<< (std::ostream&, const Bild&)
*/
int AbfrageBildaufKonsoleAusgeben();

/**
 * Die pgm-Datei wird eingelesen und in dem Vektor Bild::DateialsString gespeichert.
 * @fn operator>> (std::ifstream&, Bild&)
 * @brief liest Datei ein
 * @see Bild::DateialsString
*/
std::istream& operator>> (std::ifstream&, Bild&);

/**
 * @fn operator<< (std::ostream&, const Bild&)
 * @brief kann das bearbeitete Bild auf der Konsole ausgeben
*/
std::ostream& operator<< (std::ostream&, const Bild&);

/**
 * @fn operator<< (std::ofstream&, const Bild&)
 * @brief schreibt die Daten vom bearbeiteten Bild in eine pgm-Datei
*/
std::ostream& operator<< (std::ofstream&, const Bild&);