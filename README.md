
# AEP 2 - PSE: Saúde Bucal

Projeto acadêmico desenvolvido para a disciplina de **Análise e
Desenvolvimento de Sistemas (ADS)** da **UniCesumar**.

## Integrantes

-   **Karen Andrade Cassero** --- RA 26005674-2
-   **Lais Santana de Carvalho** --- RA 26008051-2
-   **Odair Manganaro Junior** --- RA 26004679-2

## Sobre o projeto

O projeto propõe o desenvolvimento de um sistema computacional simples,
em **linguagem C**, para auxiliar no planejamento, registro e
acompanhamento de ações de **saúde bucal** realizadas no âmbito do
**Programa Saúde na Escola (PSE)**.

A ideia é centralizar informações das atividades em um único sistema,
facilitando o cadastro, a consulta e o acompanhamento das ações.

> O sistema utiliza dados fictícios e informações coletivas. Não tem
> como objetivo substituir profissionais da saúde, realizar diagnósticos
> ou armazenar informações clínicas individuais.

## Objetivo geral

Desenvolver uma solução computacional simples para auxiliar no
planejamento, registro e acompanhamento de ações de saúde bucal
realizadas no âmbito do Programa Saúde na Escola.

## Funcionalidades previstas

O sistema deverá permitir:

-   Cadastrar novas ações;
-   Consultar ações cadastradas;
-   Atualizar a situação das ações;
-   Registrar a quantidade de participantes;
-   Consultar ações de acordo com sua situação;
-   Exibir informações gerais sobre as atividades cadastradas.

### Situações das ações

As ações poderão ser classificadas como:

-   **Planejada**
-   **Em andamento**
-   **Concluída**
-   **Cancelada**

## Informações cadastradas

Para cada ação, poderão ser registrados:

-   Nome da ação;
-   Tema;
-   Escola;
-   Data;
-   Responsável;
-   Quantidade prevista de participantes;
-   Situação da atividade;
-   Quantidade de participantes após a realização.

## O que não faz parte do sistema

O projeto não contempla:

-   Cadastro de informações clínicas individuais;
-   Diagnósticos;
-   Prescrição de tratamentos;
-   Armazenamento de prontuários;
-   Integração com sistemas governamentais;
-   Utilização de dados reais de estudantes.

## Algoritmos e lógica

O funcionamento do sistema foi planejado por meio de:

-   Fluxograma geral;
-   Fluxogramas detalhados;
-   Pseudocódigos;
-   Estrutura de menu e operações de cadastro, consulta e atualização.

## Processo de desenvolvimento

Foi definida uma abordagem **incremental**, com desenvolvimento dividido
em seis sprints semanais:

  Sprint   Etapa           Principal objetivo
  -------- --------------- ----------------------------------------------
  1        Levantamento    Problema, usuários, escopo e requisitos
  2        Modelagem       Fluxogramas e pseudocódigos
  3        Implementação   Desenvolvimento do sistema em C
  4        Testes          Validação, identificação e correção de erros
  5        Documentação    Organização do código e documentação
  6        Apresentação    Revisão, demonstração e preparação do vídeo

## Tecnologias

-   **Linguagem:** C
-   **Paradigma:** programação estruturada
-   **Documentação:** Markdown
-   **Modelagem:** fluxogramas e pseudocódigos

## Organização sugerida do repositório

``` text
AEP-2-PSE-Saude-Bucal/
│
├── README.md
├── src/
│   └── main.c
│
├── docs/
│   ├── fluxograma-geral
│   ├── fluxograma-cadastrar-acao
│   ├── fluxograma-consultar-acao
│   └── trabalho-aep2.pdf
│
└── testes/
    └── casos-de-teste.txt
```

## Execução

Após a implementação do código em C, o programa poderá ser compilado
utilizando um compilador C.

Exemplo:

``` bash
gcc src/main.c -o sistema
```

Para executar:

### Windows

``` bash
sistema.exe
```

### Linux/macOS

``` bash
./sistema
```

## Escopo do sistema

O sistema foi planejado para apoiar o gerenciamento das ações do PSE,
contemplando cadastro, consulta e acompanhamento das atividades
realizadas ou planejadas.

O foco está na **organização das ações coletivas de saúde bucal**, e não
no atendimento clínico individual.

## Referências

-   BRASIL. Decreto nº 6.286, de 5 de dezembro de 2007. Institui o
    Programa Saúde na Escola --- PSE e dá outras providências.
-   BRASIL. Ministério da Saúde. *O que é o Programa Saúde na Escola
    (PSE)?* Brasília, DF, 2025.
-   BRASIL. Ministério da Saúde. *Quais são as ações do PSE?* Brasília,
    DF, 2025.
-   BRASIL. Ministério da Saúde; Ministério da Educação. *Caderno
    temático do Programa Saúde na Escola: saúde bucal.* Brasília, DF,
    2022.
-   SOMMERVILLE, Ian. *Engenharia de software.* 10. ed. São Paulo:
    Pearson Education do Brasil, 2019.
