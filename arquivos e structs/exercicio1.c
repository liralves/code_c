#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 256

void lerStr(char *str, int n, FILE *arq);
int createArchive(char *str);

int main() {
    char string[TAM];
    
    int status = createArchive(string);
    if (status != 0){
        return 1;
    }

    return 0;
}


int createArchive(char *str) {
    
    FILE *arquivo = fopen("teste1.txt", "at");
    if (arquivo == NULL) {
        printf("Erro na abertura.\n");
        return 1;
    } else {
        printf("Abertura realizada.\n");
    }
    
    printf("Digite um texto para salvar no arquivo:\n");
    lerStr(str, TAM, stdin);

    fputs(str, arquivo);
    printf("Texto lido: %s\n", str);

    
    if (!fclose(arquivo)) {
        printf("Arquivo fechado.\n");
    } else {
        printf("Erro ao tentar fechar o arquivo!\n");
        return 1;
    }
    return 0;
}
void lerStr(char *str, int n, FILE *arq) {
    fgets(str, n, arq);
    int len = strlen(str);

    // Remove o '\n' do final
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
