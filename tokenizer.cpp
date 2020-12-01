#include "tokenizer.h"

Tokenizer::Tokenizer(const std::string& s, char delimeter):
    myString(s), myDelim(delimeter), myPos(0)
{ //Sonderbehandlung Leerstring
    if (myString.size() == 0)
        myPos=std::string::npos;
}

std::string Tokenizer::next(){
    std::string::size_type newpos = myString.find(myDelim, myPos);
    std::string res = myString.substr(myPos, newpos-myPos);
    //nur bei Trennezichen aktuelle Pos nach das Trennzeochen setzen
    myPos=(newpos == std::string::npos) ? newpos : newpos+1;
    return res;
}

bool Tokenizer::hasMore() const{
    return myPos != std::string::npos;
}
