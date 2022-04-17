// Mocking SpongeBob
// COMP1511 Revision Session (T1, 2022)
// Written by Jeffrey Yao for CSESoc Education

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define TRUE 0

bool check_if_vowel(char *word, int i);

int main(void)
{
    // Read string using fgets.
    char string[MAX_LENGTH];
    fgets(string, MAX_LENGTH, stdin);

    // Iterate over string word-wise.
    // Begin with the first word.
    char *word = strtok(string, " ");

    while (word != NULL)
    {
        bool first_vowel = true;
        int consonant = 0;

        // Iterate over letters in word.
        for (int i = 0; i < strlen(word) && strcmp(&word[i], " ") != 0; i++)
        {
            bool is_vowel = check_if_vowel(word, i);
            if (is_vowel == true && first_vowel)
            {
                // Convert first vowel to uppercase.
                word[i] = toupper(word[i]);
                // First vowel found - switch flag.
                first_vowel = false;
            }
            else if (is_vowel == false)
            {
                consonant++;
                if (consonant == 2)
                {
                    word[i] = toupper(word[i]);
                }
            }
        }
        // Print word.
        printf("%s ", word);
        // Move to next word in string.
        word = strtok(NULL, " ");
    }

    return 0;
}

// Checks if given letter in word is vowel.
bool check_if_vowel(char *word, int i)
{
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o'
        || word[i] == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}