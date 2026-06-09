#pragma once
#include <disreality_engine.h>

/**
 * @brief Information about the application
 */
class AboutScreen : public dr::Screen
{
public:
	void init();
	void handleInput();
	void update(float dt);
	void render(sf::RenderWindow& window);
};