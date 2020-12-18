#include<stdio.h>
#include<string.h>

typedef struct{
	char responsavel[200];
	int numeroApartamento;
	int area;
	int numeroMoradores;
	float valorCondominio;
} Predio;

Predio pred[100];
int qtdeAptos = 0;
void populaDadosPredio();
void retornaDadosApto();
void somaAreaTotalAptos();
void calculaSaldoMes();
void retornaDadosAptosMais4();
void reajustaCondominio10();

int main(){
	
	int escolha = 0;
	int resp = 0;

	printf("\n\n\n............................................................\n");
	printf("............................................................\n");
	printf("............................................................\n");
	printf("............ Sistema de controle de condominios ............\n");
	printf("............ Vamos iniciar a coleta de dados ...............\n");
	printf("............................................................\n");
		
	populaDadosPredio();	
	
	printf("............................................................\n");
	printf(".............Pronto!!! Dados coletados!!!...................\n");


	do
	{

		printf("............................................................\n");	
		printf("............................................................\n");
		printf("....... Escolha entre as cinco funcoes pelo codigo: ........\n");
		printf("....... 1 -> Retornar dados apartamento            .........\n");
		printf("....... 2 -> Retornar area total condominio        .........\n");
		printf("....... 3 -> Retornar saldo do mes (-despesas)     .........\n");	
		printf("....... 4 -> Retornar apto mais de 4 moradores     .........\n");	
		printf("....... 5 -> Reajustar valor do codominio em 10    .........\n");
		printf("....... 0 -> Para Sair                             .........\n");
		printf("............................................................\n");
	
		scanf("%d", &escolha);
		
		switch ( escolha )
		{
		    case 1 :
		    retornaDadosApto();
		    break;
		    
		    case 2 :
		    somaAreaTotalAptos();
		    break;
		    
		    case 3 :
		    calculaSaldoMes();
		    break;
		    
		    case 4 :
		    retornaDadosAptosMais4();
		    break;
		    
		    case 5 :
		    reajustaCondominio10();
		    break;
		    
		    default :
		    resp=1;
	  	}
	
	} while (resp==0);
	 
	return 0;
}

void populaDadosPredio(){
	
	int i;
	
	for(i=0;i<100;i++){
		printf(" -------------------- Apartamento %3d --------------------- \n",i+1);
		printf(" -> Digite nome do responsavel: ");
		scanf("%s",pred[i].responsavel);
		printf(" -> Digita o numero do apartamento: ");
		scanf("%3d", &pred[i].numeroApartamento);
		printf(" -> Digite o tamanho da area: ");
		scanf("%3d", &pred[i].area);
		printf(" -> Digite o numero de moradores: ");
		scanf("%d", &pred[i].numeroMoradores);
		printf(" -> Digite o valor do Condominio: ");
		scanf("%3f", &pred[i].valorCondominio);
	}
	
	qtdeAptos = i;
	
}
void somaAreaTotalAptos(){
	
	int areaTotal = 0;
	int i = 0;
	
	for(i=0;i<qtdeAptos;i++){      
		areaTotal = areaTotal + pred[i].area;
    }
    printf("............................................................\n");
    printf("............................................................");
	printf("\n -> A area total do condominio e:           %3d ", areaTotal);
	printf("\n............................................................\n");
    printf("............................................................\n");
}

void reajustaCondominio10(){
	
	int i = 0;
	
	for(i=0;i<qtdeAptos;i++){      
		pred[i].valorCondominio = pred[i].valorCondominio + (pred[i].valorCondominio * 0.1);
		printf("............................................................\n");
    	printf("............................................................");
		printf("\n -> Valor reajustado da unidade %3d:           R$ %3.2f ", pred[i].numeroApartamento, pred[i].valorCondominio);
		printf("\n............................................................\n");
    	printf("............................................................\n");
    }

}

void calculaSaldoMes(){
	
	float saldoMes = 0.0;
	int i = 0;
	float gastosMes = 0.0;
	
	printf("\nEntao me informe o valor total das despesas do mes: \n");
	scanf("%f",&gastosMes);	
	
	for(i=0;i<qtdeAptos;i++){      
		saldoMes = saldoMes + pred[i].valorCondominio;
    }
    printf("............................................................\n");
    printf("............................................................");
	printf("\n -> O saldo do mes e:                                R$ %5.2f ", saldoMes-gastosMes);
	printf("\n............................................................\n");
    printf("............................................................\n");
}

void retornaDadosAptosMais4(){
	int i = 0;
	for(i=0;i<qtdeAptos;i++){      	
        if(pred[i].numeroMoradores > 4){
        	printf("............................................................\n");
        	printf("............................................................");
        	printf("\n -> Nome do responsavel:           %s ", pred[i].responsavel);
			printf("\n -> Numero Apartamento:            %3d ", pred[i].numeroApartamento);
			printf("\n -> Area:                         %3d ", pred[i].area);
			printf("\n -> Numero Moradores:              %d ", pred[i].numeroMoradores);
			printf("\n -> Valor Condominio:              R$ %3.2f ", pred[i].valorCondominio);
			printf("\n............................................................\n");
        	printf("............................................................\n");
		}
    }
}

void retornaDadosApto(){
	
	int opcao = 1;
	char nome_responsavel[200];
	int nro_apto;
	int i = 0;
	
	printf("\nSe voce quiser pesquisar por nome do responsavel digite 1 ou 2 para numero do apto.\n");
	scanf("%d",&opcao);
	
    if(opcao == 1){
        printf("\nEntao digite o nome do responsavel: ");
        scanf("%s",nome_responsavel);
        
        for(i=0;i<qtdeAptos;i++){      	
        	if(strcmp(pred[i].responsavel, nome_responsavel) == 0){
        		printf("............................................................\n");
        		printf("............................................................");
        		printf("\n -> Nome do responsavel:           %s ", pred[i].responsavel);
				printf("\n -> Numero Apartamento:            %3d ", pred[i].numeroApartamento);
				printf("\n -> Area:                          %3d ", pred[i].area);
				printf("\n -> Numero Moradores:              %d ", pred[i].numeroMoradores);
				printf("\n -> Valor Condominio:              R$ %3.2f ", pred[i].valorCondominio);
				printf("\n............................................................\n");
        		printf("............................................................\n");
			}
        }
    }else if( opcao == 2){
        printf("\nEntao digite o numero do apto: ");
        scanf("%d",&nro_apto);
        
        for(i=0;i<qtdeAptos;i++){      	
        	if(pred[i].numeroApartamento == nro_apto){
        		printf("............................................................\n");
        		printf("............................................................");
        		printf("\n -> Nome do responsavel:           %s ", pred[i].responsavel);
				printf("\n -> Numero Apartamento:            %3d ", pred[i].numeroApartamento);
				printf("\n -> Area:                          %2d ", pred[i].area);
				printf("\n -> Numero Moradores:              %d ", pred[i].numeroMoradores);
				printf("\n -> Valor Condominio:              R$ %3.2f ", pred[i].valorCondominio);
				printf("\n............................................................\n");
        		printf("............................................................\n");
			}
        }
    }	
}

