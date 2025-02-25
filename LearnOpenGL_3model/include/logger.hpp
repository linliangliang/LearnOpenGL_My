#pragma once


#include <stdio.h>

#define glLOG(...) { \
fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__); \
fprintf(stderr, __VA_ARGS__); \
fprintf(stderr,"\n"); \
}
