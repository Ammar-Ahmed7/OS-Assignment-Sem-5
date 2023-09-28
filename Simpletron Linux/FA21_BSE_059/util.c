#include "simple.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int accumulator = 0;
int instructionCounter = 0;
bool instCount = true;
int instructionRegister = 0;
int operationCode = 0;
int operand = 0;
int arr[100] = {0};
int ind = 0;

void load(char smlarr[100]) {

    FILE *file = fopen(smlarr, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        exit(0);
        return; 
    }

    for (int i = 0; i < 7; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void store() {
    if (instCount == false) {
        instructionCounter++;
    }
    instructionRegister = arr[ind];
    ind++;
    operationCode = instructionRegister / 100;
    operand = instructionRegister % 100;
}

void execute() {
    if (operationCode == READ) {
        int num;
        printf("\nEnter a number : ");
        scanf("%02d", &num);
        arr[operand] = num;
        printf("\nPress Enter to Proceed");
    }
    else if(operationCode == WRITE){
        printf("\nThe number loaded from the specific memory location is : %d",arr[operand]);
    }
    else if(operationCode==LOAD){
        accumulator=arr[operand];
        printf("\nPress Enter to load the value in the accumulator");
    }
    else if(operationCode==STORE){
        arr[operand]=accumulator;
        printf("\nPress Enter to load the value in the memory location from the accumulator");
    }
    else if(operationCode==ADD){
        accumulator=arr[operand]+accumulator;
         printf("\nPress Enter to load the added result in the accumulator");
    }
     else if(operationCode==SUBTRACT){
        accumulator=accumulator-arr[operand];
         printf("\nPress Enter to load the subtracted result in the accumulator");
    }
    else if(operationCode==DIVIDE){
        accumulator=accumulator/arr[operand];
         printf("\nPress Enter to load the Divided result in the accumulator");
    }
    else if(operationCode==MULTIPLY){
        accumulator=accumulator*arr[operand];
         printf("\nPress Enter to load the multiplied result in the accumulator");
    }
    else if(operationCode==BRANCH){
         instructionCounter=operand;
         instructionCounter++;
         printf("\nPress Enter to load the subtracted result in the accumulator");
    }
     else if(operationCode==BRANCHNEG){
        if(accumulator<0){
         instructionCounter=operand;
         instructionCounter++;
         printf("\nPress Enter to load the subtracted result in the accumulator");
        }
    }
     else if(operationCode==BRANCHZERO){
        if(accumulator==0){
         instructionCounter=operand;
         instructionCounter++;
         printf("\nPress Enter to load the subtracted result in the accumulator");
        }
    }
    
    else if(operationCode==HALT){
        printf("\nProgram Halt");
        exit(0);
    }

}

void display() {
    printf("accumulator = %d", accumulator);
    printf("\ninstructionCounter = %d", instructionCounter);
    printf("\ninstructionRegister = %d", instructionRegister);
    printf("\noperationCode = %d", operationCode);
    printf("\noperand = %02d", operand); 
    printf("\n\n");

    printf("     ");
    for (int i = 0; i < 10; i++) {
        printf("%5d", i);
    }
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%5d", i * 10);

        for (int j = 0; j < 10; j++) {
            printf("%5d", arr[i * 10 + j]);
        }
        printf("\n");
    }

    instCount = false;
}

