#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc <= 2) {
        printf("Too few arguments!\n");
        exit(-1);
    }
    FILE *fp_in = NULL;
    fp_in = fopen(argv[1], "r");
    FILE *fp_out = NULL;
    fp_out = fopen(argv[2],"w");
    int64_t ch;
    if(fp_in == NULL) {
        printf("%s: File Not Found!\n", argv[1]);
        exit(-1);
    }
    while ((ch = fgetc(fp_in)) != EOF) {
        if(ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        }
        fputc(ch, fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}