// shoutout to chatgpt for resolving weird ahh compiler error
// i tried to put the periodic table in a different file, just as an array of elements
// it worked until it didn't..???!?!!?!?!!??!?!

#ifndef PTABLE_H
#define PTABLE_H

#include <stdint.h>

struct element {
    uint8_t atomicnum;
    float molarmass;
    char abbr[3];
};

extern struct element ptable[];
// im writing this comment so i remember in future
// fyi extern basically just tells the compiler
// that this variable or function is defined, just not in this file.

#endif
