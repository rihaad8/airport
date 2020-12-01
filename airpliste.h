#ifndef AIRPLISTE_H
#define AIRPLISTE_H
#include "airport.h"


class AirpListe
{
private:
    Airport myAirpListe[100];
    int mySize;
public:
    AirpListe();
    int gibSize();
    std::string gibName(int i);
    void addAirport(const Airport& airport);
    void readFile(const std::string liste);
    //void loeschen(std::string akurz);
    void show();
    void writeFile(const std::string liste);
};

#endif // AIRPLISTE_H
