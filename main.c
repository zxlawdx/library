#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char titulo[50];
    char autor[50];
    int ano_edicao;
    int exemplares_disponiveis;
    int exemplares_total;
} livro;

typedef struct
{
    char nome[50];
    char ID[10];
    livro emprestimo;
} usuario;

int LerCatalogo(livro list[MAX], int *j)
{
    int i = 0;
    char temp[200];
    FILE *Library = fopen("livros.txt", "r");
    if (Library == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        getchar();
        system("cls");
        return 0;
    }
    while (fscanf(Library, " %199[^\n]\n", temp) != EOF && i < MAX)
    {
        char *token = strtok(temp, ";");
        if (token != NULL)
        {
            strncpy(list[i].titulo, token, sizeof(list[i].titulo) - 1);
            list[i].titulo[sizeof(list[i].titulo) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            strncpy(list[i].autor, token, sizeof(list[i].autor) - 1);
            list[i].autor[sizeof(list[i].autor) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            list[i].ano_edicao = atoi(token);
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            list[i].exemplares_disponiveis = atoi(token);
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            list[i].exemplares_total = atoi(token);
        }
        printf("Titulo: %s\n", list[i].titulo);
        printf("Autor: %s\n", list[i].autor);
        printf("Ano: %d\n", list[i].ano_edicao);
        printf("Exemplares disponiveis: %d\n", list[i].exemplares_disponiveis);
        printf("Exemplares totais: %d\n\n", list[i].exemplares_total);
        i++;
    }
    fclose(Library);
    printf("\n\npress enter\n\n");
    getchar();
    getchar();
 sistema("cls");
 *j = i;
 retornar *j;
}

int incluir (livro cadastro[], int *quantidade)
{
 setlocale(LC_ALL, "Português");
 printf("Digite a quantidade de livros que serao cadastrados: ");
 scanf("% d", quantidade);
 ARQUIVO *Biblioteca = fopen("livros.txt", "a");
 se (Biblioteca == NULL)
    {
 printf("Nao foi possivel abrir o arquivo\n");
 retorno 1;
    }
 int eu;
 para (i = 0; i < *quantidade; i++)
    {
 printf("\nNome do livro: ");
 scanf("%49[^\n]s", cadastro[i].titulo);

 printf("Autor do livro: ");
 scanf("%49[^\n]s", cadastro[i].autor);

 printf("Ano de edicao: ");
 scanf("%d", &cadastro[i].ano_edicao);

 printf("Exemplares disponiveis: ");
 scanf("%d", &cadastro[i].exemplares_disponiveis);

 printf("Exempla totais: ");
 scanf("%d", &cadastro[i].exemplares_total);

 fprintf(Biblioteca, "%s;", cadastro[i].titulo);
 fprintf(Biblioteca, "%s;", cadastro[i].autor);
 fprintf(Biblioteca, "%d;", cadastro[i].ano_edicao);
 fprintf(Biblioteca, "%d;", cadastro[i].exemplares_disponiveis);
 fprintf(Biblioteca, "%d", cadastro[i].exemplares_total);
 fprintf(Biblioteca, "\n");

 getchar();
 sistema("cls");
    }
 fclose(Biblioteca);
 retorno *quantidade;
}

int cadastrar (usuário * identidade)
{
	
 ARQUIVO *usuário = fopen("emprestimo.txt", "a");
 se (usuário == NULL)
    {
 printf("Arquivo inválido!!\n");
 retorno 0;
    }
 printf("Nome do usuário: ");
 scanf("% 49[^\n] s", identidade->nome);
 printf("ID do usuário: ");
 scanf("% 9[^\n] s", identidade->ID);
 strcpy(identidade->emprestimo.titulo, "sem emprestimo");
 strcpy(identidade->emprestimo.autor, "sem emprestimo");
 fprintf(usuário, "%s;", identidade->nome);
 fprintf(usuário, "%s;", identidade->ID);
 fprintf(usuário, "%s;", identidade->emprestimo.titulo);
 fprintf(usuário, "%s;", identidade->emprestimo.autor);
 fprintf(usuário, "\n");
 fclose(usuário);
 retorno 1;
}
int excluir (lista viva [MAX])
{
 int j;
 char nome[200];
 LerCatalogo(lista, &j);
 ARQUIVO *livros_atualizar = fopen("livros.txt", "w");
 if (livros_atualizar == NULL)
    {
 printf("Nao foi possivel abrir o arquivo\n");
 retorno 0;
    }
 printf("digite o nome do Livro que deseja excluir: ");
 scanf("%199[^\n]", nome);
 int eu,l;
 para (i = 0; i < j; i++)
    {
 if (strcmp(nome, list[i].titulo) == 0)
        {
 para (l = i; l < j - 1; l++)
            {
                list[l] = list[l + 1];
            }
            for (l = 0; l < j - 1; l++)
            {
                fprintf(livros_atualizar, "%s;", list[l].titulo);
                fprintf(livros_atualizar, "%s;", list[l].autor);
                fprintf(livros_atualizar, "%d;", list[l].ano_edicao);
                fprintf(livros_atualizar, "%d;", list[l].exemplares_disponiveis);
                fprintf(livros_atualizar, "%d", list[l].exemplares_total);
                fprintf(livros_atualizar, "\n");
            }
            break;
        }
    }
    fclose(livros_atualizar);
    return 1;
}
int atualizar(livro list[MAX], usuario identidade, usuario verificar[MAX])
{
    int j;
    LerCatalogo(list, &j);
    emprestar(&identidade, verificar, list);
    FILE *livros_atualizar = fopen("livros.txt", "w");
    if (livros_atualizar == NULL)
    {
        printf("Nao foi possivel abrir o arquivo\n");
        return 0;
    }
    int i;
    for (i = 0; i < j; i++)
    {
        if (strcmp(list[i].titulo, identidade.emprestimo.titulo) == 0)
        {
            list[i].exemplares_disponiveis -= 1;
        }
        fprintf(livros_atualizar, "%s;", list[i].titulo);
        fprintf(livros_atualizar, "%s;", list[i].autor);
        fprintf(livros_atualizar, "%d;", list[i].ano_edicao);
        fprintf(livros_atualizar, "%d;", list[i].exemplares_disponiveis);
        fprintf(livros_atualizar, "%d", list[i].exemplares_total);
        fprintf(livros_atualizar, "\n");
    }
    fclose(livros_atualizar);
    return 1;
}

int emprestar(usuario *identidade, usuario verificar[], livro catalogo[MAX])
{
    int i = 0;
    int usuarioEncontrado = 0;
    printf("Digite o nome do usuario: ");
    scanf(" %49[^\n]s", identidade->nome);
    getchar();
    system("cls");
    FILE *emprestimo = fopen("emprestimo.txt", "r");
    char temp[100];
    if (emprestimo == NULL)
    {
        printf("Arquivo invalido!!\n");
        printf("- Pressione enter para continuar:\n\n");
        getchar();
        system("cls");
        return 0;
    }
    while (fscanf(emprestimo, " %99[^\n]\n", temp) != EOF && i < MAX)
    {
        char *token = strtok(temp, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].nome, token, sizeof(verificar[i].nome) - 1);
            verificar[i].nome[sizeof(verificar[i].nome) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].ID, token, sizeof(verificar[i].ID) - 1);
            verificar[i].ID[sizeof(verificar[i].ID) - 1] = '\0';
        }
        if (strcmp(identidade->nome, verificar[i].nome) == 0)
        {
            printf("Digite seu ID: ");
            scanf(" %9[^\n]s", identidade->ID);
            if (strcmp(identidade->ID, verificar[i].ID) == 0)
            {
                usuarioEncontrado = 1;
                break;
            }
            else
            {
                printf("ID invalido!!\n");
                fclose(emprestimo);
                return 0;
            }
        }
        i++;
    }
    fclose(emprestimo);

    if (!usuarioEncontrado)
    {
        printf("Usuario nao encontrado.\n");
        printf("- Pressione enter para continuar:\n\n");
        getchar();
        system("cls");
        return 0;
    }
    int k;
    LerCatalogo(catalogo, &k);
    char nome[50];
    char opc;
    printf("Digite o nome do livro: ");
    scanf(" %49[^\n]s", nome);
    getchar();
    system("cls");
   
	for (i = 0; i < k; i++)
    {
        if (strcmp(nome, catalogo[i].titulo) == 0)
        {
            if (catalogo[i].exemplares_disponiveis > 0)
            {
                printf("Deseja confirmar o emprestimo desse livro? (s/n)\n");
                scanf(" %c", &opc);
                switch (opc)
                {
                case 's':
                    strcpy(identidade->emprestimo.titulo, catalogo[i].titulo);
                    strcpy(identidade->emprestimo.autor, catalogo[i].autor);
                    printf("Emprestimo feito com sucesso!!\n\n");
                    printf("- Pressione enter para continuar:\n\n");
                    getchar();
                    system("cls");
                    return 1;
                case 'n':
                    return 0;
                default:
                    printf("Opcao invalida\n");
                    printf("- Pressione enter para continuar:\n\n");
                    getchar();
                    system("cls");
                    return 0;
                }
            }
            else
            {
                printf("Nao ha exemplares disponiveis desse livro.\n");
                return 0;
            }
        }
    }
    printf("Livro nao encontrado.\n");
    getchar();
    system("cls");
    return 0;
}
int devolver(usuario *identidade, usuario verificar[MAX], livro catalogo[MAX])
{
    int i = 0;
    int usuarioEncontrado = 0;
    char temp[100];

    printf("Digite o nome do usuario: ");
    scanf(" %49[^\n]", identidade->nome);
    getchar();

    FILE *emprestimo = fopen("emprestimo.txt", "r");
    if (emprestimo == NULL)
    {
        printf("Arquivo invalido!!\n");
        printf("- Pressione enter para continuar:\n\n");
        getchar();
        system("cls");
        return 0;
    }

    while (fscanf(emprestimo, " %99[^\n]\n", temp) != EOF && i < MAX)
    {
        char *token = strtok(temp, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].nome, token, sizeof(verificar[i].nome) - 1);
            verificar[i].nome[sizeof(verificar[i].nome) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].ID, token, sizeof(verificar[i].ID) - 1);
            verificar[i].ID[sizeof(verificar[i].ID) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].emprestimo.titulo, token, sizeof(verificar[i].emprestimo.titulo) - 1);
            verificar[i].emprestimo.titulo[sizeof(verificar[i].emprestimo.titulo) - 1] = '\0';
        }
        token = strtok(NULL, ";");
        if (token != NULL)
        {
            strncpy(verificar[i].emprestimo.autor, token, sizeof(verificar[i].emprestimo.autor) - 1);
            verificar[i].emprestimo.autor[sizeof(verificar[i].emprestimo.autor) - 1] = '\0';
        }
        i++;
    }
    fclose(emprestimo);
    int j;
    for (j = 0; j < i; j++)
    {
        if (strcmp(identidade->nome, verificar[j].nome) == 0)
        {
            printf("Digite seu ID: ");
            scanf(" %9[^\n]", identidade->ID);
            if (strcmp(identidade->ID, verificar[j].ID) == 0)
            {
                usuarioEncontrado = 1;
                break;
            }
            else
            {
                printf("ID invalido!!\n");
                printf("- Pressione enter para continuar:\n\n");
                getchar();
                system("cls");
                return 0;
            }
        }
    }

    if (!usuarioEncontrado)
    {
        printf("Usuario nao encontrado.\n");
        printf("- Pressione enter para continuar:\n\n");
        getchar();
        system("cls");
        return 0;
    }

    int k;
    LerCatalogo(catalogo, &k);
    char nome[50];
    char opc;

    printf("Digite o nome do livro: ");
    scanf(" %49[^\n]", nome);
    getchar();

    int livroEncontrado = 0;
    
    for (i = 0; i < k; i++)
    {
        if (strcmp(nome, catalogo[i].titulo) == 0)
        {
            livroEncontrado = 1;
            catalogo[i].exemplares_disponiveis++;
            
            FILE *emprestimo_temp = fopen("emprestimo_temp.txt", "w");
            if (emprestimo_temp == NULL)
            {
                printf("Erro ao criar o arquivo temporário!!\n");
                printf("- Pressione enter para continuar:\n\n");
                getchar();
                system("cls");
                return 0;
            }

            for (j = 0; j < i; j++)
            {
                fprintf(emprestimo_temp, "%s;%s;%s;%s\n", verificar[j].nome, verificar[j].ID, verificar[j].emprestimo.titulo, verificar[j].emprestimo.autor);
            }
            for (j = i + 1; j < k; j++)
            {
                fprintf(emprestimo_temp, "%s;%s;%s;%s\n", verificar[j].nome, verificar[j].ID, verificar[j].emprestimo.titulo, verificar[j].emprestimo.autor);
            }

            fclose(emprestimo_temp);

            remove("emprestimo.txt");
            rename("emprestimo_temp.txt", "emprestimo.txt");

            FILE *livros_atualizar = fopen("livros.txt", "w");
            if (livros_atualizar == NULL)
            {
                printf("Nao foi possivel abrir o arquivo para atualizar os livros\n");
                return 0;
            }
            for (i = 0; i < k; i++)
            {
                fprintf(livros_atualizar, "%s;%s;%d;%d;%d\n", catalogo[i].titulo, catalogo[i].autor, catalogo[i].ano_edicao, catalogo[i].exemplares_disponiveis, catalogo[i].exemplares_total);
            }
            fclose(livros_atualizar);

            printf("Devolucao feita com sucesso!!\n\n");
            printf("- Pressione enter para continuar:\n\n");
            getchar();
            system("cls");
            return 1;
        }
    }

    if (!livroEncontrado)
    {
        printf("Livro nao encontrado.\n");
        getchar();
        system("cls");
        return 0;
    }
}

int main()
{
    livro catalogo[MAX];
    usuario usuarioAtual;
    usuario verificar[MAX];
    int j = 0;
    int *i = &j;
    int quantidadeLivros;
    int opcao;
    char senha[30] = {"biblioteca123"};
    char tentativa[30];
    while (1)
    {
        printf("\n-----------Menu------------\n");
        printf("1. Cadastrar livros\n");
        printf("2. Cadastrar usuario\n");
        printf("3. Emprestar livro\n");
        printf("4. Listar livros\n");
 printf("5. excluir livro\n");
 impressãof("6. Devólver Livro\n");impressãof("6. Devólver Livro\n");
 impressãof("7. Sair\n");impressãof("7. Sair\n");
 impressãof("\n-------\n");impressãof("\n-------\n");
 impressãof("Escolha uma operação:");impressãof("Escolha uma operação:");
 digitalização("%d", &opcão);digitalização("%d", &opcão);
 pegue char();pegue char();

 interruptor (opcão)interruptor (opcão)
        {
 caso 1:caso 1:
 sistema("cls");sistema("cls");
 impressãof("Digite uma senhora de acesso:");impressãof("Digite uma senhora de acesso:");
 digitalização("% 29[^\n]", tentativa);digitalização("% 29[^\n]", tentativa);
 se (strcmp(senha, tentativa) == 0)se (strcmp(senha, tentativa) == 0)
            {
 inclusir (catalogo, & quantidadeLivros);inclusir (catalogo, & quantidadeLivros);
            }
 outra outraoutra outra
            {
 impressãof("Senha incorreta!!\n");impressãof("Senha incorreta!!\n");
 impressãof("Saindo...\n");impressãof("Saindo...\n");
 pegue char();pegue char();
 sistema("cls");sistema("cls");
 quebrar;quebra;
            }
 quebrar;quebra;
 caso 2:caso 2:
 sistema("cls");sistema("cls");
 cadastro (&usuarioAtual);cadastro (&usuarioAtual);
 quebrar;quebra;
 caso 3:caso 3:
 sistema("cls");sistema("cls");
 se (atualizar(catalogo, usuarioAtual, verificar))se (atualizar(catalogo, usuarioAtual, verificar))
 impressãof("Emprestimo bem sucedido\n");impressãof("Emprestimo bem sucedido\n");
 outra outraoutra outra
 impressãof("Falha no emprestimo\n");impressãof("Falha no emprestimo\n");
 impressãof("- Pressione entrer para contínuo:\n\n");impressãof("- Pressione entrer para contínuo:\n\n");
 pegue char();pegue char();
 sistema("cls");sistema("cls");
 quebrar;quebra;
 caso 4:caso 4:
 sistema("cls");sistema("cls");
 LerCatalogo(catálogo, i);LerCatalogo(catálogo, i);
 quebrar;quebra;
 caso 5:caso 5:
 sistema("cls");sistema("cls");
 excluir(catálogo);excluir(catálogo);
 quebrar;quebra;
 caso 6:caso 6:
 sistema("cls");sistema("cls");
 devolver(&usuarioAtual, verificar, catalogo);devolver(&usuarioAtual, verificar, catalogo);
 caso 7:caso 7:
 retardo 0;retorno 0;
 quebrar;quebra;
 pré-definição: pré-definição:
 sistema("cls");sistema("cls");
 impressãof("Opcao inválida!\n");impressãof("Opcao inválida!\n");
 quebrar;quebra;
        }
    }

 retardo 0;retorno 0;
}
