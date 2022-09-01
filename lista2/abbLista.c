#include <time.h>
#include "abbLista.h"



Arvore* cria_arvore_vazia (void) 
{
   return NULL;
}

void arvore_libera (Arvore* a)
{
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}


//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v)
{
   if (a == NULL)
   {
    a = (Arvore*)malloc(sizeof(Arvore));
    a->info = v;
    a->esq = NULL;
    a->dir = NULL;
   }
   else if (v <= a->info)
   {
    a->esq = inserir(a->esq, v);
   }
   else
   {
    a->dir = inserir(a->dir, v);
   }
   
   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) 
{
    if (a != NULL)
    {
        if (a->info == v)
        {
            if ((a->esq == NULL) && (a->dir == NULL))
            {
                free(a);
                return NULL;
            }
            else if ((a->esq != NULL) && (a->dir != NULL))
            {
                Arvore* temp = a->esq;
                while (temp->dir != NULL)
                {
                    temp = temp->dir;
                }

                a->info = temp->info;
                temp->info = v;
                a->esq = remover(a->esq, v);

                return a;
            }
            
            else if(a->esq != NULL)
            {
                Arvore* temp = a;
                a = a->esq;

                free(temp);
            }
            else if(a->dir != NULL)
            {
                Arvore* temp = a;
                a = a->dir;

                free(temp);
            }

        
        }
        else if(v <= a->info)
        {
            a->esq = remover(a->esq, v);
        }
        else
        {
            a->dir = remover(a->dir, v);
        }
    }

   
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) 
{
   if (a == NULL)
   {
        return 0;
   }
   else if (v < a-> info)
   {
        return buscar(a->esq, v);
   }
   else if (v > a->info)
   {
        return buscar(a->dir, v);
   }
   else
   {
        return 1;
   }
   
    
}

//========= Q2 - min =====
int min(Arvore* a) //retorna valor minimo ou NULL se arvore estiver vazia
{
    int n = NULL;
    Arvore* aux;

    aux = a;

    while (aux != NULL)
    {
        n = a->info;

        aux = aux->esq;
    }

    return n;
    
}

//========= Q2 - max =====
int max(Arvore* a) //retorna valor maximo ou NULL se arvore estiver vazia
{
    int n = NULL;
    Arvore* aux;

    aux = a;

    while (aux != NULL)
    {
        n = a->info;

        aux = aux->dir;
    }

    return n;
    
}

//========= Q3 - imprime_decrescente =====
void imprimeDecrescente(Arvore* a)
{
   if (a != NULL)
   {
      imprimeDecrescente(a->dir);
      printf("%d, ", a->info);
      imprimeDecrescente(a->esq);  
   }
}



//========= Q4 - maior ramo =====
int maiorRamo(Arvore* a)
{
   if (a != NULL)
   {
      int n1 = maiorRamo(a->esq);
      int n2 = maiorRamo(a->dir);

      return a->info + ( (n1 >= n2) ? n1 : n2);
   }

   return 0;
   
}


void pre_order (Arvore* a) 
{
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () 
{

    //int i;

    Arvore *a = cria_arvore_vazia ();

    //inserir
    /*
    a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);

    printf("\n");
    pre_order (a);	
    printf("\n");

    //busca valor a arvore
    if (buscar(a, 40))
    {
        printf("40 esta na arvore\n");
    }
     else
    {
        printf("90 nao esta na arvore");
    }
    
    //remove
    remover(a, 90);

    printf("\n");
    pre_order (a);	
    printf("\n");

    if (buscar(a, 90))
    {
        printf("90 esta na arvore\n");
    }
    else
    {
        printf("90 nao esta na arvore");
    }
    
    //imprime maior e menor chave
    printf("O menor valor na arvore é $d\n\n", min(a));
    printf("O menor valor na arvore é $d\n\n", min(a));

    //imprime decrescente
    imprimeDecrescente(a);
    //maior ramo
    printf("\n\nmaior ramo %d", maiorRamo(a));
    */

    // ====== Q5 ====
    // insere 10000 valores em sequencia 
    /*
    for (int i = 0; i < 10000; i++)
    {
        a = inserir(a, i);
    }

    if (buscar(a, 10000))
    {
        printf("10000 esta na arvore\n");
    }
     else
    {
        printf("10000 nao esta na arvore");
    }
    

    //numeros aleatorios
    srand(time(NULL));
     for (int i = 0; i < 10000; i++)
    {
        a = inserir(a, (rand()%10000));
    }

    if (buscar(a, 10000))
    {
        printf("10000 esta na arvore\n");
    }
     else
    {
        printf("10000 nao esta na arvore");
    }

    */

    arvore_libera(a);
    return 0;
}

