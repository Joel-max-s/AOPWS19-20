#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Bild
{     
    public:
    	Bild(){}
        friend std::istream& operator>> (std::ifstream& in, Bild& Bild1);
        friend std::ostream& operator<< (std::ostream& out, const Bild& Bild1);
    private:
		std::vector <std::string> Dateialsstring;
};

std::istream& operator>> (std::ifstream& in, Bild& Bild1)
{
    //std::vector <std::string> Dateialsstring;
    std::ifstream& ifs (in);
	while( ifs )
    {
        std::string zeile;
    	std::getline(ifs, zeile);
        Bild1.Dateialsstring.push_back(zeile);
    }
    return in;
}

std::ostream& operator<< (std::ostream& out, const Bild& Bild1)
{
   int n = 0;
   while (n < Bild1.Dateialsstring.size()-1)
    {
    	out << Bild1.Dateialsstring.at(n) << "\n";
    	n++;
	}
   return out;
}


int main()
{
    std::ifstream test("feep.pgm");
    Bild Bild1;
    test >> Bild1;
    std::ofstream raus("nennenwieichwill.pgm");
	raus << Bild1;
	std::cout << Bild1;
}

