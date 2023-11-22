#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "utils.h"

#define LINE_MAX_SIZE   100
#define WORD_SIZE       5
#define DICO_SIZE       6973

bool filterDico(char filepath[], size_t size) {
    FILE* in = fopen(filepath, "r");
    if (in == NULL) {
        return false;
    }
    FILE* out = fopen("dico_filtered.txt", "w");
    if (out == NULL) {
        return false;
    }

    while (!feof(in)) {
        char line[LINE_MAX_SIZE];
        fscanf(in, "%s", line);
        if (strlen(line) == size) {
            fprintf(out, "%s\n", line);
        }
    }

    fclose(in);
    fclose(out);
    return true;
}

bool wordMatch(char* word, char* pattern, char* patternWord) {
    
    char wordCopy[WORD_SIZE];
    strcpy(wordCopy, word);

    // printf("%s\n", wordCopy);

    for (int i = 0; i < WORD_SIZE; i++) {
        if (pattern[i] == 'v') {
            if (wordCopy[i] != patternWord[i]) {
                return false;
            }
            wordCopy[i] = '-';
        }
        
    }

    // printf("%s\n", wordCopy);

    for (int i = 0; i < WORD_SIZE; i++) {
        if (pattern[i] == 'g' 
        && char_in_str(wordCopy, patternWord[i]) != -1) {
            return false;
        }
        
        if (pattern[i] == 'j') {
            const int k = char_in_str(wordCopy, patternWord[i]);
            if (k == -1) {
                return false;
            }
            wordCopy[k] = '-';
        }
        
    }

    return true;
}

int matchingWordsCount(char* patternWord, char* pattern, char** dico, int dicoSize) {
    int count = 0;
    for (int i = 0; i < dicoSize; i++) {
        if (wordMatch(dico[i], pattern, patternWord)) {
            count++;
        }
    }
    return count;
}

void loadDico(char* filepath, char*** dico) {
    *dico = malloc(DICO_SIZE * sizeof(char*));

    FILE* in = fopen(filepath, "r");
    if (in == NULL) {
        exit(1);
    }

    for (int i = 0; i < DICO_SIZE; i++) {
        (*dico)[i] = malloc(5 * sizeof(char));
        // printf("%s\n", dico[i]);
        fscanf(in, "%s", (*dico)[i]);
    } 

    fclose(in);
}

int main(void) {

    // printf("%d\n", wordMatch("RATIE", "jvjvv", "TARIE"));

    char** dico = NULL;
    loadDico("dico_filtered.txt", &dico);
    if (dico == NULL) {
        printf("Error: cannot load dico\n");
        return 1;
    }
    int c = matchingWordsCount("TARIE", "vvvvg", dico, DICO_SIZE);
    printf("Count: %d\n", c);

    // printf("%s\n", filterDico("dico.txt", WORD_SIZE) ? "Done!" : "An error occurred");
}