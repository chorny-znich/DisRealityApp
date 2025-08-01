#include "about_screen.h"

void AboutScreen::init()
{
	mBackground.setTexture(dr::Textures::get("disreality_engine_background"));
	/*
	sf::Text description = dr::TextManager::get("description");
	description.setPosition(200, 500);
	mInfo.push_back(description);

	sf::Text version = dr::TextManager::get("version");
	version.setPosition(900, 600);
	mInfo.push_back(version);
	*/
	mMainMenu.setPosition({ 850.f, 900.f });
	mMainMenu.setColor(sf::Color(255, 255, 224, 255));
	mMainMenu.addImageButton({ 300.f, 120.f }, "button_back");
  /*dr::TextButton buttonBack({200, 75}, dr::TextManager::get("back_button"));
	buttonBack.setPosition({ 900, 1000 });
  mButtons.push_back(buttonBack);*/
}

void AboutScreen::inputHandler(sf::Keyboard::Key key, bool isPressed)
{
}

void AboutScreen::inputHandler(sf::Mouse::Button button, bool isPressed, sf::Vector2i position, sf::RenderWindow* window)
{
	sf::Vector2f worldCoords = window->mapPixelToCoords(position, mMainView);
	int buttonIndex = mMainMenu.handleInput(worldCoords);

	switch (buttonIndex)
	{
	case 0:
		dr::GameState::destroyScreen();
		break;
	}
}

void AboutScreen::update(sf::Time dt)
{
}

void AboutScreen::render(sf::RenderWindow& window)
{
	window.setView(mMainView);
	window.draw(mBackground);
	mMainMenu.render(window);
}