#include <iostream>
#include "airpliste.h"
#include "airport.h"
#include "gesliste.h"
#include "gesell.h"
#include "flugliste.h"
#include "flug.h"
#include <fstream>
#include <string>
const std::string LISTE = "liste.dat";
const std::string GLISTE = "gliste.dat";
const std::string FLISTE = "fListe.dat";

std::string kleinschreiben(const std::string& wert) {
    std::string res;
    std::string::size_type k;
    for (k = 0; k < wert.length(); k++) {
        char c = wert[k];
        if (c >= 'A' && c <= 'Z') {
            c += 'a'-'A';
        }
        res += c;
    }
    return res;
}

void airportEingabe(AirpListe& airpListe){
    std::string kur = " ";
    std::string name = " ";
    int dist = 0;

    std::cout<<"Gib Kuerzel des Flughafens an: "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, kur);
    std::cout<<"Gib den vollen Namen des Flughafens an: "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, name);
    std::cout<<"Wie weit ist die Strecke zwischen Flughafen und Stadtzentrum?\nGib eine Strecke in km an: "<<std::endl;
    std::cin>>dist;
    Airport airport(kur, name, dist);
    airpListe.addAirport(airport);

}

void gesellEingabe(GesListe& gesListe){
    std::string abk = " ";
    std::string gName = " ";
    int anzVerb = 0;
    std::cout<<"Gib Kuerzel der Fluggesellschaft an: "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, abk);
    std::cout<<"Gib den vollen Namen der Fluggesellschaft an: "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, gName);
    Gesell gesell(abk, gName, anzVerb);
    gesListe.addGesell(gesell);
}

void flugEingabe(FlugListe& flugliste, AirpListe& airpListe){
    std::string kurz = " ";
    int nummer = 0;
    std::string start = " ";
    std::string ziel = " ";
    int zeit = 0;
    int i = 0;
    int pruef;
    std::string prob;
    int asize = airpListe.gibSize();


    std::cout<<"Gib Kuerzel der Fluggesellschaft an: "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, kurz);
    std::cout<<"Gib die Flugnummer an: "<<std::endl;
    std::cin>>nummer;
    while(i != 4){
        i = 0;
        pruef = nummer;
        while(pruef != 0){
            pruef /= 10;
            i++;
        }
        if(i != 4){
            i = 0;
            std::cout<<"Flugnummer muss 4stellig sein. Bitte neu eingeben! "<<std::endl;
            nummer = 0;
            std::cin>>nummer;

        }
    }
    std::cout<<"An welchem Flughafen startet der Flieger? "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, start);
    pruef = 0;
    std::string c = kleinschreiben(start);
    while(pruef == 0){
          int j = 0;
        for(j = 0; j < asize; j++){
            std::string var =airpListe.gibName(j);
            std::string varneu = kleinschreiben(var);
            if(c == varneu){ pruef++;}
        }
        if(pruef == 0){
            std::cout<<"Der eingegebene Flughafen existiert nicht. Bitte neu Eingeben."<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, start);
            c = kleinschreiben(start);
        }
    }


    std::cout<<"An welchem Flughafen landet der Flieger? "<<std::endl;
    std::cin>>std::ws;
    getline(std::cin, ziel);
    pruef = 0;
    c = kleinschreiben(ziel);
    while(pruef == 0){
          int j = 0;
        for(j = 0; j < asize; j++){
            std::string var = airpListe.gibName(j);
            std::string varneu = kleinschreiben(var);
            if(c == varneu){ pruef++;}
        }
        if(pruef == 0){
            std::cout<<"Der eingegebene Flughafen existiert nicht. Bitte neu Eingeben."<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, ziel);
            c = kleinschreiben(ziel);
        }
    }
    //pruef
    std::cout<<"Wieviele Minuten daurert der Flug? "<<std::endl;
    std::cin>>zeit;
    Flug flug(kurz, nummer, start, ziel, zeit);
    flugliste.addFlug(flug);
}

void gesellPruef(FlugListe& flugListe, GesListe& gesListe){

    std::string a, b;
    int fsize = flugListe.gibBig();
    int gsize = gesListe.gibGross();
    int i = 0;
    int pruef = 0;
    while(i < fsize){
        a = flugListe.gibKurz(i);
        std::string aneu = kleinschreiben(a);
        int j = 0;
        while(j < gsize){
            b = gesListe.gibAbk(j);
            j++;
            std::string bneu = kleinschreiben(b);
            //std::cout<<bneu;
            //std::cout<<cneu;
            if(bneu == aneu){pruef++;}
        }


        if(pruef == 0){
            std::cout<<"Fuer das Kuerzel "<<a<<" gibt es keine Gesellschaft."<<std::endl;
        }
        i++;
        if(pruef != 0){
            std::cout<<"Alle Kuerzel sind in einer Fluggesellschaft vertreten"<<std::endl;
            pruef = 0;
        }

    }
}

void ziele(FlugListe& flugListe, std::string abfrage){
    std::string a, b, c;
    int i = 0;
    int j = 0;
    int z = 1;
    int fsize = flugListe.gibBig();

    do{
        a = abfrage;
        b = flugListe.gibStart(i);
        std::string aneu = kleinschreiben(a);
        std::string bneu = kleinschreiben(b);
        c = flugListe.gibZiel(i);
        if(aneu == bneu){
            std::cout<<"Ziel "<<z<<" ist "<<c<<std::endl;
            j++;
            z++;
        }
        i++;
    }while(i < fsize);
    if(j == 0){std::cout<<"Es wurden keine Ziele gefunden."<<std::endl; }
}

void verbindung(FlugListe& flugListe,std::string hafen1, std::string hafen2){
    std::string a, b;
    int i = 0;
    int j = 0;
    int fsize = flugListe.gibBig();

    do{
        a = hafen1;
        b = hafen2;
        std::string aneu = kleinschreiben(a);
        std::string bneu = kleinschreiben(b);
        while(i < fsize){
            std::string fstart = flugListe.gibStart(i);
            std::string fziel = flugListe.gibZiel(i);
            int fnummer = flugListe.gibNummer(i);
            std::string fkurz = flugListe.gibKurz(i);
            fstart = kleinschreiben(fstart);
            fziel = kleinschreiben(fziel);
            if((aneu == fstart || aneu == fziel) && (bneu == fstart || bneu == fziel)){
                std::cout<<"Es gibt eine Flugverbindung zwischen "<<hafen1<<" und "<<hafen2<<" mit der Kennung "<<fkurz<<" "<<fnummer<<std::endl;

                j++;
            }

            i++;
        }
        if(j == 0){std::cout<<"Es gibt keine Flugverbindung zwischen "<<hafen1<<" und "<<hafen2<<std::endl;}

    }while(i < fsize);
}

void verbGes(FlugListe& flugListe, GesListe& gesListe){
    std::string a, b;
    int fsize = flugListe.gibBig();
    int gsize = gesListe.gibGross();
    int j = 0;
    int verb = 0;
    while(j <= fsize){
        b = gesListe.gibAbk(j);
        std::string bneu = kleinschreiben(b);
        int i = 0;
        while(i <= gsize){
            a = flugListe.gibKurz(i);
            i++;
            std::string aneu = kleinschreiben(a);
            if(bneu == aneu){
                verb++;
                gesListe.myGesListe[j].myAnzVerb=verb;

            }
        }

        j++;

    }


    int posMax;
    Gesell speich;

    for (int k=0; k < gsize-1; k++)
    {
        posMax = k;

        for (int l=k+1; l < gsize; l++)
        {

            if (gesListe.myGesListe[l].myAnzVerb > gesListe.myGesListe[posMax].myAnzVerb)
                posMax=l;

        }

        if (posMax != k)
        {
            speich = gesListe.myGesListe[k];
            gesListe.myGesListe[k] = gesListe.myGesListe[posMax];
            gesListe.myGesListe[posMax] = speich;
        }
    }
    for(int h = 0; h < gsize; h++){
        std::cout<<"Anzahl der Verbindungen: "<<gesListe.myGesListe[h]/*<<" Name der Gesellschaft: "<<gesListe.myGesListe[h].gName()*/<<std::endl;
    }

}

void umstVerb(FlugListe& flugListe,std::string hafen3, std::string hafen4){


    int fsize = flugListe.gibBig();
    std::string a, ziel;
    std::string b, c, d;
    std::string zneu;
    a = kleinschreiben(hafen3);
    b = kleinschreiben(hafen4);
    for(int i = 0; i < fsize; i++){
        c = flugListe.gibStart(i);
        std::string cneu = kleinschreiben(c);
        if(a == cneu){
            ziel = flugListe.gibZiel(i);
            zneu = kleinschreiben(ziel);

        }
    }
    for(int j = 0; j < fsize; j++){
        d = flugListe.gibStart(j);
        std::string dneu = kleinschreiben(c);
        std::string e = flugListe.gibZiel(j);
        std::string eneu = kleinschreiben(e);
        if(zneu == dneu || b == eneu){
            std::cout<<"Sie erreichen "<<hafen4<<" mit Umstieg in "<<ziel<<" wenn Sie in "<<hafen3<<" starten."<<std::endl;

        }
    }
}

void display(AirpListe& airpListe, GesListe& gesListe, FlugListe& flugListe){
    int eing = 0;
    std::string fkur;
    int fnr;
    std::string abfrage;
    std::string hafen1;
    std::string hafen2;
    std::string hafen3;
    std::string hafen4;

    do{

        std::cout<<"Welche Funktion wollen sie ausfuehren? "<<std::endl;
        std::cout<<"[1]  Erfassen von Flughaefen"<<std::endl;
        std::cout<<"[2]  Erfassen von Flugverbindungen"<<std::endl;
        std::cout<<"[3]  Loeschen von Flugverbindungen"<<std::endl;
        std::cout<<"[4]  Erfassen von Fluggesellschaften"<<std::endl;
        std::cout<<"[5]  Gehoeren Kuerzel wirklich zu Fluggesellschaft"<<std::endl;
        std::cout<<"[6]  Erreichbare Ziele eines Flughafens"<<std::endl;
        std::cout<<"[7]  Liste aller Gesellschaften sortiert nach Anz. d. Verb."<<std::endl;
        std::cout<<"[8]  Besteht eine Verbindung zw. zwei Flughaefen"<<std::endl;
        std::cout<<"[9]  Besteht eine Verbindung wenn man einmal Umsteigt"<<std::endl;
        std::cout<<"[10] Gibt ALLE Daten aus"<<std::endl;
        std::cout<<"[11] Beende Programm und speichere alles in Dateien"<<std::endl;
        std::cin>>eing;

        switch(eing){
        case 1: //Flughafeneingabe
            airportEingabe(airpListe);

            break;

        case 2: //Flugverbindungseingabe
            flugEingabe(flugListe, airpListe);
            break;

        case 3: //obriges Loeschen
            std::cout<<"Bitte Kuerzel der Fluggesellschaft eingeben"<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, fkur);
            std::cout<<"Bitte vollstaendige Flugnummer des Fluges eingeben"<<std::endl;
            std::cin>>fnr;
            flugListe.loeschen(fkur, fnr);
            break;

        case 4: //Fluggesellschaftseingabe
            gesellEingabe(gesListe);
            break;

        case 5: //Kuerzel existent
            gesellPruef(flugListe, gesListe);
            break;

        case 6: //moegl. Ziele eines Flughafens
            std::cout<<"Fuer welchen Flughafen sollen die Ziele angezeigt werden?"<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, abfrage);
            ziele(flugListe, abfrage);
            break;

        case 7: //Liste aller Gesellschaften sortiert nach Anz. d. Verb.
            verbGes(flugListe, gesListe);
            break;
        case 8: //Besteht Verbindung zwischen 2 Flughaefen
            std::cout<<"Geben Sie einen der zwei Fluhaefen ein: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, hafen1);
            std::cout<<"Geben Sie den zweiten Fluhaefen ein: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, hafen2);
            verbindung(flugListe, hafen1, hafen2);
            break;

        case 9: //oberes mit umsteigen
            std::cout<<"Geben Sie den Startfluhaefen ein: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, hafen3);
            std::cout<<"Geben Sie den Landefluhaefen ein: "<<std::endl;
            std::cin>>std::ws;
            getline(std::cin, hafen4);
            umstVerb(flugListe, hafen3, hafen4);
            break;

        case 10: //gib alles aus
            std::cout<<"Gespeicherte Flughaefen: "<<std::endl;
            airpListe.show();
            std::cout<<"\nGespeichterte Fluggesellschaften: "<<std::endl;
            gesListe.show();
            std::cout<<"\nGespeichterte Flugverbindungen: "<<std::endl;
            flugListe.show();
            break;

        case 11:
            std::cout<<"Programm wird beendet und die Daten gespeichert."<<std::endl;
            break;

        default:
            std::cout<<"Falsche Eingabe! Bitte Zahl zwischen 1 und 9 waehlen."<<std::endl;
            break;
        }
    }while(eing != 11);

}

int main()
{
    AirpListe airpListe;
    GesListe gesListe;
    FlugListe flugListe;
    airpListe.readFile(LISTE);
    gesListe.readFile(GLISTE);
    flugListe.readFile(FLISTE);
    display(airpListe, gesListe, flugListe);
    airpListe.writeFile(LISTE);
    gesListe.writeFile(GLISTE);
    flugListe.writeFile(FLISTE);

    return 0;
}

