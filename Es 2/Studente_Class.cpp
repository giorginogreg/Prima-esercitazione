#include "Studente_Class.h"
#include <iostream>

using namespace std;

void Studente_Class::set_matricola(int m)
{
    matricola = m;
}

int Studente_Class::get_matricola()
{
    return matricola;
}

void Studente_Class::set_nome(string n)
{
    nome = n;
}

void Studente_Class::set_cognome(string c)
{
    cognome = c;
}

void Studente_Class::set_eta(int e)
{
    eta = e;
}

ostream &operator <<(ostream& stream, Studente_Class& studente)
{
    stream << "Nome: " << studente.nome << endl;
    stream << "Cognome: " << studente.cognome << endl;
    stream << "Matricola: " << studente.matricola << endl;
    stream << "Età: " << studente.eta << endl;
    return stream;
}

