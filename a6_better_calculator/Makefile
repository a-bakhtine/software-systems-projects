#!/bin/bash

.PHONY: test
test: minicalc
	./run-tests

minicalc: minicalc.c
	gcc -Wall -o minicalc minicalc.c -lm 

stringbuilder: stringbuilder.c stringbuilder.h
	gcc -Wall -o stringbuilder stringbuilder.c
