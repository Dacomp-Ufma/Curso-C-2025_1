#include <stdio.h>

//                    STRUCTS                             //

typedef struct {
  int id;
  char* nome;
  float nota;
} ALUNO;

typedef struct frutas {
  int banana;
  char* melancia;
  float abacaxi;
  double melão;
} FRUTAS;

ALUNO nova_struct(int id, char* nome, float nota) {
  ALUNO retorno;
  retorno.id = id;
  retorno.nome = nome;
  retorno.nota = nota;

  return retorno;
}

void imprimir_nome(ALUNO aluno_para_imprimir) {
  printf("%s\n", aluno_para_imprimir.nome);
}

//                    ENUMS                             //
enum SONIC1_STAGES {
  GREEN_HILL = 5,
  MARBLE_ZONE,
  LABYRINT_ZONE,
  SCRAP_BRAIN,
};

enum DOOM1_STAGES {
  KNEE_DEEP_IN_THE_DEAD,
  THE_SHORES_OF_HELL,
  INFERNO,
  THY_FLESH_CONSUMED
};

//                    UNIONS                             //
union magica {
  int numero1;
  int numero2;
  int numero3;
};

union pessoa {
  ALUNO aluno;
  ALUNO pessoa;
  ALUNO ser;
  ALUNO mamífero;
  ALUNO vertebrado;
};


int main(){
  //                    STRUCTS                             //
  ALUNO alunos[10];

  ALUNO minha_nova_struct = nova_struct(5, "Asfalto", 5.0f);

  //imprimir_nome(minha_nova_struct);

  //                     ENUMS                             //
  enum SONIC1_STAGES current_stage = GREEN_HILL;

  current_stage = MARBLE_ZONE;

  int doom1_current_stage = KNEE_DEEP_IN_THE_DEAD;

  doom1_current_stage = THE_SHORES_OF_HELL;

  doom1_current_stage = THY_FLESH_CONSUMED;

  if (current_stage = THY_FLESH_CONSUMED);

  //                    UNIONS                             //
  union magica minha_magica;

  minha_magica.numero1 = 5;

  printf("%d\n", minha_magica.numero3);

  union pessoa minha_nova_pessoa;

  minha_nova_pessoa.aluno = nova_struct(5, "Asfalto", 5.0f);

  imprimir_nome(minha_nova_pessoa.mamífero);


  return 0;
}
