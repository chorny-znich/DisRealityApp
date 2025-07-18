#include "menu_screen.h"
#include "screen_manager.h"
#include <iostream>
#include <format>
#include "about_screen.h"

void MenuScreen::init()
{
  mBackground.setTexture(dr::Textures::get("menu_screen_background"));
	mMainMenu.setPosition({ 750.f, 350.f });
	mMainMenu.setColor(sf::Color(255, 255, 224));
	
	std::shared_ptr<dr::TextButton> buttonAbout = 
		std::make_shared<dr::TextButton>({ 200, 75 }, sf::Text()/*dr::TextManager::get("about_button")*/);
	buttonAbout->setFillColor(sf::Color(255, 165, 0));
  mMainMenu.addButton(buttonAbout);
  /*dr::TextButton buttonExit({200, 75}, dr::TextManager::get("exit_button"));
	buttonExit.setPosition( { 900, 900 } );
  mButtons.push_back(buttonExit);*/
}

void MenuScreen::inputHandler(sf::Keyboard::Key key, bool isPressed)
{
}

void MenuScreen::inputHandler(sf::Mouse::Button button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window)
{/*
	size_t buttonIndex = -1;

	for (size_t i = 0; i < mButtons.size(); ++i)
	{
		sf::Vector2f worldCoords = window->mapPixelToCoords(position, mMainView);
		if (mButtons[i].isClicked({ worldCoords.x, worldCoords.y }))
		{
			buttonIndex = i;
			break;
		}
	}

	switch (buttonIndex)
	{
	case 0:
		dr::ScreenManager::createScreen<AboutScreen>("ABOUT");
		break;
	case 1:
		dr::GameState::destroyScreen();
		break;
	}*/
}

void MenuScreen::update(sf::Time dt)
{
}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.setView(mMainView);
  window.draw(mBackground);
	mMainMenu.render(window);
	/*for (auto& btn : mButtons) {
    btn.render(window);
  }*/
}
