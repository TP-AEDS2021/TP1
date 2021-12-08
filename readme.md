# TP 1 de Algoritmos e Estruturas de Dados

## Introdução

***

### Tipos Abstratos

## Módulos

***

### UTILS

  | Função | Tipo | Argumentos | Descrição |
  | :----- | :-------- | :--------: | :-------- |
  | `menu()` | `void` |  | Imprime na saída padrão as opções de interação do sistema
  | `cls()` | `void` | | limpa a saida padrão |
  | `uid(int)` | `char *` | `int length` | Gera um identificador único do proçesso de tamanho `length` recebido como parâmetro |

***

## Comando para compilar o projeto

    make

### Exemplo de compilação

    make
    make clean
    make all
***

## Comandos principais

- adiciona alteração para ser enviado

      git add <nome_do_arquivo>

- adiciona todas alterações

      git add .

- commitar as alterações

      git commit -m "mensagem"

- enviar as alterações para o repositório remoto

      git push origin master

- baixar as alterações do repositório remoto

      git pull <nome_do_repositorio> <branch>

- verificar o status do repositório

      git status

- verificar o log do repositório

      git log

---

## Compilar a documentação

- Gera arquivo PDF com o mesmo nome do arquivo markdown (não mudar nome do aquivo .md, crie uma cópia com outro nome e compile a cópia, ou mude o nome do arquivo resultado)

      md-to-pdf readme.md

    >
    > - Para gerar o arquivo PDF, é necessário ter instalado o programa `md-to-pdf` , caso não tenha a ferramenta de build de documentação instalada
    >
    <br>

        pip install md-to-pdf
        --- ou ---
        npm install md-to-pdf
