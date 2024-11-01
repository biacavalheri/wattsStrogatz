#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graph.h"

// Função para alocar memória para o grafo (matriz de adjacência)
int **alocar_grafo(int num_vertices) {
    int **grafo = (int **)malloc(num_vertices * sizeof(int *));
    for (int i = 0; i < num_vertices; i++) {
        grafo[i] = (int *)calloc(num_vertices, sizeof(int));
    }
    return grafo;
}

// Função para liberar a memória do grafo
void liberar_grafo(int **grafo, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        free(grafo[i]);
    }
    free(grafo);
}

// Função para gerar um grafo regular com num_vizinhos vizinhos por vértice
void gerar_grafo_regular(int **grafo, int num_vertices, int num_vizinhos) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 1; j <= num_vizinhos / 2; j++) {
            int vizinho_direita = (i + j) % num_vertices;
            int vizinho_esquerda = (i - j + num_vertices) % num_vertices;

            // Adiciona arestas para vizinhos à direita e à esquerda
            grafo[i][vizinho_direita] = 1;
            grafo[i][vizinho_esquerda] = 1;
        }
    }
}

// Função para religar arestas com probabilidade p
void religar_arestas(int **grafo, int num_vertices, int num_vizinhos, double p) {
    srand(time(NULL));

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 1; j <= num_vizinhos / 2; j++) {
            int vizinho_direita = (i + j) % num_vertices;

            // Religa aresta com probabilidade p
            if ((double)rand() / RAND_MAX < p) {
                int novo_vizinho;
                do {
                    novo_vizinho = rand() % num_vertices;
                } while (novo_vizinho == i || grafo[i][novo_vizinho] == 1);

                // Remove a aresta antiga e cria uma nova
                grafo[i][vizinho_direita] = 0;
                grafo[i][novo_vizinho] = 1;
            }
        }
    }
}

// Função para exibir o grafo (matriz de adjacência)
void exibir_grafo(int **grafo, int num_vertices) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
}

// Função para calcular o grau máximo do grafo
int calcular_grau_maximo(int **grafo, int num_vertices) {
    int grau_maximo = 0;
    for (int i = 0; i < num_vertices; i++) {
        int grau_atual = 0;
        for (int j = 0; j < num_vertices; j++) {
            if (grafo[i][j] == 1) {
                grau_atual++;
            }
        }
        if (grau_atual > grau_maximo) {
            grau_maximo = grau_atual;
        }
    }
    return grau_maximo;
}

// Função para encontrar o tamanho do maior clique maximal
int encontrar_maior_clique(int **grafo, int num_vertices) {
    int maior_clique = 0;

    for (int i = 0; i < num_vertices; i++) {
        // Usamos um vetor para marcar os vértices do clique
        int *marcados = (int *)calloc(num_vertices, sizeof(int));
        int tamanho_clique = 1;
        marcados[i] = 1;

        // Verificamos quais vértices são adjacentes a i
        for (int j = 0; j < num_vertices; j++) {
            if (grafo[i][j] == 1 && !marcados[j]) {
                // Verificamos se todos os vértices marcados formam um clique com j
                int eh_clique = 1;
                for (int k = 0; k < num_vertices; k++) {
                    if (marcados[k] && grafo[j][k] == 0) {
                        eh_clique = 0;
                        break;
                    }
                }
                if (eh_clique) {
                    marcados[j] = 1;
                    tamanho_clique++;
                }
            }
        }

        if (tamanho_clique > maior_clique) {
            maior_clique = tamanho_clique;
        }
        
        free(marcados);
    }

    return maior_clique;
}

// Função para calcular limites cromáticos e retornar ambos os limites
void calcular_limites_cromaticos(int **grafo, int num_vertices, int *limite_inferior, int *limite_superior) {
    int grau_maximo = calcular_grau_maximo(grafo, num_vertices);
    int maior_clique = encontrar_maior_clique(grafo, num_vertices);

    // Atribui os valores dos limites para os ponteiros fornecidos
    *limite_inferior = maior_clique;
    *limite_superior = grau_maximo + 1;

    printf("Limite inferior (maior clique): %d\n", *limite_inferior);
    printf("Limite superior (grau máximo + 1): %d\n", *limite_superior);
}


// Função para gerar grafo Erdős-Rényi
void gerar_grafo_er(int **grafo, int num_vertices, double p) {
    srand(time(NULL));
    for (int i = 0; i < num_vertices; i++) {
        for (int j = i + 1; j < num_vertices; j++) {
            if ((double)rand() / RAND_MAX < p) {
                grafo[i][j] = 1;
                grafo[j][i] = 1;
            }
        }
    }
}

// Função para gerar grafo Watts-Strogatz
void gerar_grafo_ws(int **grafo, int num_vertices, int num_vizinhos, double p) {
    // Gera grafo regular primeiro
    gerar_grafo_regular(grafo, num_vertices, num_vizinhos);
    
    // Religa arestas com a probabilidade p
    religar_arestas(grafo, num_vertices, num_vizinhos, p);
}
