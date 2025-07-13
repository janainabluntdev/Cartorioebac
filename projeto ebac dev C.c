#include <stdio.h> //biblioteca de comunicação
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //função respondavel por cadastrar os usuários no sistema
{
	// inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variais/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informção de usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strig
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); // cria o arquivo e "w significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file, ","); // Adiciona uma vírgula para separar os valores no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informção de usuário
	scanf("%s",nome); //scanf le entrada do usuario e %s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,nome); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo 
	fprintf(file, ","); // Adiciona uma vírgula para separar os valores no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informção de usuário
	scanf("%s",sobrenome); //scanf le entrada do usuario
	
	file = fopen(arquivo,"a"); //cria o arquivo 
	fprintf(file,sobrenome);//salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); // Adiciona uma vírgula para separar os valores no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informção de usuário
	scanf("%s",cargo); //scanf le entrada do usuario
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,cargo); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a execusão (Windows)
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//"char" Variavel de caractere único
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: "); //coletando informção de usuário
	scanf("%s",cpf);
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r");
	
	if(file == NULL) // Checa se o arquivo falhou ao abrir
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s",conteudo); // Exibe o conteúdo na tela
		printf("\n\n"); // Imprime duas quebras de linha para espaçamento
	}
	system ("pause"); //pausa a execusão (Windows)
	

	
}


   void deletar()
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado:");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL) // Checa se o arquivo falhou ao abrir
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
	}
    
}

int main() // Ponto de entrada do programa. Retorna 0 quando executa com sucesso.
    {
    int opcao=0; //definindo variáveis 
	int laco = 1; // Inicializa o laço com valor 1
	char senhadigitada[10]="a"; // Cria a string 'senhadigitada' com valor inicial "a"
	int comparacao; // Guarda o valor do teste de comparação
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao =strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{ 
		system("cls");
	    for(laco=1;laco==1;)
	   {
		
		 system("cls"); //responsavel por limpar a tea 
	
	     setlocale(LC_ALL, "portuguese"); //definindo linguagem
	
        	printf("### Cartório da EBAC ###\n\n");//inicio do menu
        	printf("Escolha a opção desejada do menu\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
    	    printf("\t3 - Deletar nomes\n\n");
    	    printf("\t4 - Sair do sistema\n\n");
        	printf("Opção: "); //fim do menu
	
	        scanf("%d",&opcao); //armazenando a escolha do usuario 
	
    	    system("cls"); 
    	
    	  
    	    switch(opcao) //inicio da seleção do menu
        	{
    	      case 1:	
    	      registro(); //chamada de funções 
		      break;
		  
		      case 2:
		      consulta(); // Opção 2: Executa a função de consulta
	          break;
	      
	          case 3:
	          deletar(); // Opção 3: Executa a função de deletar
	          break;
	      
	          case 4: 
	          printf("Obrigado por utilizar o sistema!\n"); // Caso 4: Agradece ao usuário e encerra o programa
	          return 0; // Finaliza a execução
	          break; // Desnecessário, pois o return já encerra
	      
	          default:
	          printf("Essa opção não está disponivel!\n"); // Executa se a opção não for reconhecida
	          system("pause");
	          break; 
	       } // fim da seleção
	   }	 			  
   }    

else 
    printf("Senha incorreta\n\n");
    return 0;
}
