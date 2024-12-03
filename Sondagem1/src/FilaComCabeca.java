public class FilaComCabeca {
    private Crianca cabeca;

    public FilaComCabeca() {
        cabeca = new Crianca(null);
    }

    public void cadastrarCrianca(String nome) {
        Crianca novoAluno = new Crianca(nome);
        Crianca atual = cabeca;
        while (atual.proxima != null) {
            atual = atual.proxima;
        }
        atual.proxima = novoAluno;
        System.out.println("Criança cadastrada: " + novoAluno.nome);
    }

    public Crianca realizarSondagem() {
        if (cabeca.proxima == null) {
            String primeiro = "A fila está vazia";
            System.out.println(primeiro);
            return null;
        }
        Crianca primeiro = cabeca.proxima;
        cabeca.proxima = primeiro.proxima;
        System.out.println("Criança atendida: " + primeiro.nome);
        return primeiro;
    }
}