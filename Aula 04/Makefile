NOME_DA_VAR=valor valor valor valor
OPTIMIZATION_LEVEL=3
ARQUIVOS=$(wildcard *.c)
default: arquivos struct_union_enum
MSG=

ifeq ($(SO), Windows)
	MSG='"Seu sistema é windows. Existe sim"'
else ifeq ($(SO), macOS)
	MSG='"Seu sistema é macOS. Existe sim"'
endif

all:
	echo $(MSG)

arquivos: ./arquivos.c
	echo $(ARQUIVOS)
	gcc -O$(OPTIMIZATION_LEVEL) -o $@ $^ -DESTAVARNAOEXISTE=$(MSG)

struct_union_enum: ./struct_union_enum.c
	gcc -O$(OPTIMIZATION_LEVEL) -o $@ $^

final: $(ARQUIVOS)
	echo "Compilando $^ para $@"
	gcc -O$(OPTIMIZATION_LEVEL) -o $@ $^