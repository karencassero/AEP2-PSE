#include <stdio.h>
#include <string.h>

#define MAX 100

// Vetores para armazenar os dados das acoes
int codigo[MAX];
char nome[MAX][100];
char escola[MAX][100];
char tema[MAX][100];
char data[MAX][20];
char responsavel[MAX][100];
char publico[MAX][100];
int previstos[MAX];
int efetivos[MAX];
int situacao[MAX];

int total = 0;

// Funcao para ler numeros inteiros
int lerInteiro() {
    int valor;
    
    while (scanf("%d", &valor) != 1) {
        printf("Valor invalido! Digite um numero: ");
        while (getchar() != '\n');
    }

    while (getchar() != '\n');

    return valor;
}

// Funcao para ler textos
void lerTexto(char texto[]) {
    scanf(" %99[^\n]", texto);
    while (getchar() != '\n');
}

// Funcao para validar a data DD/MM/AAAA
int validarData(char d[]) {
    int i;

    if (strlen(d) != 10)
        return 0;

    if (d[2] != '/' || d[5] != '/')
        return 0;

    for (i = 0; i < 10; i++) {
        if (i != 2 && i != 5) {
            if (d[i] < '0' || d[i] > '9')
                return 0;
        }
    }

    return 1;
}

// Funcao de login
int login() {
    char email[100];
    char senha[100];
    int tipo;

    printf("\n========== LOGIN PSE ==========\n");

    printf("E-mail: ");
    lerTexto(email);

    printf("Senha: ");
    lerTexto(senha);

    printf("\nTipo de usuario:\n");
    printf("1 - Diretor da escola\n");
    printf("2 - Profissional da saude\n");
    printf("3 - Professor/Equipe pedagogica\n");
    printf("4 - Coordenador/Gestor do PSE\n");

    printf("Escolha: ");
    tipo = lerInteiro();

    if (strcmp(email, "admin@pse.com") == 0 &&
        strcmp(senha, "1234") == 0 &&
        tipo >= 1 && tipo <= 4) {

        printf("\nLogin realizado com sucesso!\n");
        return 1;
    }

    printf("\nDados de login invalidos!\n");
    return 0;
}

// Funcao para localizar uma acao pelo codigo
int localizarAcao(int cod) {
    int i;

    for (i = 0; i < total; i++) {
        if (codigo[i] == cod) {
            return i;
        }
    }

    return -1;
}

// Funcao para cadastrar uma acao
void cadastrarAcao() {
    int cod;

    if (total >= MAX) {
        printf("\nLimite de cadastros atingido!\n");
        return;
    }

    printf("\n========== CADASTRAR ACAO ==========\n");

    printf("Codigo: ");
    cod = lerInteiro();

    if (localizarAcao(cod) != -1) {
        printf("Esse codigo ja esta cadastrado!\n");
        return;
    }

    if (cod <= 0) {
        printf("O codigo deve ser maior que zero!\n");
        return;
    }

    codigo[total] = cod;

    printf("Nome da acao: ");
    lerTexto(nome[total]);

    printf("Escola: ");
    lerTexto(escola[total]);

    printf("Tema do PSE: ");
    lerTexto(tema[total]);

    do {
        printf("Data (DD/MM/AAAA): ");
        scanf("%19s", data[total]);
        while (getchar() != '\n');

        if (!validarData(data[total])) {
            printf("Data invalida! Tente novamente.\n");
        }

    } while (!validarData(data[total]));

    printf("Publico-alvo: ");
    lerTexto(publico[total]);

    printf("Responsavel: ");
    lerTexto(responsavel[total]);

    do {
        printf("Quantidade prevista de participantes: ");
        previstos[total] = lerInteiro();

        if (previstos[total] < 0) {
            printf("A quantidade nao pode ser negativa!\n");
        }

    } while (previstos[total] < 0);

    // Situacao inicial: Planejada
    situacao[total] = 1;

    // Participacao ainda nao registrada
    efetivos[total] = -1;

    total++;

    printf("\nAcao cadastrada com sucesso!\n");
}

// Funcao para listar as acoes
void listarAcoes() {
    int i;

    printf("\n========== LISTA DE ACOES ==========\n");

    if (total == 0) {
        printf("Nao existem acoes cadastradas.\n");
        return;
    }

    for (i = 0; i < total; i++) {

        printf("\nCodigo: %d\n", codigo[i]);
        printf("Nome: %s\n", nome[i]);
        printf("Escola: %s\n", escola[i]);
        printf("Tema: %s\n", tema[i]);
        printf("Data: %s\n", data[i]);
        printf("Publico-alvo: %s\n", publico[i]);
        printf("Responsavel: %s\n", responsavel[i]);
        printf("Participantes previstos: %d\n", previstos[i]);

        printf("Situacao: ");

        if (situacao[i] == 1)
            printf("Planejada\n");
        else if (situacao[i] == 2)
            printf("Em andamento\n");
        else if (situacao[i] == 3)
            printf("Concluida\n");
        else
            printf("Cancelada\n");

        if (efetivos[i] != -1)
            printf("Participantes efetivos: %d\n", efetivos[i]);
        else
            printf("Participantes efetivos: Nao registrados\n");
    }
}

// Funcao para pesquisar acoes
void pesquisarAcao() {
    int opcao, cod, i, encontrou = 0;
    char busca[100];

    printf("\n========== PESQUISAR ACAO ==========\n");
    printf("1 - Pesquisar por codigo\n");
    printf("2 - Pesquisar por nome\n");
    printf("3 - Pesquisar por escola\n");
    printf("4 - Pesquisar por tema\n");
    printf("Escolha: ");

    opcao = lerInteiro();

    if (opcao < 1 || opcao > 4) {
        printf("Opcao invalida!\n");
        return;
    }

    if (opcao == 1) {
        printf("Digite o codigo: ");
        cod = lerInteiro();

        i = localizarAcao(cod);

        if (i != -1) {
            printf("\nAcao encontrada: %s\n", nome[i]);
            printf("Escola: %s\n", escola[i]);
            printf("Tema: %s\n", tema[i]);
            printf("Data: %s\n", data[i]);
            printf("Codigo: %d\n", codigo[i]);
        } else {
            printf("Acao nao encontrada!\n");
        }

        return;
    }

    printf("Digite o termo da pesquisa: ");
    lerTexto(busca);

    for (i = 0; i < total; i++) {

        if ((opcao == 2 && strstr(nome[i], busca) != NULL) ||
            (opcao == 3 && strstr(escola[i], busca) != NULL) ||
            (opcao == 4 && strstr(tema[i], busca) != NULL)) {

            printf("\nCodigo: %d\n", codigo[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Escola: %s\n", escola[i]);
            printf("Tema: %s\n", tema[i]);

            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhuma acao encontrada!\n");
    }
}

// Funcao para atualizar a situacao
void atualizarSituacao() {
    int cod, pos, nova;

    printf("\n========== ATUALIZAR SITUACAO ==========\n");

    printf("Codigo da acao: ");
    cod = lerInteiro();

    pos = localizarAcao(cod);

    if (pos == -1) {
        printf("Acao nao encontrada!\n");
        return;
    }

    printf("\n1 - Planejada\n");
    printf("2 - Em andamento\n");
    printf("3 - Concluida\n");
    printf("4 - Cancelada\n");

    printf("Nova situacao: ");
    nova = lerInteiro();

    if (nova < 1 || nova > 4) {
        printf("Situacao invalida!\n");
        return;
    }

    situacao[pos] = nova;

    printf("\nSituacao atualizada com sucesso!\n");
}

// Funcao para registrar a participacao
void registrarParticipacao() {
    int cod, pos, quantidade;

    printf("\n========== REGISTRAR PARTICIPACAO ==========\n");

    printf("Codigo da acao: ");
    cod = lerInteiro();

    pos = localizarAcao(cod);

    if (pos == -1) {
        printf("Acao nao encontrada!\n");
        return;
    }

    if (situacao[pos] != 3) {
        printf("A acao precisa estar concluida!\n");
        return;
    }

    do {
        printf("Quantidade efetiva de participantes: ");
        quantidade = lerInteiro();

        if (quantidade < 0) {
            printf("Quantidade invalida!\n");
        }

    } while (quantidade < 0);

    efetivos[pos] = quantidade;

    printf("\nParticipacao registrada com sucesso!\n");
}

// Funcao para gerar o resumo geral
void gerarResumo() {
    int i;
    int planejadas = 0;
    int andamento = 0;
    int concluidas = 0;
    int canceladas = 0;

    int totalPrevistos = 0;
    int totalEfetivos = 0;

    float percentual = 0;

    printf("\n========== RESUMO GERAL ==========\n");

    if (total == 0) {
        printf("Nao existem dados para apresentar.\n");
        return;
    }

    for (i = 0; i < total; i++) {

        if (situacao[i] == 1)
            planejadas++;

        else if (situacao[i] == 2)
            andamento++;

        else if (situacao[i] == 3) {
            concluidas++;
            totalPrevistos += previstos[i];

            if (efetivos[i] != -1) {
                totalEfetivos += efetivos[i];
            }
        }

        else if (situacao[i] == 4)
            canceladas++;
    }

    if (totalPrevistos > 0) {
        percentual = (float)totalEfetivos /
                     totalPrevistos * 100;
    }

    printf("\nTotal de acoes: %d\n", total);
    printf("Planejadas: %d\n", planejadas);
    printf("Em andamento: %d\n", andamento);
    printf("Concluidas: %d\n", concluidas);
    printf("Canceladas: %d\n", canceladas);

    printf("\nParticipantes previstos nas acoes concluidas: %d\n",
           totalPrevistos);

    printf("Participantes efetivos registrados: %d\n",
           totalEfetivos);

    printf("Percentual de participacao: %.2f%%\n",
           percentual);
}

// Programa principal
int main() {
    int opcao;
    int acesso = 0;

    printf("====================================\n");
    printf(" SISTEMA PSE - SAUDE NA ESCOLA\n");
    printf("====================================\n");

    // Permite tentar o login novamente
    while (acesso == 0) {
        acesso = login();
    }

    do {

        printf("\n========== MENU PRINCIPAL ==========\n");
        printf("1 - Cadastrar acao\n");
        printf("2 - Listar acoes\n");
        printf("3 - Pesquisar acao\n");
        printf("4 - Atualizar situacao\n");
        printf("5 - Registrar participacao\n");
        printf("6 - Gerar resumo geral\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        opcao = lerInteiro();

        switch (opcao) {

            case 1:
                cadastrarAcao();
                break;

            case 2:
                listarAcoes();
                break;

            case 3:
                pesquisarAcao();
                break;

            case 4:
                atualizarSituacao();
                break;

            case 5:
                registrarParticipacao();
                break;

            case 6:
                gerarResumo();
                break;

            case 0:
                printf("\nEncerrando o sistema PSE...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
