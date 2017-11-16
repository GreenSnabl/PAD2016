/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MP3Lib.cpp
 * Author: dennis
 * 
 * Created on November 15, 2017, 9:36 PM
 */

#include "MP3Lib.h"

void menu(){
    
}



void Lied::setInterpret(std::string newInterpret) {if (newInterpret.size() < 80 && newInterpret.size() > 0) interpret = newInterpret;}
void Lied::setTitle(string newTitle) { if(newTitle.size() < 100 && newTitle.size() > 0) titel = newTitle;}
void Lied::setYear(int year) {if(year > 0 && year < 2018) erscheinungsjahr = year;}
void Lied::setLength(double len) {if (len > 0) laenge = len;}
void Lied::setGenre(int newGenre) {if (newGenre >= 0 && newGenre < 6) genre = (Genre)newGenre;}


Lied::Lied(string title, string interpreter, int year, double len, int genre)
{
    setTitle(title);
    setInterpret(interpreter);
    setYear(year);
    setLength(len);
    setGenre(genre);
}

string Lied::getGenre()
{
    switch ((int)genre)
    {
        case 0: return "Pop"; break;
        case 1: return "Rock"; break;
        case 2: return "Klassik"; break;
        case 3: return "Hard_Rock"; break;
        case 4: return "Metal"; break;
        case 5: return "Hip_Hop"; break;    
    }
}

void Lied::print()
{
    cout << "Interpret: " << getInterpret() << "\n" 
         << "Titel: " << getTitle() << "\n" 
         << "Erscheinungsjahr: " << getYear() << "\n"
         << "Lange: "<< getLen() << " min\n"
         << "Genre: " << getGenre() << "\n";
}

void Liedverwaltung::addLied()
{
    cin.ignore();
    Lied l;
    std::string str;
    int year, genre;
    double length;
    cout << "Interpret: ";
    getline(cin, str);
    l.setInterpret(str);
    cout << "\nTitel: ";
    getline(cin, str);
    l.setTitle(str);
    cout << "\nErscheinungsjahr: ";
    cin >> year;
    l.setYear(year);
    cout << "\nLänge: ";
    cin >> length;
    l.setLength(length);
    cout << "\nGenre:\n "
         << "\t(1) Pop\t\t(2) Rock\t(3) Klassik\n\t(4) Hard Rock\t(5) Metal\t(6) Hip Hop\n";
    cin >> genre;
    l.setGenre(genre-1);
    
    lieder.push_back(l);
}

void Liedverwaltung::printAll()
{
    for (int i = 0; i < lieder.size(); ++i)
    {
        lieder[i].print();
        cout << "\n";
    }


}

int Liedverwaltung::getIndex()
{
   int index; 
   cout << "Anzahl der Einträge: " << lieder.size() << "\n"
        << "Geben Sie bitte den Index des gewünschten Eintrags an: ";
   while(cin >> index)
   if (index > 0 && index <= lieder.size()) return index;
   else cout << "Keine gültige Eingabe, bitte geben Sie einen gültigen Index an.";
}

void Liedverwaltung::printEntry()
{
    int index = getIndex();
    lieder[index-1].print();
}

void Liedverwaltung::eraseLied(int index)
{
    if(index < lieder.size()-1 && index >= 0) {
    for (int i = index; i < lieder.size() - 1; ++i)
    {
        lieder[i] = lieder[i+1];    
    }
    }
    if(index < lieder.size() && index >= 0) lieder.pop_back();
}

void Liedverwaltung::editSong()
{
    int index = -1;
    string str;
    int year, genre;
    double length;
    if(lieder.size() == 0) {cout << "Keine Einträge vorhanden!\n\n"; return;}
    cout << "Welchen Eintrag wollen Sie bearbeiten?\n\n Bitte geben Sie die Liednummer an:\n";
    cin >> index;
    while (index < 1 || index > lieder.size()) {cout << "Falsche Eingabe! Geben Sie einen gültigen Wert zwischen 1 und " << lieder.size() << " an."; cin >> index;}
    char token = 1;
    while(token != 0) {
    cout << "Welche Details sollen verändert werden?\n\n"
            << "\t(I)nterpret\n"
            << "\t(T)itel\n"
            << "\t(E)rscheinungsjahr\n"
            << "\t(D)auer\n"
            << "\t(G)enre\n\n"
            << "Drücken Sie \"0\" zum Beenden\n";
    cin >> token;
    switch (token)
    {
        case 'i': case 'I': cin.ignore(); cout << "\nInterpret: "; getline(cin, str); lieder[index-1].setInterpret(str); break;
        case 't': case 'T': cin.ignore(); cout << "\nTitel: "; getline(cin, str); lieder[index-1].setTitle(str); break;
        case 'e': case 'E': cout << "\nErscheinungsjahr: "; cin >> year; lieder[index-1].setYear(year); break;
        case 'd': case 'D': cout << "\nLänge: "; cin >> length; lieder[index-1].setLength(length); break;
        case 'g': case 'G': cout << "\nGenre:\n\t(1) Pop\t\t(2) Rock\t(3) Klassik\n\t(4) Hard Rock\t(5) Metal\t(6) Hip Hop\n"; cin >> genre; lieder[index-1].setGenre(genre); break;
        case 48: return;
    }
    cout << "\n";
    
    }

}