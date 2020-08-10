//
// Created by forol on 10/08/2020.
//

#include <stdio.h>

#ifndef LDB_PARSER_H
#define LDB_PARSER_H

typedef struct {
    char* buffer;
    // size_t for positive values size in bytes
    size_t bufferLength;
    // ssize_t for negative values
    ssize_t inputLength;
} InputBuffer;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED,
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT,
} PrepareResult;

// type of statements
typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType;

// struct to statement containing the type, etc..
typedef struct {
    StatementType type;
} Statement;


MetaCommandResult MetaCommand(InputBuffer* inputBuffer);

#endif //LDB_PARSER_H
