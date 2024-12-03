package ProntoSocorro.src;

public class Main {
    public static void main(String[] args) {
        ListaComCabeca lista = new ListaComCabeca();

        lista.adicionarPaciente("Maria", "Baixo risco");
        lista.adicionarPaciente("João", "Baixo risco");
        lista.adicionarPaciente("Ana", "Médio risco");
        
        lista.mostrarPacientes();
    }
}
