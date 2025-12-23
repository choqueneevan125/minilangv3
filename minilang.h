#ifndef MINILANG_H
#define MINILANG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "version.h"

// ============================================================================
// TYPES ET STRUCTURES
// ============================================================================

// Types de tokens
typedef enum {
    TOKEN_INT, TOKEN_FLOAT, TOKEN_STR, TOKEN_VOID,
    TOKEN_IDENTIFIER, TOKEN_NUMBER, TOKEN_STRING,
    TOKEN_ASSIGN, TOKEN_PRINT, TOKEN_LPAREN, TOKEN_RPAREN,
    TOKEN_SEMICOLON, TOKEN_EOF, TOKEN_COMMA,
    TOKEN_PLUS, TOKEN_MINUS, TOKEN_MULT, TOKEN_DIV, TOKEN_MOD,
    TOKEN_EQ, TOKEN_NEQ, TOKEN_LT, TOKEN_GT, TOKEN_LTE, TOKEN_GTE,
    TOKEN_AND, TOKEN_OR, TOKEN_NOT,
    TOKEN_IF, TOKEN_ELSE, TOKEN_WHILE, TOKEN_FOR,
    TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_LBRACKET, TOKEN_RBRACKET,
    TOKEN_FUNC, TOKEN_RETURN
} TokenType;

// Structure Token
typedef struct {
    TokenType type;
    char *value;
    int line;
} Token;

// Types de variables
typedef enum {
    VAR_INT, VAR_FLOAT, VAR_STRING, VAR_ARRAY, VAR_VOID
} VarType;

// Structure pour tableaux
typedef struct {
    int *int_array;
    float *float_array;
    char **str_array;
    int size;
    VarType elem_type;
} Array;

// Structure Variable
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
    Param *params;
    int param_count;
    VarType return_type;
    int body_start;
    int body_end;
    struct Function *next;
} Function;

// Stack pour les scopes de variables
typedef struct VarScope {
    Variable *vars;
    struct VarScope *parent;
} VarScope;

// Structure pour les valeurs de retour
typedef struct {
    bool has_return;
    ExprResult value;
} ReturnValue;

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

// ============================================================================
// PROTOTYPES - LEXER
// ============================================================================

void lexer(const char *source);
Token create_token(TokenType type, const char *value, int line);

// ============================================================================
// PROTOTYPES - PARSER
// ============================================================================

void parser();
void parse_statement();
void parse_block();
void parse_function_declaration();
ExprResult call_function(const char *func_name);

// ============================================================================
// PROTOTYPES - EVALUATOR
// ============================================================================

ExprResult evaluate_expression();
ExprResult evaluate_comparison();
ExprResult evaluate_logical();
ExprResult parse_term();
ExprResult parse_factor();
bool is_true(ExprResult result);

// ============================================================================
// PROTOTYPES - SYMBOLES (Variables et Fonctions)
// ============================================================================

Variable *find_variable(const char *name);
void add_variable(const char *name, VarType type);
Function *find_function(const char *name);
void add_function(Function *func);
void push_scope();
void pop_scope();

// ============================================================================
// PROTOTYPES - UTILITAIRES
// ============================================================================

void free_tokens();
void free_variables();
void free_functions();
const char *type_to_string(VarType type);
void print_error(const char *message, int line);

#endif // MINILANG_H
