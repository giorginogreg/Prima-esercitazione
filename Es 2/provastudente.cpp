#include "Studente_Class.h"
#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    Studente_Class s;

    bool redo = true;    
    int matricola;
    do
    {
        cout << "Inserisci la matricola dello studente" << endl;
        cin >> matricola;
        if (matricola > 255312 && matricola <= 499999) {
            s.set_matricola(matricola);
            redo = false;
        } else 
            cout << "La matricola inserita non è valida. Riprova." << endl;
    } while (redo);


    string nome;
    redo = true;
    do
    {
        cout << "Inserisci il nome dello studente: " << endl;
        cin >> nome;
        if (nome.size() < 30) {
            s.set_nome(nome);
            redo = false;
        } else
            cout << "Il nome inserito supera i 30 caratteri (limite massimo). Riprova." << endl;
    } while (redo);
    

    string cognome;
    redo = true;
    do
    {
        cout << "Inserisci il cognome dello studente: " << endl;
        cin >> cognome;
        if (cognome.size() < 30) {
            s.set_cognome(cognome);
            redo = false;
        } else
            cout << "Il cognome inserito supera i 30 caratteri (limite massimo). Riprova." << endl;
    } while (redo);
    
   
    int eta;
    redo = true;
    do
    {
        cout << "Inserisci l'età dello studente: " << endl;
        cin >> eta;
        if (eta >= 12 && eta <= 105)
        {
            redo = false;
            s.set_eta(eta);
        } else
            cout << "L'età deve essere compresa fra i 12 e i 105 anni. Riprova." << endl;            
    } while (redo);
    
    cout << s;

    return 0;
}
