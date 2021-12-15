# TP 1 de Algoritmos e Estruturas de Dados

## Introdução

1. [Tipos abstratos]('#tipos-abstratos')
1. [Modulos e funções](#modules)
1. [Como compilar o projeto](#compilando-o-projeto)
1. [Como compilar a documentação](#compilando-a-documentacao)

---

## Tipos Abstratos <tipos-abstratos>

## **Processo**

- **Tipo**

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

- **_Funções_**

  | Função                | Tipo         | Argumentos                 | Descrição                                                                     |
  | --------------------- | ------------ | -------------------------- | ----------------------------------------------------------------------------- |
  | `inicializa_processo` | `void`       | `(Processo* )`             | Inicializa o processo com os valores de PID, prioridade e horario de criacao. |
  | `imprime_processo`    | `void`       | `(Processo)`               | funcao para imprimir o processo, recebe um processo e imprime seus valores.   |
  | `get_PID`             | `int`        | `(Processo*)`              | Retorna o valor do campo PID de um processo.                                  |
  | `set_PID`             | `void`       | `(Processo* , int)`        | Define o valor do campo PID de um processo.                                   |
  | `get_prioridade`      | `int`        | `(Processo*)`              | Retorna o valor do campo prioridade de um processo.                           |
  | `set_prioridade`      | `void`       | `(Processo* , int)`        | Define o valor do campo prioridade de um processo.                            |
  | `get_horario_criacao` | `struct tm*` | `(Processo*)`              | Retorna o valor do campo horario_criacao de um processo.                      |
  | `set_horario_criacao` | `void`       | `(Processo* , struct tm*)` | Define o valor do campo horario_criacao de um processo.                       |

<div style="page-break-after: always; visibility: hidden">
\pagebreak
</div>

## **Cursor**

- Tipo

  `Cursor é um tipo abstrato que representa um ponteiro para um elemento de uma lista.`

  ```C
  typedef int cursor;
  ```

## **Celula**

- Tipo

      ```Celula é um tipo abstrato que representa um elemento de uma lista.```

  | Campo      | tipo         | Descrição                                      |
  | ---------- | ------------ | ---------------------------------------------- |
  | `processo` | `Processo *` | O processo que está armazenado na celula.      |
  | `prox`     | `cursor`     | O apontador (`indice`) para a próxima celula.  |
  | `ant`      | `cursor`     | O apontador (`indice`) para a celula anterior. |

  ```C
  typedef struct Tcelula {
    Processo *processo;
    cursor ant;
    cursor prox;
  } Celula;
  ```

  - **_Funções_**

    | Função                   | Tipo   | Argumentos              | Descrição                                                                                                            |
    | ------------------------ | ------ | ----------------------- | -------------------------------------------------------------------------------------------------------------------- |
    | `inicializa_celula_nula` | `void` | `(Celula* , int)`       | Inicializa a celula com o valor de `prox` passado como parametro e `ant` igual a -1.                                 |
    | `inicializa_celula`      | `void` | `(Celula* , Processo*)` | Inicializa a celula com o valor de `prox` e `ant` igual ao valor passado, e o campo processo como o processo passado |

<div style="page-break-after: always; visibility: hidden">
\pagebreak
</div>

## **Lista**

- Tipo

  | Campo                 | tipo      | Descrição                                                 |
  | --------------------- | --------- | --------------------------------------------------------- |
  | `primeiro`            | `cursor`  | O apontador (`indice`) para a primeira celula.            |
  | `ultimo`              | `cursor`  | O apontador (`indice`) para a ultima celula.              |
  | `primeira_disponivel` | `cursor`  | O apontador (`indice`) para a primeira celula disponivel. |
  | `numCelOcupadas`      | `int`     | O numero de celulas ocupadas.                             |
  | `plista`              | `Celula*` | O ponteiro para a lista.                                  |
  | `tamanho`             | `int`     | O tamanho da lista.                                       |

  ```C
  typedef struct Tlista {
    cursor primeiro;
    cursor primeira_disponivel;
    cursor ultimo;
    int numCelOcupadas;
    Celula *plista;
  } Lista;
  ```

<div style="page-break-after: always; visibility: hidden">
\pagebreak
</div>

## Módulos <modules>

---

### UTILS

| Função     | Tipo     | Argumentos | Descrição                                                 |
| :--------- | :------- | :--------: | :-------------------------------------------------------- |
| `menu()`   | `void`   |            | Imprime na saída padrão as opções de interação do sistema |
| `cls()`    | `void`   |            | Limpa a saida padrão                                      |
| `pid(int)` | `char *` |            | Gera um id único do processo de tamanho `20`              |

---

<div style="page-break-after: always; visibility: hidden">
\pagebreak
</div>

## Comando para compilar o projeto <compilando-o-projeto>

```bash
    make
```

### Exemplo de compilação

```bash
    make
    make clean
    make all
```

## Comandos principais

- adiciona alteração para ser enviado

```bash
    git add <nome_do_arquivo>
```

- adiciona todas alterações

```bash
    git add .
```

- commitar as alterações

```bash
    git commit -m "mensagem"
```

- enviar as alterações para o repositório remoto

```bash
    git push origin master
```

- baixar as alterações do repositório remoto

```bash
    git pull <nome_do_repositorio> <branch>
```

- verificar o status do repositório

```bash
      git status
```

- verificar o log do repositório

```bash
    git log
```

- busca alterações no repositório

```bash
    git fetch -p -t
```

---

<div style="page-break-after: always; visibility: hidden">
\pagebreak
</div>

## Compilar a documentação <compilando-a-documentacao>

```bash
    make doc
```

- Gera arquivo PDF com o mesmo nome do arquivo markdown (não mudar nome do aquivo .md, crie uma cópia com outro nome e compile a cópia, ou mude o nome do arquivo resultado)

```bash
      md-to-pdf readme.md
```

> - Para gerar o arquivo PDF, é necessário ter instalado o programa `md-to-pdf` , caso não tenha a ferramenta de build de documentação instalada

```bash
      pip install md-to-pdf
      --- ou ---
      npm install md-to-pdf
```
