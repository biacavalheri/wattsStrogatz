#ifndef GRAPH_H
#define GRAPH_H

// Função para alocar o grafo (matriz de adjacência)
int **alocar_grafo(int num_vertices);

// Função para liberar o grafo da memória
void liberar_grafo(int **grafo, int num_vertices);

// Função para gerar o grafo regular
void gerar_grafo_regular(int **grafo, int num_vertices, int num_vizinhos);

// Função para religar as arestas com probabilidade p
void religar_arestas(int **grafo, int num_vertices, int num_vizinhos, double p);

// Função para exibir o grafo (opcional, apenas para verificar o resultado)
void exibir_grafo(int **grafo, int num_vertices);

// Função para calcular o grau máximo do grafo
int calcular_grau_maximo(int **grafo, int num_vertices);

// Função para encontrar o tamanho do maior clique maximal
int encontrar_maior_clique(int **grafo, int num_vertices);

// Função para calcular limites cromáticos
void calcular_limites_cromaticos(int **grafo, int num_vertices);


#endif
