#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "airport.h"
#include "airpliste.h"

AirpListe::AirpListe():
    mySize(0)
{
}

int AirpListe::gibSize(){
    return mySize;
}

std::string AirpListe::gibName(int i){
    return myAirpListe[i].name();
}

void AirpListe::addAirport(const Airport& airport){
    myAirpListe[mySize] = airport;
    mySize++;
}

void AirpListe::readFile(const std::string liste){
    std::ifstream fi(liste.c_str());
    if(!fi){
        std::cout<<"Datei"<<liste<<"kann nicht geoeffnet werden. \n";
        return;
    }
  std::string line;
  while (getline (fi,line)){
      //Zeilen überspringen
      if (line.size()==0 || line[0] =='#' || line[0] =='^'){
          continue;
      }
     Airport airport=createAirport(line);
     myAirpListe[mySize] = airport;
     mySize++;
  }
  fi.close();
}

/*void AirpListe::loeschen(std::string akurz){
    int i, k;
    for(i = 0; i < mySize; i++){  //Suche Position
        if(myAirpListe[i].kur() == akur){
            for(k = i; k < mySize; k++){ //loesche Element
                myAirpListe[k] = myAirpListe[k+1];
          }
            mySize--;
            }

     }
}
*/
void AirpListe::show(){
    for (int i = 0; i < mySize; i++){
        std::cout<< myAirpListe[i] <<std::endl;
    }
}

void AirpListe::writeFile(const std::string liste){
    std::ofstream fo(liste.c_str());
    if(!fo){
        std::cout<<"Datei kann nicht geschreiben werden! \n";
        return;
    }
    //Kommentar
    fo<<"#pro Zeile ein Objekt: \n";
    fo<<"#Kuerzel^Name^Distanz\n";
    for(int i = 0; i < mySize; i++){
        fo<<myAirpListe[i].umwandl()<<std::endl;
       }
    fo.close();
 }

