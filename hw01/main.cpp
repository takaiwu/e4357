#include "mbed.h"

DigitalOut ptr(p9);

int main() {
    while(1) {
        ptr = 1;
        ptr = 0;
    }
}
