@SuppressWarnings("serial")
public class Libro implements Comparable<Libro>{

	private String autore;
	private String titolo;
	private double prezzo;

	public Libro(String autore, String titolo, double prezzo) {

		this.autore = autore;
		this.titolo = titolo;
		this.prezzo = prezzo;
	}

	@Override
	public int hashCode() {
		return (autore+titolo).hashCode();
	}

	@Override
	public boolean equals(Object libro) {
		return (this.autore == ((Libro) libro).autore && this.titolo == ((Libro) libro).titolo);

	}

	/**
	 * @return the autore
	 */
	public String getAutore() {
		return autore;
	}

	/**
	 * @param autore the autore to set
	 */
	public void setAutore(String autore) {
		this.autore = autore;
	}

	/**
	 * @return the titolo
	 */
	public String getTitolo() {
		return titolo;
	}

	/**
	 * @param titolo the titolo to set
	 */
	public void setTitolo(String titolo) {
		this.titolo = titolo;
	}

	/**
	 * @return the prezzo
	 */
	public Double getPrezzo() {
		return prezzo;
	}

	/**
	 * @param prezzo the prezzo to set
	 */
	public void setPrezzo(Double prezzo) {
		this.prezzo = prezzo;
	}

	@Override
	public int compareTo(Libro libroDaConfrontare) {
		return this.autore.compareTo(libroDaConfrontare.autore);
	}

}
