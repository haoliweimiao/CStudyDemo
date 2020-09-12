#include <stdio.h>

int main(){
    FILE *file;
    char *file_path = "./file.txt";

    file = fopen(file_path, "w+");
    if( file = NULL ){
        printf("open file error");
        return -1;
    }

    char* write_content = "write something to file";
    fwrite(write_content, 1, sizeof(write_content), file);
    fclose(file);


    return 0;
}

