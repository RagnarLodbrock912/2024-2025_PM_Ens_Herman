#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_WORD_LENGTH 50

// Функция для поиска возможных направлений для слова
void checkWordLocating(int height, int width, int wordLength, int i, int j, int wordChecker[8]) {
    if(i - (wordLength - 1) >= 0) // вверх
        wordChecker[0]++;
    if(i - (wordLength - 1) >= 0 && j + (wordLength - 1) <= width) // по диагонали вверх вправо
        wordChecker[1]++;
    if(j + (wordLength - 1) <= width) // вправо
        wordChecker[2]++;
    if(i + (wordLength - 1) <= height && j + (wordLength - 1) <= width) // по диагонали вниз вправо
        wordChecker[3]++;
    if(i + (wordLength - 1) <= height) // вниз
        wordChecker[4]++;
    if(i + (wordLength - 1) <= height && j - (wordLength - 1) >= 0) // по диагонали вниз влево
        wordChecker[5]++;
    if(j - (wordLength - 1) >= 0) // влево
        wordChecker[6]++;
    if(i - (wordLength - 1) >= 0 && j - (wordLength - 1) >= 0) // по диагонали вверх влево
        wordChecker[7]++;       
}

// Функция для проверки слова в тексте
void checkWordInText(int i, int j, int wordChecker[8], int wordLength, char *word, char text[][MAX_COLS]) {
    // Вверх
    for(int k = i, m = 0; (m < wordLength ) && (wordChecker[0] != 0); k--, m++) {
        if(word[m] != text[k][j]) {
            wordChecker[0] = 0;
            break;
        }    
    }
    // По диагонали вверх вправо
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[1] != 0); k--, l++, m++) {
        if(word[m] != text[k][l]) {
            wordChecker[1] = 0;
            break;
        }    
    }
    // Вправо
    for(int l = j, m = 0; (m < wordLength) && (wordChecker[2] != 0); l++, m++) {
        if(word[m] != text[i][l]) {
            wordChecker[2] = 0;
            break;
        }    
    }
    // По диагонали вниз вправо
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[3] != 0); k++, l++, m++) {
        if(word[m] != text[k][l]) {
            wordChecker[3] = 0;
            break;
        }    
    }
    // Вниз
    for(int k = i, m = 0; (m < wordLength) && (wordChecker[4] != 0); k++, m++) {
        if(word[m] != text[k][j]) {
            wordChecker[4] = 0;
            break;
        }    
    }
    // По диагонали вниз влево
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[5] != 0); k++, l--, m++) {
        if(word[m] != text[k][l]) {
            wordChecker[5] = 0;
            break;
        }    
    }
    // Влево
    for(int l = j, m = 0; (m < wordLength) && (wordChecker[6] != 0); l--, m++) {
        if(word[m] != text[i][l]) {
            wordChecker[6] = 0;
            break;
        }    
    }
    // По диагонали вверх влево
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[7] != 0); k--, l--, m++) {
        if(word[m] != text[k][l]) {
            wordChecker[7] = 0;
            break;
        }    
    }
}


// Функция для замены найденных слов в ответе
void replaceLettersInText(int i, int j, int wordChecker[8], char answerText[][MAX_COLS], int wordLength) {
    // Вверх
    for(int k = i, m = 0; (m < wordLength ) && (wordChecker[0] != 0); k--, m++) {
        answerText[k][j] = '-';
    }
    // По диагонали вверх вправо
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[1] != 0); k--, l++, m++) {
        answerText[k][l] = '-';   
    }
    // Вправо
    for(int l = j, m = 0; (m < wordLength) && (wordChecker[2] != 0); l++, m++) {
        answerText[i][l] = '-';    
    }
    // По диагонали вниз вправо
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[3] != 0); k++, l++, m++) {
        answerText[k][l] = '-';    
    }
    // Вниз
    for(int k = i, m = 0; (m < wordLength) && (wordChecker[4] != 0); k++, m++) {
        answerText[k][j] = '-';    
    }
    // По диагонали вниз влево
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[5] != 0); k++, l--, m++) {
        answerText[k][l] = '-';    
    }
    // Влево
    for(int l = j, m = 0; (m < wordLength) && (wordChecker[6] != 0); l--, m++) {
        answerText[i][l] = '-';  
    }
    // По диагонали вверх влево
    for(int k = i, l = j, m = 0; (m < wordLength) && (wordChecker[7] != 0); k--, l--, m++) {
        answerText[k][l] = '-';  
    }
}

int main() {
    int height = 0, width = 0;
    char text[MAX_ROWS][MAX_COLS], answerText[MAX_ROWS][MAX_COLS];

    printf("Osmismerka:\n");
    char line[MAX_COLS + 1];

    while (fgets(line, sizeof(line), stdin) && line[0] != '\n') {
        line[strcspn(line, "\n")] = 0;
        if (height == 0) {
            width = strlen(line);
        } else if ((size_t)strlen(line) != (size_t)width) {
            printf("Nespravny vstup.\n");
            return 0;
        }
        strcpy(text[height], line);
        strcpy(answerText[height], line);
        height++;
    }

    fgets(line, sizeof(line), stdin);

    char command[MAX_WORD_LENGTH + 10];
    while (fgets(command, sizeof(command), stdin)) {
        command[strcspn(command, "\n")] = 0;

        if (strlen(command) == 0 || command[0] == '\n') {
            printf("Nespravny vstup.\n");
            continue;
        }

        if (command[0] == '?') {
            printf("Tajenka:\n");
            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if(answerText[i][j] != '-'){
                        printf("%c", answerText[i][j]);
                    }
                }
            }
        }
                else if (command[0] == '-' || command[0] == '#') {
            char word[MAX_WORD_LENGTH];
            char *trimmed_command = command + 1;

            while (*trimmed_command == ' ') {
                trimmed_command++;
            }

            if (sscanf(trimmed_command, "%s", word) != 1) {
                printf("Nespravny vstup.\n");
                continue;
            }

            int wordLength = strlen(word);
            int count = 0;

            for (int i = 0; i < height; i++) {
                for (int j = 0; j < width; j++) {
                    if (word[0] == text[i][j]) {
                        int wordChecker[8] = {0, 0, 0, 0, 0, 0, 0, 0};
                        checkWordLocating(height, width, wordLength, i, j, wordChecker);
                        checkWordInText(i, j, wordChecker, wordLength, word, text);
                        replaceLettersInText(i, j, wordChecker, answerText, wordLength);

                        for (int k = 0; k < 8; k++) {
                            if (wordChecker[k] != 0) {
                                count++;
                            }
                        }
                    }
                }
            }

            if (count == 0) {
                printf("%s: 0x\n", word);
            } else {
                printf("%s: %dx\n", word, count);
            }
        } else {
            printf("Nespravny vstup.\n");
        }
    }

    return 0;
}
