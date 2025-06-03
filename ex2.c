#include <stdio.h>
#include <string.h>

int main(void){
    char nome[50];
    float x, y, width, height;

    printf("Digite o nome do arquivo: ");
    scanf("%49s", nome);
    strcat(nome, ".svg");

    printf("Digite a largura: ");
    scanf("%f", &width);

    printf("Digite a altura: ");
    scanf("%f", &height);

    printf("Digite o valor de x: ");
    scanf("%f", &x);

    printf("Digite o valor de y: ");
    scanf("%f", &y);

    FILE *pQuadrado = fopen(nome, "w");
    pQuadrado = fopen(nome, "w");

    if(pQuadrado == NULL){
        printf("Erro ao abrir o arquivo\n");
    } else{
        fprintf(pQuadrado, "<svg version=\"1.1\"\n width=\"300\" height=\"200\"\n xmlns=\"http://www.w3.org/2000/svg\">\n <rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" fill=\"red\" />\n</svg>\n", x, y, width, height);
        fclose(pQuadrado);
    }
    
    return 0;
}
