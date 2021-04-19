#include "print.h"

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;

//maintaning col and row sizes
size_t col = 0;
size_t row = 0;
//maintaning the colors
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4;

void clear_row(size_t row) {
    struct Char empty = (struct Char) {
        character: ' ',
        color: color,
    };

    for (size_t col = 0; col < NUM_COLS; col++) {
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear() {
    for (size_t i = 0; i < NUM_ROWS; i++) {
        clear_row(i);
    }
}

void print_newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        print_newline();
        return;
    }

    if (col > NUM_COLS) {
        print_newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        print_char(character);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}

// Number of lines for the alphabet's pattern
int height = 5;
// Number of character width in each line
int width = (2 * 5) - 1;

// Function to print the pattern of 'N'
void printN()
{
    int i, j, counter = 0;
    for (i = 0; i < height; i++) {
        print_str("#");
        for (j = 0; j <= height; j++) {
            if (j == height)
                print_str("#");
            else if (j == counter)
                print_str("#");
            else
                 print_str(" ");
        }
        counter++;
       print_str("\n");
    }
}

 // Function to print the pattern of 'U'
void printU()
{
    int i, j;
    for (i = 0; i < height; i++) {
        if (i != 0 && i != height - 1)
           print_str("*");
        else
           print_str(" ");
        for (j = 0; j < height; j++) {
            if (((i == height - 1)
                 && j >= 0
                 && j < height - 1))
               print_str("#");
            else if (j == height - 1 && i != 0
                     && i != height - 1)
                print_str("#");
            else
               print_str(" ");
        }
        print_str("\n");
    }
}

// Function to print the pattern of 'S'
void printS()
{
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if ((i == 0 || i == height / 2
                 || i == height - 1))
                print_str("#");
            else if (i < height / 2
                     && j == 0)
                print_str("#");
            else if (i > height / 2
                     && j == height - 1)
               print_str("#");
            else
               print_str(" ");
        }
       print_str("\n");
    }
}
  
// Function to print the pattern of 'T'
void printT()
{
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < height; j++) {
            if (i == 0)
                print_str("#");
            else if (j == height / 2)
               print_str("#");
            else
                 print_str(" ");
        }
         print_str("\n");
    }
}

//function to print nust text 
void nusttext(){
    print_str("*****         ***   ****          ****   *************   *************\n");   
    print_str("** ***        ***   ****          ****   *************   *************\n"); 
    print_str("**   ***      ***   ****          ****   *****              *****      \n");   
    print_str("**     ***    ***   ****          ****   ****               *****      \n");   
    print_str("**       ***  ***   ****          ****   *************      *****      \n");   
    print_str("**        *** ***   ****          ****            *****     *****      \n");          
    print_str("**          *****   ****          ****            *****     *****      \n");   
    print_str("**           ****   ******************   **************     *****      \n");   
    print_str("**           ****   ******************   **************     *****      \n");   
}