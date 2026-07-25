#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[]) {

    /* 1. Initialize SDL Video Subsystem */
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    /* 2. Create the Window */
    SDL_Window* window = SDL_CreateWindow(
        "My First SDL Window",      /* Window title */
        SDL_WINDOWPOS_CENTERED,     /* X position */
        SDL_WINDOWPOS_CENTERED,     /* Y position */
        800,                        /* Width in pixels */
        600,                        /* Height in pixels */
        SDL_WINDOW_SHOWN            /* Flags */
    );

    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* 3. Set up the Event Loop */
    int running = 1;
    SDL_Event event;

    /* 4. The "Game Loop" */
    while (running) {

        /* Check the event queue for new events */
        while (SDL_PollEvent(&event)) {

            /* If the user clicks the 'X' button on the window */
            if (event.type == SDL_QUIT) {
                running = 0; /* Breaks the loop */
            }
        }

        /*
         * Future code: This is where you will clear the screen,
         * draw your graphics, and update the display.
         */

        /* Give the CPU a tiny break (~60 frames per second) */
        SDL_Delay(16);
    }

    /* 5. Clean up memory and exit */
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}