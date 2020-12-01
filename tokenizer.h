#ifndef TOKENIZER_H
#define TOKENIZER_H
#include<string>

class Tokenizer{
private:
    std::string myString;
    char myDelim;
    std::string::size_type myPos;
public:
    Tokenizer(const std::string&s, char delimeter);
    std::string next();
    bool hasMore() const;
};

#endif // TOKENIZER_H
