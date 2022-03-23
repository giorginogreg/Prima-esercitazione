# Struttura dati Lista

## Specifica sintattica

### Tipi
List - Lista su cui effettuare le operazioni (di tipo T, poichè ogni suo elemento è di tipo T)  
P - posizione  
T - Tipo dell'elemento


### Operatori
#### Modificatori
- create(): List l - Ritorna una lista vuota
- writeValue( List l, P pos, T elem of typeElem ): List l - Scrive nella posizione pos l'elemento T.
- insert( List l, P pos, T elem of typeElem): List l - Inserisce un nodo dopo il pos con il valore T
- delete( List l, P pos ): List l - Elimina l'elemento dalla posizione P
#### Osservatori
- readValue( List l, P pos ): T elem of typeElem
- isEmpty( List l ): boolean - vero se il numero di nodi è 1
- isLastPosition( List l, P pos ): boolean
- firstNodeList( List l ): P pos
- nextPosition( List l, P pos ): P pos
- previousPosition( List l, P pos ): P pos

**Ricordarsi di inserire i tipo nella specifica sintattica!**

## Specifica semantica
### Tipi
- lista: sequenza di nodi <elem₁, elem₂, ... , elemⁿ>, con 1 <= i <= n + 1.  Ogni elemento è di tipo typeElem, e l'i-esimo elemento ha valore elemᵢ e posizione pos(i)
- boolean: insieme dei valori di verità

Operatore | Input | Output | Specifica sintattica | Specifica semantica | Pre-condizioni | Post-condizioni | Note
---------|--|--------|---------|--|--|--|--
  create | - | List l  | create(): List l | create() = l' | - | l' = lista vuota | 
 writeValue | List l, P pos, T elem of typeElem | List l | writeValue:( List l, P pos, T elem of typeElem ): List l | writeValue(list, pos, elem) = list' | - |  list' = list + elemento elem in posizione pos | 
 insert | List l, P pos, T elem | List l | insert( List l, P pos, T elem of typeElem): List l | insert(list, pos, elem) = list' | 1 <= pos <= n + 1 | list' = (1 <= pos <= n) ? <a<sub>1</sub>, a<sub>2</sub> ... a<sub>i-1</sub>, **elem**, a<sub>i+1</sub>, ... a<sub>n</sub>> : a<sub>1</sub>, a<sub>2</sub> ... a<sub>i-1</sub>, a<sub>i</sub>, a<sub>i+1</sub>, ... a<sub>n</sub>, **elem**> | 
 delete | List l, P pos | List l | delete(List l, P pos): List l | delete(list, pos) = list' | 1 <= pos <= n + 1 | - | 
readValue | List l, P pos | T elem of typeElem | readValue(List, P): T | readValue(list, pos) = elem | 1 <= pos <= n + 1 | elem = elem(i) | 
isEmpty | List l | boolean | isEmpty(L): true\|false | isEmpty(list) = bool | - | b = ( list = <> ) | Operatore equivalente a isLastPosition(firstNodeList(list), list)
isLastPosition | List l, P pos | boolean | isLastPosition(List, P): true\|false | isLastPosition(list, pos) = b | 1 <= pos <= n + 1 | b = (pos == n + 1) | 
firstNodeList | List l | T elem of typeElem | firstValue( List ): P | firstValue( list ): pos | !isEmpty(list) | pos = pos(1) | 
nextPosition| List l, P pos |  P pos | nextPosition( List, P ): T | nextPosition(list, p) = elem | !isLastPosition(list, p) && !isEmpty(list) && p = pos(i), 1 <= i <= n | elem = pos(i + 1) | 
previousPosition | List l, P pos |  P pos | previousPosition( List, P ): T | nextPosition(list, p) = elem | p = pos(i), 1 < i <= n | elem = pos(i - 1) | 