public class Degrau {

    int valor;
    Degrau proximo;

    public Degrau(int valor) {
        this.valor = valor;
        this.proximo = null;
    }

    public int getValor() {return valor;}

    public void setValor(int valor) {this.valor = valor;}

    public Degrau getProximo() {return proximo;}

    public void setProximo(Degrau proximo) {this.proximo = proximo;}
}
static class Pilha {
    private Degrau topo;

    public void subir(int valor) {
        if (topo == null) {
            topo = new Degrau(valor);
        } else {
            Degrau novo = new Degrau(valor);
            novo.setProximo(topo);
            topo = novo;
        }
        System.out.println("Degrau atual: " + topo.getValor());
    }

    public Degrau descer() {
        if (topo == null || topo.getProximo() == null) {
            System.out.println("A pilha está vazia");
            return null;
        }
        Degrau removido = topo;
        topo = topo.getProximo();
        System.out.println("Desceu o degrau: " + removido.getValor() + " Degrau atual: " + (topo != null ? topo.getValor() : "nenhum"));
        return removido;
    }
}

public static void main(String[] args) {
    Pilha pilha = new Pilha();
    pilha.subir(1);
    pilha.subir(2);
    pilha.subir(3);
    // pilha.subir(4);
    // pilha.subir(5);
    // pilha.subir(6);
    // pilha.subir(7);
    // pilha.subir(8);
    // pilha.subir(9);
    // pilha.subir(10);
    // pilha.subir(11);
    // pilha.subir(12);
    // pilha.subir(13);
    // pilha.subir(14);
    // pilha.subir(15);
    // pilha.subir(16);
    pilha.descer();
    pilha.descer();
    pilha.descer();
    pilha.descer();
    pilha.descer();
}
