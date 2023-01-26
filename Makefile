SRC = $(wildcard src/*.c)

NAME = PathFinding

CC = gcc

CFLAGS = -Wall -Wextra -g -Og #-fsanitize=address
LDFLAGS = -lmlx -lm -lbsd -lX11 -lXext

OBJ_DIR = obj
SRC_DIR = src
DOC_DIR = doc
BIN_DIR = bin
INC_DIR = inc
MLX_DIR = minilibx-linux

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:$(SRC_DIR)/%.c=%.o))

# -j multifil (multi threads) / ameliore la vitesse de compliation
# --no-print-directory / n'affiche pas: make[N]: Leaving directory '...'
all:
	@$(MAKE) -j $(BIN_DIR)/$(NAME) --no-print-directory

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
$(BIN_DIR)/$(NAME): $(OBJ) .gitignore
	@mkdir -p $(BIN_DIR)
	$(CC) -o $@ -L $(MLX_DIR) $(OBJ) $(LDFLAGS)
	@echo $(NAME) : created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)	
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@rm -fr $(DOC_DIR)
	@rm -rf $(BIN_DIR)
	@echo "obj, bin, doc deleted"

init:	
	@mkdir -p src inc
	@echo $(SRC_DIR) $(INC_DIR) : created !

doc:
	@mkdir -p doc
	@echo creation of the DoxyFile...
	echo DOXYFILE_ENCODING      = UTF-8 > $(DOC_DIR)/DoxyFile
	echo PROJECT_NAME           = "$(NAME)" >> $(DOC_DIR)/DoxyFile
	echo OUTPUT_LANGUAGE        = French >> $(DOC_DIR)/DoxyFile
	echo INPUT                  = ../src ../inc ../README.md >> $(DOC_DIR)/DoxyFile
	echo OPTIMIZE_OUTPUT_FOR_C  = YES >> $(DOC_DIR)/DoxyFile
	echo QUIET                  = YES >> $(DOC_DIR)/DoxyFile
	@echo $(DOC_DIR)/DoxyFile : created !

docHtml:
	@(cd doc; doxygen DoxyFile)
	firefox ./doc/html/index.html &

re: clean all

.gitignore:
	@echo $(OBJ_DIR) > .gitignore
	@echo $(BIN_DIR) >> .gitignore
	@echo $(DOC_DIR) >> .gitignore
	@echo *.log >> .gitignore
	@echo ".gitignore created !"

#Un peu inutile mais CY-tech le veux dans son Makefile
save:
	cp -r src .save
	echo .save >> .gitignore
	@echo "save src and update .gitignore"

restore:
	cp -fr .save restore

.PHONY: all, clean, init, save, doc, docHtml
