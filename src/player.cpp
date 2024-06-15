#include "player.h"

namespace Game
{

    void Player::SetTurn(const bool aTurn)
    {
        if (_has_turn != aTurn)
        {
            _has_turn = aTurn;
        }
    }

}