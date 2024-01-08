#include <stdio.h>
#include "../utils/io_utils.h"

#define YY_STDINIT
#define YYSTYPE double
extern YYSTYPE yylval;

extern int yyparse(void);

extern FILE *yyin;


void handle_client_input(int type, int client_fd, const char *file_path);
void handle_input(int client_fd);
void handle_file(int client_fd, const char *file_path);
void parse_send_request(int client_fd);