#include "about_screen.h"

/**
 * @brief Initialize screen resources
 */
void AboutScreen::init()
{
	sf::Text description = dr::TextManager::get("main_description");
	description.setPosition({ 200.f, 500.f });
	description.setString("Description");
	mInfo.push_back(description);

	sf::Text version = dr::TextManager::get("main_version");
	version.setPosition({ 900.f, 600.f });
	version.setString("Version");
	mInfo.push_back(version);
}

void AboutScreen::handleInput(const sf::Event& event)
{
}

void AboutScreen::update(float dt)
{
}

void AboutScreen::render(sf::RenderWindow& window)
{
	//window.setView(mMainView);

	for (const auto& txt : mInfo) 
	{
		window.draw(txt);
	}
}
