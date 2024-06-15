#ifndef PLAYER_H
#define PLAYER_H


namespace Game
{

class Player
{

public:

    Player() {};

    inline bool HasTurn() const {return _has_turn;};
    
    void SetTurn(const bool aTurn);

private:

    bool _has_turn;

};

}

#endif
