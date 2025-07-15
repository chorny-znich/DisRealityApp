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
  }
  catch (const std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }
}