public class SistemaSondagem {
    public static void main(String[] args) {
        FilaComCabeca fila = new FilaComCabeca();
        
        fila.cadastrarCrianca("Ana");
        fila.cadastrarCrianca("Bruno");
        fila.cadastrarCrianca("Carlos");
        fila.cadastrarCrianca("Daniela");

        fila.realizarSondagem();

        fila.cadastrarCrianca("Eduardo");
        fila.cadastrarCrianca("Fernanda");

        fila.realizarSondagem();
        fila.realizarSondagem();
        fila.realizarSondagem();
        fila.realizarSondagem();
        fila.realizarSondagem();
        fila.realizarSondagem();
    }
}