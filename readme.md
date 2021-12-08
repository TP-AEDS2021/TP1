# TP 1 de Algoritmos e Estruturas de Dados

## Introdução

## Comando para compilar o projeto

    make

### Exemplo de compilação

    make
    make clean
    make all

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

## Build documentação

- Gera arquivo PDF com o mesmo nome do arquivo markdown (não mudar nome do aquivo .md, crie uma cópia com outro nome e compile a cópia, ou mude o nome do arquivo resultado)

      md-to-pdf readme.md

- Caso não tenha a ferramenta de build

```python pip
    pip install md-to-pdf
```

```javascript npm
    npm install md-to-pdf
```
