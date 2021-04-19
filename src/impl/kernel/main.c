#include "print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_PINK, PRINT_COLOR_BLACK);
    print_str("\n-------------------------------------------------\n");
    print_str("\nWelcome to our 64-bit kernel!\n");
    print_str("\n-------------------------------------------------\n");

    print_str("\n Printing Nust Text Using Astericks : \n\n");          
    nusttext();
}