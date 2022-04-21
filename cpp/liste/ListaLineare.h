
template <class T, class P>
class ListaLineare { // Classe astratta
    public:
        typedef T tipoelem;   // Tipologia degli elementi
        typedef P posizione; // Posizione dell'elemento all'interno della lista
    
        virtual ListaLineare crealista();
        virtual bool listaVuota() const;

        virtual tipoelem leggiLista(posizione) const;
        virtual void scriviLista(tipoelem, posizione);

        virtual posizione primoLista() const; // const = vincolo che non ti permette la modifica dello stato dell'oggetto
        virtual posizione fineLista() const; 

        virtual posizione succLista(posizione) const;
        virtual posizione predLista(posizione) const;

        virtual void insLista(tipoelem, posizione);
        virtual void cancLista(posizione);

    // protected:

    // private:
};