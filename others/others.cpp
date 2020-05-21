#include <cstdlib>

// clearWindow() clears the terminal on Windows or Unix Systems
void clearWindow() {
    if(getenv("windir")) {
        system("cls");
    } else {
        system("clear");
    }
}