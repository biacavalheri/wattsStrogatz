import pandas as pd
import glob
import numpy as np

def carregar_dados():
    # Carrega todos os arquivos .csv (res1.csv, res2.csv, ..., res10.csv)
    file_list = glob.glob("results/res*.csv")
    data_frames = [pd.read_csv(file) for file in file_list]
    data = pd.concat(data_frames, ignore_index=True)
    return data

def calcular_estatisticas(data):
    # Separação de dados para Modelo 1 (Erdős-Rényi) e Modelo 2 (Watts-Strogatz)
    modelo1_data = data[data['Modelo'] == 1]
    modelo2_data = data[data['Modelo'] == 2]

    # Estatísticas para Modelo 1 (agrupado por Vertices e Probabilidade)
    stats_modelo1 = modelo1_data.groupby(['Vertices', 'Probabilidade']).agg(
        LimiteInferior_Mean=('LimiteInferior', 'mean'),
        LimiteInferior_Std=('LimiteInferior', 'std'),
        LimiteSuperior_Mean=('LimiteSuperior', 'mean'),
        LimiteSuperior_Std=('LimiteSuperior', 'std')
    ).reset_index()

    # Estatísticas para Modelo 2 (agrupado por Vertices, Probabilidade e NumVizinhos)
    stats_modelo2 = modelo2_data.groupby(['Vertices', 'Probabilidade', 'NumVizinhos']).agg(
        LimiteInferior_Mean=('LimiteInferior', 'mean'),
        LimiteInferior_Std=('LimiteInferior', 'std'),
        LimiteSuperior_Mean=('LimiteSuperior', 'mean'),
        LimiteSuperior_Std=('LimiteSuperior', 'std')
    ).reset_index()

    return stats_modelo1, stats_modelo2

def main():
    # Carregar os dados dos arquivos CSV
    data = carregar_dados()
    
    # Calcular as estatísticas para cada modelo
    stats_modelo1, stats_modelo2 = calcular_estatisticas(data)
    
    # Exibir as estatísticas
    print("Estatísticas para o Modelo 1 (Erdős-Rényi):")
    print(stats_modelo1)
    print("\nEstatísticas para o Modelo 2 (Watts-Strogatz):")
    print(stats_modelo2)
    
    # Salvar os resultados em arquivos separados para fácil consulta
    stats_modelo1.to_csv("results/statistics_erdos-renyi.csv", index=False)
    stats_modelo2.to_csv("results/statistics_watts-strogatz.csv", index=False)
    print("\nEstatísticas salvas em 'statistics_erdos-renyi.csv' e 'statistics_watts-strogatz.csv'.")

if __name__ == "__main__":
    main()
