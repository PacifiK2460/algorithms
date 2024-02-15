#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int _random(int min, int max)
{
    return min + rand() % (max - min);
}

void merge(int *array, int start, int end)
{
    int len = end - start;
    if (len <= 1)
    {
        // Si no tengo elementos, o solo tengo 1, no tengo que hacer nada
        return;
    }

    int mid = start + len / 2;
    merge(array, start, mid);
    merge(array, mid, end);

    int temp[len];
    int i = start;
    int j = mid;
    for (int k = 0; k < len; k++)
    {
        /*
            Si todavia tengo elementos a comparar en la primera mitad y:
                - No tengo elementos en la segunda mitad
                - O el elemento de la primera mitad es menor que el de la segunda mitad

            Entonces, el elemento que va en la posicion k es el de la primera mitad.

            En caso contrario, simplemente copio el elemento de la segunda mitad.
        */
        if (i < mid && (j >= end || array[i] < array[j]))
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }

    // Copio los elementos ordenados en el array original
    for (int k = 0; k < len; k++)
    {
        array[start + k] = temp[k];
    }
}

int main()
{
    int len = 99999;
    srand(time(NULL));

    int unsorted[len];
    for (int i = 0; i < len; i++)
    {
        unsorted[i] = _random(1, len);
        printf("%d ", unsorted[i]);
    }
    printf("\n");

    merge(unsorted, 0, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", unsorted[i]);
    }
    printf("\n");
}