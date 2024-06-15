#include "card.h"

namespace Game
{

    Card::Card() :
        Card(0, 0)
    {}

    Card::Card(uint16_t aNumber, uint16_t aFamily) :
        _number(aNumber), _family(aFamily)
    {}
    /**
    Card::Card(uint16_t aNumber, uint16_t aFamily, bn::sprite_ptr& aSprite) :
        Card(aNumber, aFamily), _sprite(aSprite)
    {}
    */

    void Card::SetPosition(const uint16_t aPosition)
    {
        if (aPosition != _position)
        {
            _position = aPosition;
        }
    }
}