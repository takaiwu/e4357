#include "mbed.h"

DigitalOut ptr(p9);

int main() {
    while(1) {
        ptr = 1;
        //wait(0.2);
        ptr = 0;
        //wait(0.2);
    }
}
