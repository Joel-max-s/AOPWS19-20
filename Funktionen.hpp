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
 * @fn Endlosschleifebeheben()
 * @brief beugt Endlosschleifen vor
*/
void Endlosschleifebeben();

/**
 * @fn AbfrageImportierName()
 * @brief Fragt den Benutzer welche pgm-Datei importiert werden soll
 * @returns den Dateinamen
*/
std::string AbfrageImportierName();

/**
 * @fn AbfrageExportierName()
 * @brief Fragt den Benutzer wie die zu exportierende pgm-Datei genannt werden soll
 * @returns den Dateinamen
*/
std::string AbfrageExportierName();

/**
 * @fn AbfrageBildaufKonsoleAusgeben()
 * @brief Fragt den Benutzer ob das bearbeitete Bild auf der Konsole ausgegeben werden soll
 * @returns int der darüber entscheidet ob das Bild auf der Konsole ausgegeben werden soll
 * @see operator<< (std::ostream&, const Bild&)
*/
int AbfrageBildaufKonsoleAusgeben();

/**
 * @fn operator>> (std::ifstream&, Bild&)
 * @brief liest die Datei ein und speichert die Daten in einen string
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