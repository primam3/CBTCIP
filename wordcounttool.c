#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include<string.h>

int main(){
    FILE *file;
    char filename[100];
    char ch;
    int wordCount = 0, lineCount = 1, charCount = 0;
    printf("Enter the file name: ");
    scanf("%s", filename);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("\nError opening file.Please make sure the file exists.");
        return 0;
    }
    while ((ch = fgetc(file)) != EOF) 
    {
        charCount++;
        if (ch == '\n') 
        {
            lineCount++;
        }
          if (isspace(ch))  
        {
            wordCount++;
        }
    }
    fclose(file);
    if (charCount > 0) {
        wordCount++;
    }
     printf("\nTotal words:%d", wordCount);
    printf("\nTotal lines:%d", lineCount);
    printf("\nTotal characters:%d", charCount);
    return 0;
}