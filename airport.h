#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport
{
  private:
    std::string myKur;
    std::string myName;
    int myDist;

  public:
    Airport();
    Airport(std::string kur, std::string name, int dist);

   //Getter
    std::string kur() const {return myKur;}
    std::string name() const {return myName;}
    int dist () const {return myDist;}

   //Setter
    void setKur(std::string kur){myKur = kur;}
    void setName(std::string name){myName = name;}
    void setDist(int dist){myDist = dist;}

    //Zum Speichern in String umwandeln
    std::string umwandl() const;

    //Loeschen
    void loeschen();

};
//Debug-Ausgabe im Stream
std::ostream& operator<<(std::ostream& str, const Airport& Airport);

//erstellen
Airport createAirport(const std::string& s);

#endif // AIRPORT_H
