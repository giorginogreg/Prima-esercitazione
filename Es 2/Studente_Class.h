#ifndef STUDENTE_CLASS_H
#define STUDENTE_CLASS_H
#include <string>
using namespace std;

class Studente_Class
{
    public:
        int get_matricola();
        void set_matricola(int);

        string get_nome();
        void set_nome(string);

        string get_cognome();
        void set_cognome(string);
        
        int get_eta();
        void set_eta(int);

        friend ostream &operator <<(ostream&, Studente_Class&);

    private:
        int matricola;
        string nome;
        string cognome;
        int eta;
};

#endif