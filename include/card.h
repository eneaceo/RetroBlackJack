#ifndef CARD_H
#define CARD_H

#include "bn_sprite_ptr.h"

namespace Game
{

class Card
{

public:

    Card();
    Card(uint16_t aNumber, uint16_t aFamily);
    //Card(uint16_t aNumber, uint16_t aFamily, bn::sprite_ptr& aSprite);

    //inline bn::sprite_ptr& GetSprite() const {return _sprite;}
    
    inline uint16_t GetNumber() const {return _number;}
    inline uint16_t GetFamily() const {return _family;}
    
    inline uint16_t GetPosition() const {return _position;}
    void SetPosition(const uint16_t aPosition);

private:

    //bn::sprite_ptr& _sprite;

    uint16_t _number;
    uint16_t _family;

    uint16_t _position;

};

}

#endif
