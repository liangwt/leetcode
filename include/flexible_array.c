#include <stdlib.h>
#include <stdbool.h>

#define INIT_LEN 8
#define EXPANSION_COEFFICIENT 128

typedef struct _flexible_array
{
    int cap;
    int len;
    void **els;
} flexible_array;

void flexible_array_create(int init_len)
{
    flexible_array *array = malloc(sizeof(flexible_array));
    if (!array)
    {
        return;
    }
    init_len = (init_len && init_len > INIT_LEN) ? init_len : INIT_LEN;
    void **els = malloc(sizeof(void *) * init_len);
    if (!els)
    {
        return;
    }

    array->len = 0;
    array->els = els;
    array->cap = INIT_LEN;
}

int _flexible_array_expansion_compute(int cap)
{
    return cap < EXPANSION_COEFFICIENT ? cap * 2 : EXPANSION_COEFFICIENT;
}

void _flexible_array_expansion(flexible_array *array)
{
    int cap = _flexible_array_expansion_compute(array->cap);
    void **els = realloc(array->els, sizeof(void *) * cap);
    array->els = els;
    array->cap = cap;
    return;
}

bool flexible_array_push(flexible_array *array, void *el)
{
    // should resize array
    if (array->len == array->cap)
    {
        _flexible_array_expansion(array);
    }

    array->els[array->len] = el;
    array->len++;
}
