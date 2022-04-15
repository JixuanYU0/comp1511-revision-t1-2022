#include <stdio.h>

void moveToFront(char bookstack[], int day);
void moveToMiddle(char bookstack[], int day);

int main(void) {
    int total;
    scanf("%d", &total);
    char bookstack[total + 1];
    scanf("%s", bookstack);

    int day = total - 1; //subtracted 1 as this is also going to be the index
    while ((day + 1) >  0) {

        //This means there was an even number of books and hence we move the book to the front
        if ((day + 1) % 6 == 0) {
            moveToFront(bookstack, day);
        }
        //this means there was an odd number of books and hcne we move the book to the middle
        else if ((day + 1) % 3 == 0) {
            moveToMiddle(bookstack, day);
        }
        day--; //we are rewinding back our days
    }

    printf("%s\n", bookstack);
}

/**
 * moves a book to the front while shufflling other books up one
 */
void moveToFront(char bookstack[], int day) {
    char temp = bookstack[day];
    int curr = day;
    while (curr != 0) {
        bookstack[curr] = bookstack[curr - 1];
        curr--;
    }
    bookstack[0] = temp;
}

/**
 * moves a book to the middle while shufflling other books up one
 */
void moveToMiddle(char bookstack[], int day) {
    char temp = bookstack[day];
    int middle = (day + 2) / 2;
    int curr = day;
    while (curr != middle - 1) {
        bookstack[curr] = bookstack[curr - 1];
        curr--;
    }
    bookstack[middle - 1] = temp;
}
