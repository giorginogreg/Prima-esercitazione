#ifndef STUDENTE_CLASS_H
#define STUDENTE_CLASS_H
#include <string>
using namespace std;

class Studente_Class
{
    public:
        int get_matricola() const;
        void set_matricola(int);

        string get_nome() const;
        void set_nome(string);

        string get_cognome() const;
        void set_cognome(string);
        
        int get_eta() const;
        void set_eta(int);

        friend ostream &operator <<(ostream&, Studente_Class&);

    private:
        int matricola;
        string nome;
        string cognome;
        int eta;
};

#endif