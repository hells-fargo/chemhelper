#include "./ptable.h"

struct element ptable[] = {
  // {atomic number, molar mass, abbreviation}
  // Element #0, !!, is used in place of an error.
  {0, 0, "!!"},
  {1, 1.01, "H"},
  {2, 4.00, "He"},
  {3, 6.94, "Li"},
  {4, 9.01, "Be"},
  {5, 10.81, "B"},
  {6, 12.01, "C"},
  {7, 14.01, "N"},
  {8, 16.00, "O"},
  {9, 18.99, "F"},
  {10, 20.18, "Ne"},
  {11, 22.99, "Na"},
  {12, 24.31, "Mg"},
  {13, 26.98, "Al"},
  {14, 28.09, "Si"},
  {15, 30.97, "P"},
  {16, 32.06, "S"},
  {17, 35.45, "Cl"},
  {18, 39.95, "Ar"},
  {19, 39.10, "K"},
  {20, 40.08, "Ca"},
  {21, 44.96, "Sc"},
  {22, 47.87, "Ti"},
  {23, 50.94, "V"},
  {24, 52.00, "Cr"},
  {25, 54.94, "Mn"},
  {26, 55.85, "Fe"},
  {27, 58.93, "Co"},
  {28, 58.69, "Ni"},
  {29, 63.55, "Cu"},
  {30, 65.38, "Zn"},
  {31, 69.72, "Ga"},
  {32, 72.63, "Ge"},
  {33, 74.92, "As"},
  {34, 78.97, "Se"},
  {35, 79.90, "Br"},
  {36, 83.80, "Kr"}
  // {etc...}
  // O(n)
};

const int ptSize = sizeof(ptable) / sizeof(ptable[0]);
// returns no. bytes occupied, divide by bytes occupied by a single one to get array size
