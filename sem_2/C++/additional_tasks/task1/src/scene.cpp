#include <scene.hpp>
#include <cmath>
#include <fstream>

namespace mt
{
	void LoadPointsFromFile(const std::string& filename, int &m_size, Point* m_points, Color* m_colors) {
		std::ifstream file(filename);
		if (!file) {
			std::cerr << "Error during opening\n";
			return;
		}
	
		file >> m_size;
	
		for (int i = 0; i < m_size; i++) {
			file >> m_points[i].x >> m_points[i].y >> m_points[i].z >> m_colors[i].r >> m_colors[i].g >> m_colors[i].b >> m_colors[i].a;
		}
	
		file.close();
	}

	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture);

		Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
		Point position = { 0.0, 0.0, 0.0 };
		Angles angles = { 0.0,0.0,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);

		m_points = new Point[2000000];
		m_colors = new Color[2000000];

		LoadPointsFromFile("../../src/points.txt", m_size, m_points, m_colors);
	}
	Scene::~Scene()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}

	void Scene::LifeCycle()
	{
		sf::Clock clock;
		float move_v = 1;
		float roll_v = 1;

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				m_camera->dZ(move_v * dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_camera->dZ(-(move_v * dt));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_camera->dX(-(move_v * dt));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_camera->dX(move_v * dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_camera->dPitch(-(roll_v * dt));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_camera->dPitch(roll_v * dt);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_camera->dRoll(-(roll_v * dt));
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_camera->dRoll(roll_v * dt);
			}

			for (int i = 0; i < m_size; i++)
					m_camera->ProjectPoint(m_points[i], {(uint8_t)(m_colors[i].r), (uint8_t)(m_colors[i].g), (uint8_t)(m_colors[i].b), (uint8_t)(m_colors[i].a)});

			m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}
	}
}