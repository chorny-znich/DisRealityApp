#include "game_engine.h"
#include "menu_screen.h"
#include "game_data.h"
#include <disreality_engine.h>
#include <iostream>

void GameEngine::createStartScreen()
{
  dr::ScreenManager::createScreen<MenuScreen>("MENU");
}

void GameEngine::init()
{
  try {
    dr::Textures::init(GameData::path::TextureListFile);
    dr::Fonts::init(GameData::path::FontListFile);
  }
  catch (const std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }
  sf::Font& mainFont = dr::Fonts::get("main");
  // sf::Text object for text on the about screen
  sf::Text aboutText;
  aboutText.setFont(mainFont);
  aboutText.setCharacterSize(75);
  aboutText.setFillColor(sf::Color::Black);

  aboutText.setString("This is a template for all apps build on the DisReality Engine");
  dr::TextManager::load("description", aboutText);

  aboutText.setCharacterSize(25);
  aboutText.setString("version 0.1.0");
  dr::TextManager::load("version", aboutText);
}