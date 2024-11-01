import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# Configuração do estilo do Seaborn
sns.set(style="whitegrid")

# Paleta de cores personalizada
custom_palette = sns.color_palette("Set1", n_colors=10)

def plot_erdosRenyi():
    # Carregar dados do modelo Erdős-Rényi (Modelo 1)
    data = pd.read_csv("results/statistics_erdos-renyi.csv")
    data = data.sort_values(by='Probabilidade', ascending=False)

    # Gráfico para Média do Limite Cromático Inferior
    plt.figure(figsize=(18, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteInferior_Mean', hue='Probabilidade', marker='o', palette=custom_palette, hue_order=sorted(data['Probabilidade'].unique(), reverse=True))
    plt.title("Modelo Erdős-Rényi - Média do Limite Cromático Inferior")
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Inferior (Média)")
    plt.legend(title="Probabilidade")
    plt.savefig("charts/erdosRenyi_media_limite_inferior.png")
    plt.close()

    # Gráfico para Média do Limite Cromático Superior
    plt.figure(figsize=(18, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteSuperior_Mean', hue='Probabilidade', marker='o', palette=custom_palette, hue_order=sorted(data['Probabilidade'].unique(), reverse=True))
    plt.title("Modelo Erdős-Rényi - Média do Limite Cromático Superior")
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Superior (Média)")
    plt.legend(title="Probabilidade")
    plt.savefig("charts/erdosRenyi_media_limite_superior.png")
    plt.close()

    # Gráfico para Desvio Padrão do Limite Cromático Inferior
    plt.figure(figsize=(18, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteInferior_Std', hue='Probabilidade', marker='o', palette=custom_palette, hue_order=sorted(data['Probabilidade'].unique(), reverse=True))
    plt.title("Modelo Erdős-Rényi - Desvio Padrão do Limite Cromático Inferior")
    plt.ylim(0, 0.7)  # Define o limite do eixo Y para [0, 0.7]
    plt.yticks(np.linspace(0, 0.7, 10))  # Define 10 divisões no eixo Y
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Inferior (Desvio Padrão)")
    plt.legend(title="Probabilidade")
    plt.savefig("charts/erdosRenyi_desvio_limite_inferior.png")
    plt.close()

    # Gráfico para Desvio Padrão do Limite Cromático Superior
    plt.figure(figsize=(18, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteSuperior_Std', hue='Probabilidade', marker='o', palette=custom_palette, hue_order=sorted(data['Probabilidade'].unique(), reverse=True))
    plt.title("Modelo Erdős-Rényi - Desvio Padrão do Limite Cromático Superior")
    plt.ylim(0, 20)  # Define o limite do eixo Y para [0, 20]
    plt.yticks(np.linspace(0, 20, 10))  # Define 10 divisões no eixo Y
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Superior (Desvio Padrão)")
    plt.legend(title="Probabilidade")
    plt.savefig("charts/erdosRenyi_desvio_limite_superior.png")
    plt.close()

def plot_wattsStrogatz():
    # Carregar dados do modelo Watts-Strogatz (Modelo 2)
    data = pd.read_csv("results/statistics_watts-strogatz.csv")

    # Gráfico para Média do Limite Cromático Inferior
    g = sns.FacetGrid(data, col="NumVizinhos", col_wrap=3, height=4, aspect=1.5, sharey=False)
    g.map_dataframe(sns.lineplot, x="Vertices", y="LimiteInferior_Mean", hue="Probabilidade", marker='o', palette="viridis")
    g.set_titles(col_template="NumVizinhos = {col_name}")
    g.set_axis_labels("Número de Vértices", "Média do Limite Cromático Inferior")
    g.set(xlim=(0, 5000), xticks=range(0, 5001, 500))  # Define o limite e as divisões do eixo X
    g.add_legend(title="Probabilidade")
    g.savefig("charts/wattsStrogatz_media_limite_inferior.png")
    plt.close()

    # Gráfico para Média do Limite Cromático Superior
    plt.figure(figsize=(10, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteSuperior_Mean', hue='Probabilidade', style='NumVizinhos', marker='o', palette="viridis")
    plt.title("Modelo Watts-Strogatz - Média do Limite Cromático Superior")
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Superior (Média)")
    plt.legend(title="Probabilidade e Vizinhos")
    plt.savefig("charts/wattsStrogatz_media_limite_superior.png")
    plt.close()

    # Gráfico para Desvio Padrão do Limite Cromático Inferior usando FacetGrid para NumVizinhos
    g = sns.FacetGrid(data, col="NumVizinhos", col_wrap=3, height=4, aspect=1.5, sharey=False)
    g.map_dataframe(sns.lineplot, x="Vertices", y="LimiteInferior_Std", hue="Probabilidade", marker='o', palette="viridis")
    g.set_titles(col_template="NumVizinhos = {col_name}")
    g.set_axis_labels("Número de Vértices", "Desvio Padrão do Limite Cromático Inferior")
    g.set(xlim=(0, 5000), xticks=range(0, 5001, 500))  # Define o limite e as divisões do eixo X
    g.add_legend(title="Probabilidade")
    g.savefig("charts/wattsStrogatz_desvio_limite_inferior.png")
    plt.close()

    # Gráfico para Desvio Padrão do Limite Cromático Superior
    plt.figure(figsize=(10, 6))
    sns.lineplot(data=data, x='Vertices', y='LimiteSuperior_Std', hue='Probabilidade', style='NumVizinhos', marker='o', palette="viridis")
    plt.title("Modelo Watts-Strogatz - Desvio Padrão do Limite Cromático Superior")
    plt.xlabel("Número de Vértices")
    plt.ylabel("Limite Cromático Superior (Desvio Padrão)")
    plt.legend(title="Probabilidade e Vizinhos")
    plt.savefig("charts/wattsStrogatz_desvio_limite_superior.png")
    plt.close()

def main():
    plot_erdosRenyi()
    plot_wattsStrogatz()

if __name__ == "__main__":
    main()
