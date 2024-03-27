#include "Categoria.h"

int Categoria::ganancia(int categoria) {
    if(categoria == 1)
        return 15;
    if (categoria == 2)
        return 20;
    if (categoria == 3)
        return 30;
    return 0;
}
