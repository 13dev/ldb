#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler/parser.h"

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

    // remove trailing newline \n
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

        if(inputBuffer->buffer[0] == '.')
        {
            switch (MetaCommand(inputBuffer))
            {
                case META_COMMAND_SUCCESS:
                    continue;
                case META_COMMAND_UNRECOGNIZED:
                    printf("Unrecognized command \"%s\".\n", inputBuffer->buffer);
                    continue;

            }
        }

        Statement statement;

        switch (PrepareStatement(inputBuffer, &statement))
        {
            case PREPARE_SUCCESS:
                break;
            case PREPARE_UNRECOGNIZED_STATEMENT:
                printf("Unrecognized keyword at start of \"%s\".\n", inputBuffer->buffer);
                continue;
        }

        ExecuteStatement(&statement);
        printf("Executed. \n");

    }

}
