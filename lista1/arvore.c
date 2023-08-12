#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====
void preOrdem(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        printf("%c", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
    
}

//========= Exercício 2 - in-ordem ====
void inOrdem(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        inOrdem(a->esq);
        inOrdem(a->dir);
        printf("%c", a->info);
    }
    
}

//========= Exercício 2 - pós-ordem ====
void posOrdem(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        posOrdem(a->esq);
        printf("%c", a->info);
        posOrdem(a->dir);
    }
    
}

//========= Exercício 3 - pertence ====
int pertence_arv (Arvore *a, char c)
{
    if (!verifica_arv_vazia(a))
    {
        if (a->info == c)
        {
            return 1;
        }
        else
        {
            return (pertence_arv(a->esq, c) + pertence_arv(a->dir, c));
        }
        
    }

    return 0;
    
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
       return 1 + (conta_nos(a->esq) + conta_nos(a->dir));
        
    }

    return 0;
}

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        int e = calcula_altura_arvore(a->esq);
        int d = calcula_altura_arvore(a->dir);

        return 1 + (e > d ? e : d);
        
    }
    
    return -1;
}


//========= Exercício 6 - conta folhas ====
int conta_nos_folha (Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        if ((a->esq == NULL) && (a->dir == NULL))
        {
            return 1;
        }
        else
        {
            return (conta_nos_folha(a->esq) + conta_nos_folha(a->dir));
        }
        
    }

    return 0;
    
}


int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   printf("pre-ordem:");
   preOrdem(a);
   printf("in-ordem:");
   inOrdem(a);
   printf("pos-ordem:");
   posOrdem(a);
   if (pertence_arv(a, 'e'))
   {
    printf("a letra 'e' esta na arvore");
   }
   
   printf("a arvore tem %d nos", conta_nos(a));
   printf("a arvore tem %d nos folha", conta_nos_folha(a));
   printf("a arvore tem uma alturea de %d ", calcula_altura_arvore(a));


   arv_libera (a);

   return 0;
}
