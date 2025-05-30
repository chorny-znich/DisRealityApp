#include "game_engine.h"
#include "game_data.h"
#include <DisRealityGF.h>
#include <iostream>

void GameEngine::init()
{
  try {
    dr::Textures::init(GameData::path::TextureListFile);
  }
  catch (const std::runtime_error& err) {
    std::cout << err.what() << std::endl;
  }
}