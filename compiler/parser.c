//
// Created by forol on 10/08/2020.
//

#include <string.h>
#include <stdlib.h>
#include "parser.h"

MetaCommandResult MetaCommand(InputBuffer* inputBuffer)
{
    if (strcmp(inputBuffer->buffer, ".exit") != 0)
    {
        return META_COMMAND_UNRECOGNIZED;
    }

    exit(EXIT_SUCCESS);
}