#pragma once
#include 'CommonHeader.h'

#define MAX_SIZE 100


inline void error(const char* str) {
	printf("%s\n", str);
	exit(1);
}