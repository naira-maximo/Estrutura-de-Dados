def insertion_sort(lista):
    for i in range(1, len(lista)):
        atual = lista[i]
        anterior = i - 1
        # Move os elementos da lista[0..i-1] que são maiores que o atual, uma posição à frente
        while anterior >= 0 and atual < lista[anterior]:
            lista[anterior + 1] = lista[anterior]
            anterior -= 1
        lista[anterior + 1] = atual

# Exemplo de uso
lista = [64, 25, 12, 22, 11]
print("Lista original:", lista)
insertion_sort(lista)
print("Lista ordenada:", lista)