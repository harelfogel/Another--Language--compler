%{

#include <stdio.h>
#include <stdlib.h>
#include "globalUtils.h"
#include <string.h>
#include <ctype.h>

extern FILE* yyout;
extern FILE* yyin;

/*
 * Global variables
 *
 */

int currentPosition = 0;
const char* constStr = "(const int[]){";
const char* opArray = "arrayOperations(" ;


/*
 * Global data structures
 *
 */

char printType[MAX_SIZE];
char intType[ARR_SIZE];
char arrType[ARR_SIZE][BUFF];

/*
 * Prototypes: Functions declarations
 *
 */

void yyerror();
int yylex();
char* loadFunctionsFile();
char *stringToken(char *srcString, char *delim);
unsigned int isDelim(char c, char *delim);
char* getHeadersAndIncludes();
void statementListHandler(char* res, char* statement,char* statementList);
void blockHandler(char* res,char* begin,char* statement,char* end);
void arrTypeHandler(char* res,char* arrRegex);
void squareParthesisHandler(char* res,char* variable,char* position,char* expression);
void parthesisHandler(char* res,char* p1, char* expr,char* p2);
void dotProductHandler(char * res, char * expression1, char * dotProductAt, char * expression2);
void expressionListHandler(char * res, char * expression_, char * comma_, char * expressionList_);
void variableListHandler(char* res,char* variable_, char* comma_, char* varList);
void ifAndLoopHandler(char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block);
void positionHandler(char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2);
void assigmentHandler(char* res,char* variable,char* assigment,char* expression);
void opHandler(char* res, char* arr1, char* arr2, char* arr3);
void decleratorHandler(char * res,char* langTypes, char* varList);
void pointerHandler(char* src);
bool validateArr(char* identifier);
bool validateArrConst(char* tok);
void storeArray(char* src);
int getArraySize(char* value);
void printHandler(char* expressions);
%}



%union{
    char token[8192];
}


%error-verbose
%start program


/*
 * Tokens Decleration
 *
 */

%token beginVar endVar numRegex id arrRegex intVar arrVar  
%token leftBracket rightBracket openParenthesis closeParenthesis semiColon
%token assigment position comma dotProduct plus minus multiply divide
%token greaterThan lessThan lessEqualThan greateEqualsThan notEquals equals
%token whileVar doVar ifVar thenVar printVar


%type <token>       beginVar endVar intVar arrVar
                    whileVar doVar printVar
                    ifVar thenVar 

%type <token>       semiColon leftBracket rightBracket
                    closeParenthesis openParenthesis 
                    position comma dotProduct 

%type <token>       id numRegex arrRegex assigment
                    greaterThan lessThan lessEqualThan
                    greateEqualsThan notEquals equals
                    multiply divide plus minus  

%type <token>       program block statement statementList   
                    cond ops identifier number langTypes declarator
                    assignment conditional loop print  
                    expression expressionList variable variableList 


%left openParenthesis closeParenthesis
%left dotProduct
%left divide multiply
%left plus minus
%left position
%left assigment
%%



/*
 * Grammer- Section
 *
 */

program         : block                                              {fprintf(yyout, "%s", $$);}
                ;
block           : beginVar statementList endVar                      {blockHandler($$,$1,$2,$3);}
                ;

statementList   : statement statementList                            {statementListHandler($$,$1,$2);}
                | statement                                          {strcpy($$, $1);}
                ;

statement       : declarator semiColon                               {strcpy($$, $1); strcat($$, $2);}
                | assignment semiColon                               {strcpy($$, $1); strcat($$, $2);}
                | conditional                                        {strcpy($$, $1);}
                | loop                                               {strcpy($$, $1);}
                | print semiColon                                    {strcpy($$, $1); strcat($$, $2);}
                ;

declarator      : langTypes variableList                              {decleratorHandler($$,$1,$2);}
                ;

assignment      : variable assigment expression                       {assigmentHandler($$,$1,$2,$3);}                 

                | variable position expression assigment expression   {positionHandler($$,$1,$2,$3,$4,$5);}               
                ;

conditional     : ifVar openParenthesis cond closeParenthesis 
                  thenVar block                                       {ifAndLoopHandler($$,$1,$2,$3,$4,$5,$6);}
                ;


loop            : whileVar openParenthesis cond closeParenthesis 
                  doVar block                                         {ifAndLoopHandler($$,$1,$2,$3,$4,$5,$6);}
                                                                         
                ;

print           : printVar expressionList                             {printHandler($2); strcpy($$, printType);} 
                ;

variableList    : variable                              
                | variable comma variableList                         {variableListHandler($$,$1,$2,$3);}    
                ;

expressionList  : expression                              
                | expression comma expressionList                     {expressionListHandler($$,$1,$2,$3);}        
                ;

variable        : identifier                                
                ;

expression      : expression plus expression                          { opHandler($$, $1, $2, $3); }
                | expression minus expression                         { opHandler($$, $1, $2, $3); }
                | expression multiply expression                      { opHandler($$, $1, $2, $3); }
                | expression divide expression                        { opHandler($$, $1, $2, $3); }
                | expression dotProduct expression                    { dotProductHandler($$,$1,$2,$3);}
                | openParenthesis expression closeParenthesis         { parthesisHandler($$,$1,$2,$3);}    
                | variable                                  
                | number                                    
                | variable position expression                        {squareParthesisHandler($$,$1,$2,$3);}
                ;

cond            : expression ops expression                           {strcpy($$, $1); strcat($$, $2); strcat($$, $3);}
                ;

ops             : greaterThan                                    
                | lessThan                                    
                | lessEqualThan                                   
                | greateEqualsThan                                   
                | notEquals                                    
                | equals                                    
                ;

identifier      : id                                        
                ;

number          : numRegex
                | minus numRegex                                      {strcpy($$, $1); strcat($$, $2);}    
                | arrRegex                                            {arrTypeHandler($$,$1);}
                ;

langTypes       : intVar                                     
                | arrVar                                              {strcpy($$, "int*")}
                ;

%%

/*
 * Functions- Implementations
 *
 */



/*
 * name:  statementListHandler
 * @params:char* res, char* statement,char* statementList
 * @desc: Concatenating statements according to grammer.
 */

void statementListHandler(char* res, char* statement,char* statementList){
    strcpy(res, statement);
    strcat(res, "\n");
    strcat(res, statementList);
}

/*
 * name:  squareParthesisHandler
 * @params:char* res,char* variable,char* position,char* expression
 * @desc: Concatenating sqaure parathensis for arrays declarations.
 */

void squareParthesisHandler(char* res,char* variable,char* position,char* expression)
{
        if(!validateArr(variable)){
            yyerror("Cannot make an position operation on int type.");
        }else{
            strcpy(res, variable);
            strcat(res,"[");strcat(res,expression);
            strcat(res,"]");
        }
}

/*
 * name:  parthesisHandler
 * @params:char* res,char* p1, char* expr,char* p2
 * @desc: Concatenating  parathensis for declarations.
 */
 
void parthesisHandler(char* res,char* p1, char* expr,char* p2){
    strcpy(res, p1);
    strcat(res, expr);
    strcat(res, p2);
}


/*
 * name:  dotProductHandler
 * @params:char * res, char * expression1, char * dotProductAt, char * expression2
 * @desc: Concatenating  expressions for handle with dot product operation.
 */

 void dotProductHandler(char * res, char * expression1, char * dotProductAt, char * expression2)
{

    if ((validateArr(expression1) || validateArrConst(expression1)) && (validateArr(expression2) || validateArrConst(expression2))) {

        strcpy(res, "dotProduct(");
        strcat(res, expression1);
        strcat(res, ", ");
        strcat(res, expression2);
        strcat(res, ", ");

        if (validateArr(expression1)) {
            strcat(res, "getArraySize(");
            strcat(res, expression1);
            strcat(res, ")");
        } else if (validateArrConst(expression1)) {
            getArraySize(expression1);
            strcat(res, intType);
        }
        strcat(res, ")");
    } else {
        yyerror("Error.Illegal dot product operation.");
    }
}


/*
 * name:  expressionListHandler
 * @params:char * res, char * expression_, char * comma_, char * expressionList_
 * @desc: Concatenating  expression list by the grammer rules.
 */
 
void expressionListHandler(char * res, char * expression_, char * comma_, char * expressionList_)
{
        strcpy(res, expression_);
        strcat(res, "|");
        strcat(res,expressionList_);
}

/*
 * name:  variableListHandler
 * @params:char* res,char* variable_, char* comma_, char* varList
 * @desc: Concatenating  variable list by the grammer rules.
 */

void variableListHandler(char* res,char* variable_, char* comma_, char* varList)
{
strcpy(res, variable_);
strcat(res, comma_);
strcat(res,varList);
}

/*
 * name:  ifAndLoopHandler
 * @params:char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block
 * @desc: Concatenating  if  and loop conditions  by the grammer rules.
 */
void ifAndLoopHandler(char* res,char* ifVar,char* openParenthesis,char* cond,char* closeParenthesis,char* thenVar,char* block)
{
    strcpy(res, ifVar);
    strcat(res, openParenthesis);
    strcat(res, cond);
    strcat(res, closeParenthesis);
    strcat(res, block);
}

/*
 * name:  positionHandler
 * @params:char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2
 * @desc: Positioning ans assigment concatination.
 */
void positionHandler(char* res,char* variable, char* position, char* expression1,char* assigment,char* expression2){
    if(!validateArr(variable)){
    yyerror("Error!Cannot operate array indexing on int type.");
}
    else{
        strcpy(res, variable);
        strcat(res, " = elementAt(");
        strcat(res, variable);
        strcat(res, ", ");
        strcat(res, expression1);
        strcat(res, ", ");
        strcat(res, expression2);
        strcat(res, ")");
    }
}


/*
 * name:  assigmentHandler
 * @params:char* res,char* variable,char* assigment,char* expression
 * @desc: Concatination for assigment expressions.
 */

void assigmentHandler(char* res,char* variable,char* assigment,char* expression)
{
    if(!validateArr(variable)){
        if(validateArrConst(expression)){
            yyerror("Error: Setting arr to an int!!");
        }else{
            strcpy(res, variable);
            strcat(res, assigment);
            strcat(res, expression);
        }
    }else{
    
        strcpy(res, variable);
        strcat(res, assigment);
        strcat(res, "arrayAssigment(");
        strcat(res, variable);
        strcat(res, ",");
        if(validateArr(expression) || validateArrConst(expression)){
            strcat(res, expression);
        }else{

            strcat(res, "(const int[]){");
            strcat(res, expression);
            strcat(res, "}");
            
        }

        if(validateArr(expression)){
                strcat(res, ",getArraySize(");
                strcat(res, expression);
                strcat(res, "))");
        }else{
            if(validateArrConst(expression)){
                getArraySize(expression);
                strcat(res, ",");
                strcat(res, intType);
                strcat(res, ")");
            }else{
                strcat(res, ",");
                strcat(res, "1");
                strcat(res, ")");
            }
        }
        
    }
}   


/*
 * name:  decleratorHandler
 * @params:char * res,char* langTypes, char* varList
 * @desc: Type decleration operations.
 */
void decleratorHandler(char * res,char* langTypes, char* varList)
{
    strcpy(res, langTypes); strcat(res, " "); 
    if(strcmp(langTypes, "int")>0){
        storeArray(varList);
        pointerHandler(varList);
        varList[0] = ' ';
        strcat(res, varList);
    }
    else{
        strcat(res, varList);
    }
}


/*
 * name:  int isDelim
 * @params:int mode,char* res,char* src
 * @desc: Checking for a delimiters in a given string.
 */
unsigned int isDelim(char c, char *delim)
{
    while(*delim != '\0')
    {
        if(c == *delim)
            return 1;
        delim++;
    }
    return 0;
}

/*
 * name:  char *stringToken
 * @params:char *srcString, char *delim
 * @desc:  Tokenizing a string based on a delimiter
 */

char *stringToken(char *srcString, char *delim)
{
    static char *backup_string; // start of the next search
    if(!srcString)
    {
        srcString = backup_string;
    }
    if(!srcString)
    {
        return NULL;
    }
    // handle beginning of the string containing delims
    while(1)
    {
        if(isDelim(*srcString, delim))
        {
            srcString++;
            continue;
        }
        if(*srcString == '\0')
        {
            // we've reached the end of the string
            return NULL; 
        }
        break;
    }
    char *ret = srcString;
    while(1)
    {
        if(*srcString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = srcString;
            return ret;
        }
        if(isDelim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}

/*
 * name:  pointerHandler
 * @params:char *str
 * @desc: Pointers operations.
 */

void pointerHandler(char *str) {
    char *strToken = stringToken(str, ",");
    char buff[MAX_SIZE];
    buff[0] = 0;
    while (strToken != NULL) {
        strcat(buff, "*");
        strcat(buff, strToken);
        strcat(buff, "=NULL, ");
        strToken = stringToken(NULL, ",");
    }
    if(strlen(buff) >= 4)
        buff[strlen(buff) - 2] = 0;
    strcpy(str, buff);
}

/*
 * name:  storeArray
 * @params:char *str
 * @desc: Storing Arrays in memory.
 */
void storeArray(char *str) {
    char buff[MAX_SIZE];
    strcpy(buff, str);

    char *strToken = stringToken(buff, ",");
    while (strToken != NULL) {
        strcat(arrType[currentPosition++], strToken);
        strToken = stringToken(NULL, ",");
    }
}

/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Checking array validity.
 */
bool validateArr(char* identifier){
    for( int i = 0; i < currentPosition; i++){
        if(strcmp(arrType[i], identifier) == 0)
            return true;
    }
    const char* dest = "mathOpOnArray(";
    bool ret=strncmp(identifier, dest, strlen(dest));
    return !ret;
}


/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Checkingif it is a constant array
 */
bool validateArrConst(char* src){
    const char* dest = CONST;
    bool ret=strncmp(src, dest, strlen(dest));
    return !ret;
}

/*
 * name:  storeArray
 * @params:char *identifier
 * @desc: Gets the num of element in the array
 */
int getArraySize(char* value){
    int count = 0;
    if(strlen(value) > 0)
        count++;

    for(int i = 0; i < strlen(value); i++){
        if(value[i] == ',')
            count++;
    }
    intType[0] = 0;
    sprintf( intType, "%d", count );
    return count;
}

/*
 * name:  countChar
 * @params:char* str, char c
 * @desc: Char counter
 */
int countChar(char* str, char c){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == c)
            count++;
    }
    return count;
}

/*
 * name:  opHandler
 * @params:char* res, char* arr1, char* arr2, char* arr3
 * @desc: Operations between arrays.
 */
void opHandler(char* res, char* arr1, char* arr2, char* arr3){
    if((validateArr(arr1) || validateArrConst(arr1)) && (validateArr(arr3) || validateArrConst(arr3)))
    {
        strcpy(res, "mathOpOnArray(");
        strcat(res, arr1);
        strcat(res, ", ");
        strcat(res, arr3);
        strcat(res, ", ");
        if(validateArr(arr1)){
            strcat(res, "getArraySize(");
            strcat(res, arr1);
            strcat(res, ")");
        }else{
            getArraySize(arr1);
            strcat(res, intType);
        }
        strcat(res, ",");
        if(validateArr(arr3)){
            strcat(res, "getArraySize(");
            strcat(res, arr3);
            strcat(res, ")");
        }else{
            getArraySize(arr3);
            strcat(res, intType);
        }
        strcat(res, ",'");
        strcat(res, arr2);
        strcat(res, "')");
    }
    else if((validateArr(arr1) || validateArrConst(arr1)) || (validateArr(arr3) || validateArrConst(arr3))){
        yyerror("Error! Cannot operate between array and int types.");
    }
    else
    {
        strcpy(res, arr1);
        strcat(res, arr2);
        strcat(res, arr3);
    }
}

/*
 * name:  printHandler
 * @params:char* expressions
 * @desc: Enabeling  Printing.
 */

void printHandler(char* expressions){
    char buffer[MAX_SIZE];
    int numOfExpressions = countChar(expressions, '|');
    printType[0] = 0;
    strcpy(buffer, expressions);

    char* token = stringToken(buffer, "|");
    while(token != NULL){
        if(validateArr(token))
        {
            strcat(printType, "printArray_(");
            strcat(printType, token);
            strcat(printType, ", getArraySize(");
            strcat(printType, token);
            strcat(printType, "));");
        }else if(validateArrConst(token)){
            strcat(printType, "printArray_(");
            strcat(printType, token);
            strcat(printType, ", ");
            getArraySize(token);
            strcat(printType, intType);
            strcat(printType, ");");
        }else{
            strcat(printType, "printf(\"%d\", ");
            strcat(printType, token);
            strcat(printType, ");");
        }
        if(numOfExpressions>0)
            strcat(printType, "printf(\",\");");
        numOfExpressions--;

        token = stringToken(NULL, "|");
    }
    strcat(printType, "printf(\"\\n\")");    
}

/*
 * name:  blockHandler
 * @params:char* res,char* begin,char* statement,char* end
 * @desc: Concatination with block tokens according to grammer
 */

void blockHandler(char* res,char* begin,char* statement,char* end)
{
    strcpy(res, "{\n");
    strcat(res, statement);
    strcat(res, "\n}");
}

/*
 * name: arrTypeHandler
 * @params:char* res,char* arrRegex
 * @desc: Concatenating const array types.
 */
 void arrTypeHandler(char* res,char* arrRegex)
 {
     strcpy(res, CONST);
     arrRegex[0] = '{'; arrRegex[strcspn(arrRegex, "]")]='}';
     strcat(res, arrRegex);
 }

/*
 * name: loadFunctionsFile
 * @params:void
 * @desc: Return a string that contains the cout.c file.
 */
char* loadFunctionsFile() 
{
     return ("return 0;"
"}\n"
"\n"
"\n"
"int *createArrayAllocation(int *intArr) {\n"
"    if (intArr == NULL)\n"
"        intArr = malloc(sizeof(int));\n"
"        if(!intArr) printf(\"Error! Cannot allocate memory;\");\n"
"    currIndex[numOfArrays] = intArr;\n"
"    arrBuffer[numOfArrays] = 0;\n"
"    numOfArrays++;\n"
"    return intArr;\n"
"}\n"
"\n"
"int *appendToArray(int *arr, int num) {\n"
"    int i;\n"
"\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == arr)\n"
"            break;\n"
"\n"
"    if (i == numOfArrays) {\n"
"        if (numOfArrays < ARR_SIZE) {\n"
"            arr = createArrayAllocation(arr);\n"
"        } else {\n"
"            return NULL;\n"
"        }\n"
"    }\n"
"    int size = arrBuffer[i];\n"
"    arrBuffer[i]++;\n"
"    arr = realloc(arr, (size + 1) * sizeof(int));\n"
"    currIndex[i] = arr;\n"
"    arr[size] = num;\n"
"    return arr;\n"
"}\n"
"\n"
"int getArraySize(const int *arr) {\n"
"    int i;\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == arr)\n"
"            break;\n"
"    if (i < numOfArrays)\n"
"        return arrBuffer[i];\n"
"    return -1;\n"
"}\n"
"\n"
"int *elementAt(int *intArr, int pos, int val) {\n"
"    int i=0;\n"
"    for (i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == intArr)\n"
"            break;\n"
"\n"
"    if (i == numOfArrays) {\n"
"        if (numOfArrays < ARR_SIZE) {\n"
"            intArr = createArrayAllocation(intArr);\n"
"        } else {\n"
"            return NULL;\n"
"        }\n"
"    }\n"
"    int size = arrBuffer[i];\n"
"    if (pos < size)\n"
"        intArr[pos] = val;\n"
"    else {\n"
"        arrBuffer[i] = pos + 1;\n"
"        intArr = realloc(intArr, (pos + 1) * sizeof(int));\n"
"        if(!intArr) printf(\"Error! Cannot allocate memory;\");\n"
"        currIndex[i] = intArr;\n"
"        intArr[pos] = val;\n"
"    }\n"
"    return intArr;\n"
"}\n"
"\n"
"int *arrayAssigment(int *dest, const int *src, int arrSize) {\n"
"    if (dest != NULL)\n"
"        free(dest);\n"
"    dest = NULL;\n"
"    dest = elementAt(dest, arrSize - 1, src[arrSize - 1]);\n"
"    for (int i = 0; i < arrSize - 1; i++)\n"
"        dest[i] = src[i];\n"
"\n"
"    return dest;\n"
"}\n"
"\n"
"int dotProduct(const int *left, const int *right, int size) {\n"
"    int i, totalSum = 0;\n"
"    for (i = 0; i < size; i++) {\n"
"        totalSum += left[i] * right[i];\n"
"    }\n"
"    return totalSum;\n"
"}\n"
"\n"
"void printArray_(int *arr, int size) {\n"
"    int i;\n"
"    printf(\"{\");\n"
"    for (i = 0; i < size; i++) {\n"
"        printf(\"%%d\", arr[i]);\n"
"        if (i < size - 1)\n"
"            printf(\", \");\n"
"    }\n"
"    printf(\"}\");\n"
"}\n"
"\n"
"int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op) {\n"
"    int enlargeSize =0;\n                            "
"    if(leftSize>rightSize)\n                         "
"      enlargeSize=leftSize; \n                       "
"     else             \n                             "
"     enlargeSize=rightSize;  \n                      "       
"    int *newArr = malloc(enlargeSize * sizeof(int));\n"
"    if(!newArr) printf(\"Error! Cannot allocate memory;\");\n"
"    newArr = createArrayAllocation(newArr);\n"
"\n"
"    for (int i = 0; i < numOfArrays; i++)\n"
"        if (currIndex[i] == newArr) { arrBuffer[i] = enlargeSize; }\n"
"\n"
"    for (int i = 0; i < enlargeSize; i++) {\n"
"        int leftValue = i < leftSize ?  left[i] : 0;\n"
"        int rightValue = i < rightSize ? right[i] : 0;\n"
"        switch (op) {\n"
"            case '+':\n"
"                newArr[i] = leftValue + rightValue;\n"
"                break;\n"
"            case '-':\n"
"                newArr[i] = leftValue - rightValue;\n"
"                break;\n"
"            case '*':\n"
"                newArr[i] = leftValue * rightValue;\n"
"                break;\n"
"            case '/':\n"
"                newArr[i] = leftValue / rightValue;\n"
"                break;\n"
"            default:\n"
"                newArr[i] = 0;\n"
"        }\n"
"    }\n"
"    return newArr;\n"
"}");
 }


/*
 * name:  getHeadersAndIncludes
 * @params:void
 * @desc: Returns includes and prototypes of fucntions.
 */
char* getHeadersAndIncludes(){
    return ("\n"
"\n"
"#include <stdio.h>\n"
"#include <stdlib.h>\n"
"#include <string.h>\n"
"#include <ctype.h>\n"
"\n"
"\n"
"int numOfArrays = 0;\n"
"int arrBuffer[ARR_SIZE];\n"
"int *currIndex[ARR_SIZE];\n"
"\n"

"\n"
"int* createArrayAllocation(int *arr);\n"
"int* appendToArray(int *arr, int val);\n"
"int  getArraySize(const int *arr);\n"
"int *arrayAssigment(int *dest, const int *src, int arrSize);\n"
"int* elementAt(int *arr, int index, int val);\n"
"int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op);\n"
"void printArray_(int *a, int size);\n"
"int dotProduct(const int *left, const int *right, int size);\n"
"\n"
"\n"
"int main()\n"
"{\n");
}


int main(int argc, char** argv){
    // Open the source code file
    if(argc == 2){
        yyin = fopen(argv[1], "r");
        if(!yyin)
   		{
   		 	fprintf(stderr, "Error! Cannot open the file %s\n", argv[1]);
   		 	return 1;
   		}
    }
    yyout = fopen("out.c", "w");
    if(!yyout){
        fprintf(stderr, "Cannot open the out.c file.\n");
    }
    // Handling dynamoc arrays
    fprintf(yyout, "#define ARR_SIZE %d\n", 128);
    fprintf(yyout,getHeadersAndIncludes());
    // Parsing
    yyparse();
    fprintf(yyout,loadFunctionsFile());

    //Closing files
    fclose(yyin);
    fclose(yyout);
    return 0;
}