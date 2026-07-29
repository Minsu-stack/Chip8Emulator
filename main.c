#include <stdio.h>
#include <SDL.h>
#include "chip8.h"
#include "stack.h"

int main(int argc, char* argv[]) {

    initialize(&chip8.stack);

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
        640,                        /* Width in pixels */
        320,                        /* Height in pixels */
        SDL_WINDOW_SHOWN            /* Flags */
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /* 3. Set up the Event Loop */
    int running = 1;
    SDL_Event event;

    const Uint32 frame_ms = 1000 / 60;  // 16 ms

    int x = 0;

    while (running) {
        Uint32 frame_start = SDL_GetTicks();


        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Update game state and render here
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < 64; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                if (chip8.display[i][j] == true)
                {
                    SDL_Rect rect;
                    rect.x = i * 10;   // X-coordinate of top-left corner
                    rect.y = j * 10;   // Y-coordinate of top-left corner
                    rect.w = 10;  // Width in pixels
                    rect.h = 10;  // Height in pixels
                    SDL_RenderFillRect(renderer, &rect);

                }

            }
        }
        SDL_RenderPresent(renderer);

        Uint32 elapsed = SDL_GetTicks() - frame_start;

        if (elapsed < frame_ms) {
            SDL_Delay(frame_ms - elapsed);
        }
    }

    /* 5. Clean up memory and exit */
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}