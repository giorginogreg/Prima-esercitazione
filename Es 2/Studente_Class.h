#ifndef STUDENTE_CLASS_H
#define STUDENTE_CLASS_H
#include <string>
using namespace std;

class Studente_Class
{
    public:
        Studente_Class(): matricola(0), nome(""), cognome(""), eta(0){}; // Initialized constructor
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