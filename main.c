#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main() {
    int num_vertices;
    int num_vizinhos;
    double probabilidade;
    int **grafo;

    // Parâmetros para variação
    int modelos = 2;  // 1 para ER, 2 para WS
    double probabilidades[] = {0.1, 0.08, 0.05, 0.02, 0.01};
    int num_vertices_variados[] = {100, 200, 500, 1000, 1500};
    int num_vizinhos_ws[] = {10, 15, 20, 25, 30};  // Apenas para Watts-Strogatz

    for (int modelo = 1; modelo <= modelos; modelo++) {  // Itera sobre os modelos
        for (int p_idx = 0; p_idx < 5; p_idx++) {  // Itera sobre as probabilidades
            probabilidade = probabilidades[p_idx];

            for (int i = 0; i < 5; i++) {  // Itera sobre num_vertices_variados
                num_vertices = num_vertices_variados[i];
                num_vizinhos = num_vizinhos_ws[i];  // Apenas para WS

                // Aloca o grafo
                grafo = alocar_grafo(num_vertices);

                if (modelo == 1) {  // Modelo Erdős-Rényi
                    printf("\n--- Erdős-Rényi: N=%d, p=%.2f ---\n", 
                           num_vertices, probabilidade);
                    gerar_grafo_er(grafo, num_vertices, probabilidade);
                } else if (modelo == 2) {  // Modelo Watts-Strogatz
                    printf("\n--- Watts-Strogatz: N=%d, K=%d, p=%.2f ---\n", 
                           num_vertices, num_vizinhos, probabilidade);
                    gerar_grafo_ws(grafo, num_vertices, num_vizinhos, probabilidade);
                }

                // Calcula e exibe limites cromáticos e clique máximo
                calcular_limites_cromaticos(grafo, num_vertices);

                // Libera a memória alocada para o grafo
                liberar_grafo(grafo, num_vertices);
            }
        }
    }

    return 0;
}
