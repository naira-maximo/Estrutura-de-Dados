package ProntoSocorro.src;

public class ListaComCabeca {
    private Celula cabeca;

    public ListaComCabeca() {
        // Cria cabeça vazia
        cabeca = new Celula(null, null);
    }

    public void adicionarPaciente(String nome, String classificacao) {
        Celula nova = new Celula(nome, classificacao);
        Celula atual = cabeca;
        while (atual.proxima != null) {
            atual = atual.proxima;
        }
        System.out.println("Paciente adicionado: " + nome);
        atual.proxima = nova;
    }

    public void adicionarPacienteEmergencia(String nome) {
        Celula nova = new Celula(nome, "Emergência");
        Celula atual = cabeca;
        while (atual.classificacao.equals("Emergência")) {
            atual = atual.proxima;
        }
        cabeca.proxima = nova;
    }

    public void adicionarPacienteDepoisDe(String nome, String classificacao, Celula celula) {
        if (celula == null) {
            throw new IllegalArgumentException("A celula é nula");
        }
        Celula nova = new Celula(nome, classificacao);
        nova.proxima = celula.proxima;
        celula.proxima = nova;
    }

    public Celula atenderPaciente(Celula celula) {
        if (estaVazia()) {
            throw new IllegalStateException("A lista está vazia");
        }
        Celula primeira = cabeca.proxima;
        cabeca.proxima = primeira.proxima;
        System.out.println("Paciente atendido: " + primeira.nome);
        return primeira;
    }

    public boolean estaVazia() {
        return cabeca.proxima == null;
    }

    public void mostrarPacientes() {
        Celula atual = cabeca.proxima;
        while (atual != null) {
            System.out.println("Nome: " + atual.nome + ", Classificação de Risco: " + atual.classificacao);
            atual = atual.proxima;
        }
    }

    public Celula buscarNodoPorNome(String nome) {
        Celula atual = cabeca.proxima;
        while (atual != null) {
            if (atual.nome.equals(nome)) {
                return atual;
            }
            atual = atual.proxima;
        }
        return null;
    }
}


