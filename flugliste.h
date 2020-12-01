#ifndef FLUGLISTE_H
#define FLUGLISTE_H
#include "flug.h"


class FlugListe
{
private:
    Flug myFlugListe[500];
    int myBig;
public:

    FlugListe();
    int gibBig();
    std::string gibKurz(int i);
    int gibNummer(int i);
    std::string gibStart(int i);
    std::string gibZiel(int i);
    void addFlug(const Flug& flug);
    void readFile(const std::string fListe);
    void loeschen(const std::string fkur, int fnr);
    void show();
    void writeFile(const std::string fListe);
};


#endif // FLUGLISTE_H
