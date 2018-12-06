//System 1.0//

//BIBLIOTECAS//
#include <stdio.h>  	//Biblioteca de padrão de saída e entrada//
#include <stdlib.h>  	//Biblioteca de funções auxiliares//
#include <windows.h> 	//Biblioteca para funções graficas//
#include <string.h> 	//Biblioteca para manipulação de strings//
#include <conio.h>  	//Biblioteca grafica e para funções de strings//

//VARIAVEIS DEFINE//
#define sleep 1000		//Definição do tempo de sleep em carregamentos e erros//
#define MAX 100			//Definição do tamanho máximo das strings//
#define L_MINIMA 4 		//Defiição da localização da menor linha do programa//
#define L_MAXIMA 36		//Defiição da localização da maior linha do programa//
#define C_MINIMA 4		//Defiição da localização da menor coluna do programa//
#define C_MAXIMA 76		//Definição da localização da maior coluna do programa//
#define ENTER 13		//Definição do valor de ENTER na tabela ASCII//
#define SETA_ESQUERDA 75 //Definição do valor da seta esquerda na tabela ASCII//
#define SETA_CIMA 72	//Definição do valor da seta cima na tabela ASCII//
#define SETA_DIREITA 77 //Definição do valor da seta dirEita na tabela ACII//
#define SETA_BAIXO 80	//Definição do valor da seta baixo na tabela ASCII//
#define ESC 27			//Definição do valor de ESC na tabela ASCII//

//ESCOPO GLOBAL//

//STRUCTS//
//Struct para definir destinos e local de partida//
typedef struct destiny{
	char embark[MAX];
	char arrive[MAX];
} d1;

//Struct para configuração de disponibilidade//
typedef struct set{
	int lug; 	//Variável que receberá o número de poltronas disponíveis para venda//
	int *array; //Array de poltronas em função da quantidade de poltronas disponibilizadas//
} s1;

//Struct para configuração de venda//
typedef struct confirm{
	int quantity; 	//Variável para armazenar a quantidade de poltronas para reserva//
	int *chair;		//Array em função da variável quantity//
	int option; 	//variavel condicional//
} c1;

//Struct para criação de conta//
typedef struct create{
	char name[MAX]; //variável para cadastro de nome//
	char cpf[11]; 		//código de pessoa física//
	char key[MAX]; 		//senha do cadastro//
	char ver[MAX]; 		//verificação//
	char email[MAX]; //email//
} ac;

typedef struct zap{
	char email[MAX];
	char key[MAX];
} jubiscleito;



//ENUMS//
//Enum que conterá os codigos da cores//
enum DOS_COLORS{
        PRETO , AZUL , VERDE , CIANO , VERMELHO , MAGENTA , MARROM ,
        LIGHT_GRAY , DARK_GRAY , LIGHT_BLUE , LIGHT_GREEN , LIGHT_CYAN ,
        LIGHT_RED , LIGHT_MAGENTA , AMARELO , BRANCO 
};

//VARIAVEIS GLOBAIS//
int log = 0;		//Variavel que contera a informação se existe ou não uma conta logada

//Variavel onde se contera os nomes das cores//
DOS_COLORS CPrincipais [ 16 ] = { PRETO , AZUL , VERDE , CIANO , VERMELHO , MAGENTA , MARROM , LIGHT_GRAY , DARK_GRAY ,
                        LIGHT_BLUE , LIGHT_GREEN , LIGHT_CYAN , LIGHT_RED , LIGHT_MAGENTA ,AMARELO , BRANCO
						 };

//PROTOTIPOS DAS FUNÇÕES//
//Funções void//
void cadastro(create ac,zap jubiscleito); //função de criação de conta//  
void aSeta(int coluna,int linha);
void check(destiny d1,int x,int y); // protótipo da função de check in//
void continua(int linha); //função para exibição de título//
void fim(void);
void finish(void); //Função de exibição de mensagem de reserva//
void gotoxy(int x , int y); //função gráfica//
void ImprimeAviao (int linha,int tipo); //parametro x e y = coordenada para o ponto superior esquerdo, onde a partir dai sera imprimido//
void lMoldura(int cMinima,int cMaxima,int lMinima,int lMaxima);
void inicio(void);
void menuP(int cond);
void moldura(int cMinima, int cMaxima, int lMinima, int lMaxima,int verificador);//funcao que imprime a moldura com as coordenadas dadas
void scan(destiny d1); //protótipo da função de leitura dos locais de saida e chegada//
void seta(int coluna,int linha);
void setaM(int *aux,int max,int coluna[],int linha[],char opc);
void tabela1(int aux,int cond);
void tempo(void);
void textcolor(DOS_COLORS iColor); 	//Função para mudar cor das letras
void titulo(int linha); //função titulo//
void transicaoFim (int inicio);
void transicaoInicio (int inicio); //protótipo de transição p2//
void tabela4(int cond,int aux);
void tabela6(int cond,int aux);
void linha(int l,int cor);
void mover(int *aux,int max,char opc);
void coordenadas(void); //Função para developer(temporaria)//
void ask(void); // função para questionamento sobre criação de conta//
void mHorizontal(int *aux,int max,char opc); //função para movimento de seleção//
void lLinha(int cMinima,int cMaxima,int lLinha);
void login(create ac,zap jubiscleito); //função de login//
void show(); //função de exibição//
void exclude();
void dLogar();
void tabela2(int cond,int aux);


//Funções int//
int centraliza(int tamanho);
int menu( int x , int y); 
int selec(confirm c1 ,struct set s1);
int confirmlog();
int confirm();
int confirmcheck();

//FUNÇÕES DE VALIDAÇÃO//
int validarEMAIL(char email[]);
int validarCPF(char cpf[]);
int validarSENHA(char senha1[],char senha2[]);
int validarNOME(char nome[]);
int compare(zap jubiscleito,create ac);

//FUNÇÃO PRINCIPAL(MAIN)//
int main(void){ 
	//Definição do tamanho ta tela//
	system("MODE 80, 41");
	//Definição das cores iniciais//
	system("color 4f"); 
	//Definição do titulo do DOS// 
	SetConsoleTitle("Rivail Linhas Aereas 1.0 (developed by Johann,Francisco,Monike,Malu)");

	//PARTE PARA E INICIAR O PROGRAMA//
	int x=7, y=5; 
	gotoxy(25, 20);
	printf("Pressione qualquer tecla...\n");
	getch();
	
	//Parte de inicicialização grafica do programa//
	inicio();
	
	//Chamada da função reguladora do programa//
	menuP(1);
	
	system("cls");	//Limmpeza total da tela
	return 0;	
}

int compare(zap jubiscleito, create ac){ //funcao para verificacao de login//
	
	int i = 0;
	
	FILE *fptr;
	fptr=fopen("account.bin","rb");
	
	fread(&jubiscleito,sizeof(zap),1,fptr);
	
	while(i != EOF){
		
		for(i= 0 ; i < MAX;i++){
			if(jubiscleito.key[i]==ac.key[i] && jubiscleito.email[i]==ac.email[i]){
				return 1;
			}
			
			else{
				return 0;
			}
		}
		
		i++;
		
	}
	
	fclose(fptr);
}

//Menu que controlara as ações primarias
//Recebera um int que servira para imprimir as molduras inicias
void menuP(int cond){
	//Se condição passada for igual a um então ele imprimira moldura
	if (cond == 1){
		moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
		moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
	}
	//Sanão não for igual a um então ele apenas limpara a moldura
	else
		lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	char opc;			//Variavel que lera o teclado
	int coluna[7] = {21,20,28,30,30,25};	//Variavel que contera as localizações iniciais das colunas referente as setas
	int linha[7] = {9,12,15,18,21,24};	//Variavel que contera as localizações iniciais referente as linhas das setas
	int aux = 0;		//Variavel controladora
	
	int x = 5,y =7, c;	//Variaveis controladoras 
	
	tabela1(aux,0);				//Chamada da impressão das opções
	tempo();					//Chamada da impressão das informações de tempo
	seta(coluna[0],linha[0]);	//Impressão da seta
	
	//Laço do-while
	do{	
		fflush(stdin);		//Limpeza de buffer
		opc = getch();		//Leitura do teclado
		setaM(&aux,6,coluna,linha,opc);	//Movimentação da seta
		tabela1(aux,1);		//Impressão da tabela com seta movimentada
		
		//Se opção for igual a ENTER e chamada aluma função
		if(opc == ENTER){
			//Menu switch
			switch(aux){
//////////////////////////////////////////
				//Se opção for a primeira então e chamada a 
				case 0:
					lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
					
					if (!log)
						ask(); //verificação de criação de conta//
					
					scan(d1()); //chamada da função de leitura//
					
					menuP(0);
					
					break;
					
				case 1:
					
					lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
					check(d1(),x,y);
					break;
										
//////////////////////////////////				
				//Se for a quarta opção então e chamada a função de cadastro
				case 2:
					cadastro(ac(),jubiscleito()); //chamada da função de cadastro//
					menuP(0);		//Retomada da função menuP
					break;
////////////////////////////////////			
				case 3:
					lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
					dLogar();
					menuP(1);
					break;
///////////////////////////////////				
				//Se for selecionada a sexta opção então e chamada a função de login
				case 4:
					if (log){
						lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
						c = centraliza(53);
						gotoxy(c, 20);
						printf ("Conta ja logada. Saia para entrar com uma nova conta.");
						getch();
						lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
						
						menuP(1);
					}
					else{
						login(ac(),jubiscleito());	//Chamada da função de login
						menuP(0);
					}
							//Retomada da função menuP
					break;
				
				//Se for selecionada a ultima opção então opc e trasformada em esc e saira do loop
				case 5:
					opc = ESC;
					break;
			}
		}
	//Saida do loop
	}while(opc!=ESC );
	
	transicaoFim(27);	//Chamada da função de animação final
	fim();				//Chamada da função fim
}
/////////////////////////////////////////////////////////


void exclude(){
	FILE *fptr;
	fptr=fopen("destiny.bin","wb");
	
	fptr = NULL;
}

void show(){
	int c;
	
	c = centraliza(18);			//Centralização da coluna
	moldura(c-1,c+20,8,10,1);	//Criação da caixinha onde ficara a mensagem
	gotoxy(c,9);				//Posicionamento do cUrsor para escrever a mensagem
	printf("BOLETO DE CHECK-IN");	//Escrita da mensagem
	getch();
}

//Função de controle de variaveis de escolha, nas horizontais
void mHorizontal(int *aux,int max,char opc){	
	//Se aux for ifual ao numero minimo e opção ser para diminuir mais a aux, então aux retornara no numero maximo das opções
	if(*aux==1 && opc == SETA_ESQUERDA){
		*aux=max;
	}
	//Senão se aux for ifual ao numero maximo e opção ser para umentar mais a aux, então aux retornara no numer minimo das opções
	else if(*aux == max && opc == SETA_DIREITA){
			(*aux)=1;
		}
		//Senão se opc for para aumentar mais então aux++
		else if(opc==SETA_DIREITA){
				(*aux)++;
			}
			//Senão se opc for para diminuir mais então aux--
			else if(opc==SETA_ESQUERDA){
					(*aux)--;
				}	
}

int confirmlog(){
	int c;
	char opc;
	int aux = 1;
	
//	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	c = centraliza(18);
	moldura(c-1,c+20,19,21,1);
	gotoxy(c, 20);
	printf("DESEJA CONTINUAR ?");
	
	do{
		mHorizontal(&aux,2,opc);
		
		if(aux==1){
			textcolor(PRETO);
			moldura(32,38,22,24,1);
			gotoxy(33,23);
			printf("LOGIN");
		}
		
		else{
			textcolor(BRANCO);
			moldura(32,38,22,24,1);
			gotoxy(33,23);
			printf("LOGIN");
			
		}
		
		if(aux==2){
			textcolor(PRETO);
			moldura(42,48,22,24,1);
			gotoxy(43, 23);
			printf("CRIAR");
		}
		
		else{
			textcolor(BRANCO);
			moldura(42,48,22, 24,1);
			gotoxy(43,23);
			printf("CRIAR");
		}
		gotoxy(0,0);
		
		opc=getch();
	
	}while(opc!=ENTER);
	
	if(aux==1){
		return 0;
	}
	
	else{
		return 1;
	}
}

//Função que pergutara se usuario que fazer o login
int confirmcheck(){
	int c;			//Variavel controladora das coordenadas da coluna
	char opc;		//Variavel que sera lida pelo usuario
	int aux = 1;	//Variavel controladora da posição
	
	//Chamada da função de limpeza de dentro da moldura
	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	c = centraliza(39);			//Centralização da coluna
	moldura(c-1,c+40,8,10,1);	//Criação da caixinha onde ficara a mensagem
	gotoxy(c,9);				//Posicionamento do cUrsor para escrever a mensagem
	printf("VOC\xD2 DESEJA CONFIRMAR O CHECK-IN ?",229);	//Escrita da mensagem
	
	//Laço do-while 
	do{
		//Se variave aux == 1 então sigifica que a opção desejada e sim
		if(aux==1){
			textcolor(VERDE);		//Mudança de cpr para verde
			moldura(32,36,12,14,1);	//Impressão da moldura em volta da mensgem
			gotoxy(33,13);			//Posicionamento do curso para impressão da mensagem
			printf("SIM");			//Escrita da mensagem
		}
		
		//Senão então a opção não sera destacada
		else{
			textcolor(BRANCO);		//Mudança de cor para branco
			moldura(32,36,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(33,13);			//Posicionamento do curso para impressão da mensagem
			printf("SIM");			//Escrita da mensagem
			
		}
		
		//Se variave aux == 2 então sigifica que a opção desejada e não
		if(aux==2){
			textcolor(PRETO);		//Mudança de cor para verde
			moldura(42,46,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(43,13);			//Posicionamento do curso para impressão da mensagem
			printf("N\x8EO");		//Escrita da mensagem
		}
		
		//Senão então a opção não sera destacada
		else{
			textcolor(BRANCO);		//Mudança de cor para branco
			moldura(42,46,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(43,13);			//Posicionamento do curso para impressão da mensagem
			printf("N\x8EO");		//Escrita da mensagem
		}
		//Posicionamento do cursor no inicio da tela
		gotoxy(0,0);
		
		opc=getch();		//Leitura do teclado
		mHorizontal(&aux,2,opc);	//Se opção for alguma das setas então variavel aux mudara
		
		//Se opc for igual a ENTER então saira 
	}while(opc!=ENTER);
	
	//Se opção for sim então retornara 1
	if(aux==1){
		return 1;
	}
	//Senão ira retorna 0
	else{
		return 0;
	}
}

//Função que perguntara ao usuario se deseja prosseguir
int confirm(){

	int c;			//Variavel controladora das coordenadas da coluna
	char opc;		//Variavel que sera lida pelo usuario
	int aux = 1;	//Variavel controladora da posição
	
	//Chamada da função de limpeza de dentro da moldura
	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	c = centraliza(39);			//Centralização da coluna
	moldura(c-1,c+40,8,10,1);	//Criação da caixinha onde ficara a mensagem
	gotoxy(c,9);				//Posicionamento do crsor para escrever a mensagem
	printf("VOC\xD2 DESEJA CONFIRMAR AS INFORMA\x80%cES ?",229);	//Escrita da mensagem
	
	//Laço do-while 
	do{
		//Se variave aux == 1 então sigifica que a opção desejada e sim
		if(aux==1){
			textcolor(VERDE);		//Mudança de cpr para verde
			moldura(32,36,12,14,1);	//Impressão da moldura em volta da mensgem
			gotoxy(33,13);			//Posicionamento do curso para impressão da mensagem
			printf("SIM");			//Escrita da mensagem
		}
		
		//Senão então a opção não sera destacada
		else{
			textcolor(BRANCO);		//Mudança de cor para branco
			moldura(32,36,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(33,13);			//Posicionamento do curso para impressão da mensagem
			printf("SIM");			//Escrita da mensagem
			
		}
		
		//Se variave aux == 2 então sigifica que a opção desejada e não
		if(aux==2){
			textcolor(PRETO);		//Mudança de cor para verde
			moldura(42,46,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(43,13);			//Posicionamento do curso para impressão da mensagem
			printf("N\x8EO");		//Escrita da mensagem
		}
		
		//Senão então a opção não sera destacada
		else{
			textcolor(BRANCO);		//Mudança de cor para branco
			moldura(42,46,12,14,1);	//Impressão da moldura em volta do mensagem
			gotoxy(43,13);			//Posicionamento do curso para impressão da mensagem
			printf("N\x8EO");		//Escrita da mensagem
		}
		//Posicionamento do cursor no inicio da tela
		gotoxy(0,0);
		
		opc=getch();		//Leitura do teclado
		mHorizontal(&aux,2,opc);	//Se opção for alguma das setas então variavel aux mudara
		
		//Se opc for igual a ENTER então saira 
	}while(opc!=ENTER);
	
	//Se opção for sim então retornara 1
	if(aux==1){
		return 1;
	}
	//Senão ira retorna 0
	else{
		return 0;
	}
}
void dLogar(){
	if(log){
		if(confirm){
			log = 0;
			lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
			int c = centraliza(29);
			gotoxy(c,20);
			printf("CONTA DESLOGADA COM SUCESSO");
			getch();
		}
	}else{
			lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
			int c = centraliza(27);
			gotoxy(c,20);
			printf("NENHUMA CONTA ESTA LOGADA");
			getch();
	}
}

void ask(void){
	int c; //vaiavel return//
	int coluna;
	
	moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
		
	coluna = centraliza(45);
	gotoxy(coluna, 15);
	printf("E Necessario uma conta para reservar passagens\n");
	//Sleep(sleep);
	coluna = centraliza(34);
	gotoxy(coluna, 16);
	printf("Se ja possui uma conta, faca log-in\n");
	//Sleep(sleep);
	coluna = centraliza(16);
	gotoxy(coluna, 17);
	printf("Se nao, crie uma.");
	 
		
	//lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
		
	c = confirmlog();
		
//	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
		
	if(c ==1){
		cadastro(ac(),jubiscleito());
	}else{
		login(ac(),jubiscleito());
	}
		
}

////////////////////////////////////////////

void scan(struct destiny d1){ //corpo da função de leitura//
	int i;
	int aux = 0;
	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	FILE *fptr; //uso de arquivos para gravação dos locais//
	fptr=fopen("destiny.bin","wb");
	
	do{
		aux = 0;
		tabela2(1,aux);
		fgets(d1.embark,50,stdin);
		aux++;
	
		tabela2(0,aux);
		fgets(d1.arrive,50,stdin);
		
		aux = confirm();

	}while(aux == 0);
	for(i = 0;i <2;i++){
		fwrite(&d1,sizeof(struct destiny) , 1 , fptr); //gravação no arquivo//
	}
	
	fclose(fptr); //fechamento do arquivo//
	
	system("CLS");
}

int menu(int x,int y){ //Corpo da função de menu de confirmação//
	char t;
	int i;
	system("cls"); //Limpeza de tela//
	
//variável de controle para retorno de opção//
	 i = 1;
	do{
		moldura (4, 76, 4, 36,1);
		gotoxy(25, 15);
		printf("CONFIRMACAO");
		gotoxy(25, 16);
		printf("  Editar local de partida e chegada");
		gotoxy(25, 17);
		printf("  Confirmar e gerar boleto de Check in");
		gotoxy(25, 15 + i);
		printf (">");
		gotoxy(25, 15 + i);
		t = getch();
		if (t == 72) i = 1;
		if (t == 80) i = 2;
		
		system("ClS");
	}while (t != 13); 
	
 
	if(i ==1){
		scan(d1());
		menu(x,y);
	}
	else{
		check(d1(),x,y);
	}
	
	
	system("cls");

}

void tabela2(int cond,int aux){
	int c,l = 10;
	
	if(cond == 1){
		lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
		tempo();
		textcolor(PRETO);
		c = centraliza(15);	
		moldura(c-1,c+15,5,7,1);
		gotoxy(c,6);
		printf("CADASTRAR LOCAL");
	}
	
	textcolor(BRANCO);
	gotoxy(7,l);
	printf("LOCAL DE PARTIDA : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("LOCAL DE CHEGADA : ");
	l++;
	linha(l,15);
	l+=2;
	
	textcolor(PRETO);
	switch(aux){
		case 0:
			l = 10;
			gotoxy(7,l);
			printf("LOCAL DE PARTIDA : ");
			l++;
			linha(l,0);
			gotoxy(21+5,l-1);
			break;
			
		case 1:
			l = 13;
			gotoxy(7,l);
			printf("LOCAL DE CHEGADA : ");
			l++;
			linha(l,0);
			gotoxy(20+5,l-1);
			break;
	}
	textcolor(BRANCO);

}


void check(struct destiny d1,int x , int y){ //Função para geração do boleto de Check-in//
	
	char check[3]; //variável para confirmação de Check-in//
	int i, cck;
	
	system("cls");
	
	FILE *fptr; //criação do ponteiro para arquivo//
	fptr=fopen("destiny.bin" ,"rb"); //abertura do arquivo//
	
	if(fptr==NULL){
			moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
			moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
			gotoxy(30,18);
			printf("Nenhuma passagem reservada\n");
			Sleep(sleep);
			lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
			
			menuP(1);	
	}
	
	else{
	
	
	moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
	moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
	show();
	gotoxy(30,18);
	printf("LOCAIS:\n");

	for( i=0; i <1;i++){
		fread(&d1,sizeof(struct destiny), 1 , fptr); //acesso ao arquivo//
		gotoxy (30, 19+i);
		printf("%s" , d1.embark);
		gotoxy(30, 20 + i);
		printf("%s" , d1.arrive);
		fseek(fptr, sizeof(struct destiny), SEEK_END); //busca no arquivo//
	}
		
		Sleep(sleep);
	
	start:
		
		cck = confirmcheck();
		
		
		if(cck==0){
			
			cck = confirm();	
			
			if(cck==1){
				menuP(1);
			}
			
			else{
				goto start;
			}
	}
			
	
	 //Função strcmp para conexão condicional//
		
		moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
		gotoxy(30,18);
		printf("Check-in realizado\a\a\n\n");
		Sleep(sleep);
		lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	menuP(1);
	}
}


void finish(void){
	
	printf("Passagem reservada\n\a\a");
	system("pause");
}

//Função que mostra mensagem para prosseguir no programa e recebe um int da linha onde ela devera ser imprimeda
void continua(int linha){ 
	moldura(24,55,linha-1,linha+1,1);	//Impressão da caixinha ao redor da mensagem	
	
	char x;	//Variavel que lera o teclado
	int c;	//Variavel da coordenada das colunas
	c= centraliza(28);	//Chamando a função centralizar para centralizar a palavra
	gotoxy(c,linha);	//Posicionamento do curso
	printf("Para prosseguir aperte ENTER");	//Mensagem para o usuario
	
	//Laço do-while
	do{
		setbuf(stdin,NULL);
		x = getch();		//Leitura do teclado
	}while(x != ENTER);		//Loop onde so saira se aperta ENTER	
}

//Funçao que recebera o tamanho da palavra e retornara a coluna onde ela estara centralizada
int centraliza(int tamanho){ 
	return ((70 - tamanho)/2)+5;
}

//coordenadas(para developers)//
void coordenadas(){ 
	textcolor(BRANCO);
	gotoxy(0,0);
	printf("01234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
	printf("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25\n26\n27\n28\n29\n30\n31\n32\n33\n34\n35\n36\n37\n38\n39");
}

//Função que recebera dois inteiros que serão as coordenadas e apagara as seta
void aSeta(int c, int l){
	gotoxy(c,l);		//Posicionameto do curso nas coordenadas recebidas
	printf("  ");		//Impressão de espaços 
}


void tabela1(int aux,int cond){
	int c;
	if(cond == 0){
		textcolor(PRETO);
		c = centraliza(24);
		moldura(23,55,5,7,1);
		gotoxy(c,6);
		printf("ESCOLHA A OP\x80\x8EO DESEJADA");
	}
	textcolor(BRANCO);
	c = centraliza(30);
	gotoxy(c,9);
	printf("PESQUISA E COMPRA DE PASSAGENS");
	c = centraliza(32);
	gotoxy(c,12);
	printf("CONSULTA DE PASSAGENS COMPRADAS");
	c = centraliza(15);
	gotoxy(c,15);
	printf("CADASTRAR CONTA");
	c = centraliza(14);
	gotoxy(c,18);
	printf("SAIR DA CONTA");
	c = centraliza(11);
	gotoxy(c,21);
	printf("LOGAR CONTA");
	c = centraliza(21);
	gotoxy(c,24);
	printf("FINALIZAR O PROGRAMA");

	
	switch(aux){
		case 0 :
			c = centraliza(30);
			gotoxy(c,9);
			textcolor(PRETO);
			printf("PESQUISA E COMPRA DE PASSAGENS");
			gotoxy(c-2,9);
			break;

		case 1:
			c = centraliza(32);
			gotoxy(c,12);
			textcolor(PRETO);
			printf("CONSULTA DE PASSAGENS COMPRADAS");
			gotoxy(c-2,12);
			break;

		case 2:
			c = centraliza(15);
			gotoxy(c,15);
			textcolor(PRETO);
			printf("CADASTRAR CONTA");
			gotoxy(c-2,15);
			break;

		case 3:
			c = centraliza(14);
			gotoxy(c,18);
			textcolor(PRETO);
			printf("SAIR DA CONTA");
			gotoxy(c-2,18);
			break;
				
		case 4:
			c = centraliza(11);
			gotoxy(c,21);
			textcolor(PRETO);
			printf("LOGAR CONTA");
			gotoxy(c-2,21);
			break;
			
		case 5:
			c = centraliza(21);
			gotoxy(c,24);
			textcolor(PRETO);
			printf("FINALIZAR O PROGRAMA");
			gotoxy(c-2,24);
			break;
	}
	
	textcolor(BRANCO);
}

void tabela4(int cond,int aux){
	int c,l = 10;
	
	if(cond == 1){
		lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
		tempo();
		textcolor(PRETO);
		c = centraliza(15);	
		moldura(c-1,c+15,5,7,1);
		gotoxy(c,6);
		printf("CADASTRAR CONTA");
	}
	
	textcolor(BRANCO);
	gotoxy(7,l);
	printf("NOME : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("CPF : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("SENHA : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("CONFIRMAR SENHA : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("E-MAIL : ");
	l++;
	linha(l,15);
	
	textcolor(PRETO);
	switch(aux){
		case 0:
			l = 10;
			gotoxy(7,l);
			printf("NOME : ");
			l++;
			linha(l,0);
			gotoxy(9+5,l-1);
			break;
			
		case 1:
			l = 13;
			gotoxy(7,l);
			printf("CPF : ");
			l++;
			linha(l,0);
			gotoxy(8+5,l-1);
			break;
			
		case 2:
			l=16;
			gotoxy(7,l);
			printf("SENHA : ");
			l++;
			linha(l,0);
			gotoxy(10+5,l-1);
			break;
	
		case 3:
			l = 19;
			gotoxy(7,l);
			printf("CONFIRMAR SENHA : ");
			l++;
			linha(l,0);
			gotoxy(20+5,l-1);
			break;
	
		case 4:
			l = 22;
			gotoxy(7,l);
			printf("E-MAIL : ");
			l++;
			linha(l,0);
			gotoxy(10+5,l-1);
			break;
	}
	textcolor(BRANCO);

}

void tabela6(int cond,int aux){
	int c,l = 10;
	
	if(cond == 1){
		lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
		tempo();
		textcolor(PRETO);
		c = centraliza(11);	
		moldura(c-1,c+12,5,7,1);
		gotoxy(c,6);
		printf("LOGAR CONTA");
	}
	
	gotoxy(7,l);
	printf("E-MAIL : ");
	l++;
	linha(l,15);
	l+=2;
	
	gotoxy(7,l);
	printf("SENHA : ");
	l++;
	linha(l,15);
	l+=2;
	
	textcolor(PRETO);
	switch(aux){
		case 0:
			l = 10;
			gotoxy(7,l);
			printf("E-MAIL : ");
			l++;
			linha(l,0);
			gotoxy(10+5,l-1);
			break;
			
		case 1:
			l = 13;
			gotoxy(7,l);
			printf("SENHA : ");
			l++;
			linha(l,0);
			gotoxy(10+5,l-1);
			break;
			
	}
	textcolor(BRANCO);

}

//Fução controladora da mensagem final
void fim(){
	moldura (3,77,3,37,1);		//Impressão da moldura externa
	moldura (4, 76, 4, 36,1);	//Impressão da moldura interna
	gotoxy(centraliza(10),20);	//Centralização do cursor
	exclude();					//Excluir as informações
	printf("Obrigado !!!");		//Mensagem de obrigado
	Sleep(3000);				//Tempo de espera
	transicaoFim(26);	
	log = 0;		//Limpeza de tela
	exit(1);
	
}

void setaM(int *aux,int max,int coluna[],int linha[],char opc){
	max --;
	
	if(*aux == 0 && opc == SETA_CIMA){
		(*aux) = max;
		aSeta(coluna[0],linha[0]);
		seta(coluna[*aux],linha[*aux]);
		}else if((*aux) == max && opc == SETA_BAIXO){
			(*aux) = 0;
			aSeta(coluna[max],linha[max]);
			seta(coluna[*aux],linha[*aux]);
			}else if(opc == SETA_BAIXO){
				(*aux)++;
				aSeta(coluna[*aux-1],linha[*aux-1]);
				seta(coluna[*aux],linha[*aux]);
			}else if(opc == SETA_CIMA)
				(*aux)--;
				aSeta(coluna[*aux+1],linha[*aux+1]);
				seta(coluna[*aux],linha[*aux]);
}

//Função que ira controlar as animações iniciais
void inicio(){
	setbuf(stdin,NULL); 	//limpeza de buffer//
	transicaoInicio(28); 	//chamada da primeira função de transição//
	gotoxy(30, 20);			//Artifício gráfico para o título//
	titulo(6); 				//chamada da função título//
	transicaoFim(28);		//finalização da transição//
	setbuf(stdin,NULL);		 //limpeza de buffer//
}

//Função que controla a opção de cadastro
void cadastro(create ac , zap jubiscleito){ 
	int i;		
	int c;      //Variavel que controlara as colunas
	int aux;	//Variavel auxiliar que servira para contar as posições

	
	FILE *fptr;
	fptr=fopen("account.bin","ab");
	
	//Laço do-while que so saira se usuario no final escolher a opção sim
	do{
		
		aux = 0;	   		//No inicio de cada loop aux recebe 0
		tabela4(1,aux);		//Chamada da função tabela ja marcada com a primeira opção
		
		//Laço do-while onde so saira se as informações forem corretas
		do{
			lLinha(14,50,10);	//Limpeza da linha caso ainda haja alguma informação printada la
			gotoxy(14,10);		//Posicionamento do curso depois da mensagem
			fgets(ac.name,MAX,stdin);	//Leitura da informação
			setbuf(stdin,NULL);			//Limpeza de buffer
			fflush(stdin);				//Limpeza de buffer
			
			//IF onde apaecera mensagem de ERRO caso informação seja incorreta ou usuario tenha precionado ENTER primeiramente
			if(validarNOME(ac.name) != 1  || ac.name[0] == 10){
				lLinha(14,60,10);		//Limpeza de linha
				c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,10);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
			}
			//Saida do laço caso informações dadas serem validadas
		}while(validarNOME(ac.name) != 1 || ac.name[0] == 10);
		
		//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
		aux++;	
		tabela4(0,aux);

		//Laço do-while onde so saira se as informções forem corretas
		do{
			lLinha(13,50,13);	//Limpeza da linha caso ainda haja alguma informação printada la
			gotoxy(13,13);		//Posicionamento do curso depois da mensagem
			fgets(ac.cpf,12,stdin);		//Leitura da informação
			setbuf(stdin,NULL);			//Limpeza de buffer
			fflush(stdin);				//Limpeza de buffer
			
			//IF onde apaecera mensagem de ERRO caso informação seja incorreta ou usuario tenha precionado ENTER primeiramente
			if(validarCPF(ac.cpf) != 1 || ac.cpf[0] == 10){
				lLinha(13,60,13);		//Limpeza de linha
				c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,13);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
			}
			//Saida do laço caso informações dadas serem validadas
		}while(validarCPF(ac.cpf) != 1 || ac.cpf[0] == 10);
		
		//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
		aux++;		
		tabela4(0,aux);
		
		//Laço do-while onde so saira se as informções forem corretas
		do{
			lLinha(15,50,16);	 //Limpeza da linha caso ainda haja alguma informação printada la
			gotoxy(15,16);		//Posicionamento do curso depois da mensagem
			fgets(ac.key,MAX,stdin);		//Leitura da informação
			setbuf(stdin,NULL);				//Limpeza de buffer
			fflush(stdin);					//Limpeza de buffer
			
			//IF onde apaecera mensagem de ERRO caso usuario tenha precionado ENTER primeiramente
			if(ac.key[0] == 10){
				lLinha(25,60,16);		//Limpeza de linha
				c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,16);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
			}
			//Saida do laço caso informações dadas serem validadas
		}while(ac.key[0] == 10);
		
		//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
		aux++;
		tabela4(0,aux);
		
		//Laço do-while onde so saira se as informações forem corretas
		do{
			lLinha(25,50,19);	//Limpeza da linha caso ainda haja alguma informação printada la
			gotoxy(25,19);		//Posicionamento do curso depois da mensagem
			fgets(ac.ver,MAX,stdin);		//Leitura da informação
			setbuf(stdin,NULL);				//Limpeza de buffer
			fflush(stdin);					//Limpeza de buffer
			
			//IF onde apaecera mensagem de ERRO caso informação seja incorreta ou usuario tenha precionado ENTER primeiramente
			if(validarSENHA(ac.key,ac.ver) == 1|| ac.ver[0] == 10){
				lLinha(25,60,19);		//Limpeza de linha
				c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,19);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
			}
			//Saida do laço caso informações dadas serem validadas
		}while(validarSENHA(ac.key,ac.ver) == 1 || ac.ver[0] == 10);
		
		//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
		aux++;
		tabela4(0,aux);
		
		//Laço do-while onde so saira se as informções forem corretas
		do{
			lLinha(15,50,22);	//Limpeza da linha caso ainda haja alguma informação printada la
			gotoxy(15,22);		//Posicionamento do curso depois da mensagem
			fgets(ac.email,MAX,stdin);		//Leitura da informação
			setbuf(stdin,NULL);				//Limpeza de buffer
			fflush(stdin);					//Limpeza de buffer
			
			//IF onde apaecera mensagem de ERRO caso informação seja incorreta ou usuario tenha precionado ENTER primeiramente
			if(validarEMAIL(ac.email) != 1 || ac.email[0] ==10){
				lLinha(15,60,22);		//Limpeza de linha
				c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,22);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
			}
			//Saida do laço caso informações dadas serem validadas
		}while(validarEMAIL(ac.email) != 1 || ac.email[0] == 10);
		
		//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
		aux++;	
		tabela4(0,aux);
		
		//Chamada da função confirm para confirmação de salvamento
		aux = confirm();
		
		//Caso usuario escolha sim então saira do laço
	}while(aux != 1);
	
	for(int i=0;i < MAX;i++){
		jubiscleito.key[i]=ac.key[i];
		jubiscleito.email[i]=ac.email[i];
	}

	for(int a=0; a < 2;a++){
		fwrite(&jubiscleito,sizeof(zap) , 1 , fptr);
	}
	
	fclose(fptr);

	
	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	c = centraliza(23);
	gotoxy(c,15);
	printf("CONTA SALVA COM SUCESSO");
	Sleep(2000);
	lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
	
	log = 1;
}

void login(create ac,zap jubiscleito){ //editar//
	system("cls");
	
	FILE *fptr;
	
	moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
	moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);
	
	int i;		
	int c;      //Variavel que controlara as colunas
	int aux;	//Variavel auxiliar que servira para contar as posições
	
	aux = 0;	   		//No inicio de cada loop aux recebe 0
	tabela6(1,aux);		//Chamada da função tabela ja marcada com a primeira opção

	lLinha(16,50,10);	//Limpeza da linha caso ainda haja alguma informação printada la
	gotoxy(16,10);		//Posicionamento do curso depois da mensagem
	fgets(ac.email,MAX,stdin);	//Leitura da informação
	setbuf(stdin,NULL);			//Limpeza de buffer
	fflush(stdin);				//Limpeza de buffer
		
	//Incremento da variavel auxiliar para a chamada da função grafica passar para a outra opção
	aux++;	
	tabela6(0,aux);
		
	lLinha(15,50,13);	//Limpeza da linha caso ainda haja alguma informação printada la
	gotoxy(15,13);		//Posicionamento do curso depois da mensagem
	fgets(ac.key,12,stdin);		//Leitura da informação
	setbuf(stdin,NULL);			//Limpeza de buffer
	fflush(stdin);				//Limpeza de buffer
	
	compare( jubiscleito, ac);
	
	if(compare(jubiscleito,ac)==1){
		
		moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
		moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);	
			c = centraliza(23);
			gotoxy(c,15);
			printf("CONTA LOGADA COM SUCESSO");
			Sleep(2000);
			lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
			
			menuP(1);
	
	}
	
	else{	
		moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);
		moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);	
		c =	centraliza(17);		//Centralização do cursor
				gotoxy(c,22);			//Posicionamento do cursor
				printf("FORMATO INCORRETO");	//Impressão da mensagem de erro
				Sleep(sleep);
				lMoldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA);
				
				login(ac,jubiscleito);
	}
	
}

void mover(int *aux,int max,char opc){
	if(*aux == 0 && opc == SETA_CIMA){
		*aux = max;
	}else if(*aux == max && opc == SETA_BAIXO){
		(*aux) = 0;
		}else if(opc == SETA_BAIXO){
			(*aux)++;
			}else if(opc == SETA_CIMA)
				(*aux)--;
				
}

//////////////////////////
//FUNÇÕES DE VALIDAÇÕES//
/////////////////////////

//Função que recebera um char e verificar se ele um CPF valido
int validarCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

//Função que recebera um char e verificar se ele um email valido
int validarEMAIL(char email[]){
	//Variaveis de controle
	int cont = 0,aux = 0,i;
	//Variavel que guardara o numero de verificações verdadeiras
	int veri= 0;
	//Variavel que guardara o tipo e dominio dos emails
	char tipo[15];
	
	
	//FOR que contara os numeros de digitos ate o @ ou ate a string acabar
	for(aux = 0,cont = 0;email[aux] != '@' || '\0' ;aux++,cont++){
	}
	
	//Se o for acabar em @ então veri passara e ele ira fazer a verificação do dominio
	if(email[aux] == '@')
		veri++;
	
	if(veri == 1){
		//Opreção em que passamos o resto da string para a variavel tipo
		for(i = 0;email[aux+1] != '\0';aux++,i++){
			tipo[i] = email[aux];
		}
		tipo[i] = '\0';	

		//Se o tipo for igual ao dominios declarados então função passara a ser verdadeis
		if(strcmp(tipo,"@gmail.com") == 0 || strcmp(tipo,"@hotmail.com") == 0 || strcmp(tipo,"@outlook.com") == 0){
			veri++;
		}
	}
	
	//Verificar as condições e retorna verdadeiro ou falso
	if(cont >= 6 && veri == 2){
		return 1;
	}else
		return 0;
}

//Função que recebera um char e vriicar se ele e uma senha valido
int validarSENHA(char senha1[],char senha2[]){
	//Compara as senhas e retorna verdadeiro caso verdadeiro
	if(strcmp(senha1,senha2)){
		return 1;
	}else
		return 0;
}

//Função que recebera um char e verificar se ele um nome valido
int validarNOME(char nome[]){
	int i = 0;
	//Verificar se o digito e igual a espaço ou letra e retorna falso caso contrario
	do{
		if(isalpha(nome[i]) || isspace(nome[i]) || nome[i] == '\0'){	
		}

		else {
			switch(nome[i]){
				//Se nenhuma das verificações acima ser verdadeira ira ver ser o caracter e algum acento
				case -21: break;
				case -22: break;
				case -23: break;
				case -27: break;
				case -28: break;
				case -29: break;
				case -30: break;
				case -34: break;
				case -40: break;
				case -41: break;
				case -42: break;
				case -44: break;
				case -45: break;
				case -46: break;
				case -57: break;
				case -58: break;
				case -73: break;
				case -74: break;
				case -75: break;
				case -91: break;
				case -92: break;
				case -93: break;
				case -94: break;
				case -95: break;
				case -96: break;
				case -105: break;
				case -106: break;
				case -115: break;
				case -116: break;
				case -118: break;
				case -120: break;
				case -121: break;
				case -128: break;
				//Se não for nada então retornara falso
				default : return 0;
			}
		}
		i++;
	}while(nome[i] != '\0');
	
	return 1;
}


/////////////////////
//Funções graficas//
////////////////////

//Função para posicionamento do cursor
void gotoxy(int x , int y){ 
	COORD graph;
	graph.X=x;
	graph.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),graph); //função da windows.h//
}

//Função para mudança de cor nas letras
void textcolor( DOS_COLORS iColor ){
        HANDLE hl = GetStdHandle ( STD_OUTPUT_HANDLE ) ;
        CONSOLE_SCREEN_BUFFER_INFO bufferInfo ;
        BOOL b = GetConsoleScreenBufferInfo ( hl , & bufferInfo ) ;
        bufferInfo. wAttributes &= 0x00F0 ;
        SetConsoleTextAttribute ( hl , bufferInfo. wAttributes |= iColor ) ;
}

//Função que imprimir o avião//
//Recebe dois inteiros sendo um indicado a linha inicial e outro indicando se o avião ira linpar ou não as molduras//
void ImprimeAviao (int y,int cond){ 
	
	int x= centraliza(38); 	//Variavel que centalizara colunas do avião
	
	//Impressão do avião
	gotoxy(x,y);
	printf("                  /\\");
	y++;
	gotoxy(x,y);
	printf("                 |^^|");
	y++;
	gotoxy(x,y);
	printf("                 |{}|");
	y++;
	gotoxy(x,y);
	printf("  _______________/~~\\________________");
	y++;
	gotoxy(x,y);
	printf(" /               |  |                \\");
	y++;
	gotoxy(x,y);
	//Se condição passada for igual 1 então avião apagara as colunas
	if(cond == 0){
		x = centraliza(74);
		gotoxy(x,y);
		printf("                  `========--------.  .---------========'                  ");
		y++;
		gotoxy(x,y);
		printf("                                   ||||                                     ");
		y++;
		gotoxy(x,y);
		printf("                                    ||                                      ");
		y++;
		gotoxy(x,y);
		printf("                                    ||                                      ");
		y++;
		gotoxy(x,y);
		printf("                                    ||                                       ");
		y++;
		gotoxy(x,y);
		printf("                                ,---||---,                                   ");
		y++;
		gotoxy(x,y);
		printf("                                '---<>---'                                   ");
	}
	//Se não então avião imprimira normalmente
	else{
		centraliza(38);
		gotoxy(x,y);
		printf("`========--------.  .---------========'");
		y++;
		x = centraliza(38);
		gotoxy(x,y);
		printf("                 ||||                   ");
		y++;
		gotoxy(x,y);
		printf("                  ||                    ");
		y++;
		gotoxy(x,y);
		printf("                  ||                    ");
		y++;
		gotoxy(x,y);
		printf("                  ||                     ");
		y++;
		gotoxy(x,y);
		printf("              ,---||---,                 ");
		y++;
		gotoxy(x,y);
		printf("              '---<>---'                 ");
	}
	y++;
	
	gotoxy(4,y);
	//For que apagara a parte restante do avião
	for(int z = 0;z < 73;z++){
		printf(" ");
	}
}

//Função onde ela ira imprimir uma linha grafica, ela recebera a localização da linha e a cor dela
void linha(int l,int cor){
	textcolor(CPrincipais[cor]);	//Mudança de cor para a recebida
	
	//FOR onde percorrera as colunas
	for(int i = 7;i < C_MAXIMA-3;i++){
		gotoxy(i,l);	//Posicionamento do cursor
		printf("\xC4");	//Impressão da linha
	}
}

//Função que limpara dentro da moldura
//Recebera os limites da moldura
void lMoldura(int cMinima,int cMaxima,int lMinima,int lMaxima){
	int i, j;		//Variaveis auxiliares
	for ( i = cMinima+1 ; i <= cMaxima-1 ; i++){	//Controle da coluna
		for ( j = lMinima+1 ; j <= lMaxima-1 ; j++){	//Controle da linha
			gotoxy(i, j);		//Posicionamento do cursor
			printf (" ");		//Limpeza de tela
		}
	}
}

//Função que limpara conteudo de uma linha
//Recebera as colunas limites e a linha
void lLinha(int cMinima,int cMaxima,int lLinha){
	int i;	//Variavel auxilia
	for ( i = cMinima ; i <= cMaxima ; i++){	//Controle da coluna
		gotoxy(i,lLinha);	//Posicionamento do cursor
		printf (" ");		//Limpeza da tela
	}
}

//Função que imprimira as caixinhas ou moldura
//Receber as delimitações da caixinha e tambem uma condição de impressão da linha iniciasl
void moldura (int cMinima, int cMaxima, int lMinima, int lMaxima,int verificador){
	int i, j;	//Variaveis auxiliares
	
	//For que controlara as colunas
	for ( i = cMinima ; i <= cMaxima ; i++){
		//For que controlara as linhas
		for ( j = lMinima ; j <= lMaxima ; j++){
			gotoxy(i, j);	//Posicionamento do cursor
			//Se localização for igual a uma das colunas e diferente das linhas minimas e maxima então imprimira a coluna
			if (i == cMinima || i == cMaxima &&( j != lMinima && j != lMaxima))
				printf ("\xBA");
			//Senão se condição nao for verdadeira então ele imprimira a linha minima
			else if(verificador !=1){
					if (j == lMaxima && (i != cMinima && i != cMaxima)){
						printf ("\xCD");
					}
				//Senão imprimirialinha minima ou maxima
				}else if (j == lMinima || j == lMaxima && (i != cMinima && i != cMaxima))
						printf ("\xCD");
			//Senão for nenhuma das condiçõe então imprimira um espaço
			else 
				printf(" ");
		}
	}
	//Se verificador for verdadeiro então imprimira as esquinas das linhas iniciais
	if(verificador == 1){
		gotoxy (cMinima, lMinima);
		printf ("\xC9");
		gotoxy (cMaxima, lMinima);
		printf ("\xBB");
	}
	//Impressão das esquinas nas ultimas linhas 
	gotoxy (cMinima, lMaxima);
	printf ("\xC8");
	gotoxy (cMaxima, lMaxima);
	printf ("\xBC");
}

//Função que controlara as animaçõs de inicio e recebera um inteiro correspondende a linha inicial da animação do avião
void transicaoInicio (int inicio){
	
	int c = L_MAXIMA,i,j;	//Variaveis auxiliares
	
	system("cls");	//Limpeza total da tela
	
	//Laço do-while
	do{
		moldura(C_MINIMA-1,C_MAXIMA+1,c-1,L_MAXIMA+1,0);//Chamada da função moldura sem fechar completamente o retangulo
		ImprimeAviao(inicio,1);		//Chamada da impressão do avião,com a função de apagalo
		inicio--;					//decremento da linha de inicio
		c--;						//Decremento da linha minima
		Sleep(1);					//Pausa de tempo
	
	//Se linha for igual a 0 então ele saír do laço
	}while (inicio > 0);
	
	system("cls");		//Limpeza total da tela
	
	moldura(C_MINIMA-1,C_MAXIMA+1,L_MINIMA-1,L_MAXIMA+1,1);		//Chamada da moldura externa
	moldura(C_MINIMA,C_MAXIMA,L_MINIMA,L_MAXIMA,1);				//Chamada da moldura interna
}

//Função que controlara a animação final,e que recebe uma linha de inicio
void transicaoFim (int inicio){
	int c = L_MAXIMA,i,j;	//Variaveis auxiliares
	
	//Laço do-while
	do{
		ImprimeAviao(inicio,0); //Chamda da função de impressão do avião com a condição de as asas dele paguem a moldura
		inicio--;		//Decremento da linha de inicio		
		c--;			//Decremento da variavel contadora

		Sleep(25);	//Pausa de tempo
		
	//Saida ddo laço
	}while (c >= 14);
	
	system("cls");	//Apagamento total da tela
}

//Função que recebera dois inteiros que serão as coordenadas e imprimira as seta
void seta(int c,int l){
	char s[] = ">>";	//Char que contem o desenho da seta
	
	gotoxy(c,l);		//Posicionamento do cursor nas coordenadas recebidas
	textcolor(PRETO);	//Mudança de cor para preto
	printf(">>");		//Impressão da seta
	textcolor(BRANCO);	//Mudança de cor para Branco
}

//Função que imprimira o titulo e recebe um int onde indicara onde ela deve comeeçar a ser imprimida
void titulo(int linha){
	int i,j1,j2,j3;			//Variaveis com s coordenadas das linhas e colunas;
	i = linha;				//Variavel que ira controlar as linhas 
	
	j1 = centraliza(38);	//Variavel que ira controlar as colunas da palavra RIVAIL
	j2 = centraliza(44);	//Variavel que ira cintrolar as colunas da palavra LINHAS
	j3 = centraliza(47);	//Variavel que ira controlar as colunas da palavra AEREAS
	
	gotoxy(j1,i);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xBB\xDB\xDB\xBB   \xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xBB\xDB\xDB\xBB");   
	i++;
	gotoxy(j1,i);          
	printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xDB\xDB\xBA   \xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xDB\xDB\xBA");  
	i++;
	gotoxy(j1,i);                      
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xBA\xDB\xDB\xBA   \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xBA\xDB\xDB\xBA");
	i++;
	gotoxy(j1,i);                        
	printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xC8\xDB\xDB\xBB \xDB\xDB\xC9\xBC\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA\xDB\xDB\xBA\xDB\xDB\xBA");
	i++;
	gotoxy(j1,i);                         
	printf("\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xBA \xC8\xDB\xDB\xDB\xDB\xC9\xBC \xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	i++;
	gotoxy(j1,i);                    
	printf("\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xCD\xCD\xBC  \xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC");                                                                    
	//Fim da palavra RIVAIL
	i+=2;
	gotoxy(j2,i);                                                      
	printf("\xDB\xDB\xBB     \xDB\xDB\xBB\xDB\xDB\xDB\xBB   \xDB\xDB\xBB\xDB\xDB\xBB  \xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB"); 
	i++;
	gotoxy(j2,i);          
	printf("\xDB\xDB\xBA     \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xBB  \xDB\xDB\xBA\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC");
	i++;
	gotoxy(j2,i);          
	printf("\xDB\xDB\xBA     \xDB\xDB\xBA\xDB\xDB\xC9\xDB\xDB\xBB \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	i++;
	gotoxy(j2,i);          
	printf("\xDB\xDB\xBA     \xDB\xDB\xBA\xDB\xDB\xBA\xC8\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA\xC8\xCD\xCD\xCD\xCD\xDB\xDB\xBA");
	i++;
	gotoxy(j2,i);         
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA\xDB\xDB\xBA \xC8\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	i++;
	gotoxy(j2,i);          
	printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC");          
	//Fim da palavra LINHAS
	i+=2;
	gotoxy(j3,i);                                                      
	printf(" \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	i++;
	gotoxy(j3,i);       
	printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC");
	i++;
	gotoxy(j3,i);       
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xBB  \xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xDB\xDB\xDB\xBB  \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB");
	i++;
	gotoxy(j3,i);        
	printf("\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xBC  \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xC9\xCD\xCD\xBC  \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBA\xC8\xCD\xCD\xCD\xCD\xDB\xDB\xBA");
	i++;
	gotoxy(j3,i);        
	printf("\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBA");
	i++;
	gotoxy(j3,i);       
	printf("\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC");
                
	//Chamada da Função continua para continuar a exibição//
	continua(29);
}

//Função que imprimira data e hora
void tempo(){
	gotoxy(63,33);		//Posicionameno do cursor
	system("time /t");	//Impressão da hora
	gotoxy(61,34);		//Posicionamento do cursor
	system("date /t");	//Impressão do tempo
}
