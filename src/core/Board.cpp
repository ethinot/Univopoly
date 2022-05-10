#include "Board.h"
#include "Property.h"
#include "Gare.h"
#include <iostream>
#include <fstream>


Board::Board(){
    game_board.push_back(Tile("Start", "white", 0, -1, -1));
    game_board.push_back(Property("Braconnier", "violet", 1, 60, 30, 50, 2, 10, 30, 90, 160, 250));
    game_board.push_back(Tile("Chance", "white", 2, -1, 100));
    game_board.push_back(Property("Darwin", "violet", 3, 60, 30, 50, 4, 20, 60, 180, 320, 450));
    game_board.push_back(Tile("AML", "white", 4, 50, 100));
    game_board.push_back(Gare("Condorcet", "white", 5, 200, 100));
    game_board.push_back(Property("Gouy", "cyan", 6, 100, 50, 50, 6, 30, 90, 270, 400, 550));
    game_board.push_back(Tile("Chance", "white", 7, -1, 100));
    game_board.push_back(Property("Lippmann", "cyan", 8, 100, 50, 50, 6, 30, 90, 270, 400, 550));
    game_board.push_back(Property("Ampere", "cyan", 9, 120, 60, 50, 8, 40, 100, 300, 450, 600));
    game_board.push_back(Tile("Visit Prison", "white", 10, -1, -1));
    game_board.push_back( Property("Polytech", "purple", 11, 140, 70, 100, 10, 50, 150, 450, 625, 750));
    game_board.push_back(Tile("Stage", "white", 12, 200, 100));
    game_board.push_back(Property("SUAPS HallTennis", "purple", 13, 140, 70, 100, 10, 50, 150, 450, 625, 750));
    game_board.push_back(Property("SUAPS Complexe", "purple", 14, 160, 80, 100, 12, 60, 180, 500, 700, 900));
    game_board.push_back(Gare("Universite Lyon 1", "white", 15, 200, 100));
    game_board.push_back(Property("Forel", "orange", 16, 180, 90, 100, 14, 70, 200, 550, 700, 900));
    game_board.push_back(Tile("Chance", "white", 17, 200, 100));
    game_board.push_back(Property("Ariane", "orange", 18, 180, 90, 100, 14, 70, 200, 550, 700, 950));
    game_board.push_back(Property("Marie-Curie", "orange", 19, 200, 100, 100, 16, 80, 220, 600, 800, 1000));
    game_board.push_back(Tile("Parc", "white",20, 200, 100));
    game_board.push_back(Property("Berthollet", "red", 21, 220, 110, 150, 18, 90, 250, 700, 875, 1050));
    game_board.push_back(Tile("Chance", "white", 22, 200, 100));
    game_board.push_back(Property("Omega", "red", 23, 220, 110, 150, 18, 90, 250, 700, 875, 1050));
    game_board.push_back(Property("Quai 43", "red", 24, 140, 120, 150, 20, 100, 300, 750, 925, 1100));
    game_board.push_back(Gare("Gaston Berger", "white", 25, 200, 100));
    game_board.push_back(Property("Deambu 2", "yellow", 26, 260, 130, 150, 22, 110, 330, 800, 975, 1150));
    game_board.push_back(Property("Deambu 3", "yellow", 27, 260, 130, 150, 22, 110, 330, 800, 975, 1150));
    game_board.push_back(Tile("Stage", "white", 28, 200, 100));
    game_board.push_back(Property("Deambu 4", "yellow", 29, 280, 140, 150, 24, 120, 360, 850, 1025, 1200));
    game_board.push_back(Tile("Go To Jail", "white", 30, 200, 100));
    game_board.push_back(Property("Grignard", "green", 31, 300, 150, 200, 26, 130, 390, 900, 1100, 1275));
    game_board.push_back(Property("Astree", "green", 32, 300, 150, 200, 26, 130, 390, 900, 1100, 1275));
    game_board.push_back(Tile("Chance", "white", 33, 200, 100));
    game_board.push_back(Property("Themis", "green", 34, 320, 160, 200, 28, 150, 450, 1000, 1200, 1400));
    game_board.push_back(Gare("INSA Einstein", "white", 35, 200, 100));
    game_board.push_back(Tile("Chance", "white", 36, 200, 100));
    game_board.push_back(Property("Nautibus Ext", "blue", 37, 350, 175, 200, 35, 175, 500, 1100, 1300, 1500));
    game_board.push_back(Tile("AML", "white", 38, 200, 100));
    game_board.push_back(Property("Nautibus", "blue", 39, 400, 200, 200, 50, 200, 600, 1400, 1700, 2000));

}

Board::Board(std::string filename){

}

Board::~Board() {
    game_board.clear();
}

Tile* Board::getTile(unsigned int property_id){ 
    return &game_board[property_id];
}
	