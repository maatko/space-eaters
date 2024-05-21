#ifndef DATA_D
#define DATA_D

#include <entity/component/component.h>

typedef struct data_t
{
    float score;

    int hearts;
    int bombs;

    float player_speed;
    float star_speed;
    float enemy_speed;

    collision_callback collision_callback;
} data_t;

extern data_t data;

#endif //DATA_D