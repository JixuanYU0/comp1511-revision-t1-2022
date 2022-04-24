#include <stdio.h>
#include <stdlib.h>

typedef struct transaction {
  struct transaction *next;
  int id;
  char sender;
  int amount;
} Transaction;

void freeList(Transaction *head) {
  Transaction *prev = head;
  while (head != NULL) {
    prev = head;
    head = head->next;
    free(prev);
  }
}

void printTransaction(Transaction *t) {
  if (t == NULL)
    return;
  printf("*** Transaction ***\n");
  printf("id: %d, sender: %c, amount: %d\n", t->id, t->sender, t->amount);
  printf("*******************\n\n");
  printTransaction(t->next);
}

int main(void) {
  Transaction *head = NULL;
  Transaction *curr = NULL;

  int t, r;
  scanf("%d %d", &t, &r);

  for (int i = 0; i < t; i++) {
    int id, amount;
    char sender;
    scanf("%d %d %c", &id, &amount, &sender);

    Transaction *new = malloc(sizeof(Transaction));
    new->amount = amount;
    new->id = id;
    new->sender = sender;
    new->next = NULL;

    if (head == NULL)
      curr = head = new;
    else
      curr = curr->next = new;
  }

  for (int i = 0; i < r; i++) {
    int id;
    scanf("%d", &id);
    curr = head;
    Transaction *prev = curr;
    // If removing from front of list
    if (curr->id == id) {
      head = curr->next;
      free(curr);
      continue;
    }
    while (curr != NULL) {
      if (curr->id == id) {
        prev->next = curr->next;
        free(curr);
        break;
      }
      prev = curr;
      curr = curr->next;
    }
  }

  curr = head;
  int bBalance = 100;
  while (curr != NULL) {
    bBalance += (curr->sender == 'B') ? -curr->amount : curr->amount;
    curr = curr->next;
  }
  printf("%d %d\n", bBalance, 200 - bBalance);
  freeList(head);
}
