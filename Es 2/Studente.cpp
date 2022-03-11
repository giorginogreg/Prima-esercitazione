#include "Studente.h"
#include <iostream>

using namespace std;

void set_matricola(Studente &s, int matricola)
{
    s.matricola = matricola;
}

int get_matricola(Studente &s)
{
    return s.matricola;
}

void set_nome(Studente s, string nome)
{
    if (nome.size() < 30)
        s.nome = nome;
}
void set_cognome(Studente s, string cognome)
{
    if (cognome.size() < 30)
        s.cognome = cognome;
}
void set_eta(Studente s, int eta)
{
    if (eta >= 12 && eta <= 105)
    {
        s.eta = eta;
    }
}