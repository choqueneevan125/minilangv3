#include "minilang.h"

// Créer un token
Token create_token(TokenType type, const char *value, int line) {
    Token token;
    token.type = type;
    token.value = strdup(value);
    token.line = line;
    return token;
}

// Lexer - Analyse lexicale avec support des commentaires
void lexer(const char *source) {
    int len = strlen(source);
    int capacity = 100;
    tokens = malloc(capacity * sizeof(Token));
    token_count = 0;
    int line = 1;
    
    int i = 0;
    while (i < len) {
        // Commentaires //
        if (source[i] == '/' && i + 1 < len && source[i + 1] == '/') {
            while (i < len && source[i] != '\n') {
                i++;
            }
            if (i < len && source[i] == '\n') {
                line++;
                i++;
            }
            continue;
        }
        
        // Commentaires /* */
        if (source[i] == '/' && i + 1 < len && source[i + 1] == '*') {
            i += 2;
            while (i + 1 < len && !(source[i] == '*' && source[i + 1] == '/')) {
                if (source[i] == '\n') line++;
                i++;
            }
            i += 2;
            continue;
        }
        
        // Espaces
        if (isspace(source[i])) {
            if (source[i] == '\n') line++;
            i++;
            continue;
        }
        
        // Redimensionner si nécessaire
        if (token_count >= capacity) {
            capacity *= 2;
            tokens = realloc(tokens, capacity * sizeof(Token));
        }
        
        // Mots-clés et identifiants
        if (isalpha(source[i]) || source[i] == '_') {
            int start = i;
            while (i < len && (isalnum(source[i]) || source[i] == '_')) {
                i++;
            }
            char *word = strndup(source + start, i - start);
            
            TokenType type = TOKEN_IDENTIFIER;
            
            if (strcmp(word, "int") == 0) type = TOKEN_INT;
            else if (strcmp(word, "float") == 0) type = TOKEN_FLOAT;
            else if (strcmp(word, "str") == 0) type = TOKEN_STR;
            else if (strcmp(word, "void") == 0) type = TOKEN_VOID;
            else if (strcmp(word, "bool") == 0) type = TOKEN_BOOL;
            else if (strcmp(word, "true") == 0) type = TOKEN_TRUE;
            else if (strcmp(word, "false") == 0) type = TOKEN_FALSE;
            else if (strcmp(word, "print") == 0) type = TOKEN_PRINT;
            else if (strcmp(word, "input") == 0) type = TOKEN_INPUT;
            else if (strcmp(word, "if") == 0) type = TOKEN_IF;
            else if (strcmp(word, "else") == 0) type = TOKEN_ELSE;
            else if (strcmp(word, "while") == 0) type = TOKEN_WHILE;
            else if (strcmp(word, "for") == 0) type = TOKEN_FOR;
            else if (strcmp(word, "func") == 0) type = TOKEN_FUNC;
            else if (strcmp(word, "return") == 0) type = TOKEN_RETURN;
            else if (strcmp(word, "break") == 0) type = TOKEN_BREAK;
            else if (strcmp(word, "continue") == 0) type = TOKEN_CONTINUE;
            
            tokens[token_count++] = create_token(type, word, line);
            free(word);
            continue;
        }
        
        // Nombres
        if (isdigit(source[i])) {
            int start = i;
            while (i < len && (isdigit(source[i]) || source[i] == '.')) {
                i++;
            }
            char *num = strndup(source + start, i - start);
            tokens[token_count++] = create_token(TOKEN_NUMBER, num, line);
            free(num);
            continue;
        }
        
        // Chaînes
        if (source[i] == '"') {
            i++;
            int start = i;
            while (i < len && source[i] != '"') {
                if (source[i] == '\n') line++;
                i++;
            }
            char *str = strndup(source + start, i - start);
            tokens[token_count++] = create_token(TOKEN_STRING, str, line);
            free(str);
            i++;
            continue;
        }
        
        // Opérateurs doubles
        if (source[i] == '=' && i + 1 < len && source[i + 1] == '=') {
            tokens[token_count++] = create_token(TOKEN_EQ, "==", line);
            i += 2;
            continue;
        }
        if (source[i] == '!' && i + 1 < len && source[i + 1] == '=') {
            tokens[token_count++] = create_token(TOKEN_NEQ, "!=", line);
            i += 2;
            continue;
        }
        if (source[i] == '<' && i + 1 < len && source[i + 1] == '=') {
            tokens[token_count++] = create_token(TOKEN_LTE, "<=", line);
            i += 2;
            continue;
        }
        if (source[i] == '>' && i + 1 < len && source[i + 1] == '=') {
            tokens[token_count++] = create_token(TOKEN_GTE, ">=", line);
            i += 2;
            continue;
        }
        if (source[i] == '&' && i + 1 < len && source[i + 1] == '&') {
            tokens[token_count++] = create_token(TOKEN_AND, "&&", line);
            i += 2;
            continue;
        }
        if (source[i] == '|' && i + 1 < len && source[i + 1] == '|') {
            tokens[token_count++] = create_token(TOKEN_OR, "||", line);
            i += 2;
            continue;
        }
        
        // Opérateurs simples
        switch (source[i]) {
            case '=': tokens[token_count++] = create_token(TOKEN_ASSIGN, "=", line); break;
            case '(': tokens[token_count++] = create_token(TOKEN_LPAREN, "(", line); break;
            case ')': tokens[token_count++] = create_token(TOKEN_RPAREN, ")", line); break;
            case '{': tokens[token_count++] = create_token(TOKEN_LBRACE, "{", line); break;
            case '}': tokens[token_count++] = create_token(TOKEN_RBRACE, "}", line); break;
            case '[': tokens[token_count++] = create_token(TOKEN_LBRACKET, "[", line); break;
            case ']': tokens[token_count++] = create_token(TOKEN_RBRACKET, "]", line); break;
            case ';': tokens[token_count++] = create_token(TOKEN_SEMICOLON, ";", line); break;
            case ',': tokens[token_count++] = create_token(TOKEN_COMMA, ",", line); break;
            case '+': tokens[token_count++] = create_token(TOKEN_PLUS, "+", line); break;
            case '-': tokens[token_count++] = create_token(TOKEN_MINUS, "-", line); break;
            case '*': tokens[token_count++] = create_token(TOKEN_MULT, "*", line); break;
            case '/': tokens[token_count++] = create_token(TOKEN_DIV, "/", line); break;
            case '%': tokens[token_count++] = create_token(TOKEN_MOD, "%", line); break;
            case '<': tokens[token_count++] = create_token(TOKEN_LT, "<", line); break;
            case '>': tokens[token_count++] = create_token(TOKEN_GT, ">", line); break;
            case '!': tokens[token_count++] = create_token(TOKEN_NOT, "!", line); break;
        }
        i++;
    }
    
    tokens[token_count++] = create_token(TOKEN_EOF, "", line);
}

// Libérer les tokens
void free_tokens() {
    for (int i = 0; i < token_count; i++) {
        if (tokens[i].value != NULL) {
            free(tokens[i].value);
        }
    }
    if (tokens != NULL) {
        free(tokens);
        tokens = NULL;
    }
    token_count = 0;
}
