#include "card.h"

namespace Game
{

    Card::Card(int aNumber, int aFamily, bn::sprite_ptr& aSprite) :
        _number(aNumber), _family(aFamily), _sprite(aSprite)
    {}

}