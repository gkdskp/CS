/* Implement the assembler module to solve the forward references of the kind
	ALPHA EQU BETA
	BETA EQU GAMMA
	GAMMA EQU DELTA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SymTabItem {
  char labelName[20];
  int no_of_unresolved;
  char target[20];
  int dependsLength;
  int finalAddr;
  struct SymTabItem *depends[5];
};

int main() {
  struct SymTabItem *symtabItems[100];
  int symTabLength = 0;
  int found1, found2, temp;

  char label[20], opcode[20], target[20], targs[20], *targ1, *targ2;
  FILE *input = fopen("input.txt", "r");

  while (!feof(input)) {
    fscanf(input, "%s %s %s", label, opcode, target);

    strcpy(targs, target);

    if (strcmp(opcode, "EQU") == 0) {
      if (strchr(targs, '+') != NULL) {
        targ1 = strtok(targs, "+");
        targ2 = strtok(NULL, "+");
      } else if (strchr(targs, '-') != NULL) {
        targ1 = strtok(targs, "-");
        targ2 = strtok(NULL, "-");
      } else {
        targ1 = strtok(targs, "/");
        targ2 = strtok(NULL, "-");
      }

      found1 = -1;
      for (int i = 0; i < symTabLength; i++) {
        if (strcmp(symtabItems[i]->labelName, label) == 0) {
          found1 = i;
          break;
        }
      }
	  struct SymTabItem *sym;
      if (found1 != -1)
        sym = symtabItems[found1];
      else {
        sym = malloc(sizeof(struct SymTabItem));
        strcpy(sym->labelName, label);
        sym->no_of_unresolved = (targ2 == NULL) ? 1 : 2;
        strcpy(sym->target, target);
      }

      for (int i = 0; i < symTabLength; i++) {
        found1 = 0;
        found2 = 0;
        if (strcmp(symtabItems[i]->labelName, targ1) == 0) {
          symtabItems[i]->depends[symtabItems[i]->dependsLength] = sym;
          symtabItems[i]->dependsLength += 1;
          found1 = 1;
        }

        if (targ2 != NULL) {
          if (strcmp(symtabItems[i]->labelName, targ2) == 0) {
            symtabItems[i]->depends[symtabItems[i]->dependsLength] = sym;
            symtabItems[i]->dependsLength += 1;
            found2 = 1;
          }
        }
      }

      if (!found1) {
        if (strcmp(targ1, "*") == 0) {
          printf("Enter locctr position: \n");
          scanf("%d", &temp);
          sym->finalAddr = temp;
          // TODO: Change the depends on of others
        } else {
          struct SymTabItem *sym2 = malloc(sizeof(struct SymTabItem));
          strcpy(sym2->labelName, targ1);
          sym2->depends[0] = sym;
          sym2->dependsLength = 1;

          symtabItems[symTabLength] = sym2;
          symTabLength++;
        }
      }

      if (!found2 && targ2 != NULL) {
        struct SymTabItem *sym2 = malloc(sizeof(struct SymTabItem));
        strcpy(sym2->labelName, targ1);
        sym2->depends[0] = sym;
        sym2->dependsLength = 1;

        symtabItems[symTabLength] = sym2;
        symTabLength++;
      }

      symtabItems[symTabLength] = sym;
      symTabLength += 1;
    } else if (strcmp(opcode, "RESB")) {
      printf("Enter the value for %s: ", label);
      scanf("%d", temp);
      for (int i = 0; i < symTabLength; i++) {
        if (strcmp(symtabItems[i]->labelName, label) == 0) {
          symtabItems[i]->finalAddr = temp;
          // TODO: Solve depending on
        }
      }
    }
    for (int i = 0; i < symTabLength; i++) {
      printf("%s - no of unresolved dependency: %d, operand: %s, final "
             "Value: %d, no of items depending on: %d\n",
             symtabItems[i]->labelName, symtabItems[i]->no_of_unresolved,
             symtabItems[i]->target, symtabItems[i]->finalAddr,
             symtabItems[i]->dependsLength);
    }
    printf("\n");
  }
}