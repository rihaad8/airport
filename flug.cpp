#include "flug.h"
#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <sstream>

Flug::Flug():
    myKurz(" "),
    myNummer(0),
    myStart(" "),
    myZiel(" "),
    myZeit(0)
{}


Flug::Flug(std::string kurz, int nummer, std::string start, std::string ziel, int zeit):
    myKurz(kurz),
    myNummer(nummer),
    myStart(start),
    myZiel(ziel),
    myZeit(zeit)
{}

std::string Flug::umwandl() const{
    std::ostringstream oss;
    oss<<myKurz<<"^"<<myNummer<<"^"<<myStart<<"^"<<myZiel<<"^"<<myZeit;
    return oss.str();
}

std::ostream& operator<<(std::ostream& str, const Flug& flug){
    str<<"[Flug]"<<flug.kurz()<<" "<<flug.nummer()<<" "<<flug.start()<<" "<<flug.ziel()<<" "<<flug.zeit();
    return str;
}


Flug createFlug(const std::string& s){
    Tokenizer tok(s, '^');
    std::istringstream sKurz(tok.next());
    std::string kurz;
    sKurz>>kurz;

    std::istringstream sNummer(tok.next());
    int nummer;
    sNummer>>nummer;

    std::istringstream sStart(tok.next());
    std::string start;
    sStart>>start;

    std::istringstream sZiel(tok.next());
    std::string ziel;
    sZiel>>ziel;

    std::istringstream sZeit(tok.next());
    int zeit;
    sZeit>>zeit;
    return Flug(kurz, nummer, start, ziel, zeit);
}

