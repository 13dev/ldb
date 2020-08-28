//
// Created by 13dev on 10/08/2020.
//

#include <string.h>
#include <stdlib.h>
#include "parser.h"

MetaCommandResult MetaCommand(InputBuffer* inputBuffer)
{
    if (strcmp(inputBuffer->buffer, ".exit") == 0)
    {
        exit(EXIT_SUCCESS);
    }

    return META_COMMAND_UNRECOGNIZED;
}

PrepareResult PrepareStatement(InputBuffer* inputBuffer, Statement* statement)
{
    if(strncmp(inputBuffer->buffer, "insert", 6) == 0)
    {
        statement->type = STATEMENT_INSERT;

        int assignedArgs = sscanf(inputBuffer->buffer, "insert %d %s %s",)

        return PREPARE_SUCCESS;
    }

    if(strcmp(inputBuffer->buffer, "select") == 0)
    {
        statement->type = STATEMENT_SELECT;

        return PREPARE_SUCCESS;
    }

    // i dont understand it :/
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void ExecuteStatement(Statement* statement)
{
    switch (statement->type) {
        case STATEMENT_SELECT:
            printf("select.");
            break;
        case STATEMENT_INSERT:
            printf("insert.");
            break;
    }

}