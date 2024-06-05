#ifndef CARD_H
#define CARD_H

#include "bn_sprite_ptr.h"

namespace Game
{

class Card
{

public:
   
    explicit Card(int aNumber, int aFamily, bn::sprite_ptr& aSprite);

    bn::sprite_ptr& _sprite;

    int _number = -1;
    int _family = -1;

};

}

#endif
