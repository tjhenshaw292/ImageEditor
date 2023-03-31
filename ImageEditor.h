#pragma once
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"

class ImageEditor
{
	sf::RenderWindow m_window;
	sf::Font m_font;
	sf::Text m_imagesDetected;
	sf::Text m_sameSize;
	sf::Text m_variations;
	sf::Text m_process;
public:
	ImageEditor();
	void openWindow();
};