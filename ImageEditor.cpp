#include "ImageEditor.h"
#include <filesystem>
#include <string>
#include <iostream>

ImageEditor::ImageEditor()
{
	//We did it
}

void ImageEditor::openWindow()
{
	m_window.create(sf::VideoMode(320, 320), "Image Editor");
	sf::Event event;
	m_font.loadFromFile("Carlito-Regular.ttf");
	m_imagesDetected = sf::Text("Images Detected: ", m_font, 32);
	m_sameSize = sf::Text("Same Size?: ", m_font, 32);
	std::string variations{ "Variations: " };
	m_variations = sf::Text(variations, m_font, 32);
	m_process = sf::Text("Process", m_font, 32);

	std::vector<sf::Image*> images;
	
	for (const auto& file : std::filesystem::directory_iterator("\Input"))
	{
		std::cout << "Got File\n";
		if (file.path().extension() == ".png")
		{
			images.push_back(new sf::Image);
			std::string pathString{ file.path().string() };
			std::cout << pathString << '\n';
			images.back()->loadFromFile(pathString);
		}
	}

	while (true)
	{
		m_window.clear(sf::Color::Blue);
		m_window.pollEvent(event);
		m_window.display();
	}

	for (auto& element : images)
		delete element;
}