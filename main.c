#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "./ptable.h"
extern int ptSize;

// v0.60 beta

typedef void (*module_function)();

struct element searchByAbbr(char abbr[3]) {
  for (int i = 0; i < ptSize; i++) {
    if (!strcmp(ptable[i].abbr, abbr)) {
      return ptable[i];
    }
  } return ptable[0];
}

void search_fail() {
  printf("Error: no such module.\n\n");
}

void findfm() {
  char formula[50] = "";
  char tosearch[3] = "";
  float totalfm = 0.0;
  int coeff = 1;

  // cannot handle coefficients >9

  printf("Find formula mass of: ");
  scanf("%49s", formula);
  if (strchr(formula, '(') != 0) {
    puts("errcode 1: no parentheses plz");
  } else {
    for (int i = 0; i < strlen(formula); i++) {
      int coeff = 1;
      if (isdigit(formula[i])) { continue; }
      if (isdigit(formula[i+1])) { coeff = formula[i+1] - '0';}
      if (islower(formula[i+1])) {
        if (isdigit(formula[i+2])) { coeff = formula[i+2] - '0'; }
        strncpy(tosearch, formula + i, 2);
        tosearch[2] = '\0';
        totalfm = totalfm + (searchByAbbr(tosearch).molarmass * coeff);
      } else {
        strncpy(tosearch, formula + i, 1);
        tosearch[1] = '\0';
        totalfm = totalfm + (searchByAbbr(tosearch).molarmass * coeff);
      }
    }
    printf("%f g/mol\n\n", totalfm);
  }
}

void boyles_law() {
  puts("A/B can refer to either P or V");
  float known1 = 0;
  float known2 = 0;
  float known3 = 0;
  printf("known #A1: ");
  scanf("%f", &known1);
  printf("known #B1: ");
  scanf("%f", &known2);
  printf("known #A2: ");
  scanf("%f", &known3);
  
  printf("unknown = %f\n", (known1 * known2 / known3));
}

void gaylussac() {
  puts("A/B can refer to either P or T");
  puts("Always use kelvin!!");
  float known1 = 0;
  float known2 = 0;
  float known3 = 0;
  printf("known #A1: ");
  scanf("%f", &known1);
  printf("known #B1: ");
  scanf("%f", &known2);
  printf("known #A2: ");
  scanf("%f", &known3);

  printf("unknown = %f\n", (known3 / known1 * known2));
}

void combined_gas_law() {
  float p1 = 0;
  float v1 = 0;
  float t1 = 0;
  float p2 = 0;
  float v2 = 0;
  float t2 = 0;
  printf("Which variable is unknown? (P/V/T) ");
  char which = getchar();
  while ((getchar()) != '\n');
  which = tolower(which);
  switch (which) {
    case 'p':
      printf("P1? "); scanf(" %f", &p1);
      printf("V1? "); scanf(" %f", &v1);
      printf("T1? "); scanf(" %f", &t1);
      printf("V2? "); scanf(" %f", &v2);
      printf("T2? "); scanf(" %f", &t2);

      p2 = (p1 * v1 / t1) / (v2 / t2);
      printf("unknown = %f\n", p2);
      break;
    
    case 'v':
      printf("P1? "); scanf(" %f", &p1);
      printf("V1? "); scanf(" %f", &v1);
      printf("T1? "); scanf(" %f", &t1);
      printf("P2? "); scanf(" %f", &p2);
      printf("T2? "); scanf(" %f", &t2);

      v2 = (p1 * v1 / t1) / (p2 / t2);
      printf("unknown = %f\n", v2);
      break;
    
    case 't':
      printf("P1? "); scanf(" %f", &p1);
      printf("V1? "); scanf(" %f", &v1);
      printf("T1? "); scanf(" %f", &t1);
      printf("P2? "); scanf(" %f", &p2);
      printf("V2? "); scanf(" %f", &v2);

      t2 = (p2 * v2) / (p1 * v1 * t1);
      printf("unknown = %f\n", t2);
      break;
      // should be good

      default:
        printf("crashout initating in 3.. 2.. 1..");
  }
}

struct module {
  char name[16];
  void *function;
};

struct module modlist[] = {
  {"ERROR!", search_fail},
  {"findfm", findfm},
  {"boyle", boyles_law},
  {"gaylussac", gaylussac},
  {"combgas", combined_gas_law}
  // add more as they are made
};

struct module getmodule(char name[16]) {
  for (int i = 0; i < sizeof(modlist) / sizeof(modlist[0]); i++) {
    if (!strcmp(modlist[i].name, name)) {
      return modlist[i];
    }
  } return modlist[0];
}

int main() {
  while (1) {
    char tosearch[16];
    printf("chemhelper (beta)\n\navailable modules: \n");
    for (int i = 1; i < (sizeof(modlist) / sizeof(modlist[0])); i++) {
      printf(" - %s\n", modlist[i].name);
    }
    printf("select one: ");
    scanf("%15s", tosearch);
    printf("\n");
    while ((getchar()) != '\n');
    
    for (int i = 0; i < strlen(tosearch); i++) {
      tosearch[i] = tolower(tosearch[i]);
    }
    
    module_function function = (module_function)getmodule(tosearch).function;
    function(); // shoutout chatgpt bruh idk wtf is going on here
    puts("\n-------------------\n");
  }
  
  return 0;
}
