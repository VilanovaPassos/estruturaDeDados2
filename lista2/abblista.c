#include "abbLista.h"

Arvore *cria_arv_vazia(void)
{
    return NULL;
}

int verifica_arv_vazia(Arvore *a)
{
    return (a == NULL);
}

void arvore_libera(Arvore *a)
{
    if (a != NULL)
    {
        arvore_libera(a->esq);
        arvore_libera(a->dir);
        free(a);
    }
}

//========= Q1 - inserir
Arvore *inserir(Arvore *a, int v)
{
    if (a == NULL)
    {
        a = (Arvore *)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (v < a->info)
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
Arvore *remover(Arvore *a, int v)
{
    if (!verifica_arv_vazia(a))
    {
        // encontra chave
        if (a->info < v)
        {
            a->dir = remover(a->dir, v);
        }
        else if (a->info > v)
        {
            a->esq = remover(a->esq, v);
        }
        else
        {
            if ((a->esq == NULL) && (a->dir == NULL)) // remove no folha
            {
                free(a);
                a = NULL;
            }
            else if (a->esq == NULL) // substitui nó com nó maior a direita e remove nó
            {
                Arvore *tmp = a;
                a = a->dir;
                free(tmp);
            }
            else if (a->dir == NULL) // remove nó com nó menor a esquerda e remove nó
            {
                Arvore *tmp = a;
                a = a->esq;
                free(tmp);
            }
            else // substitui nó pai com o maior nó da sub-arvore a esquerda e manda remover nó substituído
            {
                Arvore *tmp = a->esq;
                while (tmp->dir != NULL)
                {
                    tmp = tmp->dir;
                }

                a->info = tmp->info;
                tmp->info = v;

                a->esq = remover(a->esq, v); // remove nó substituído
            }
        }
    }

    return a;
}

//========= Q1 - busca
int buscar(Arvore *a, int v)
{
    if (a != NULL)
    {
        if (a->info == v)
        {
            return 1;
        }
        else if (v < a->info)
        {
            return buscar(a->esq, v);
        }
        else
        {
            return buscar(a->dir, v);
        }
    }

    return 0;
}

//========= Q2 - min =====
int min(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        while (a->esq != NULL)
        {
            a = a->esq;
        }

        return a->info;
    }

    return -1;
}

//========= Q2 - max =====
int max(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        while (a->dir != NULL)
        {
            a = a->dir;
        }

        return a->info;
    }

    return -1;
}

//========= Q3 - imprime_decrescente =====
// in ordem trocado direita e esquerda
void imprime_decrescente(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}

//========= Q4 - maior ramo =====
int maior_ramo(Arvore *a)
{
    if (!verifica_arv_vazia(a))
    {
        int e = maior_ramo(a->esq);
        int d = maior_ramo(a->dir);

        return a->info + (e > d ? e : d);
    }

    return -1;
}

void pre_order(Arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        pre_order(a->esq);
        pre_order(a->dir);
    }
}

int main()
{

    Arvore *a = cria_arv_vazia();

    // inserir
    a = inserir(a, 50);
    a = inserir(a, 30);
    a = inserir(a, 90);
    a = inserir(a, 20);
    a = inserir(a, 40);
    a = inserir(a, 95);
    a = inserir(a, 10);
    a = inserir(a, 35);
    a = inserir(a, 45);

    if (buscar(a, 30))
    {
        printf("30 esta na arvore");
    }

    printf("\n");
    printf("o menor valor e %d", min(a));

    printf("\n");
    printf("o maior valor e %d", max(a));

    printf("\n");
    imprime_decrescente(a);

    printf("\n");
    printf("o maior ramo da arvore e %d", maior_ramo(a));

    // ====== Q5 ====
    /*o item a demora mais tempo pois produz uma arvore degenerada, o que leva ao pior caso com tempo n*/

    return 0;
}
