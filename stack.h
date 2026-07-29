//
// Created by megat on 7/29/2026.
//

#ifndef CHIP8EMULATOR_STACK_H
#define CHIP8EMULATOR_STACK_H

// Stack implementation for C from https://www.geeksforgeeks.org/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Define the maximim capacity of the stack
#define MAX_SIZE 16

// Define a structure for the stack
typedef struct {
    uint16_t arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *stack);

// Function to check if the stack is empty
bool isEmpty(Stack *stack);

// Function to check if the stack is full
bool isFull(Stack *stack);

// Function to push an element onto the stack
void push(Stack *stack, int value);

// Function to pop an element from the stack
int pop(Stack *stack);

// Function to peek the top element of the stack
int peek(Stack *stack);

#endif //CHIP8EMULATOR_STACK_H
