#include "Board.h"
#include "Property.h"
#include "Gare.h"
#include <iostream>
#include <fstream>




Board::Board(){
    game_board.push_back(new Property("Property1", 1, 200, 100, 50, 25, 30, 35, 40, 45, 60));
    game_board.push_back(new Property("Property2", 2, 200, 100, 50, 25, 30, 35, 40, 45, 60));
    game_board.push_back(new Property("Property3", 3, 200, 100, 50, 25, 30, 35, 40, 45, 60));

    //game_board.push_back(new Gare("Gare1", 1, 100, 50, 25));

    game_board.push_back(new Property("Property4", 4, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property5", 5, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property6", 6, 300, 150, 70, 40, 40, 45, 50, 55, 65));

    //game_board.push_back(new Gare("Gare2", 2, 100, 50, 25));

    game_board.push_back(new Property("Property1", 7, 200, 100, 50, 25, 30, 35, 40, 45, 60));
    game_board.push_back(new Property("Property2", 8, 200, 100, 50, 25, 30, 35, 40, 45, 60));
    game_board.push_back(new Property("Property3", 9, 200, 100, 50, 25, 30, 35, 40, 45, 60));

    //game_board.push_back(new Gare("Gare1", 3, 100, 50, 25));

    game_board.push_back(new Property("Property4", 10, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property5", 11, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property6", 12, 300, 150, 70, 40, 40, 45, 50, 55, 65));

    //game_board.push_back(new Gare("Gare2", 4, 100, 50, 25));
    game_board.push_back(new Property("Property4", 13, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property5", 14, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property6", 15, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property4", 16, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property5", 17, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property6", 18, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property4", 19, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property5", 20, 300, 150, 70, 40, 40, 45, 50, 55, 65));
    game_board.push_back(new Property("Property6", 21, 300, 150, 70, 40, 40, 45, 50, 55, 65));
}

Board::Board(std::string filename){

}

Board::~Board() {
    game_board.clear();
}

Tile* Board::getTile(unsigned int property_id){
    return game_board[property_id];
}
	