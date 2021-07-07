#include "array.cpp"
#include <iostream>
#include <iterator> // for iterators
#include <vector>   // for vectors
#include <sstream>
#include <iterator>
using namespace std;

void clearArr(ostringstream *oss, vector<int> *ar);

int main(int argc, char const *argv[])
{
     ostringstream oss;
     vector<int> ar = {1, 2, 5, 4, 5, 3, 6, 9};
     copy(ar.begin(), ar.end() - 1,
          ostream_iterator<int>(oss, ","));

     // Now add the last element with no delimiter
     oss << ar.back();

     cout << "Array di test: " << oss.str() << endl;

     // Now add the last element with no delimiter
     oss << ar.back();
     int greaterer = 1;
     int b = greaterThan(ar, greaterer);
     cout << "Ci sono " << b << " numeri più grandi di " << greaterer << endl;

     vector<int> testArr = {1, 2, 6};
     for (int el : testArr)
     {
          cout << "L'elemento " << el << (member(ar, el) ? "" : " NON")
               << " è stato trovato all'interno dell'array." << endl;
     }

     largestStruct l = largest(ar);
     cout << "L'elemento più grande trovato nell'array è " << l.largest << " in posizione " << l.pos << endl;

     remove(&ar, 5);

     oss.str("");
     oss.clear();
     copy(ar.begin(), ar.end() - 1,
          ostream_iterator<int>(oss, ","));

     // Now add the last element with no delimiter
     oss << ar.back();

     cout << "Array di test DOPO il remove: " << oss.str() << endl;

     remove(&ar, 5);

     cout << "Array di test DOPO il remove: " << oss.str() << endl;

     vector<int> testArrCrescente = {1, 2, 6};
     vector<int> testArrCostante = {0, 0, 0, 0};
     vector<int> testArrDecrescente = {0, -1, -20};
     vector<int> testArrNonOrdinato = {0, 1, -1, -20};

     try
     {
          int order = ordering(&testArrCrescente);
          cout << "Primo array, risultato: " << order << endl;

          order = ordering(&testArrCostante);
          cout << "Array costante, risultato: " << order << endl;

          order = ordering(&testArrDecrescente);
          cout << "Array decrescente, risultato: " << order << endl;

          order = ordering(&testArrNonOrdinato);
          cout << "Array non ordinato, risultato: " << order << endl;
     }
     catch (NotOrderedException &e)
     {
          cout << "ERRORE! " << endl;
          cerr << e.what() << '\n';
     }

     clearArr(&oss, &testArrCrescente);

     cout << "Array di test attuale: " << oss.str() << endl;

     reverse(testArrCrescente);

     clearArr(&oss, &testArrCrescente);

     cout << "Array di test dopo il reverse: " << oss.str() << endl;

     clearArr(&oss, &testArrNonOrdinato);

     cout << "Array di test attuale: " << oss.str() << endl;

     reverse(testArrNonOrdinato);

     clearArr(&oss, &testArrNonOrdinato);

     cout << "Array di test dopo il reverse: " << oss.str() << endl;

     return 0;
}

void clearArr(ostringstream *oss, vector<int> *ar)
{
     (*oss).str("");
     (*oss).clear();
     copy((*ar).begin(), (*ar).end() - 1,
          ostream_iterator<int>((*oss), ","));

     (*oss) << (*ar).back();
}
