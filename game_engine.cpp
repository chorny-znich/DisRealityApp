#include "game_engine.h"
#include "about_screen.h"
#include <disreality_engine.h>

void GameEngine::init()
{
}

/**
 * @brief Create the start screen. Usually a screen with the main menu
 */
void GameEngine::createStartScreen()
{
  dr::ScreenManager::addScreen<AboutScreen>("about_screen");
}