#include <stdio.h>
#include <string.h>

void main(){
    //create
    char createNome[50], createEmail[50] = "", createSenha[20];
    int createIdade;

    //login
    char loginEmail[50], loginSenha[20];

    //funcionalidade
    int escolha, validacaoEmail, validacaoSenha;

    //laço principal 
    while (1){
        //pagina inicial
        printf("Digite uma das opções abaixo: \n");
        printf("1 - Create new acount\n");
        printf("2 - Login\n");
        printf("0 - Finish\n");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            //create -> nome | idade | email(@) | senha(8 char)
            
            //nome
            printf("Digite o seu nome: ");
            scanf("%s", &createNome);

            //idade
            printf("Digite a sua idade: ");
            scanf("%d", &createIdade);

            //email
            validacaoEmail = 0;
            while (validacaoEmail != 1)
            {
                printf("Digite o seu email: ");
                scanf("%s", &createEmail);

                for(int i = 0; i <= strlen(createEmail); i++){
                    if (createEmail[i] == '@')
                    {
                        validacaoEmail = 1;
                    }
                    
                }
            }
            
            //senha
            validacaoSenha = 0;
            while (validacaoSenha != 1)
            {
                printf("digite sua senha: ");
                scanf("%s", &createSenha);

                if (strlen(createSenha) >= 8)
                {
                    validacaoSenha = 1;
                }
                
            }
            
            // limpeza de tela
            for(int i = 1; i <= 20; i++){
                printf("\n");
            }
            printf("Conta criada com sucesso");

            break;
        
        case 2:
            //login
            if (strcmp(createEmail, "") == 0)
            {
                printf("Nenhuma conta criada\n");
                break;
            }

            //email
            validacaoEmail = 0;
            while (validacaoEmail != 1)
            {
                printf("Digite o seu email: ");
                scanf("%s", &loginEmail);

                if (strcmp(loginEmail, createEmail) == 0)
                {
                    validacaoEmail = 1;
                }
            }
            
            validacaoSenha = 0;
            // senha
            for(int i = 1; i <= 3; i++){
                printf("Digite a sua senha: ");
                scanf("%s", &loginSenha);

                if (strcmp(loginSenha, createSenha) == 0)
                {
                    validacaoSenha = 1;
                    break;
                }
                
            }

            if (validacaoSenha == 1)
            {
                printf("Login realizado com sucesso\n");
            }else{
                printf("Total de tentativas excedida\n");
            }
            
            break;

        case 0:
            //finish
            printf("Sistema finalizado\n");
            break;

        default:
            printf("Escolha inexistente\n");
            break;
        }

        if(escolha == 0){
            break;
        }
    }
    
}