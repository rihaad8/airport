#include  <fstream>
#include  <string>
#include  <stdlib.h>
#include  <iostream>
#include  "flug.h"
#include "flugliste.h"

FlugListe::FlugListe():
    myBig(0)
{
}
int FlugListe::gibBig(){
    return myBig;
}
std::string FlugListe::gibKurz(int i){
    return myFlugListe[i].kurz();
}

int FlugListe::gibNummer(int i){
    return myFlugListe[i].nummer();
}

std::string FlugListe::gibStart(int i){
    return myFlugListe[i].start();
}

std::string FlugListe::gibZiel(int i){
    return myFlugListe[i].ziel();
}

void FlugListe::addFlug(const Flug& flug){
    myFlugListe[myBig]= flug;
    myBig++;
}

void FlugListe::readFile(const std::string fListe){
    std::ifstream fi(fListe.c_str());
    if(!fi){
        std::cout<<"Datei"<<fListe<<"kann nicht geoeffnet werden.\n";
        return;
    }
    std::string line;
    while (getline(fi,line)){
        //Zeilen überspringen
        if (line.size()==0 || line[0] =='#'|| line[0] =='^'){
            continue;
        }
        Flug flug=createFlug(line);
        myFlugListe[myBig]= flug;
        myBig++;
    }
    fi.close();
}


void FlugListe::loeschen(std::string fkur, int fnr){
    int i,k;

    for (i=0 ; i < myBig;i++){  //Position suchen


        if( myFlugListe[i].nummer() == fnr && myFlugListe[i].kurz() == fkur){
            for (k=i; k< myBig;k++){  //Element rauslöschen
                myFlugListe[k]= myFlugListe[k+1];
            }

            myBig--;
        }

    }

}


void FlugListe::show(){
    for (int i=0; i<myBig;i++){
        std::cout<< myFlugListe[i] <<std::endl;
    }
}

void FlugListe::writeFile(const std::string fListe){
    std::ofstream fo(fListe.c_str());
    if(!fo){
        std::cout<<"Datei kann nicht geschrieben werden!\n";
        return;
    }
    //Kommentar
    fo<<"#pro Zeile ein Objekt: \n";
    fo<<"#Nummer^Start^Ziel^Dauer\n";
    for (int i=0; i<myBig; i++){
        fo<<myFlugListe[i].umwandl()<<std::endl;
    }
    fo.close();
}
