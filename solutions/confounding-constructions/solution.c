#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
    int width;
    struct Node *next;
} Node;

int main(void) {
    // Note that in this solution, the head represents the top
    // of the tower! This makes it easier to remove layers later.
    Node *head = NULL;
    int current_width = 0;
    int current_layers = 0;

    int max_layers;
    scanf("%d", &max_layers);

    int counter = 0;
    int new_width;
    while (counter < max_layers) {
        scanf("%d", &new_width);

        // Keep removing the head (i.e. top) of the linked list while
        // new_width is greater than the average current width.
        //
        // We multiply both sides by current_layers to avoid decimals.
        while (current_layers * new_width > current_width) {
            current_width -= head->width;
            current_layers--;
            head = head->next;
        }
        
        // Add new layer to the head of the list (i.e. top of the tower)
        Node *new_node = malloc(sizeof (Node));
        new_node->width = new_width;
        new_node->next = head;
        head = new_node;
        current_width += new_width;
        current_layers++;

        counter++;
    }

    printf("%d\n", current_layers);
}
