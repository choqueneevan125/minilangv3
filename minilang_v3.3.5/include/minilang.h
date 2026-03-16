#ifndef MINILANG_H
#define MINILANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "version.h"

// ============================================================================
// TYPES ET STRUCTURES
// ============================================================================

// Types de tokens
typedef enum {
    TOKEN_INT, TOKEN_FLOAT, TOKEN_STR, TOKEN_VOID, TOKEN_BOOL,
    TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_STRING,
    TOKEN_ASSIGN, TOKEN_PRINT, TOKEN_INPUT, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_SEMICOLON, TOKEN_EOF, TOKEN_COMMA,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_MULT, TOKEN_DIV, TOKEN_MOD,
    TOKEN_PLUS_ASSIGN, TOKEN_MINUS_ASSIGN, TOKEN_MULT_ASSIGN, TOKEN_DIV_ASSIGN,
    TOKEN_EQ, TOKEN_NEQ, TOKEN_LT, TOKEN_GT, TOKEN_LTE, TOKEN_GTE,
    TOKEN_AND, TOKEN_OR, TOKEN_NOT,
    TOKEN_IF, TOKEN_ELSE, TOKEN_WHILE, TOKEN_FOR,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_LBRACKET, TOKEN_RBRACKET,
    TOKEN_FUNC, TOKEN_RETURN, TOKEN_BREAK, TOKEN_CONTINUE,
    TOKEN_TRUE, TOKEN_FALSE,
    TOKEN_CONCAT
} TokenType;

// Types de variables
typedef enum {
    VAR_INT, VAR_FLOAT, VAR_STRING, VAR_ARRAY, VAR_VOID, VAR_BOOL
} VarType;

// Structure d'un token
typedef struct {
    TokenType type;
    char *value;
    int line;
} Token;

// Structure pour les tableaux
typedef struct {
    int size;
    VarType elem_type;
    int *int_array;
    float *float_array;
} Array;

// Structure d'une variable
typedef struct Variable {
    char *name;
    VarType type;
    union {
        int int_val;
        float float_val;
        char *str_val;
        Array array_val;
    } value;
    struct Variable *next;
} Variable;

// Structure pour les résultats d'expressions
typedef struct {
    VarType type;
    union {
        int int_val;
        float float_val;
        char *str_val;
    } value;
} ExprResult;

// Structure pour les paramètres de fonction
typedef struct Param {
    char *name;
    VarType type;
    struct Param *next;
} Param;

// Structure pour les fonctions
typedef struct Function {
    char *name;
    VarType return_type;
    Param *params;
    int param_count;
    int body_start;
    int body_end;
    struct Function *next;
} Function;

// Structure pour les scopes
typedef struct VarScope {
    Variable *vars;
    struct VarScope *parent;
} VarScope;

// Structure pour les valeurs de retour
typedef struct {
    bool has_return;
    ExprResult value;
} ReturnValue;

// Flags de contrôle de flux
typedef struct {
    bool break_flag;
    bool continue_flag;
} ControlFlow;

// ============================================================================
// VARIABLES GLOBALES
// ============================================================================

extern Variable *variables;
extern Function *functions;
extern Token *tokens;
extern int token_count;
extern int current_token;
extern int current_line;
extern VarScope *current_scope;
extern ReturnValue return_value;
extern ControlFlow control_flow;

// ============================================================================
// PROTOTYPES - LEXER
// ============================================================================

void lexer(const char *source);
void free_tokens();

// ============================================================================
// PROTOTYPES - PARSER
// ============================================================================

void parser();
void parse_statement();
void parse_block();
void parse_function_declaration();
ExprResult call_function(const char *func_name);
char *concat_strings(const char *s1, const char *s2);
char *value_to_string(ExprResult result);

// ============================================================================
// PROTOTYPES - EVALUATOR
// ============================================================================

ExprResult evaluate_logical();
ExprResult evaluate_comparison();
ExprResult evaluate_expression();
ExprResult parse_term();
ExprResult parse_factor();
bool is_true(ExprResult result);

// ============================================================================
// PROTOTYPES - SYMBOLS
// ============================================================================

void add_variable(const char *name, VarType type);
Variable *find_variable(const char *name);
void free_variables();

void add_function(Function *func);
Function *find_function(const char *name);
void free_functions();

void push_scope();
void pop_scope();

// ============================================================================
// PROTOTYPES - UTILS
// ============================================================================

void print_error(const char *message, int line);

#endif // MINILANG_H
