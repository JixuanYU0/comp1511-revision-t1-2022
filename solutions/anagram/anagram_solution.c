// Written by Simon Nguyen from CSESoc Education
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

int check_anagram(char first_word[MAX_SIZE],char second_word[MAX_SIZE]);
void remove_newline(char word[MAX_SIZE]);

int main (void) {
    char first_word[MAX_SIZE];
    char second_word[MAX_SIZE];
    fgets(first_word, MAX_SIZE, stdin);
    fgets(second_word, MAX_SIZE, stdin);
    
    remove_newline(first_word);
    remove_newline(second_word);
    
    int check = check_anagram(first_word, second_word);
    
    if (check == 1) {
        printf("These two words are an anagram! \n");
    } else {
        printf("These two words are not an anagram! \n");
    }
    
    return 0;
    
}

//Function to remove newline from end of string
void remove_newline(char word[MAX_SIZE]) {
    //Replacing newline character with null terminating character
    int len = strlen(word) - 1;
    word[len] = '\0';
    //Note indexing of array starts at 0. 
}

//Function to check if 2 strings are anagrams. 
int check_anagram(char first_word[MAX_SIZE], ch 

  //Creating 2 arrays (1 for each string) to store the frequency of 
  //characters in each string

  int alpha_first[26] = {0};
  int alpha_second[26] = {0};
  int i = 0;

  //Calculating frequency of characters in both words

  while (i < strlen(first_word)) {
    alpha_first[first_word[i] - 'a']++;
    i++;
   }

  i = 0;

  while (i < strlen(second_word)) {
    alpha_second[second_word[i] - 'a']++;
    i++;
   }

  //Comparing frequency of characters in both words 

  i = 0;
  
  while (i < 26) {
    if (alpha_first[i] != alpha_second[i]) {
        return 0;
    } else {
        i++;
    }
  }
  
  return 1;
}