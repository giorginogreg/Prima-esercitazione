/*
 Definire la classe che modella una biblioteca come insieme di libri.
  Ciascun libro è definito dagli attributi autore, titolo e prezzo
  in modo che la coppia (autore, titolo) sia unica per ciascun libro nella biblioteca
	Esercizi
	1) Definire in biblioteca il metodo che conta il numero di libri con prezzo maggiore di una determinata
	soglia.

	2) Definire in biblioteca metodo che restituisce la mappa con la lista dei libri raggruppati per autore

	3) Definire in biblioteca il metodo che calcola il numero medio di libri scritti da ciascun autore incluso
	nella biblioteca
**/

import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.function.Consumer;
import java.util.function.Predicate;
import java.util.stream.Collectors;

public class Biblioteca extends HashSet<Libro> implements Predicate<Libro>, Consumer<Libro> {

	static HashSet<Libro> biblioteca = new HashSet<Libro>();

	public static void main(String[] args) {
		biblioteca.add(new Libro("Gaetano Dibenedetto", "La mia vita senza Gregorio", 100.4f));
		biblioteca.add(new Libro("Gregorio Giorgino", "Io più Gaetano = ∞", 304.4f));
		biblioteca.add(new Libro("Gaetano Dibenedetto", "Come sono diventato Gay", 52.2));
		biblioteca.add(new Libro("Gaetano Dibenedetto", "Mi piace sentire i cactus nel culo", 41.2));
		biblioteca.add(new Libro("Gaetano Dibenedetto", "La mia vita senza Gregorio", 100.4f));

		// biblioteca.stream().

		double soglia = 99.99;

		Predicate<Libro> predicato = (l) -> l.getPrezzo() > soglia;
		// Metodo 1
		// int count = (int) biblioteca.stream().filter( (l) -> l.getPrezzo() > soglia
		// ).count();

		// Metodo 2
		int count = count(predicato);
		System.out.println("I libri con soglia maggiore di " + soglia + " sono: " + count);

		Biblioteca.metodo2();

	}

	private static int count(Predicate<Libro> pred) {
		int k = 0;
		for (Libro libro : biblioteca) {
			if (pred.test(libro)) {
				k++;
			}
		}
		return k;
	}

	private static int conta(double d) {
		return (int) (biblioteca.stream().filter(l -> l.getPrezzo() >= d).map(l -> l.getAutore()).count());
	}

	private static void metodo2() {
		biblioteca.stream().forEachOrdered((l) -> {
			System.out.println(l.getTitolo());
		});
	}

	private static int metodo2_prof(double d) {

		return (biblioteca.stream().filter(l -> l.getPrezzo() >= d).mapToInt(l -> (int) l.getPrezzo()).reduce(0,
				(a, b) -> a + 1));

	}

	Map<String, List<Libro>> groupby() {
		return this.stream().collect(Collectors.groupingBy(Libro::getAutore));
	}

	double mediaLibiriPerAutore() {
		Map<String, List<Libro>> map = groupby();
		return map.values().stream().mapToInt(l -> l.size()).average().getAsDouble();
	}

	@Override
	public void accept(Libro t) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean test(Libro t) {
		// TODO Auto-generated method stub
		return false;
	}

}
