# Makefile

all: build run

run:
	@./main

build: mkbin
	@g++ \
	-g \
	main.cpp \
	-o bin/cppdsa

mkbin:
	@mkdir -p bin