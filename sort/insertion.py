import csv
import os

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def busca_binaria(arr, x):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def ler_csv(arquivo):
    numeros = []
    with open(arquivo, newline='') as arquivocsv:
        leitor = csv.reader(arquivocsv)
        for linha in leitor:
            if linha: 
                numeros.append(int(linha[0]))
    return numeros

def achar_numero(arquivo, numero):
    numeros = ler_csv(arquivo)
    insertion_sort(numeros)
    indice = busca_binaria(numeros, numero)
    if indice != -1:
        print(f"O número {numero} foi encontrado no índice {indice}.")
    else:
        print(f"O número {numero} não foi encontrado.")

arquivo = 'C:\\Users\\naira\\OneDrive\\Área de Trabalho\\FATEC\\3º SEM\\Estrutura de Dados\\sort\\numeros.csv'
numero = 1915
achar_numero(arquivo, numero)