package ProntoSocorro.src;

public class Celula {
    String nome;
    String classificacao;
    Celula proxima;

    public Celula(String nome, String classificacao) {
        this.nome = nome;
        this.classificacao = classificacao;
        this.proxima = null;
    }
}
