#include "Interface.h"

void play(Interface& interface) {
    char c = '\0';
    while(c != 'x') {
        c = getch();

    }
}

int main() {
    Interface interface;
    interface.displayInit();
    play(interface);

    return 0;
}