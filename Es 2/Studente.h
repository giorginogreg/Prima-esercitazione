#pragma once

#include <string>
using namespace std;

struct Studente
{
    int matricola;
    string nome;
    string cognome;
    int eta;
};

typedef struct Studente s;
void set_matricola(Studente &s);
