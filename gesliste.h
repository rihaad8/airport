#ifndef GESLISTE_H
#define GESLISTE_H
#include "gesell.h"

class GesListe
{
private:
    int myGross;
public:
    Gesell myGesListe[100];
    GesListe();
    int gibGross();
    std::string gibName(int j);
    std::string gibAbk(int j);
    void addGesell(const Gesell& gesell);
    void readFile(const std::string gListe);
    void loeschen(std::string aAbk);
    void show();
    void writeFile(const std::string gListe);


};


#endif // GESLISTE_H
