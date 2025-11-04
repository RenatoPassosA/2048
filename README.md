# 2048 — Projeto pessoal em C++ (OOP)

Uma implementação do clássico **2048** para treinar **orientação a objetos** em **C++**, com interface gráfica via **SFML** e foco no aprendizado de **testes automatizados**.

> **Destaques:** botão **Undo** que desfaz **até 5 jogadas**, botão **New Game** para reiniciar a partida e suíte de **testes unitários** desenvolvida com **GoogleTest**.

---

## ✨ Features

* Arquitetura orientada a objetos (tabuleiro, peças, direções, estado do jogo).
* **Undo** de até **5** movimentos anteriores (funciona ao clicar no botão na interface).
* **New Game** para reiniciar o jogo a qualquer momento.
* Animações e renderização em 2D com **SFML**.
* Suíte de **testes** com **GoogleTest**, criada para exercitar boas práticas de desenvolvimento orientado a testes (TDD).

---

## 📦 Requisitos

* **Linux** (testado)
* **g++** e **make**
* **SFML 2.5+** (gráficos, janela e sistema)
* **GoogleTest** (opcional, somente para `make test`)

### Instalação rápida (Ubuntu/Debian)

Para que o jogo funcione corretamente, é necessário instalar a biblioteca **SFML**:

```bash
sudo apt update
sudo apt install -y g++ make libsfml-dev libgtest-dev
```

> Caso a SFML não esteja instalada, ocorrerá o erro: `fatal error: SFML/Graphics.hpp: No such file or directory`.

### macOS (Homebrew)

```bash
brew install sfml googletest
```

> No macOS, ajuste os *flags* se necessário (frameworks e caminhos do Homebrew).

---

## 🚀 Como baixar e executar

### 1) Clonar o repositório

```bash
git clone https://github.com/RenatoPassosA/2048.git
cd 2048
```

### 2) Compilar o jogo

```bash
make
```

Gera o binário:

```bash
./2048
```

### 3) Controles (padrão)

* **Setas**: mover as peças
* **Botão Undo**: desfaz até 5 jogadas anteriores (clicando na interface)
* **Botão New Game**: reinicia a partida
* **ESC** ou fechar janela: sair

### 4) Executar os testes (opcional)

```bash
make test
```

Isso compila `2048_test` e executa a suíte de testes.

> Este projeto foi desenvolvido com foco em aprender **boas práticas de testes automatizados**, cobrindo as principais funções de lógica do jogo.

### 5) Limpeza

```bash
make clean   # remove objetos e binário de teste
make fclean  # remove também o executável principal
make re      # recompila do zero
```

---

## 🖼️ Demonstração 

![Gameplay 2048](assets/2048_gif.gif)

---

