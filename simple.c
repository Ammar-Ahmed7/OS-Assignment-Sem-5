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

void load() {
    FILE *file = fopen("C:/Users/Sony/Documents/OS Assignments/readvalues.txt", "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
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
    if (operationCode == 10) {
        int num;
        printf("\nEnter a number : ");
        scanf("%02d", &num);
        arr[operand] = num;
        printf("\nPress Enter to Proceed");
    }
    else if(operationCode == 11){
        printf("The number loaded from the specific memory location is : %d",arr[operand]);

    }
    else if(operationCode==20){
        accumulator=arr[operand];
        printf("\nPress Enter to load the value in the accumulator");
    }
    else if(operationCode==21){
        arr[operand]=accumulator;
        printf("\nPress Enter to load the value in the memory location from the accumulator");
    }
    else if(operationCode==30){
        accumulator=arr[operand]+accumulator;
         printf("\nPress Enter to load the added result in the accumulator");
    }
     else if(operationCode==31){
        accumulator=accumulator-arr[operand];
         printf("\nPress Enter to load the subtracted result in the accumulator");
    }
    else if(operationCode==32){
        accumulator=accumulator/arr[operand];
         printf("\nPress Enter to load the Divided result in the accumulator");
    }
    else if(operationCode==33){
        accumulator=accumulator*arr[operand];
         printf("\nPress Enter to load the multiplied result in the accumulator");
    }
    else if(operationCode==40){
        accumulator=accumulator-arr[operand];
         printf("\nPress Enter to load the subtracted result in the accumulator");
    }
    else if(operationCode==43){
        printf("Program Halt");
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

int main() {
    do {
        system("cls");
        printf("\n\n");
        load();
        store();
        display();
        execute();
        getchar();
    } while (instructionCounter != 99);
    return 0;
}
