#include <stdio.h> //biblioteca de comunica��o
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //fun��o respondavel por cadastrar os usu�rios no sistema
{
	// inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de variais/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando inform��o de usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das strig
	
	FILE *file; //cria o arquivo
	file = fopen (arquivo, "w"); // cria o arquivo e "w significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file, ","); // Adiciona uma v�rgula para separar os valores no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando inform��o de usu�rio
	scanf("%s",nome); //scanf le entrada do usuario e %s refere-se a string
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,nome); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");//cria o arquivo 
	fprintf(file, ","); // Adiciona uma v�rgula para separar os valores no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando inform��o de usu�rio
	scanf("%s",sobrenome); //scanf le entrada do usuario
	
	file = fopen(arquivo,"a"); //cria o arquivo 
	fprintf(file,sobrenome);//salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,","); // Adiciona uma v�rgula para separar os valores no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando inform��o de usu�rio
	scanf("%s",cargo); //scanf le entrada do usuario
	
	file = fopen(arquivo, "a"); //cria o arquivo 
	fprintf(file,cargo); //salvo o valor da variavel 
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a execus�o (Windows)
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	//"char" Variavel de caractere �nico
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: "); //coletando inform��o de usu�rio
	scanf("%s",cpf);
	
	FILE *file; //cria o arquivo 
	file = fopen(cpf,"r");
	
	if(file == NULL) // Checa se o arquivo falhou ao abrir
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo); // Exibe o conte�do na tela
		printf("\n\n"); // Imprime duas quebras de linha para espa�amento
	}
	system ("pause"); //pausa a execus�o (Windows)
	

	
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
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
	}
    
}

int main() // Ponto de entrada do programa. Retorna 0 quando executa com sucesso.
    {
    int opcao=0; //definindo vari�veis 
	int laco = 1; // Inicializa o la�o com valor 1
	char senhadigitada[10]="a"; // Cria a string 'senhadigitada' com valor inicial "a"
	int comparacao; // Guarda o valor do teste de compara��o
	
	printf("### Cart�rio da EBAC ###\n\n");
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
	
        	printf("### Cart�rio da EBAC ###\n\n");//inicio do menu
        	printf("Escolha a op��o desejada do menu\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
    	    printf("\t3 - Deletar nomes\n\n");
    	    printf("\t4 - Sair do sistema\n\n");
        	printf("Op��o: "); //fim do menu
	
	        scanf("%d",&opcao); //armazenando a escolha do usuario 
	
    	    system("cls"); 
    	
    	  
    	    switch(opcao) //inicio da sele��o do menu
        	{
    	      case 1:	
    	      registro(); //chamada de fun��es 
		      break;
		  
		      case 2:
		      consulta(); // Op��o 2: Executa a fun��o de consulta
	          break;
	      
	          case 3:
	          deletar(); // Op��o 3: Executa a fun��o de deletar
	          break;
	      
	          case 4: 
	          printf("Obrigado por utilizar o sistema!\n"); // Caso 4: Agradece ao usu�rio e encerra o programa
	          return 0; // Finaliza a execu��o
	          break; // Desnecess�rio, pois o return j� encerra
	      
	          default:
	          printf("Essa op��o n�o est� disponivel!\n"); // Executa se a op��o n�o for reconhecida
	          system("pause");
	          break; 
	       } // fim da sele��o
	   }	 			  
   }    

else 
    printf("Senha incorreta\n\n");
    return 0;
}
