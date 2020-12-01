#ifndef FLUG_H
#define FLUG_H


#include <string>


class Flug {
private:
    std::string myKurz;
    int myNummer;
    std::string myStart;
    std::string myZiel;
    int myZeit;

public:
   Flug();
   Flug(std::string kurz, int nummer, std::string start, std::string ziel, int zeit);

//Getter
   std::string kurz()const {return myKurz; }
   int nummer() const {return myNummer; }
   std::string start() const { return myStart; }
   std::string ziel()const { return myZiel; }
   int zeit() const { return myZeit; }

   //Setter
   void setKurz(const std::string& kurz){myKurz=kurz;}
   void setNummer(int nummer){myNummer = nummer;}
   void setStart(const std::string& start) {myStart=start;}
   void setFinal(const std::string& ziel){myZiel=ziel;}
   void setZeit(int zeit) {myZeit=zeit;}

   //In String fuer speichern in Datei umwandeln
   std::string umwandl() const;

   //Löschen
   void loeschen();
};
//Debug-Ausgabe im Stream
std::ostream& operator<<(std::ostream& str, const Flug& flug);
//erstellen
Flug createFlug(const std::string& s);


#endif // FLUG_H
