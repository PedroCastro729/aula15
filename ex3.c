#include <stdio.h>
#include <string.h>

int retangulo(FILE *pArquivo){
    int width, height, x, y;
    printf("Digite a largura do retangulo: ");
    scanf("%d", &width);
    printf("Digite a altura do retangulo: ");
    scanf("%d", &height);
    printf("Digite a coordenada x do retangulo: ");
    scanf("%d", &x);
    printf("Digite a coordenada y do retangulo: ");
    scanf("%d", &y);

    fprintf(pArquivo, "<rect width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" style=\"fill:\"red\"/>\n", width, height, x, y);
}

int circulo(FILE *pArquivo){
    int cx, cy, r;
    printf("Digite a coordenada x do centro do circulo: ");
    scanf("%d", &cx);
    printf("Digite a coordenada y do centro do circulo: ");
    scanf("%d", &cy);
    printf("Digite o raio do circulo: ");
    scanf("%d", &r);

    fprintf(pArquivo, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\"/>\n", cx, cy, r);
}

int linha(FILE *pArquivo){
    int x1, y1, x2, y2;
    printf("Digite a coordenada x do inicio da linha: ");
    scanf("%d", &x1);
    printf("Digite a coordenada y do inicio da linha: ");
    scanf("%d", &y1);
    printf("Digite a coordenada x do fim da linha: ");
    scanf("%d", &x2);
    printf("Digite a coordenada y do fim da linha: ");
    scanf("%d", &y2);

    fprintf(pArquivo, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\"/>\n", x1, y1, x2, y2);
}

int texto(FILE *pArquivo){
    int x, y;
    char texto[100];
    printf("Digite a coordenada x do texto: ");
    scanf("%d", &x);
    printf("Digite a coordenada y do texto: ");
    scanf("%d", &y);
    getchar();
    fgets(texto, 100, stdin);

    fprintf(pArquivo, "<text x=\"%d\" y=\"%d\">%s</text>\n", x, y, texto);
}


int main(void){
    char nome[100];
    char opcao;
    
    printf("Digite o nome do arquivo svg: ");
    scanf("%s", nome);
    strcat(nome, ".svg");


    FILE *pArquivo = fopen(nome, "w");
    pArquivo = fopen(nome, "w");

    fprintf(pArquivo, "<svg version=\"1.1\" width=\"300\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">");

    if(pArquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
    } else{
        do {
            printf("Escolha uma opcao: 1 - Retangulo, 2 - Circulo, 3 - Linha, 4 - Texto, F - Sair\n");
            scanf(" %c", &opcao);

            switch (opcao){
                case '1':
                    retangulo(pArquivo);
                    break;
                case '2':
                    circulo(pArquivo);
                    break;
                case '3':
                    linha(pArquivo);
                    break;
                case '4':
                    texto(pArquivo);
                    break;
                case 'f':
                    break;
                case 'F':
                    break;

                default:
                    printf("Opcao invalida\n");
                    break;
        }
    } while (opcao != 'f' && opcao != 'F');
    }

    fprintf(pArquivo, "</svg>");
    fclose(pArquivo);

    return 0;
}
