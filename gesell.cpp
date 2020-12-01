#include "gesell.h"
#include "tokenizer.h"
#include <iostream>
#include <fstream>
#include <sstream>

Gesell::Gesell():
    myAbk(""),
    myGName(""),
    myAnzVerb(0)
 {}
Gesell::Gesell(std::string abk, std::string gName, int anzVerb):
    myAbk(abk),
    myGName(gName),
    myAnzVerb(anzVerb)
 {}

std::string Gesell::umwandl() const{
    std::ostringstream oss;
    oss<<myAbk<<"^"<<myGName<<"^"<<myAnzVerb;
    return oss.str();
}

std::ostream& operator<<(std::ostream& str, const Gesell& gesell){
    str<<"[Fluggesellschaft]"<<gesell.abk()<<" "<<gesell.gName()<<" "<<gesell.anzVerb();
    return str;
}

Gesell createGesell(const std::string& s){
    Tokenizer tok(s, '^');

    std::istringstream sAbk(tok.next());
    std::string abk;
    sAbk>>abk;

    std::istringstream sGName(tok.next());
    std::string gName;
    sGName>>gName;

    std::istringstream sAnzVerb(tok.next());
    int anzVerb;
    sAnzVerb>>anzVerb;

    return Gesell(abk, gName, anzVerb);


}
