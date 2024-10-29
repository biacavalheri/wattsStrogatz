<a id="readme-top"></a>

<div align="center">
  <h1 align="center">Análise e Geração de Grafos: Erdős-Rényi e Watts-Strogatz</h1>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li><a href="#getting-started">Getting Started</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributors">Contributors</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project

Este projeto tem como objetivo **gerar e analisar grafos** utilizando os modelos **Erdős-Rényi** e **Watts-Strogatz**. A partir da variação de parâmetros como o número de vértices, probabilidade de conexão, e vizinhos iniciais, o projeto permite calcular métricas fundamentais como:
- **Limite cromático** (grau máximo + 1).
- **Tamanho do maior clique**.

Esses modelos são amplamente utilizados em teoria de grafos para estudar a conectividade e as propriedades estruturais de diferentes tipos de redes.

[Trabalho - Grafos Watts-Strogatz](https://github.com/user-attachments/files/17483678/Trabalho2.pdf)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

- Linguagem C
- [GCC](https://gcc.gnu.org/) para compilação
- [GitHub](https://github.com/) para versionamento

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

### Pré-requisitos

- **Compilador GCC** ou similar.
- **Make** (opcional) para automação de compilação.

### Instalação

1. **Clone o repositório**:
   ```bash
   git clone https://github.com/seu-usuario/projeto-grafos.git

2. **Compilação**:
   ```bash
   gcc main.c graph.c -o grafos -Wall -Wextra -pedantic

3. Flags
- **-Wall:** Habilita todos os avisos comuns (warnings) durante a compilação.
- **-Wextra:** Ativa avisos adicionais que não estão inclusos em -Wall.
- **-pedantic:** Garante que o código segue estritamente o padrão C.

### Uso

O programa permite a análise dos seguintes modelos de grafos:

Erdős-Rényi: A probabilidade de uma aresta entre dois vértices é p.
Watts-Strogatz: Começa como um grafo regular, e as arestas são religadas com uma probabilidade p.


1. **Exemplo de saída**:
   ```bash
    --- Erdős-Rényi: N=100, p=0.10 ---
    Calculando limites cromáticos...

    --- Watts-Strogatz: N=200, K=15, p=0.08 ---
    Calculando limites cromáticos...

Parâmetros configuráveis:

- N: Número de vértices.
- p: Probabilidade de criação ou religação de aresta.
- K: Número inicial de vizinhos (para Watts-Strogatz).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

- [X] Implementação dos modelos de grafos.
- [X] Cálculo de limites cromáticos e maior clique.
- [ ] Cálculo da média e desvio padrão.
- [ ] Análise de dados em tabelas e gráficos
- [ ] Slides para apresetação

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributors

<a href="https://github.com/biacavalheri/wattsStrogatz/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=biacavalheri/wattsStrogatz" alt="contrib.rocks image" />
</a>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Beatriz Cavalheri <br>
[![LinkedIn][linkedin-shield]][beatriz-linkedin-url]

Jeferson Filho <br>
[![LinkedIn][linkedin-shield]][jeferson-linkedin-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments
Proposta de projeto <br>
[Trabalho - Grafos Watts-Strogatz](https://github.com/user-attachments/files/17483678/Trabalho2.pdf)

<!-- Project Presentation <br>
[![Google][Google-url]][presentation-url] -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[Python-url]: https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54
[Pandas-url]: https://img.shields.io/badge/pandas-%23150458.svg?style=for-the-badge&logo=pandas&logoColor=white
[NumPy-url]: https://img.shields.io/badge/numpy-%23013243.svg?style=for-the-badge&logo=numpy&logoColor=white
[scikit-learn-url]: https://img.shields.io/badge/scikit--learn-%23F7931E.svg?style=for-the-badge&logo=scikit-learn&logoColor=white
[OpenCV-url]: https://img.shields.io/badge/opencv-%23white.svg?style=for-the-badge&logo=opencv&logoColor=white
[Matplotlib-url]: https://img.shields.io/badge/Matplotlib-%23ffffff.svg?style=for-the-badge&logo=Matplotlib&logoColor=black
[PyTorch-url]: https://img.shields.io/badge/PyTorch-%23EE4C2C.svg?style=for-the-badge&logo=PyTorch&logoColor=white
[TensorFlow-url]: https://img.shields.io/badge/TensorFlow-%23FF6F00.svg?style=for-the-badge&logo=TensorFlow&logoColor=white
[GitHub-url]: https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white
[Google-url]: https://img.shields.io/badge/google-4285F4?style=for-the-badge&logo=google&logoColor=white
<!-- -------------------------------------------------------------------------------- -->
[beatriz-linkedin-url]: https://www.linkedin.com/in/beatrizcavalheri/
[jeferson-linkedin-url]: https://www.linkedin.com/in/jdietrichfho/

[proposal-url]: https://docs.google.com/document/d/1uEbctbl0NRMt0JqrIm3f5ihobDgLaR9f0iVCDjmQZsY/edit?usp=sharing
[presentation-url]: https://docs.google.com/presentation/d/1A5tRD3T6Qk6GESLZ2pWrioyFeptsjCmE06kr__TXZoA/edit?usp=sharing
