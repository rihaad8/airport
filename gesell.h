#ifndef GESELL_H
#define GESELL_H
#include <string>

class Gesell
{
private:
std::string myAbk;
std::string myGName;


public:

int myAnzVerb;


    Gesell();
    Gesell(std::string abk, std::string gName, int anzVerb);

 //Getter
    std::string abk()const{return myAbk; }
    std::string gName()const{return myGName;}
    int anzVerb() const {return myAnzVerb; }

 //Setter
    void setAbk(const std::string& abk) {myAbk = abk;}
    void setGName(const std::string& gName) {myGName = gName;}
    void setAnzVerb(int anzVerb){myAnzVerb = anzVerb; }

  //In String umwandeln
    std::string umwandl() const;

  //Loeschen
    void loeschen();
};
//Debug-Ausgabe im Stream
std::ostream& operator<<(std::ostream& str, const Gesell& gesell);
//erstellen
Gesell createGesell(const std::string& s);

#endif // GESELL_H
