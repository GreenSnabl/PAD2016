#ifndef MP3LIB_H
#define MP3LIB_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "DynArray.h"

using std::cout; using std::cin; using std::vector; using std::string; using std::ostringstream; using std::ostream; using std::istream;

enum Genre{Pop, Rock, Klassik, Hard_Rock, Metal, Hip_Hop};

void menu(); 


class Lied {
public:
    Lied();
    Lied(string , string , int , double , int) ;
   
    void print();
    
    void setTitle(string newTitle);
    void setInterpret(string newInterpret);
    void setYear(int year);
    void setLength(double len);
    void setGenre(int newGenre);
    
    string getTitle(){return titel;}
    string getInterpret(){return interpret;}
    int getYear(){return erscheinungsjahr;}
    double getLen(){return laenge;}
    string getGenre();
    
private:
    string titel;
    string interpret;
    int erscheinungsjahr;
    double laenge;
    Genre genre;
};

class Liedverwaltung{
public:
    void eraseLied(int index);
    void addLied();
    Lied findLied();
    void printAll();
    void editSong();
    int getIndex();
    void printEntry();
    int getSize();
    
private:
    DynArray lieder;
};


#endif /* MP3LIB_H */

