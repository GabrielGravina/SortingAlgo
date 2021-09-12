#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> 


void bubblesort(long int elementos[], int TAM){
	// Algoritmo de ordena��o Bubblesort:
	int i=0, aux=0, cont=0;
	for (cont = 0; cont < TAM; cont++) {	
		if(TAM != 10000){
//			printf("%d", elementos[0]);
		}
   		for (i = 0; i < TAM - 1; i++) {
     		if (elementos[i] > elementos[i + 1]) {
       			aux = elementos[i];
       			elementos[i] = elementos[i + 1];
       			elementos[i + 1] = aux;
     		}		
   		}
 	}
}

void quick_sort(long int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

void countsort(long int *elementos, long int n, long int k){
    // cria um array inteiro de tamanho `n` para armazenar o array ordenado
    int output[n];
	
	
 
    // cria um elementoay inteiro de tamanho `k + 1`, inicializado por todo zero
    int freq[k + 1];
    memset(freq, 0, sizeof(freq));
 
    // 1. Usando o valor de cada item na matriz de entrada como um �ndice,
     // armazena a contagem de cada inteiro em `freq []`
    for (int i = 0; i < n; i++) {
        freq[elementos[i]]++;
    }
 
    /// 2. Calcule o �ndice inicial para cada n�mero inteiro
    int total = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int oldCount = freq[i];
        freq[i] = total;
        total += oldCount;
    }
 
    // 3. Copie para a matriz de sa�da, preservando a ordem das entradas com chaves iguais
    for (int i = 0; i < n; i++)
    {
        output[freq[elementos[i]]] = elementos[i];
        freq[elementos[i]]++;
    }
 
    // copia o array de sa�da de volta para o array de entrada
    for (int i = 0; i < n; i++) {
        elementos[i] = output[i];
    }
    
   
}

int main()
{
	long int i, vet10[10000], vet50[50000], vet90[90000], elem; 
 	int TAM10 = 10000, TAM50 = 50000, TAM90 = 90000, k = 99999, escolha = 0;
 	double tempo;
	long int *countsortArray;
 	countsortArray = (long int *)malloc(sizeof(long int)*90000);
 	time_t t_ini, t_fim;
 	
 	FILE *fptr10;
 	FILE *fptr50;
 	FILE *fptr90;
 	FILE *fptrB10;
 	FILE *fptrB50;
 	FILE *fptrB90;
 	FILE *fptrQ10;
 	FILE *fptrQ50;
 	FILE *fptrQ90;
 	FILE *fptrC10;
 	FILE *fptrC50;
 	FILE *fptrC90;
 	
 	fptr10 = fopen("10", "w");
 	fptr50 = fopen("50", "w");
 	fptr90 = fopen("90", "w");
 	
 	
 	printf("Preenchimento para 10.000 elementos\n");
	for (int cont= 0; cont < 10000; cont++) {
		elem = rand() % 99999;
		fprintf(fptr10,"  %d  ", elem);
    }
    
    printf("Preenchimento para 50.000 elementos\n");
	for (int cont= 0; cont < 50000; cont++) {
		elem = rand() % 99999;
		fprintf(fptr50,"  %d  ", elem);
    }
    
    printf("Preenchimento para 90.000 elementos\n");
	for (int cont= 0; cont < 90000; cont++) {
		elem = rand() % 99999;
		fprintf(fptr90,"  %d  ", elem);
    }
 	
	//Abre os arquivos e caso n�o seja possivel informa erro
   if ((fptr10 = fopen("10","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
   
   //Pega os valores do arquivo 
	for(int cont = 0; cont < TAM10; cont++){
   		fscanf(fptr10,"%d", &vet10[cont]);	
   }
   
   fclose(fptr10); 
 	
// 	for(int cont = 0; cont < 10000; cont++){
// 		printf(" %d ", vet10[cont]);
//	 }
 	
   if ((fptr50 = fopen("50","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	for(int cont = 0; cont < TAM50; cont++){
   		fscanf(fptr50,"%d", &vet50[cont]);	
   }
   
   fclose(fptr50); 
   
   
   if ((fptr90 = fopen("90","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	for(int cont = 0; cont < TAM90; cont++){
   		fscanf(fptr90,"%d", &vet90[cont]);	
   }
   
   fclose(fptr90); 
 	
	
	while(escolha != 4){
		
		printf("\nEscolha a opcao desejada: \n1-BubbleSort \n2-QuickSort \n3-CountingSort \n4-Sair \n\n->");
		scanf("%d", &escolha);
			
		if(escolha == 1){
			for(int iteration = 0; iteration < 2; iteration++){
				
				clock_t begin10B = clock(); //Inicia a contagem do tempo.

				bubblesort(vet10, TAM10);
				
				clock_t end10B = clock();; //Pega o tempo após a execução do algoritmo
				double time_spent10B = (double)(end10B - begin10B) / CLOCKS_PER_SEC;
				
				printf("%f in ms.\n", time_spent10B);
				
				

				clock_t begin50B = clock();

				bubblesort(vet50, TAM50);

				clock_t end50B = clock();; //Pega o tempo após a execução do algoritmo
				double time_spent50B = (double)(end50B - begin50B) / CLOCKS_PER_SEC;
				printf("%f in ms.\n", time_spent50B);	
				
				
				clock_t begin90B = clock();

				bubblesort(vet90, TAM90);
				
				clock_t end90B = clock();; //Pega o tempo após a execução do algoritmo
				double time_spent90B = (double)(end90B - begin90B) / CLOCKS_PER_SEC;
				printf("%f in ms.\n", time_spent90B);	
			}


			
			fptrB10 = fopen("B10", "w");
			fptrB50 = fopen("B50", "w");
			fptrB90 = fopen("B90", "w");
			
			
			for (int cont= 0; cont < 10000; cont++) {
				fprintf(fptrB10,"  %d  ", vet10[cont]);
    		}
    		
    		for (int cont= 0; cont < 50000; cont++) {
				fprintf(fptrB50,"  %d  ", vet50[cont]);
    		}
    		
    		for (int cont= 0; cont < 90000; cont++) {
				fprintf(fptrB90,"  %d  ", vet90[cont]);
    		}
			
    		
			
		}
		else if(escolha == 2){
			
			clock_t begin10Q = clock();
			quick_sort(vet10, 0, TAM10 - 1);

			clock_t end10Q = clock();; //Pega o tempo após a execução do algoritmo
			double time_spent10Q = (double)(end10Q - begin10Q) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spent10Q);	
			


			clock_t begin50Q = clock();
			quick_sort(vet50, 0, TAM50 - 1);

			clock_t end50Q = clock();; //Pega o tempo após a execução do algoritmo
			double time_spent50Q = (double)(end50Q - begin50Q) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spent50Q);	
			

			
			clock_t begin90Q = clock();
			quick_sort(vet90, 0, TAM90 - 1);

			clock_t end90Q = clock();; //Pega o tempo após a execução do algoritmo
			double time_spend90Q = (double)(end90Q - begin90Q) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spend90Q);	
			

			fptrQ10 = fopen("Q10", "w");
			fptrQ50 = fopen("Q50", "w");
			fptrQ90 = fopen("Q90", "w");
			
			for (int cont= 0; cont < 10000; cont++) {
				fprintf(fptrQ10,"  %d  ", vet10[cont]);
    		}
    		
    		for (int cont= 0; cont < 50000; cont++) {
				fprintf(fptrQ50,"  %d  ", vet50[cont]);
    		}
    		
    		for (int cont= 0; cont < 90000; cont++) {
				fprintf(fptrQ90,"  %d  ", vet90[cont]);
    		}
			
		}
	
		else if(escolha == 3){

			clock_t begin10C = clock();
			countsort(countsortArray, TAM10, k);

			clock_t end10C = clock();; //Pega o tempo após a execução do algoritmo
			double time_spend10C = (double)(end10C - begin10C) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spend10C);	
			
			
			clock_t begin50C = clock();
			countsort(vet50, TAM50, k);
			clock_t end50C = clock();; //Pega o tempo após a execução do algoritmo
			double time_spend50C = (double)(end50C - begin50C) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spend50C);	
			
			
			clock_t begin90C = clock();
			countsort(countsortArray, TAM90, k);
			clock_t end90C = clock();; //Pega o tempo após a execução do algoritmo
			double time_spend90C = (double)(end90C - begin90C) / CLOCKS_PER_SEC;
			printf("%f in ms.\n", time_spend90C);	
			
						
			fptrC10 = fopen("C10", "w");
			fptrC50 = fopen("C50", "w");
			fptrC90 = fopen("C90", "w");
			
			for (int cont= 0; cont < 10000; cont++) {
				fprintf(fptrC10,"  %d  ", vet10[cont]);
    		}
    		
    		for (int cont= 0; cont < 50000; cont++) {
				fprintf(fptrC50,"  %d  ", vet50[cont]);
    		}
    		
    		for (int cont= 0; cont < 90000; cont++) {
				fprintf(fptrC90,"  %d  ", vet90[cont]);
    		}
		}
	}
	


	fclose(fptrB10); 
	fclose(fptrB50); 
	fclose(fptrB90); 
	fclose(fptrQ10); 
	fclose(fptrQ50); 
	fclose(fptrQ90);
	fclose(fptrC10); 
	fclose(fptrC50); 
	fclose(fptrC90); 
	
 	printf("- - - - - - - - - - - FIM - - - - - - - - - - -\n");
 	
 	system("pause");
 	return 0;
}
