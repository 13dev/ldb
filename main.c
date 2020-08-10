#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* buffer;
    size_t bufferLength;
    ssize_t inputLength;
} InputBuffer;

InputBuffer* NewInputBuffer()
{
    InputBuffer* inputBuffer = (InputBuffer*) malloc(sizeof(InputBuffer));
    inputBuffer->buffer = NULL;
    inputBuffer->bufferLength = 0;
    inputBuffer->inputLength = 0;

    return inputBuffer;
}
void PrintPrompt()
{
    printf("ldb > ");
}

void GetInput(InputBuffer* inputBuffer)
{
    ssize_t bytesRead = getline(&(inputBuffer->buffer), &(inputBuffer->bufferLength), stdin);

    if(bytesRead <= 0)
    {
        printf("Error read input. \n");
        exit(EXIT_FAILURE);
    }

    // remove newline
    inputBuffer->inputLength = bytesRead - 1;
    inputBuffer->buffer[bytesRead - 1] = 0;
}

void CloseInputBuffer(InputBuffer* inputBuffer)
{
    free(inputBuffer->buffer);
    free(inputBuffer);
}

int main(int argc, char* argv[])
{
    InputBuffer* inputBuffer = NewInputBuffer();

    while (true)
    {
        PrintPrompt();
        GetInput(inputBuffer);

        if(strcmp(inputBuffer->buffer, ".exit") == 0)
        {
            CloseInputBuffer(inputBuffer);
            exit(EXIT_SUCCESS);

        }
        else
        {
            printf("Unreconized command \"%s\".\n", inputBuffer->buffer);
        }
    }

}
