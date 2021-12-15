# TP 1 de Algoritmos e Estruturas de Dados

## Introdução <a href="introduction"></a>

1. [Introdução](#introduction)
1. [Tipos abstrtos]('#tipos-abstratos')
1. [Modulos e funções](#modules)
1. [Como compilar o projeto](#compilando-o-projeto)

---

## Tipos Abstratos <a name="tipos-abstratos"></a>

---

<details>
  <summary> <span style="font-size:30px, font-weight:900">Processo</span> </summary>
  
### **Processo**

| Campo             | Tipo         | Descrição                                                                                                                          |
| ----------------- | ------------ | ---------------------------------------------------------------------------------------------------------------------------------- |
| `PID`             | `int`        | Um indentifiador único de cada processo ( `PID` ) que é um inteiro positivo gerado aleatoriamente. Usado para ordenar os processos |
| `prioridade`      | `int`        | A prioridade do processo. O valor deve ser um inteiro entre 0 e 5. (Gerado aleatoriamente na criação do processo).                 |
| `horario_criacao` | `struct tm*` | A hora em que o processo foi criado, alocado na memória e inicializado.                                                            |

```C
typedef struct Tprocesso
  {
      int PID; // identificador do processo
      int prioridade; //prioridade do processo
      struct tm* horario_criacao; // horario de criacao do processo
  } Processo;
```

</details>

## Módulos <a name="modules"></a>

---

### UTILS

| Função     | Tipo     |  Argumentos  | Descrição                                                 |
| :--------- | :------- | :----------: | :-------------------------------------------------------- |
| `menu()`   | `void`   |              | Imprime na saída padrão as opções de interação do sistema |
| `cls()`    | `void`   |              | Limpa a saida padrão                                      |
| `uid(int)` | `char *` | `int length` | Gera um id único do proçesso de tamanho `length`          |

---

## Comando para compilar o projeto <a name="compilando-o-projeto"></a>

    make

### Exemplo de compilação

    make
    make clean
    make all

---

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

- busca alterações no repositório

      git fetch -p -t

---

## Compilar a documentação

- Gera arquivo PDF com o mesmo nome do arquivo markdown (não mudar nome do aquivo .md, crie uma cópia com outro nome e compile a cópia, ou mude o nome do arquivo resultado)

      md-to-pdf readme.md

  > - Para gerar o arquivo PDF, é necessário ter instalado o programa `md-to-pdf` , caso não tenha a ferramenta de build de documentação instalada
  >
  > <br>

        pip install md-to-pdf
        --- ou ---
        npm install md-to-pdf
