#include <windows.h>
#include <process.h>
#include <time.h>
#include <stdio.h>

void task1(void *);
int main(int, char**) {
    int ThreadNr;
    int nucleos = 20;

    // Record the start time
    clock_t startTime = clock();

    for (int i = 0; i < nucleos; i++) {
        _beginthread(task1, 0, &ThreadNr);
    }

    while (1) {
        // Check if 5 seconds have passed
        clock_t currentTime = clock();
        if ((currentTime - startTime) >= 20 * CLOCKS_PER_SEC) {
            break;
        }
    }

    return 0;
}

void task1(void *) {
    while (1) {
        clock_t wakeup = clock() + 10;
        while (clock() < wakeup) {}
        Sleep(10);
    }
}
