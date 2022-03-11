#include "Studente_Class.h"
#include <iostream>

using namespace std;

int Studente_Class::get_matricola() const
{
    return matricola;
}

void Studente_Class::set_matricola(int m)
{
    matricola = m;
}

string Studente_Class::get_nome() const
{
    return nome;
}

void Studente_Class::set_nome(string n)
{
    nome = n;
}

string Studente_Class::get_cognome() const
{
    return cognome;
}

void Studente_Class::set_cognome(string c)
{
    cognome = c;
}

int Studente_Class::get_eta() const
{
    return eta;
}

void Studente_Class::set_eta(int e)
{
    eta = e;
}

ostream &operator <<(ostream& stream, Studente_Class& studente)
{
    stream << "Nome: " << studente.get_nome() << endl;
    stream << "Cognome: " << studente.get_cognome() << endl;
    stream << "Matricola: " << studente.get_matricola() << endl;
    stream << "Età: " << studente.get_eta() << endl;
    return stream;
}

