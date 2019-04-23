#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h>


void titulo()
{

    printf("################################################################################################################\n");
    printf("#   NN           NN         AAAA         RRRRRRR      UU        UU   TTTTTTTTTTTTTTTTTT    OOOOOOOOOOOOO       #\n");
    printf("#   NN NN        NN        AA  AA        RR     RR    UU        UU           TT           OO            OO     #\n");
    printf("#   NN  NN       NN       AA    AA       RR      RR   UU        UU           TT          OO              OO    #\n");
    printf("#   NN   NN      NN      AA      AA      RR       RR  UU        UU           TT         OO               OO    #\n");
    printf("#   NN    NN     NN     AA        AA     RR      RR   UU        UU           TT         OO               OO    #\n");
    printf("#   NN      NN   NN    AAAAAAAAAAAAAA    RRRRRRRRR    UU        UU           TT         OO               OO    #\n");
    printf("#   NN       NN  NN   AA            AA   RR     RR    UU        UU           TT          OO             OO     #\n");
    printf("#   NN        NN NN  AA              AA  RR      RR   UU        UU           TT           OO           OO      #\n");
    printf("#   NN         NNNN AA                AA RR       RR    UUUUUUUU             TT            OOOOOOOOOOOOO       #\n");
    printf("################################################################################################################\n");
}

typedef struct usuariosRegistrados
{
    char nome[20];
    char email[20];
    int senha;
    int id;
    struct usuariosRegistrados *prox;
} USUARIOS;

void loginSistema(void)
{
    setlocale(LC_ALL,"");


    USUARIOS *inicio = NULL;
    USUARIOS *fim = NULL;
    USUARIOS *auxiliar;
    USUARIOS *anterior;

    int repetir = 0;
    do
    {

        int escolha, senha[20], contadorUsuario = 1, validacacaoUsuario, senhaUsuario, senhaLogin, nomeLoop = 0;
        char nomeLogin[20], nomeTeste[20], nomeIgual[20];

        titulo();
        printf("\n");
        printf("                                              BEM VINDO!                                                        \n");
        printf("                                        [1] Ja possui uma conta?                                                \n");
        printf("                                        [2] Criar uma conta                                                     \n");
        printf("                                                                                                                 \n");
        printf("                                                                                                                 \n");
        printf("                                        [5] Fechar o programa                            [98] - Para ver todos os usuarios cadastrados!                      \n");
        scanf("%i", &escolha);

        if(escolha == 2)       // CRIAR A CONTA DO USUARIO
        {
            USUARIOS *novo=NULL;
            novo = malloc(sizeof (USUARIOS));
            validacacaoUsuario = 0; // reset na variavel

            do    // LOOP DO NOME
            {
                printf("                              Insira o seu nome: ");
                scanf("%s", nomeIgual);                                      // Precisamos verificar se ja existe usuario com o mesmo nome

                auxiliar = inicio;
                if(inicio == NULL)    // Caso nao exista usuarios registrados ele nao precisa verificar
                {
                    strcpy(novo->nome, nomeIgual);
                    nomeLoop = 1;

                }
                else
                {
                    while(auxiliar != NULL)
                    {
                        validacacaoUsuario = strcmp(nomeIgual,auxiliar->nome); // Verifica se o nome entrado é igual ao nome do nó
                        // printf("\n\nNome igual: %s, Nome Aux: %s\n\n", nomeIgual, auxiliar->nome); DEBUG
                        auxiliar = auxiliar->prox;                      // Vai para o proximo nó
                        if(validacacaoUsuario == 0)
                        {
                            break;                                     // Caso ele encontre um nome igual, sai do loop na hora
                        }
                    }
                    if(validacacaoUsuario == 0)
                    {
                        printf("Este nome de usuario ja existe, tente outro!\n");
                        system("Pause");
                        system("cls");
                        titulo();
                        printf("\n\n\n");
                    }
                    else
                    {
                        strcpy(novo->nome, nomeIgual);   // Adicionando o nome ao nó
                        nomeLoop = 1;
                        break;                          // Forçando a saida no Loop
                    }
                }

                validacacaoUsuario = 0; // reset na variavel

            }
            while(nomeLoop == 0);

            printf("                              Insira sua senha: ");
            scanf("%i", &novo->senha);
            printf("                              Insira o seu email: ");
            scanf("%s", novo->email);

            novo->id = calculoHash(novo->nome, novo->senha);  // calculando o hash do usuario


            if(inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                fim->prox = NULL;
            }
            else
            {
                novo->prox = inicio;
                inicio = novo;
            }

            system("cls");
            titulo();
            printf(" \n                               #####################################                  ");
            printf(" \n                               # Sua conta foi criada com sucesso! #                  ");
            printf(" \n                               #####################################                \n");
            system("PAUSE");
            system("cls");
        }
        else if(escolha == 1)   // LOGIN DO USUARIO
        {
            printf("                              Login: ");
            scanf("%s", nomeLogin);

            // PARA ISSO PRECISO PERCORRER TODO A LISTA E VERIFICAR SE EXISTE ESTE USUARIO!

            if(inicio == NULL)
            {
                printf("Não existe usuarios cadastrados\n");
                system("pause");
                system("cls");
            }
            else
            {
                auxiliar = inicio;

                while(auxiliar != NULL)    // 1 eh o estado inicial do loop, quando eu acho o usuario, auxiliar == 0 ai encerra.
                {
                    validacacaoUsuario = strcmp(nomeLogin,auxiliar->nome); // Verifica se o nome entrado é igual ao nome do nó
                    if(validacacaoUsuario == 0)
                    {
                        senhaUsuario = auxiliar->senha;   // Quando o usuario existe, eu já aproveito e coleto a senha dele para verificar mais tarde
                        auxiliar == 0;
                        break;                          // Forçando a saida no Loop
                    }

                    auxiliar = auxiliar->prox; // vai para o proximo nó
                }
                if(validacacaoUsuario != 0)   // caso nao exista usuario ele sai do programa
                {
                    printf("\n\nO usuario nao existe\n");
                    system("PAUSE");
                    system("cls");
                }
                else  // Caso o usuario existe ele vem pro else
                {
                    printf("                              Senha: ");
                    scanf("%i", &senhaLogin);

                    if(senhaLogin == senhaUsuario)   // Verificando se a senha do usuario está certa
                    {
                        printf("\n Login Efetuado com sucesso!");
                        animacao_demorada();
                        repetir = 1; // Sai do loop
                    }
                    else
                    {
                        printf("Senha invalida!\n");
                        system("PAUSE");
                        system("cls");
                    }
                }

            }

        }
        else if(escolha == 98)    // MOSTRAR TODOS OS USUARIOS CADASTRADOS
        {
            if(inicio == NULL)
            {
                printf("Não existe usuarios cadastrados\n");
            }
            else
            {
                printf("\nUsuarios cadastrados\n");
                auxiliar = inicio;
                while(auxiliar != NULL)
                {
                    printf("Usuario %i\n", contadorUsuario);
                    printf("NOME: %s \n", auxiliar->nome);
                    printf("SENHA: %i \n", auxiliar->senha);
                    printf("EMAIL: %s \n", auxiliar->email);
                    printf("ID: %i\n", auxiliar->id);
                    auxiliar = auxiliar->prox;
                    contadorUsuario++;

                }
            }
            system("PAUSE");
            system("cls");

        }
        else if(escolha == 5)   // Sair do programa
        {
            printf("\n                                          Saindo do programa!\n");
            exit(0);

        }

    }
    while(repetir == 0);

    selecaoPersonagem(auxiliar->id);

}


typedef struct personagem
{
    int id;
    int codigo;
    char nomePersonagem[20];
    char vila[20];
    char graduacao[20];
    int graduacaoNumero;
    char perso[20];
    char estilo[20];
    int nivel;
    int taijutsu;
    int ninjutsu;
    int genjutsu;
    int forca;
    int intelecto;
    int energia;
    int vitoriasMapa;  //adicionado
    int vitoriasDojo;  //
    int derrotasMapa;  //
    int derrotasDojo;  //
    int ryous;         //
    struct personagem *prox;
} PERSONAGEM;


void selecaoPersonagem(int codigoHash)
{
    int escolha = 0, sair = 0, contadorPersonagens = 0, codigoPersonagem, escolhaCerta;

    system("cls");
    titulo();

    PERSONAGEM *inicio=NULL;
    PERSONAGEM *fim=NULL;
    PERSONAGEM *auxiliar;
    PERSONAGEM *anterior;

    do      // INICIOOOOOOOO DO LOOOOOOP
    {

        printf("#\n#                       [1]SELECIONAR PERSONAGEM\n");
        printf("#                          [2]CRIAR PERSONAGEM\n");
        printf("#                             ESCOLHA => ");
        scanf("%i", &escolha);

        if(escolha == 2)     // CRIAR PERSONAGEM
        {
            PERSONAGEM *novo=NULL;
            novo = malloc(sizeof (PERSONAGEM));
            contadorPersonagens ++;  // Conta quantos personagens foram criados

            printf("#\n");
            printf("#              CRIACAO DO PERSONAGEM\n");
            printf("#		Nome:");
            scanf("%s", novo->nomePersonagem);
            printf("#		Escolha a sua Vila oculta                              \n");
            printf("#		[1] - Folha  [2] - Areia    [3] - Nevoa [4] - Pedra\n");
            printf("#               [5] - Nuvem  [6] - Akatsuki [7] - Som   [8] - Chuva    =>");

            do  // Loop para caso o usuario escolhe uma opcao errada
            {
                scanf("%i", &escolha);
                if(escolha>=1 && escolha <= 8)
                {
                    switch(escolha)
                    {
                    case 1:
                        strcpy(novo->vila, "Folha");
                        break;
                    case 2:
                        strcpy(novo->vila, "Areia");
                        break;
                    case 3:
                        strcpy(novo->vila, "Nevoa");
                        break;
                    case 4:
                        strcpy(novo->vila, "Pedra");
                        break;
                    case 5:
                        strcpy(novo->vila, "Nuvem");
                        break;
                    case 6:
                        strcpy(novo->vila, "Akatsuki");
                        break;
                    case 7:
                        strcpy(novo->vila, "Som");
                        break;
                    case 8:
                        strcpy(novo->vila, "Chuva");
                        break;
                    }

                    escolhaCerta = 1;
                }
                else
                {
                    printf("Escolha errada, tente novamente!");
                    escolhaCerta = 0;
                }
            }
            while(escolhaCerta == 0);
            printf("#                                                                                                           \n");
            printf("#		Escolha o seu personagem\n");
            printf("#		[1] - Naruto Uzumaki [2]- Sakura Haruno [3]- Sasuke Uchiha [4]- Kiba Inuzuka [5]- Hinata Hyuuga     \n");
            printf("#		[6] - Shino Aburame  [7]- Rock Lee      [8]- Tenten        [9]- Neji Hyuuga  [10]- Shikamaru Nara   \n");
            printf("#		[11]- Kakashi Hatake [12]- Maito Gai    [13]- Minato Namikaze                          =>");
            do // Esse Loop é para caso o usuario digite uma opcao errada
            {
                scanf("%i", &escolha);
                printf("#\n");

                if(escolha>=1 && escolha <= 13)
                {
                    switch(escolha)
                    {
                    case 1:
                        strcpy(novo->perso, "Naruto Uzumaki");
                        break;
                    case 2:
                        strcpy(novo->perso, "Sakura Haruno");
                        break;
                    case 3:
                        strcpy(novo->perso, "Sasuke Uchiha");
                        break;
                    case 4:
                        strcpy(novo->perso, "Kiba Inuzuka");
                        break;
                    case 5:
                        strcpy(novo->perso, "Hinata Hyuuga ");
                        break;
                    case 6:
                        strcpy(novo->perso, "Shino Aburame");
                        break;
                    case 7:
                        strcpy(novo->perso, "Rock Lee");
                        break;
                    case 8:
                        strcpy(novo->perso, "Tenten");
                        break;
                    case 9:
                        strcpy(novo->perso, "Neji Hyuuga");
                        break;
                    case 10:
                        strcpy(novo->perso, "Shikamaru Nara");
                        break;
                    case 11:
                        strcpy(novo->perso, "Kakashi Hatake");
                        break;
                    case 12:
                        strcpy(novo->perso, "Maito Gai");
                        break;
                    case 13:
                        strcpy(novo->perso, "Minato Namikaze");
                        break;
                    }

                    escolhaCerta = 1;
                }
                else
                {
                    printf("Escolha errada, tente novamente!");
                    escolhaCerta = 0;
                }
            }
            while(escolhaCerta == 0);

            printf("#                                                                                                                \n");
            printf("#		Escolha o seu estilo de luta. Atencao: O seu estilo determinará quais justus poderão ser utilizados      \n");
            printf("#                                                                                                                \n");
            printf("#            [1] - Taijutsu            [2] - Ninjutsu              [3] - Genjutsu                                 \n");
            printf("#                                                                                                                \n");
            printf("#       Taijutsu  |##########| 10   Taijutsu  |#         | 1    Taijutsu  |#         | 1                         \n");
            printf("#       Ninjutsu  |#         | 1    Ninjutsu  |##########| 10  	Ninjutsu  |#         | 1                         \n");
            printf("#       Genjustu  |#         | 1    Genjustu  |#         | 1    Genjustu  |##########| 1                         \n");
            printf("#       Forca     |#####     | 5    Forca     |#         | 1    Forca     |#         | 1                         \n");
            printf("#       Intelecto |#         | 1    Intelecto |#####     | 5    Intelecto |#####     | 5                         \n");
            printf("#       Energia   |##########| 10   Energia   |##########| 10   Energia   |##########| 10     =>");

            do // Esse Loop é para caso o usuario digite uma opcao errada
            {
                scanf("%i", &escolha);


                if(escolha>=1 && escolha <= 13)
                {
                    switch(escolha)
                    {
                    case 1:
                        strcpy(novo->estilo, "Taijutsu");
                        strcpy(novo->graduacao, "Estudante");
                        novo->graduacaoNumero = 0;
                        novo->taijutsu = 10;
                        novo->ninjutsu = 1;
                        novo->genjutsu = 1;
                        novo->forca = 5;
                        novo->intelecto = 1;
                        novo->energia = 10;
                        novo->nivel = 1;
                        novo->ryous = 1500;
                        novo->id = codigoHash;
                        novo->codigo = contadorPersonagens;
                        novo->vitoriasDojo = 0;
                        novo->vitoriasMapa = 0;
                        novo->derrotasDojo = 0;
                        novo->derrotasMapa = 0;
                        break;
                    case 2:
                        strcpy(novo->estilo, "Ninjutsu");
                        strcpy(novo->graduacao, "Estudante");
                        novo->graduacaoNumero = 0;
                        novo->taijutsu = 1;
                        novo->ninjutsu = 10;
                        novo->genjutsu = 1;
                        novo->forca = 1;
                        novo->intelecto = 5;
                        novo->energia = 10;
                        novo->nivel = 1;
                        novo->ryous = 1500;
                        novo->id = codigoHash;
                        novo->codigo = contadorPersonagens;
                        novo->vitoriasDojo = 0;
                        novo->vitoriasMapa = 0;
                        novo->derrotasDojo = 0;
                        novo->derrotasMapa = 0;
                        break;
                    case 3:
                        strcpy(novo->estilo, "Genjutsu");
                        strcpy(novo->graduacao, "Estudante");
                        novo->graduacaoNumero = 0;
                        novo->taijutsu = 1;
                        novo->ninjutsu = 1;
                        novo->genjutsu = 10;
                        novo->forca = 1;
                        novo->intelecto = 15;
                        novo->energia = 10;
                        novo->nivel = 1;
                        novo->ryous = 1500;
                        novo->id = codigoHash;
                        novo->codigo = contadorPersonagens;
                        novo->vitoriasDojo = 0;
                        novo->vitoriasMapa = 0;
                        novo->derrotasDojo = 0;
                        novo->derrotasMapa = 0;
                        break;
                    }
                    escolhaCerta = 1;
                }
                else
                {
                    printf("Escolha errada, tente novamente!");
                    escolhaCerta = 0;
                }
            }
            while(escolhaCerta == 0);

            printf("\n################################################################################################################\n");

            // Criação do nó do personagem
            if(inicio == NULL)
            {
                inicio = novo;
                fim = novo;
                fim->prox = NULL;

            }
            else
            {
                novo->prox = inicio;
                inicio = novo;
            }

            //     DEBUG PARA VERIFICAR SE PASSOU OS VALORES CORRETOS PARA O NÓ
            if(inicio == NULL)
            {
                //Lista Vazia!
                printf("A lista está vazia, não há o que mostrar \n");
            }
            else
            {
                printf("\nSeu personagem \n");
                auxiliar = inicio;
                while(auxiliar != NULL)
                {
                    printf("#Nome: %s \n", auxiliar->nomePersonagem);
                    printf("#Vila: %s \n", auxiliar->vila);
                    printf("#Nivel: %i \n", auxiliar->nivel);
                    printf("#Graducao: %s \n", auxiliar->graduacao);
                    printf("#Personagem: %s \n", auxiliar->perso);
                    printf("#Taijutsu: %d \n", auxiliar->taijutsu);
                    printf("#Ninjutsu: %d \n", auxiliar->ninjutsu);
                    printf("#Genjutsu: %d \n", auxiliar->genjutsu);
                    printf("#Forca: %d \n", auxiliar->forca);
                    printf("#Intelecto: %d \n", auxiliar->intelecto);
                    printf("#Energia: %d \n", auxiliar->energia);
                    printf("#Hash: %d \n", auxiliar->id);
                    printf("\n################");
                    break;
                }
            }

            system("PAUSE");
            system("cls");
            titulo();

        }
        else if(escolha == 1)   //SELECIONAR PERSONAGEM
        {

            if(inicio == NULL)
            {
                printf("Voce ainda nao possui nenhum personagem! Crie um! \n");
                system("Pause");
                system("cls");
                titulo();
            }
            else
            {
                system("cls");
                titulo();
                printf("\n#                                   OS SEUS PERSONAGENS: \n");
                printf("#            PARA ESCOLHER O PERSONAGEM PARA JOGAR, BASTA INSERIR O CODIGO DELE!\n");

                auxiliar = inicio;
                int vetorCodigo[10], k = 0;
                while(auxiliar != NULL)
                {
                    if(codigoHash == auxiliar->id)         // Aqui ele vai printar para o usuarios todos os personagens que ele possui
                    {
                        printf("#CODIGO DO PERSONAGEM: %i\n", auxiliar->codigo);
                        printf("#Nome: %s \n", auxiliar->nomePersonagem);
                        printf("#Vila: %s \n", auxiliar->vila);
                        printf("#Nivel: %i \n", auxiliar->nivel);
                        printf("#Graducao: %s \n", auxiliar->graduacao);
                        printf("#Personagem: %s \n", auxiliar->perso);
                        printf("#Taijutsu: %d \n", auxiliar->taijutsu);
                        printf("#Ninjutsu: %d \n", auxiliar->ninjutsu);
                        printf("#Genjutsu: %d \n", auxiliar->genjutsu);
                        printf("#Forca: %d \n", auxiliar->forca);
                        printf("#Intelecto: %d \n", auxiliar->intelecto);
                        printf("#Energia: %d \n", auxiliar->energia);
                        printf("#Hash: %d \n", auxiliar->id);
                        printf("###########################\n");

                        vetorCodigo[k] = auxiliar->codigo;    // Aqui o vetor vai armazernar todos os codigos dos personagens que o usuario possui
                        k++;
                    }                                         // para depois eu poder verificar se ele inseriu o codigo certo.

                    auxiliar = auxiliar->prox; // verifica o proximo nó
                }

                int i;
                //for(i=0; i<=contadorPersonagens-1; i++)  aqui serve apenas para verificar os codigos do personagens que foram armazenados
                //{
                //    printf("codigo dos personagens armazenados no vetor: %i\n", vetorCodigo[i]);
                //}

                int achei = 0;
                do             // Loop do codigo do personagem, enquanto o usuario nao digitar o codigo certo ele nao consegue logar
                {

                    printf("Insira aqui o codigo do personagem a ser jogado: ");
                    scanf("%i", &codigoPersonagem);

                    // aqui eu vou verificar se o codigo inserido pelo usuario existe, caso nao ele escolheu um personagem errado

                    for(i=0; i<=contadorPersonagens-1; i++)
                    {
                        if(codigoPersonagem == vetorCodigo[i])
                        {
                            achei = 1;
                            break;
                        }
                        else
                        {
                            achei = 0;
                        }
                    }

                }
                while(achei == 0);

                printf("\nPersonagem Selecionado, tenha um bom jogo!\n");
                system("PAUSE");

                //Trambique para passar os dados do personagem para o jogo, é nois tamo ai

                int codigo, nivel, taijutsu, ninjutsu, genjutsu, id, forca, energia, intelecto, vitoriasDojo, vitoriasMapa, derrotasDojo, derrotasMapa, ryous, graduacaoNumero;
                char nomePersonagem[20], vila[20], graduacao[20], perso[20], estilo[20];

                auxiliar = inicio;
                while(auxiliar != NULL)
                {
                    if(codigoPersonagem == auxiliar->codigo)
                    {
                        codigo = auxiliar->codigo;
                        strcpy(nomePersonagem, auxiliar->nomePersonagem);
                        strcpy(vila, auxiliar->vila);
                        nivel = auxiliar->nivel;
                        strcpy(graduacao, auxiliar->graduacao);
                        graduacaoNumero = auxiliar->graduacaoNumero;
                        strcpy(perso,auxiliar->perso);
                        taijutsu = auxiliar->taijutsu;
                        ninjutsu = auxiliar->ninjutsu;
                        genjutsu = auxiliar->genjutsu;
                        forca = auxiliar->forca;
                        intelecto = auxiliar->intelecto;
                        energia = auxiliar->energia;
                        id = auxiliar->id;
                        vitoriasDojo = auxiliar->vitoriasDojo;
                        vitoriasMapa = auxiliar->vitoriasMapa;
                        derrotasDojo = auxiliar->derrotasDojo;
                        derrotasMapa = auxiliar->derrotasMapa;
                        strcpy(estilo, auxiliar->estilo);
                        ryous = auxiliar->ryous;
                        printf("###########################\n");
                    }
                    auxiliar = auxiliar->prox; // recebe o endereço do proximo, até acabar e auxiliar ser = NULL
                }

                jogo(codigo,nivel,taijutsu,ninjutsu,genjutsu,id,forca,energia,intelecto,nomePersonagem,vila,graduacao,perso, vitoriasDojo, vitoriasMapa, derrotasDojo, derrotasMapa, estilo, ryous, graduacaoNumero);
                break;

            }
        }
        else if((escolha != 1) || (escolha != 2))
        {
            printf("Opcao invalida, retornando");
            system("pause");
            system("cls");
            titulo();
        }
    }
    while(sair == 0);  // FIM DO LOOOOOOOP


}

//Lista para armazenar os Jutsus que o usuario possui

typedef struct jutsus
{
    int codigoJutsu;
    char nomeJutsu[20];
    int ataque;
    int consumoChakra;
    int consumoStamina;
    struct jutsus *prox;
} JUTSUS;


void jogo(int codigo, int nivel,int taijutsu,int ninjutsu,int genjutsu,int id,int forca,int energia,int intelecto, char nomePersonagem[20],char vila[20],char graduacao[20],char perso[20],
          int vitoriasDojo, int vitoriasMapa, int derrotasDojo, int derrotasMapa, char estilo[20], int ryous, int graduacaoNumero)
{

    int i, escolhaMenuPrincipal, vidaAtual, vidaMax, chakraAtual, chakraMax, experienciaAtual = 0, experienciaMax = 1200, staminaAtual, staminaMax, ataqueTaijutsu, ataqueNinGenjustu, recompensaExp;
    int jutsusAprendidos = 0, tarefasConcluidas = 0, missoesConcluidas = 0;    // ATENCAO ALGUMAS DESSAS VARIAVEIS TEM QUE SER PASSADAS PARA A STRUCT DO PERSONAGEM

    JUTSUS *inicio=NULL;
    JUTSUS *fim=NULL;
    JUTSUS *auxiliar;
    JUTSUS *anterior;

    int vetorJutsusAprendidosTai[7], vetorJutsusAprendidosNin[7], vetorJutsusAprendidosGen[7]; // Esse vetor serve para saber quais jutsus eu já aprendi, para evitar de aprender o jutsu mais de uma vez
    // Entao, sempre que eu aprender eu adiciono o valor 1 na posicao do vetor do jutsu.

            for(i=1; i<=7; i++){
                    vetorJutsusAprendidosTai[i] = 0;
                    vetorJutsusAprendidosNin[i] = 0;
                    vetorJutsusAprendidosGen[i] = 0;  // Aqui eu zero todas as posicoes do vetor, para nao ter perigo de ter algum numero indesejavel dentro dele
                }

    // TABELA DE FORMULAS, PASSAR PARA FUNCAO , PARA FACILITAR O PROCESSO

    //Formula para calcular a vida do personagem
    vidaMax = energia * 6;
    vidaAtual = vidaMax;

    //Formula do Chakra
    chakraMax = energia * 6 + ninjutsu*14 + genjutsu*7;
    chakraAtual = chakraMax;

    // Formula da Stamina
    staminaMax = energia * 6 + taijutsu*7 + 14;
    staminaAtual = staminaMax;

    // Formula Ataque Taijutsu
    ataqueTaijutsu = forca/2;

    // Formula Ataque Ninjutsu e Genjutsu
    ataqueNinGenjustu = intelecto/2;

    //GraduacaoNumero
    // 0- Estudante 1- Genin 2 -Chunin 3- Jounin 4- Anbu 5- Sannin 6- Kage

    // Sistema de Experiencia e progressão de nivel, a cada nivel a experiencia necessária aumenta em 1200
    // sistemaNivel(&vidaMax, &vidaAtual, &chakraAtual, &chakraMax, &staminaAtual, &staminaMax, recompensaExp, &experienciaAtual, &experienciaMax, &nivel, &ryous);

    int repetir = 0;
    do
    {
        system("cls");
        titulo();
        printf("#                                 #      MENU      #                                \n");
        printf("#  Nome: %s   Vila Oculta: %s   Classe: %s   Graduacao: %s   Ryous: %i              \n", nomePersonagem, vila, estilo, graduacao, ryous);
        printf("#  Vida: %i/%i   Chakra: %i/%i   Stamina %i/%i   Nivel: %i   Experiencia %i/%i      \n#\n",vidaAtual, vidaMax, chakraAtual, chakraMax,staminaAtual, staminaMax, nivel, experienciaAtual, experienciaMax);
        printf("#                                 !STATUS DO PERSONAGEM!                            \n");
        printf("#                                 @$$$$$$$$$$$$$$$$$$$@                             \n");
        printf("#         ____________________	 _________    		_________               \n");
        printf("#         !RESUMO DE COMBATES!	!ATRIBUTOS!   		!NAVEGACAO!             \n");
        printf("#         |Vitorias Dojo: %i |	|Taijutsu   %i	[1] - Ficha do Personagem   \n", vitoriasDojo, taijutsu);
        printf("#         |Vitorias MAPA: %i |	|Ninjutsu   %i	[2] - Graduacoes            \n", vitoriasMapa, ninjutsu);
        printf("#         |Derrotas Dojo: %i |	|Genjustu   %i	[3] - Aprender Jutsu        \n", derrotasDojo, genjutsu);
        printf("#         |Derrotas MAPA: %i |	|Forca      %i	[4] - Melhorar Atributos    \n", derrotasMapa, forca);
        printf("#         -------------------	|Intelecto  %i	[5] - Dojo                  \n", intelecto);
        printf("#                             	|Energia    %i	[6] - Mapa PVP              \n", energia);
        printf("#                                             	[7] - Justu do Cla          \n");
        printf("#                                     	      	[8] - Mascote               \n");
        printf("#                                              	[9] - Loja                  \n");
        printf("#                                               [10] - Verificar seus Jutsus\n");
        printf("#        Escolha => ");
        scanf("%i", &escolhaMenuPrincipal);

        // Inicio das escolhas do menu

        if(escolhaMenuPrincipal == 98) // Apenas para testar
        {
            recompensaExp = 1000;
            vitoriasDojo = 2;
            tarefasConcluidas = 2;
            taijutsu = 10;
            forca = 10;
            sistemaNivel(&vidaMax, &vidaAtual, &chakraAtual, &chakraMax, &staminaAtual, &staminaMax,recompensaExp, &experienciaAtual, &experienciaMax, &nivel, &ryous);
        }
        else if(escolhaMenuPrincipal == 1)       // FICHA DO PERSONAGEM
        {

            printf("#                                 FICHA DO PERSONAGEM                            \n");
            printf("#                                                                                \n");
            printf("#                                    EM CONSTRUCAO                               \n");
            system("PAUSE");


        }
        else if(escolhaMenuPrincipal == 2)      // GRADUAÇAO
        {

            int escolhaRequisitos, escolha;

            system("cls");
            titulo();
            printf("#                                 #      GRADUACAO      #                                \n\n");
            printf("# [1] Genin -> E o primeiro passo para voce se tornar um grande ninja!\n");
            printf("# [2] Chunnin -> E um ninja com conhecimento avancado e que possui confianca da vila!\n");
            printf("# [3] Jounnin -> Ninja com um grande conhecimento nas tecnicas ninjas\n");
            printf("# [4] ANBU -> Sao conhecidos como cacadores especiais ANBU, pode obter tecnicas muito avancadas\n");
            printf("# [5] Sannin -> Sao ninjas lendarios que possui uma capacidade extrema\n");
            printf("# [6] Kage -> E o ninja mais forte da vila\n");

            printf("\nEscolha uma graduacao para saber se voce tem capacidade de graduar!\n");
            scanf("%i", &escolha);

            if(escolha == 1)    //GENIN
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Genin voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 5 ou mais                                                   \n");
                printf("#   - Possuir mais de 2 vitorias no Dojo                                    \n");
                printf("#   - Aprender um jutsu de sua classe                                       \n");
                printf("#   - Ter completado no minimo 2 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Genin!  \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 5) && (vitoriasDojo >= 2) && (jutsusAprendidos >= 1) && (tarefasConcluidas >= 2))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Genin!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Genin");
                        graduacaoNumero = 1;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Genin\n");
                        system("PAUSE");
                    }
                }
            }
            else if(escolha == 2)     //Chunnin
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Genin voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 15 ou mais                                                   \n");
                printf("#   - Possuir mais de 40 vitorias no Dojo                                    \n");
                printf("#   - Aprender 9 jutsus                                                      \n");
                printf("#   - Ter completado no minimo 10 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Chunnin!  \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 15) && (vitoriasDojo >= 40) && (jutsusAprendidos >= 9) && (tarefasConcluidas >= 10))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Chunnin!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Chunnin");
                        graduacaoNumero = 2;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Chunnin\n");
                        system("PAUSE");
                    }
                }
            }
            else if(escolha == 3)     //Jounin
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Jounin voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 25 ou mais                                                   \n");
                printf("#   - Possuir mais de 100 vitorias no Dojo                                    \n");
                printf("#   - Aprender 16 jutsus de sua classe                                       \n");
                printf("#   - Ter completado no minimo 25 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Jounin!  \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 25) && (vitoriasDojo >= 100) && (jutsusAprendidos >= 16) && (tarefasConcluidas >= 25))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Jounin!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Jounin");
                        graduacaoNumero = 3;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Jounin\n");
                        system("PAUSE");
                    }
                }
            }
            else if(escolha == 4)     //Anbu
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Anbu voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 35 ou mais                                                   \n");
                printf("#   - Possuir mais de 150 vitorias no Dojo                                    \n");
                printf("#   - Aprender 22 jutsus de sua classe                                       \n");
                printf("#   - Ter completado no minimo 40 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Anbu!  \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 35) && (vitoriasDojo >= 150) && (jutsusAprendidos >= 22) && (tarefasConcluidas >= 40))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Anbu!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Anbu");
                        graduacaoNumero = 4;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Anbu\n");
                        system("PAUSE");
                    }
                }
            }
            else if(escolha == 5)     //Sannin
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Sannin voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 45 ou mais                                                   \n");
                printf("#   - Possuir mais de 200 vitorias no Dojo                                    \n");
                printf("#   - Aprender 28 jutsus de sua classe                                       \n");
                printf("#   - Ter completado no minimo 45 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Sannin!  \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 45) && (vitoriasDojo >= 200) && (jutsusAprendidos >= 28) && (tarefasConcluidas >= 45))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Sannin!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Sannin");
                        graduacaoNumero = 5;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Sannin\n");
                        system("PAUSE");
                    }
                }
            }
            else if(escolha == 6)     //Kage
            {
                system("cls");
                titulo();
                printf("#                                 #      GRADUACAO      #                                \n#\n");
                printf("#   Para voce se tornar um Kage voce precisa alcancar os seguintes requisitos!             \n");
                printf("#   - Ser nivel 55 ou mais                                                   \n");
                printf("#   - Possuir mais de 300 vitorias no Dojo                                    \n");
                printf("#   - Aprender 36 jutsus de sua classe                                       \n");
                printf("#   - Ter completado no minimo 60 tarefas                                    \n");
                printf("#\n");
                printf("#   Aperte [1] para verificar se possui os requisitos para virar Kage!   \n");
                printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                scanf("%i", &escolhaRequisitos);
                if(escolhaRequisitos == 1)
                {
                    if((nivel >= 55) && (vitoriasDojo >= 300) && (jutsusAprendidos >= 36) && (tarefasConcluidas >= 60))
                    {
                        printf("# Parabens! Voce possui todos os requisitos para se tornar um Kage!\n");
                        printf("# Estamos te graduando agora!");
                        animacao_demorada();

                        strcpy(graduacao,"Kage");
                        graduacaoNumero = 6;
                    }
                    else
                    {
                        printf("# Infelizmente voce nao ainda nao possui todos os requisistos para se tornar um Kage\n");
                        system("PAUSE");
                    }
                }
            }  // Chave do If da ultima graduacao
        }
        else if(escolhaMenuPrincipal == 3)      // APRENDER JUTSUS
        {
            int escolhaJutsu, escolhaAprender, i;

            system("cls");
            titulo();
            printf("#                                 #      APRENDER JUTSUS      #                                \n\n");
            printf("#                     $  Escolha o estilo de jutsu que voce deseja aprender  $                      \n");
            printf("#                 [1] - Taijutsu          [2] - Ninjutsu           [3] - Genjutsu                    \n");
            printf("#                                       => Escolha: ");
            scanf("%i", &escolhaJutsu);

            //Estrutura para armazenar os valores dos Jutsus
            //int codigoJutsu;
            //char nomeJutsu[20];
            //int ataque;
            //int consumoChakra;
            //int consumoStamina;


            if(escolhaJutsu == 1)  // TAIJUTSU
            {

                printf("# Estudante             \n");
                printf("#  [1] - Dynamic Kick   \n");
                printf("# Genin                 \n");
                printf("#  [2] - Dynamic Entry  \n");
                printf("#  [3] - Hariitsuba     \n");
                printf("#  [4] - Konoha Full Kick Soccer \n");
                printf("#  [5] - Konoha Senpuu  \n");
                printf("#  [6] - Gangeki        \n");
                printf("#  [7] - Sensei Dynamic Entry \n");

                printf("#Escolha o Jutsu para verificar seus requisitos minimos!");

                int escolhaTai;

                scanf("%i", &escolhaTai);

                if((escolhaTai >= 1) && escolhaTai <= 7)   // Verificar se o usuario escolheu uma opcao que existe
                {

                    if(escolhaTai == 1 && vetorJutsusAprendidosTai[1] == 0)    // Dynamic Kick
                    {

                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Dynamic Kick              \n");
                        printf("#     - Requer 6 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Estudante                                  \n");
                        printf("#     - Requer 8 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 6) && (graduacaoNumero >= 0) && (taijutsu >= 8))
                            {
                                printf("Estamos te ensinando Dynamic Kick!");
                                animacao_demorada();
                                printf("\n");
                                //adicionando o jutsu ao usuario pela Lista
                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;  // O Codigo do jutsu é dado pelo numero de jutsus que o usuario ja aprendeu
                                strcpy(novo->nomeJutsu, "Dynamic Kick");
                                novo->ataque = (taijutsu/2) + 12;      // Formula do ataque
                                novo->consumoChakra = 6;
                                novo->consumoStamina = 36;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++; // Soma mais 1 a variavel;
                                vetorJutsusAprendidosTai[1] = 1; // Aqui eu coloco 1, para dizer que eu ja aprendi o jutsu
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }


                    }
                    else if(escolhaTai == 2 && vetorJutsusAprendidosTai[2] == 0){ // Denamic Entry

                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Dynamic Entry              \n");
                        printf("#     - Requer 8 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 10 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 8) && (graduacaoNumero >= 1) && (taijutsu >= 10))
                            {
                                printf("Estamos te ensinando Dynamic Entry!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Dynamic Entry");
                                novo->ataque = (taijutsu/2) + 15;
                                novo->consumoChakra = 4;
                                novo->consumoStamina = 44;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[2] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }

                    }
                    else if(escolhaTai == 3 && vetorJutsusAprendidosTai[3] == 0){ // Hariitsuba

                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Hariitsuba              \n");
                        printf("#     - Requer 12 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 16 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 12) && (graduacaoNumero >= 1) && (taijutsu >= 16))
                            {
                                printf("Estamos te ensinando Hariitsuba!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Hariitsuba");
                                novo->ataque = (taijutsu/2) + 22;
                                novo->consumoChakra = 4;
                                novo->consumoStamina = 44;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[3] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }
                    }
                    else if(escolhaTai == 4 && vetorJutsusAprendidosTai[4] == 0){ // Konoha Full Kick Soccer

                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Konoha Full Kick Soccer     \n");
                        printf("#     - Requer 16 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 20 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 16) && (graduacaoNumero >= 1) && (taijutsu >= 20))
                            {
                                printf("Estamos te ensinando Konoha Full Kick Soccer!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Konoha Full Kick Soccer");
                                novo->ataque = (taijutsu/2) + 29;
                                novo->consumoChakra = 14;
                                novo->consumoStamina = 88;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[4] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }

                    }
                    else if(escolhaTai == 5 && vetorJutsusAprendidosTai[5] == 0){ // Konoha Senpuu

                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Konoha Senpuu     \n");
                        printf("#     - Requer 16 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 20 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 16) && (graduacaoNumero >= 1) && (taijutsu >= 20))
                            {
                                printf("Estamos te ensinando KonohaKonoha Senpuu!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Konoha Senpuu");
                                novo->ataque = (taijutsu/2) + 29;
                                novo->consumoChakra = 14;
                                novo->consumoStamina = 88;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[5] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }
                    }
                    else if(escolhaTai == 6 && vetorJutsusAprendidosTai[6] == 0){ // Gangeki
                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Gangeki     \n");
                        printf("#     - Requer 18 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 24 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 16) && (graduacaoNumero >= 1) && (taijutsu >= 20))
                            {
                                printf("Estamos te ensinando Gangeki!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Gangeki");
                                novo->ataque = (taijutsu/2) + 34;
                                novo->consumoChakra = 18;
                                novo->consumoStamina = 102;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[6] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }
                    }
                    else if(escolhaTai == 7 && vetorJutsusAprendidosTai[7] == 0){ // Sensei Dynamic Entry
                        printf("#####################################################################\n");
                        printf("#     Requisistos Minimos para aprender o Sensei Dynamic Entry     \n");
                        printf("#     - Requer 22 pontos de forca                                     \n");
                        printf("#     - Requer graduacao: Genin                                      \n");
                        printf("#     - Requer 28 pontos em Taijutsu                                  \n");
                        printf("#                                                                        \n");
                        printf("#   Aperte [1] para verificar se possui os requisito!                    \n");
                        printf("#   Aperte [2] para voltar ao menu principal!                            \n");
                        scanf("%i", &escolhaAprender);


                        if(escolhaAprender == 1)
                        {
                            if((forca >= 22) && (graduacaoNumero >= 1) && (taijutsu >= 28))
                            {
                                printf("Estamos te ensinando Sensei Dynamic Entry!");
                                animacao_demorada();
                                printf("\n");

                                JUTSUS *novo=NULL;
                                novo = malloc(sizeof (JUTSUS));

                                novo->codigoJutsu = jutsusAprendidos;
                                strcpy(novo->nomeJutsu, "Sensei Dynamic Entry");
                                novo->ataque = (taijutsu/2) + 39;
                                novo->consumoChakra = 20;
                                novo->consumoStamina = 118;

                                if(inicio == NULL)
                                {
                                    inicio = novo;
                                    fim = novo;
                                    fim->prox = NULL;
                                }
                                else
                                {
                                    novo->prox = inicio;
                                    inicio = novo;
                                }

                                jutsusAprendidos++;
                                vetorJutsusAprendidosTai[7] = 1;
                                system("Pause");

                            }
                            else
                            {
                                printf("# Voce nao possui os requisitos necessarios para aprender o jutsu:(\n");
                                system("PAUSE");
                            }
                        }
                        else
                        {
                            printf("# Retornando ao menu!");
                            break;
                        }
                    }

                }else{  // Esse ELSE é da verificao das escolhas
                    printf("# Voce selecionou a opcao errada!"); // Caso escolha uma opcao de Jutsu que nao exista
                }


            }
            else if(escolhaJutsu == 2)   // Ninjutsu
            {

            }
            else if(escolhaJutsu == 3){    // Genjutsu
            }
        }
        else if(escolhaMenuPrincipal == 4){     // MELHORAR ATRIBUTOS
        }
        else if(escolhaMenuPrincipal == 5){     // DOJO

        }else if(escolhaMenuPrincipal == 6){    // MAPA PVP

        }else if(escolhaMenuPrincipal == 7){    // JUTSUS DO CLA

        }else if(escolhaMenuPrincipal == 8){    // MASCOTE

        }else if(escolhaMenuPrincipal == 9){    // LOJA

        }else if(escolhaMenuPrincipal == 10){    // Verificar todos os jutsus do usuario

            if(inicio == NULL){ // O usuario nao possui nenhum Jutsu
                    printf("# Voce nao possui nenhum Jutsu :( \n");
                }else{
                    printf("\nOs seus jutsus: \n ########################\n");
                    auxiliar = inicio;
                    while(auxiliar != NULL){
                        printf("# Codigo do Jutsu: %d \n", auxiliar->codigoJutsu);
                        printf("# Nome: %s \n", auxiliar->nomeJutsu);
                        printf("# Ataque: %d \n", auxiliar->ataque);
                        printf("# Consumo de Chakra: %d \n", auxiliar->consumoChakra);
                        printf("# Consumo de Stamina: %d \n", auxiliar->consumoStamina);
                        printf("################################# \n");
                        auxiliar = auxiliar->prox; // recebe o endereço do proximo, até acabar e auxiliar ser = NULL
                    }
                }
        system("Pause");
        }       // Aspas do Menu principal, proxima opcao do jogo adicionar aqui
}
while(repetir == 0);

    system("PAUSE");
}



int sistemaNivel(int *vidaMax,int *vidaAtual,int *chakraAtual,int *chakraMax,int *staminaAtual,int *staminaMax, int recompensaExp, int *experienciaAtual, int *experienciaMax, int *nivel, int *ryous)
{

    int vAux, cAux, sAux;

    vAux = *vidaMax;        // Estas variaveis servem para guardar os status do nivel anterior do jogador
    cAux = *chakraMax;      // para poderer printar o antes e depois
    sAux = *staminaMax;

    //    0  - 1200 nivel 1
    //  1201 - 2400 nivel 2
    //  2401 - 3600 nivel 3

    *experienciaAtual = *experienciaAtual + recompensaExp;
    if(*experienciaAtual > *experienciaMax)
    {
        *nivel = *nivel + 1;
        *experienciaMax = *experienciaMax + 1200;    // cada nivel vc adiciona + 1200
        *experienciaAtual = 0;                       // reseta a experiencia para 0
        *vidaMax = *vidaMax * 1.24;    // A cada nivel a vida maximo aumenta em 24%
        *vidaAtual = *vidaMax;
        *chakraMax = *chakraMax * 1.24; // O chakra tbm aumenta 24%
        *chakraAtual = *chakraMax;
        *staminaMax = *staminaMax * 1.12; // A stamina aumenta em 12%
        *staminaAtual = *staminaMax;

        system("cls");
        titulo();
        printf("#                PARABENS VOCE PASSOU PARA O NIVEL %i\n", *nivel);
        printf("#                Alguns de seus atributos foram aumentados!\n");
        printf("#                Vida: %i ---> %i\n", vAux, *vidaMax);
        printf("#                Chakra: %i ---> %i\n", cAux, *chakraMax);
        printf("#                Stamina: %i ---> %i\n", sAux, *staminaMax);
        printf("#                Tambem foram adicionados 2000 ryous na sua carteira!\n", *ryous = *ryous + 2000);
        system("pause");

    }

    //I SEE PONTEIROS, How often do you see them? ALL THE TIME!!
};


int calculoHash(char nome[20], int senha)
{

    // nome -> int -> xSenha

    // printf("Nome: %s", nome);
    //printf("\nsenha:%i\n", senha);

    int qtdLetras = strlen(nome);
    //printf("QtdLetras %i\n ", qtdLetras);

    int nomeInt = 0, k;

    for(k=0; k<=qtdLetras; k++)
    {
        nome[k] - 65;
        nomeInt = nomeInt + nome[k];
    }

    //printf("Nomeint: %i", nomeInt);

    int hash = (nomeInt*senha)/qtdLetras;
    //printf("Hash %i\n", hash);


    //printf("Hash dentro da funcao: %i", hash);
    system("PAUSE");

    return hash;

}

void animacao_demorada()
{
    int i;
    for(i=0; i<=2; i++)
    {
        printf(".");
        Sleep(1000);
    }
}

// to ficando doido da cabeça






















