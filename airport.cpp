#include "airport.h"
#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <sstream>



Airport::Airport():
    myKur(""),
    myName(""),
    myDist(0)
 {}
Airport::Airport(std::string kur, std::string name, int dist):
    myKur(kur),
    myName(name),
    myDist(dist)
 {}

std::string Airport::umwandl() const{
    std::ostringstream oss;
    oss<<myKur<<"^"<<myName<<"^"<<myDist;
    return oss.str();
}

std::ostream& operator<<(std::ostream& str, const Airport& airport){
    str<<"[Flughafen]"<<airport.kur()<<" "<<airport.name()<<" "<<airport.dist();
    return str;
}

Airport createAirport(const std::string& s){
    Tokenizer tok(s, '^');

    std::istringstream sKurz(tok.next());
    std::string kur;
    sKurz>>kur;

    std::istringstream sName(tok.next());
    std::string name;
    sName>>name;

    std::istringstream sDist(tok.next());
    int dist;
    sDist>>dist;

    return Airport(kur, name, dist);


}
