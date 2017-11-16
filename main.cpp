#include "MP3Lib.h"
#include "DynArray.h"

int main() {

    Liedverwaltung liedverwaltung1;
    char answer;
    while(answer != 48){
    cout << "************ Musikbibliothek Verion 0.1 **************\n"
         << "Hauptmenu:\n"
         << "1. (N)euen Eintrag anlegen\n"
         << "2. (D)etails eines Eintrags anzeigen\n"
         << "3. Einen Eintrag (l)oeschen\n"
         << "4. Einen Eintrag (b)earbeiten\n"
         << "5. Einen Eintrag (s)uchen\n"
         << "6. (A)lle Einträge anzeigen\n\n"
         << "0. Programm beenden\n";
    cin >> answer;
    switch (answer)
    {
        case 'N': case 'n': liedverwaltung1.addLied(); break;
        case 'D': case'd': liedverwaltung1.printEntry(); break;
        case 'L': case 'l': 
            int index; cout << "Bitte geben Sie die Liednummer des zu löschenden Eintrags an:\n"; 
            cin >> index; liedverwaltung1.eraseLied(index-1); 
            break;
        case 'B': case 'b': liedverwaltung1.editSong(); break;
        case 'S': case 's':
        case 'A': case 'a': liedverwaltung1.printAll(); break;
    }
    }
    return 0;
}

