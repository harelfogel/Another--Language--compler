%{
#include "anotherLang.tab.h"
#include "globalUtils.h"

int yylex();
void yyerror(char *s);
char* cleanBlankSpace(char* input);
int lineSpace = 1;

%}

%%

[B|b]"egin"         {sscanf(yytext, "%s", yylval.token); return beginVar;}
"print"             {sscanf(yytext, "%s", yylval.token); return printVar;}
"end"               {sscanf(yytext, "%s", yylval.token); return endVar;}
"int"               {sscanf(yytext, "%s", yylval.token); return intVar;}
"arr"               {sscanf(yytext, "%s", yylval.token); return arrVar;}
"if"                {sscanf(yytext, "%s", yylval.token); return ifVar;}
"then"              {sscanf(yytext, "%s", yylval.token); return thenVar;}
"while"             {sscanf(yytext, "%s", yylval.token); return whileVar;}
"do"                {sscanf(yytext, "%s", yylval.token); return doVar;}
"="                 {sscanf(yytext, "%s", yylval.token); return assigment;}
"["                 {sscanf(yytext, "%s", yylval.token); return leftBracket;}
"]"                 {sscanf(yytext, "%s", yylval.token); return rightBracket;}
"("                 {sscanf(yytext, "%s", yylval.token); return openParenthesis;}
")"                 {sscanf(yytext, "%s", yylval.token); return closeParenthesis;}
";"                 {sscanf(yytext, "%s", yylval.token); return semiColon;}
":"                 {sscanf(yytext, "%s", yylval.token); return position;}
","                 {sscanf(yytext, "%s", yylval.token); return comma;}
"@"                 {sscanf(yytext, "%s", yylval.token); return dotProduct;}
"+"                 {sscanf(yytext, "%s", yylval.token); return plus;}
"-"                 {sscanf(yytext, "%s", yylval.token); return minus;}
"*"                 {sscanf(yytext, "%s", yylval.token); return multiply;}
"/"                 {sscanf(yytext, "%s", yylval.token); return divide;}
"=="                {sscanf(yytext, "%s", yylval.token); return equals;}
"!="                {sscanf(yytext, "%s", yylval.token); return notEquals;}
"<"                 {sscanf(yytext, "%s", yylval.token); return greaterThan;}
">"                 {sscanf(yytext, "%s", yylval.token); return lessThan;}
"<="                {sscanf(yytext, "%s", yylval.token); return lessEqualThan;}
">="                {sscanf(yytext, "%s", yylval.token); return greateEqualsThan;}
([0-9])+                                        {sscanf(yytext, "%s", yylval.token); return numRegex;}
[_a-zA-Z][a-zA-Z0-9]{0,31}                      {sscanf(yytext, "%s", yylval.token); return id;}
\[[ ]*(-?[0-9])+[ ]*(,[ ]*(-?[0-9])+[ ]*)*\]    {cleanBlankSpace(yytext); sscanf(yytext, "%s", yylval.token); return arrRegex;}



[ \t]               ;
[\n]                lineSpace++;
.                   {ECHO; yyerror ("Error! Invalid Token.");}

%%


int yywrap (void) {
    return 1;
}

void yyerror(char *s) {
    fprintf(stderr, " Error in line number: %d: %s\n", lineSpace, s);
}

char* cleanBlankSpace(char* buffer)                                         
{
    int i=0,j=0;
    int length=strlen(buffer);
    while(i<length)
    {
        if (buffer[i]!=' '){
            buffer[j]=buffer[i];                     
        }                           
        else {
            j--; 
        }
        i++;
        j++;
    }

    buffer[j]=0;
    return buffer;
}