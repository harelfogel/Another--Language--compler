#define ARR_SIZE 128


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int numOfArrays = 0;
int arrBuffer[ARR_SIZE];
int *currIndex[ARR_SIZE];


int* createArrayAllocation(int *arr);
int* appendToArray(int *arr, int val);
int  getArraySize(const int *arr);
int *arrayAssigment(int *dest, const int *src, int arrSize);
int* elementAt(int *arr, int index, int val);
int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op);
void printArray_(int *a, int size);
int dotProduct(const int *left, const int *right, int size);


int main()
{
{
int i,fAvg;
int*  fib=NULL;
fib = elementAt(fib, 0, 0);
fib = elementAt(fib, 1, 1);
i=2;
printf("%d", 0);printf(",");printf("%d", 0);printf("\n");
printf("%d", 1);printf(",");printf("%d", 1);printf("\n");
while(i<16){
fib = elementAt(fib, i, fib[(i-2)]+fib[(i-1)]);
printf("%d", i);printf(",");printf("%d", fib[i]);printf("\n");
i=i+1;
}
printf("%d", dotProduct(fib, (const int[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, getArraySize(fib)));printf("\n");
fAvg=(dotProduct(fib, (const int[]){1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, getArraySize(fib)))/16;
printf("%d", fAvg);printf("\n");
i=2;
while(i<16){
if(fib[i]>fAvg){
printf("%d", i);printf(",");printf("%d", fib[i]);printf("\n");
}
i=i+1;
}
}return 0;}


int *createArrayAllocation(int *intArr) {
    if (intArr == NULL)
        intArr = malloc(sizeof(int));
        if(!intArr) printf("Error! Cannot allocate memory;");
    currIndex[numOfArrays] = intArr;
    arrBuffer[numOfArrays] = 0;
    numOfArrays++;
    return intArr;
}

int *appendToArray(int *arr, int num) {
    int i;

    for (i = 0; i < numOfArrays; i++)
        if (currIndex[i] == arr)
            break;

    if (i == numOfArrays) {
        if (numOfArrays < ARR_SIZE) {
            arr = createArrayAllocation(arr);
        } else {
            return NULL;
        }
    }
    int size = arrBuffer[i];
    arrBuffer[i]++;
    arr = realloc(arr, (size + 1) * sizeof(int));
    currIndex[i] = arr;
    arr[size] = num;
    return arr;
}

int getArraySize(const int *arr) {
    int i;
    for (i = 0; i < numOfArrays; i++)
        if (currIndex[i] == arr)
            break;
    if (i < numOfArrays)
        return arrBuffer[i];
    return -1;
}

int *elementAt(int *intArr, int pos, int val) {
    int i=0;
    for (i = 0; i < numOfArrays; i++)
        if (currIndex[i] == intArr)
            break;

    if (i == numOfArrays) {
        if (numOfArrays < ARR_SIZE) {
            intArr = createArrayAllocation(intArr);
        } else {
            return NULL;
        }
    }
    int size = arrBuffer[i];
    if (pos < size)
        intArr[pos] = val;
    else {
        arrBuffer[i] = pos + 1;
        intArr = realloc(intArr, (pos + 1) * sizeof(int));
        if(!intArr) printf("Error! Cannot allocate memory;");
        currIndex[i] = intArr;
        intArr[pos] = val;
    }
    return intArr;
}

int *arrayAssigment(int *dest, const int *src, int arrSize) {
    if (dest != NULL)
        free(dest);
    dest = NULL;
    dest = elementAt(dest, arrSize - 1, src[arrSize - 1]);
    for (int i = 0; i < arrSize - 1; i++)
        dest[i] = src[i];

    return dest;
}

int dotProduct(const int *left, const int *right, int size) {
    int i, totalSum = 0;
    for (i = 0; i < size; i++) {
        totalSum += left[i] * right[i];
    }
    return totalSum;
}

void printArray_(int *arr, int size) {
    int i;
    printf("{");
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("}");
}

int *mathOpOnArray(const int *left, const int *right, int leftSize, int rightSize, char op) {
    int enlargeSize =0;
                                if(leftSize>rightSize)
                               enlargeSize=leftSize; 
                            else             
                                  enlargeSize=rightSize;  
                          int *newArr = malloc(enlargeSize * sizeof(int));
    if(!newArr) printf("Error! Cannot allocate memory;");
    newArr = createArrayAllocation(newArr);

    for (int i = 0; i < numOfArrays; i++)
        if (currIndex[i] == newArr) { arrBuffer[i] = enlargeSize; }

    for (int i = 0; i < enlargeSize; i++) {
        int leftValue = i < leftSize ?  left[i] : 0;
        int rightValue = i < rightSize ? right[i] : 0;
        switch (op) {
            case '+':
                newArr[i] = leftValue + rightValue;
                break;
            case '-':
                newArr[i] = leftValue - rightValue;
                break;
            case '*':
                newArr[i] = leftValue * rightValue;
                break;
            case '/':
                newArr[i] = leftValue / rightValue;
                break;
            default:
                newArr[i] = 0;
        }
    }
    return newArr;
}