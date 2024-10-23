#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int num_vertices = 100; // Número de vértices
    int num_vizinhos = 10;  // Cada vértice será conectado a num_vizinhos
    double probabilidade_religar = 0.1; // Probabilidade de religar as arestas
    int **grafo;

    // Aloca o grafo (matriz de adjacência)
    grafo = alocar_grafo(num_vertices);

    // Gera o grafo regular com num_vizinhos vizinhos por vértice
    gerar_grafo_regular(grafo, num_vertices, num_vizinhos);

    // Religa arestas com a probabilidade fornecida
    religar_arestas(grafo, num_vertices, num_vizinhos, probabilidade_religar);

    // Exibe o grafo (opcional)
    exibir_grafo(grafo, num_vertices);

    calcular_limites_cromaticos(grafo, num_vertices);

    // Libera a memória alocada para o grafo
    liberar_grafo(grafo, num_vertices);

    return 0;
}
