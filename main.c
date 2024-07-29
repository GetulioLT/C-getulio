#include <stdio.h>
#include <string.h>

void main() {
    // Variáveis para criação de conta
    char createNome[50], createEmail[50] = "", createSenha[20];
    int createIdade;

    // Variáveis para login
    char loginEmail[50], loginSenha[20];

    // Variáveis para edição de conta
    char editarNome[50], editarEmail[50], editarSenha[20];
    int editarIdade;

    // Variáveis de funcionalidade
    int escolha, validacaoEmail, validacaoSenha;

    // Laço principal
    while (1) {
        // Página inicial
        printf("Digite uma das opções abaixo: \n");
        printf("1 - Create new account\n");
        printf("2 - Login\n");
        printf("0 - Finish\n");
        scanf("%d", &escolha);

        switch (escolha) {
        case 1:
            // Criação de conta -> nome | idade | email(@) | senha(8 char)
            
            // Nome
            printf("Digite o seu nome: ");
            scanf("%s", &createNome);

            // Idade
            printf("Digite a sua idade: ");
            scanf("%d", &createIdade);

            // Email
            validacaoEmail = 0;
            while (validacaoEmail != 1) {
                printf("Digite o seu email: ");
                scanf("%s", &createEmail);

                // Verifica se o email contém '@'
                for (int i = 0; i <= strlen(createEmail); i++) {
                    if (createEmail[i] == '@') {
                        validacaoEmail = 1;
                    }
                }
            }
            
            // Senha
            validacaoSenha = 0;
            while (validacaoSenha != 1) {
                printf("Digite sua senha: ");
                scanf("%s", &createSenha);

                // Verifica se a senha tem pelo menos 8 caracteres
                if (strlen(createSenha) >= 8) {
                    validacaoSenha = 1;
                }
            }
            
            // Limpeza de tela
            for (int i = 1; i <= 20; i++) {
                printf("\n");
            }
            printf("Conta criada com sucesso\n");

            break;
        
        case 2:
            // Login
            if (strcmp(createEmail, "") == 0) {
                printf("Nenhuma conta criada\n");
                break;
            }

            // Email
            validacaoEmail = 0;
            while (validacaoEmail != 1) {
                printf("Digite o seu email: ");
                scanf("%s", &loginEmail);

                // Verifica se o email digitado corresponde ao email da conta criada
                if (strcmp(loginEmail, createEmail) == 0) {
                    validacaoEmail = 1;
                }
            }
            
            validacaoSenha = 0;
            // Senha
            for (int i = 1; i <= 3; i++) {
                printf("Digite a sua senha: ");
                scanf("%s", &loginSenha);

                // Verifica se a senha digitada corresponde à senha da conta criada
                if (strcmp(loginSenha, createSenha) == 0) {
                    validacaoSenha = 1;
                    break;
                }
            }

            if (validacaoSenha == 1 && validacaoEmail == 1) {
                // Limpeza de tela
                for (int i = 1; i <= 20; i++) {
                    printf("\n");
                }
                while (1) {
                    printf("Login realizado com sucesso\n");
                    printf("1 - Visualizar Informações\n");
                    printf("2 - Editar Informações\n");
                    printf("0 - Sair\n");
                    scanf("%d", &escolha);

                    switch (escolha) {
                    case 1:
                        // Exibir informações
                        printf("Nome: %s\n", createNome);
                        printf("Idade: %d\n", createIdade);
                        printf("Email: %s\n", createEmail);
                        printf("Senha: %s\n", createSenha);
                        break;
                    
                    case 2:
                        // Editar informações
                        printf("1 - Nome\n");
                        printf("2 - Idade\n");
                        printf("3 - Email\n");
                        printf("4 - Senha\n");
                        printf("0 - Sair\n");
                        scanf("%d", &escolha);

                        switch (escolha) {
                        case 1:
                            // Editar nome
                            printf("Digite o novo nome: ");
                            scanf("%s", &editarNome);

                            // Validação de senha
                            validacaoSenha = 0;
                            for (int i = 1; i <= 3; i++) {
                                printf("Digite sua senha: ");
                                scanf("%s", &loginSenha);

                                // Verifica se a senha digitada corresponde à senha da conta criada
                                if (strcmp(loginSenha, createSenha) == 0) {
                                    validacaoSenha = 1;
                                    break;
                                }
                            }

                            if (validacaoSenha == 1) {
                                strcpy(createNome, editarNome);
                                printf("Nome Atualizado com Sucesso");
                            } else {
                                printf("Senha Errada");
                            }

                            break;
                        case 2:
                            // Editar idade
                            printf("Digite a nova idade: ");
                            scanf("%d", &editarIdade);

                            // Validação de senha
                            validacaoSenha = 0;
                            for (int i = 1; i <= 3; i++) {
                                printf("Digite sua senha: ");
                                scanf("%s", &loginSenha);

                                // Verifica se a senha digitada corresponde à senha da conta criada
                                if (strcmp(loginSenha, createSenha) == 0) {
                                    validacaoSenha = 1;
                                    break;
                                }
                            }

                            if (validacaoSenha == 1) {
                                createIdade = editarIdade;
                                printf("Idade Atualizada com Sucesso");
                            } else {
                                printf("Senha Errada");
                            }
                            break;
                        case 3:
                            // Editar email
                            validacaoEmail = 0;
                            while (validacaoEmail != 1) {
                                printf("Digite o seu novo email: ");
                                scanf("%s", &editarEmail);

                                // Verifica se o novo email contém '@'
                                for (int i = 0; i <= strlen(editarEmail); i++) {
                                    if (editarEmail[i] == '@') {
                                        validacaoEmail = 1;
                                    }
                                }
                            }
                            // Validação de senha
                            validacaoSenha = 0;
                            for (int i = 1; i <= 3; i++) {
                                printf("Digite sua senha: ");
                                scanf("%s", &loginSenha);

                                // Verifica se a senha digitada corresponde à senha da conta criada
                                if (strcmp(loginSenha, createSenha) == 0) {
                                    validacaoSenha = 1;
                                    break;
                                }
                            }

                            if (validacaoSenha == 1) {
                                strcpy(createEmail, editarEmail);
                                printf("Email Atualizado com Sucesso");
                            } else {
                                printf("Senha Errada");
                            }
                            
                            break;
                        case 4:
                            // Editar senha
                            validacaoSenha = 0;
                            while (validacaoSenha != 1) {
                                printf("Digite sua nova senha: ");
                                scanf("%s", &editarSenha);

                                // Verifica se a nova senha tem pelo menos 8 caracteres
                                if (strlen(editarSenha) >= 8) {
                                    validacaoSenha = 1;
                                }
                            }
                            if (validacaoSenha == 1) {
                                validacaoSenha = 0;
                                for (int i = 1; i <= 3; i++) {
                                    printf("Digite sua senha: ");
                                    scanf("%s", &loginSenha);

                                    // Verifica se a senha digitada corresponde à senha da conta criada
                                    if (strcmp(loginSenha, createSenha) == 0) {
                                        validacaoSenha = 1;
                                        break;
                                    }
                                }
                            } else {
                                printf("Tentativas excedidas\n");
                            }

                            if (validacaoSenha == 1) {
                                strcpy(createSenha, editarSenha);
                                printf("Senha Atualizada com Sucesso\n");
                            }
                            
                            break;
                        case 0:
                            // Sair da edição
                            printf("Logout Realizado");
                            break;
                        default:
                            printf("Escolha inexistente");
                            break;
                        }

                        break;
                    
                    case 0:
                        // Sair do login
                        break;
                    default:
                        printf("Escolha inexistente");
                        break;
                    }

                    if (escolha == 0) {
                        break; // Finaliza o laço
                    }
                    
                }
            } else {
                // Limpeza de tela
                for (int i = 1; i <= 20; i++) {
                    printf("\n");
                }
                printf("Total de tentativas excedida\n");
            }

            escolha = -1;
            
            break;

        case 0:
            // Finalizar sistema
            printf("Sistema finalizado\n");
            break;

        default:
            // Limpeza de tela
            for (int i = 1; i <= 20; i++) {
                printf("\n");
            }
            printf("Escolha inexistente\n");
            break;
        }

        if (escolha == 0) {
            break;
        }
    } 
}