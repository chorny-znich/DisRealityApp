#include "main_menu_screen.h"
#include "about_screen.h"

/**
 * @brief For handling Events in handleInput method
 */

struct MainMenuScreen::ScreenInputVisitor
{
	MainMenuScreen& screen;
	sf::RenderWindow& window;

	void operator()(const sf::Event::MouseMoved& mouseMoved)
	{
		sf::Vector2f mouseViewCoords = window.mapPixelToCoords(mouseMoved.position);
		for (auto& button : screen.mMenuButtons)
		{
			button.isOverlap(mouseViewCoords);
		}
	}

	/**
	 * @brief Mouse button clicked event
	 * @param  
	 */
	void operator()(const sf::Event::MouseButtonPressed mouseButton)
	{
		if (mouseButton.button == sf::Mouse::Button::Left)
		{
			sf::Vector2f mouseViewCoords = window.mapPixelToCoords(mouseButton.position);
			if (screen.mMenuButtons[0].isClicked(mouseViewCoords))
			{
				dr::ScreenManager::addScreen<AboutScreen>("about_screen");
			}
			if (screen.mMenuButtons[1].isClicked(mouseViewCoords))
			{
				dr::ScreenManager::destroyScreen();
			}
		}
	}

	void operator()(const auto&) {};
};

void MainMenuScreen::init()
{
	dr::TextButton aboutButton{ {150.f, 50.f}, dr::TextManager::get("normal_button") };
	aboutButton.setString(dr::StringManager::get("about_button"));
	aboutButton.setPosition({ 865.f, 800.f });
	mMenuButtons.push_back(aboutButton);

	dr::TextButton exitButton{ {150.f, 50.f}, dr::TextManager::get("normal_button") };
	exitButton.setString(dr::StringManager::get("exit_button"));
	exitButton.setPosition({ 865.f, 875.f });
	mMenuButtons.push_back(exitButton);
}

void MainMenuScreen::handleInput(const sf::Event& event, sf::RenderWindow& window)
{
	event.visit(ScreenInputVisitor{ *this, window });
}
void MainMenuScreen::update(float dt)
{ }
void MainMenuScreen::render(sf::RenderWindow& window)
{
	window.setView(mMainView);

	for (auto& button : mMenuButtons)
	{
		button.render(window);
	}
}