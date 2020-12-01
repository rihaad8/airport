#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "gesell.h"
#include "gesliste.h"

GesListe::GesListe():
myGross(0)
{
}
int GesListe::gibGross(){
    return myGross;
}
std::string GesListe::gibName(int j){
    return myGesListe[j].gName();
}

std::string GesListe::gibAbk(int j){
    return myGesListe[j].abk();
}

void GesListe::addGesell(const Gesell& gesell){
    myGesListe[myGross] = gesell;
    myGross++;
}

void GesListe::readFile(const std::string gListe){
    std::ifstream fi(gListe.c_str());
    if(!fi){
        std::cout<<"Datei"<<gListe<<"kann nicht geoeffnet werden. \n";
        return;
    }
  std::string line;
  while (getline (fi,line)){
      //Zeilen überspringen
      if (line.size()==0 || line[0] =='#' || line[0] =='^'){
          continue;
      }
     Gesell gesell=createGesell(line);
     myGesListe[myGross] = gesell;
     myGross++;
  }
  fi.close();
}

void GesListe::loeschen(std::string aAbk){
    int i, k;
    for(i = 0; i < myGross; i++){  //Suche Position
        if(myGesListe[i].abk() == aAbk){
            for(k = i; k < myGross; k++){ //loesche Element
                myGesListe[k] = myGesListe[k+1];
          }
            myGross--;
            }

     }
}

void GesListe::show(){
    for (int i = 0; i < myGross; i++){
        std::cout<< myGesListe[i] <<std::endl;
    }
}

void GesListe::writeFile(const std::string gListe){
    std::ofstream fo(gListe.c_str());
    if(!fo){
        std::cout<<"Datei kann nicht geschreiben werden! \n";
        return;
    }
    //Kommentar
    fo<<"#pro Zeile ein Objekt: \n";
    fo<<"#Kuerzel^Name^AnzVerb\n";
    for(int i = 0; i < myGross; i++){
        fo<<myGesListe[i].umwandl()<<std::endl;
       }
    fo.close();
 }

