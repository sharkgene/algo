//algo.cpp
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>

using namespace std;

extern "C" {
	char* echo(char* o) {
		char* out = (char*)malloc(strlen(o)+1);
		strcpy(out, o);
		return out;
	}
}