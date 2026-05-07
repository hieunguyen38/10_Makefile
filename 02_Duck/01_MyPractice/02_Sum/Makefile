PROJ_NAME := sum
OBJ_FILES = Output/main.o
OBJ_FILES += Output/$(PROJ_NAME).o

Output/main.o: Src/main.c
	@gcc -c -I./Inc Src/main.c -o Output/main.o
	
Output/$(PROJ_NAME).o: Src/$(PROJ_NAME).c
	@gcc -c -I./Inc Src/$(PROJ_NAME).c -o Output/$(PROJ_NAME).o
	
.PHONY: build
build: $(OBJ_FILES)
	@gcc $(OBJ_FILES) -o Output/main.exe
	@echo "Build Done!"
	@echo $(OBJ_FILES)

.PHONY: run
run:
	Output/main.exe

.PHONY: clean
clean:
	@rm ./Output/*
	@echo "Clear All Output File!"
	
print-%:
	@echo $($(subst print-,,$@))
	