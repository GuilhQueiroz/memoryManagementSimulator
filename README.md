# 📌 Gerenciamento de Memória – Algoritmos de Alocação

Este projeto implementa um simulador de gerenciamento de memória que trabalha com diferentes estratégias de alocação de processos. A memória física simulada possui 128 KB, organizada em endereços de 2 KB cada.

O objetivo é demonstrar como funcionam os principais algoritmos vistos em sala de aula, simulando requisições de alocação e liberação de memória.

## ⚙️ Algoritmos Implementados

- Next Fit – semelhante ao First Fit, mas continua a busca a partir da última posição utilizada.

- Best Fit – aloca no menor espaço livre que caiba o processo.

- Worst Fit – Percorre toda a memória para encontrar o maior bloco de espaço livre disponível. A ideia é alocar o processo nesse bloco grande, deixando um pedaço restante que ainda seja consideravelmente grande, evitando a criação de muitos pequenos fragmentos.

## ⚙️ Tecnologias Utilizadas
  ![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) 

## 🗂️ Estrutura do Projeto
```bash
projeto/
│── main.c          # Arquivo principal – menu e execução da simulação
│── memory.c        # Implementação dos algoritmos de alocação
│── memory.h        # Definições e protótipos
```
## 🖥️ Compilação e Execução
- Compilando com GCC <br>
No terminal, dentro da pasta do projeto:
  ```bash
  gcc main.c memory.c -o simulador
  ```
- Executando
  ```bash
  ./simulador
  ```
Será exibido um menu interativo, onde você poderá escolher:
- Criar processo

- Remover processo

- Mostrar estado da memória

- Sair do programa

## 📌 Observações
- Cada bloco da memória tem 2 KB.

- O log da simulação mostra qual algoritmo foi usado e onde o processo foi inserido.

 -  A simulação automática possui um pequeno delay (sleep) entre as etapas para que seja possível visualizar cada passo do processo de alocação e liberação de memória.

## 📫 Contato
<a href="https://github.com/GuilhQueiroz" target="_blank" rel="noopener noreferrer"><img src="https://img.shields.io/badge/github-12100E.svg?&style=for-the-badge&logo=github&logoColor=white"></a>
<a href="mailto:guiguimaraes.dev@gmail.com" target="_blank" rel="noopener noreferrer"><img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white"></a>

 ## 📝 Adicionais
 * 💡 Qualquer feedback, sugestão ou melhoria será muito bem-vinda!
Sinta-se livre para abrir uma issue ou entrar em contato.
