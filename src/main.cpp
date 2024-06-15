#include "bn_core.h"

#include "bn_keypad.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"
#include "bn_unordered_map.h"

#include "bn_sprite_items_hearts_card_01.h"
#include "bn_sprite_items_spades_card_01.h"
#include "bn_sprite_items_clubs_card_01.h"
#include "bn_sprite_items_diamonds_card_01.h"

#include "bn_sprite_items_spades_1.h"
#include "bn_sprite_items_spades_2.h"

#include "common_variable_8x8_sprite_font.h"

#include "card.h"
#include "player.h"
#include "master.h"

namespace
{
    /**
    void move(bn::sprite_ptr& Card)
    {
        if(bn::keypad::up_held())
        {
            Card.set_y(Card.y() - 1);
        }
        if(bn::keypad::down_held())
        {
            Card.set_y(Card.y() + 1);
        }
        if(bn::keypad::left_held())
        {
            Card.set_x(Card.x() - 1);
        }
        if(bn::keypad::right_held())
        {
            Card.set_x(Card.x() + 1);
        }
    }
    */

   void ChangeTurn(Game::Player& MainPlayer, Game::Player& MainMaster)
   {
        MainPlayer.SetTurn(!MainPlayer.HasTurn());
        MainMaster.SetTurn(!MainMaster.HasTurn());
   }

}

int main()
{
    bn::core::init();
    
    bn::bg_palettes::set_transparent_color(bn::color(6, 25, 6));

    //bn::sprite_ptr Card = bn::sprite_items::spades_1.create_sprite(0, 0);
    //bn::sprite_ptr SpadeCard = bn::sprite_items::spades_card_01.create_sprite(50, 0);
    //bn::sprite_ptr DiamondCard = bn::sprite_items::diamonds_card_01.create_sprite(-50, 0);
    //bn::sprite_ptr ClubsCard = bn::sprite_items::clubs_card_01.create_sprite(0,-40);

    bn::vector<bn::sprite_ptr, 16> TextSprites;
    bn::string<128> Text = " ";
    bn::sprite_text_generator TextGenerator(common::variable_8x8_sprite_font);

    //bn::sprite_ptr sprite = bn::sprite_items::spades_1.create_sprite(0, 0);
    //Game::Card card = Game::Card(1, 1, sprite);
    
    //bn::sprite_ptr& card_sprite = card.GetSprite();

    bn::unordered_map<bn::string<32>, Game::Card, 64> CardStack;

    for (uint16_t i = 1; i < 5; ++i)
    {
        bn::string<16> key_i = bn::to_string<16>(i);
        for (uint16_t j = 1; j < 14; ++j)
        {
            bn::string<16> key_j = bn::to_string<16>(j);
            CardStack[key_j + key_i] = Game::Card(j, i);
        }
    }

    Game::Player MainPlayer = Game::Player();
    Game::Master MainMaster = Game::Master();

    MainPlayer.SetTurn(true);

    while(true)
    {
        
        
        
        
        TextSprites.clear();
        
        Text = "Player turn: " + bn::to_string<64>(MainPlayer.HasTurn()) + " Master turn: " + bn::to_string<64>(MainMaster.HasTurn()) ;
        TextGenerator.generate(-6 * 16, -68, Text, TextSprites);

        if ((MainPlayer.HasTurn() and bn::keypad::any_pressed()) or (MainMaster.HasTurn() and bn::keypad::any_pressed()))
        {
            ChangeTurn(MainPlayer, MainMaster);
        }

        //Text = "Family: " + bn::to_string<32>(CardStack["112"].GetFamily()) + " Number: " + bn::to_string<32>(CardStack["112"].GetNumber());
        //TextGenerator.generate(-6 * 16, -68, Text, TextSprites);
        
        //move(card_sprite);
        //Text = "X: " + bn::to_string<16>(card_sprite.x()) + " Y: " + bn::to_string<16>(card_sprite.y());
        //TextGenerator.generate(-6 * 16, -68, Text, TextSprites);

        bn::core::update();
    }
}



