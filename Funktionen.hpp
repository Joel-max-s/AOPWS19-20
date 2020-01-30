#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Bild.hpp"


int AbfrageBildart();
void Entlosschleifebehen();
std::string AbfrageImportierName();
std::string AbfrageExportierName();
int AbfrageBildaufKonsoleAusgeben();
std::istream& operator>> (std::ifstream&, Bild&);
std::ostream& operator<< (std::ostream&, const Bild&);
std::ostream& operator<< (std::ofstream&, const Bild&);