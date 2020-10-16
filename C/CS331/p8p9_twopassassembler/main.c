/* Implement pass one of a two pass assembler */

#include <stdio.h>
#include <string.h>

int main() {
  FILE *input, *symtab, *optab, *output;
  char opcode[10], label[10], code[10], oprnd[10];
  int operand, start_address, locctr, optab_op;

  input = fopen("input.txt", "r");    // Input file
  symtab = fopen("symtab.txt", "w+"); // symtab file
  optab = fopen("optab.txt", "r");    // Optab file
  output = fopen("output.txt", "w+"); // Output file

  // Read the first line
  fscanf(input, "%s %s %d", label, opcode, &operand);

  // Check if the file starts with START instruction
  // If it does, store the operand as start address and locctr
  if (strcmp(opcode, "START") == 0) {
    locctr = start_address = operand;
    fprintf(output, "%s %s %d\n", label, opcode, operand);
  } else
    locctr = 0;

  // Read the next line
  fscanf(input, "%s %s %s", label, opcode, oprnd);

  while (strcmp(opcode, "END") != 0 && !feof(input)) {
    fprintf(output, "%d ", locctr);
    
    // If the line is labelled store in symtab 
    if (strcmp(label, "**") != 0)
      fprintf(symtab, "%s %d\n", label, locctr);
    
    // Add to output
    fprintf(output, "%s %s %s\n", label, opcode, oprnd);

    // Check optab for opcode
    fseek(optab, 0, SEEK_SET);
    while (!feof(optab)) {
      fscanf(optab, "%s %d", code, &optab_op);
      if (strcmp(opcode, code) == 0) {
        locctr += 3;
        break;
      }
    }

    // Calculate locctr change
    if (strcmp(opcode, "WORD") == 0)
      locctr += 3;
    else if (strcmp(opcode, "RESW") == 0) {
      operand = atoi(oprnd);
      locctr += 3 * operand;
    }

    else if (strcmp(opcode, "BYTE") == 0) {
      if (oprnd[0] == 'X')
        locctr++;
      else
        locctr += strlen(oprnd) - 2;
    }

    else if (strcmp(opcode, "RESB") == 0) {
      operand = atoi(oprnd);
      locctr += operand;
    }

    fscanf(input, "%s %s %s", label, opcode, oprnd);
  }
  
  fprintf(output, "%d %s %s %s\n", locctr, label, opcode, oprnd);

  printf("Program length: %d\n", locctr - start_address);
  return 0;
}