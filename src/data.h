#ifndef DATA_D
#define DATA_D

#include <entity/component/component.h>

typedef struct data_t
{
    float score;

    int hearts;
    int bombs;

    struct 
    {
        float player;
        float enemy;
        float star;
    } speed;

    collision_callback collision_callback;
} data_t;

extern data_t data;

#endif //DATA_D