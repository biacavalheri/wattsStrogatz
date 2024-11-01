#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// Função para salvar os resultados no CSV
void salvar_resultados(FILE *arquivo, int modelo, int num_vertices, double probabilidade, int num_vizinhos, int limite_inferior, int limite_superior) {
    fprintf(arquivo, "%d,%d,%.2f,%d,%d,%d\n", modelo, num_vertices, probabilidade, num_vizinhos, limite_inferior, limite_superior);
}

int main() {
    int num_vertices, num_vizinhos, limite_inferior, limite_superior;
    double probabilidade;
    int **grafo;

    // Configuração de parâmetros
    int modelos = 2;  
    double probabilidades[] = {0.01, 0.02, 0.03, 0.05, 0.08, 0.10, 0.15, 0.20, 0.30, 0.50};
    int num_vertices_variados[] = {100, 200, 300, 500, 800, 1000, 1500, 2000, 3000, 5000};
    int num_vizinhos_ws[] = {10, 15, 20, 30, 50}; 

    // Loop para criar 10 arquivos
    for (int iteracao = 1; iteracao <= 10; iteracao++) {
        // Gera o nome do arquivo baseado na iteração
        char nome_arquivo[20];
        snprintf(nome_arquivo, sizeof(nome_arquivo), "results/res%d.csv", iteracao);

        // Abre o arquivo para escrita
        FILE *arquivo = fopen(nome_arquivo, "w");
        if (!arquivo) {
            perror("Erro ao abrir o arquivo de resultados");
            return 1;
        }
        fprintf(arquivo, "Modelo,Vertices,Probabilidade,NumVizinhos,LimiteInferior,LimiteSuperior\n");

        // Executa as iterações de geração e cálculo para cada modelo e parâmetro
        for (int modelo = 1; modelo <= modelos; modelo++) {
            for (int p_idx = 0; p_idx < 10; p_idx++) {
                probabilidade = probabilidades[p_idx];

                for (int v_idx = 0; v_idx < 10; v_idx++) {
                    num_vertices = num_vertices_variados[v_idx];

                    if (modelo == 1) {  // Erdős-Rényi
                        grafo = alocar_grafo(num_vertices);
                        gerar_grafo_er(grafo, num_vertices, probabilidade);
                        calcular_limites_cromaticos(grafo, num_vertices, &limite_inferior, &limite_superior);
                        salvar_resultados(arquivo, modelo, num_vertices, probabilidade, 0, limite_inferior, limite_superior);
                        liberar_grafo(grafo, num_vertices);

                    } else if (modelo == 2) {  // Watts-Strogatz
                        for (int k_idx = 0; k_idx < 5; k_idx++) {
                            num_vizinhos = num_vizinhos_ws[k_idx];
                            grafo = alocar_grafo(num_vertices);
                            gerar_grafo_ws(grafo, num_vertices, num_vizinhos, probabilidade);
                            calcular_limites_cromaticos(grafo, num_vertices, &limite_inferior, &limite_superior);
                            salvar_resultados(arquivo, modelo, num_vertices, probabilidade, num_vizinhos, limite_inferior, limite_superior);
                            liberar_grafo(grafo, num_vertices);
                        }
                    }
                }
            }
        }

        fclose(arquivo);
        printf("Resultados salvos em results/'%s'\n", nome_arquivo);
    }

    return 0;
}
