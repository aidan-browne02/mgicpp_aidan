
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete[] animals;
	delete[] passports;
	delete character;
	delete passport;
}

bool Game::init()
{
	//background
	if(!background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png"))
	{
		std::cout << "background texture did not load \n";
	}
	background.setTexture(background_texture);

	//bird
	if (!bird_texture.loadFromFile("../Data/WhackaMole Worksheet/bird.png"))
	{
		std::cout << "bird texture did not load \n";
	}
	bird.setTexture(bird_texture);
	bird.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	bird.setScale(0.5,0.5);

	//text
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "font did not load \n";
	}
	title_text.setString("Whack-a-mole");
	title_text.setFont(font);
	title_text.setCharacterSize(50);
	title_text.setFillColor(sf::Color(255, 255, 255, 128));
	title_text.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2 - 100);

	play.setString(">Play<");
	play.setFont(font);
	play.setCharacterSize(25);
	play.setFillColor(sf::Color(255, 255, 255, 128));
	play.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2 + 200);

	quit.setString(" Quit ");
	quit.setFont(font);
	quit.setCharacterSize(25);
	quit.setFillColor(sf::Color(255, 255, 255, 128));
	quit.setPosition(
		window.getSize().x / 2 - title_text.getGlobalBounds().width / 2 + 300,
		window.getSize().y / 2 - title_text.getGlobalBounds().height / 2 + 200);

	score_text.setString("0");
	score_text.setFont(font);
	score_text.setCharacterSize(50);
	score_text.setFillColor(sf::Color(255, 255, 255, 128));
	score_text.setPosition(
		window.getSize().x - title_text.getGlobalBounds().width / 2,
		50);

	//menu
	in_menu = true;
	play_selected = true;

	//random inits
	speed = 400;
	score = 0;

	//animal and passport inits
	if (!animals[0].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "animal[0] texture did not load \n";
	}
	if (!animals[1].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/elephant.png"))
	{
		std::cout << "animal[1] texture did not load \n";
	}
	if (!animals[2].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "animal[2] texture did not load \n";
	}
	if (!passports[0].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "passport[0] texture did not load \n";
	}
	if (!passports[1].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "passport[1] texture did not load \n";
	}
	if (!passports[2].loadFromFile("../Data/Images/extra_images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "passport[2] texture did not load \n";
	}

	return true;
}

void Game::update(float dt)
{
	//bird movement
	/*
	if ((bird.getPosition().x > (window.getSize().x - bird.getGlobalBounds().width)) || (bird.getPosition().x < 0))
	{
		reverse = !reverse;
	}
	
	if (!reverse)
	{
		bird.move(1.0f * speed * dt, 0);
		bird.setTextureRect(sf::IntRect(
			0, 0, bird.getLocalBounds().width, bird.getLocalBounds().height));
	}
	else
	{
		bird.move(-1.0f * speed * dt, 0);
		bird.setTextureRect(sf::IntRect(
			bird.getLocalBounds().width,
			0,
			-bird.getLocalBounds().width,
			bird.getLocalBounds().height));
	}
	 
	//update score
	std::string my_score = std::to_string(score);
	score_text.setString(my_score);
	*/
}

void Game::render()
{
	if (in_menu)
	{
		window.draw(title_text);
		window.draw(play);
		window.draw(quit);
	}
	else
	{
		window.draw(background);
		//window.draw(*character);
		//window.draw(*passport);
		
		//window.draw(bird);
		//window.draw(score_text);
	}
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  /*
  if (collisionCheck(click, bird))
  {
	  //spawn 
	  spawn();

	  //inc score
	  score++;
  }
  */
}

void Game::keyPressed(sf::Event event)
{
	if (in_menu)
	{
		if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
		{
			play_selected = !play_selected; 

			if (play_selected)
			{
				play.setString(">Play<");
				quit.setString(" Quit ");
			}
			else
			{
				play.setString(" Play ");
				quit.setString(">Quit<");
			}
		}
		else if (event.key.code == sf::Keyboard::Enter)
		{
			if (play_selected)
			{
				in_menu = false;
			}
			else
			{
				window.close();
			}
		}

	}
	else
	{
		if (event.key.code == sf::Keyboard::A)
		{
			newAnimal();
		}
	}
}

bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
	if ((click.x < sprite.getPosition().x + sprite.getGlobalBounds().width) && (sprite.getPosition().x < click.x) && (click.y < sprite.getPosition().y + sprite.getGlobalBounds().height) && (sprite.getPosition().y < click.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::spawn()
{
	/*
	bird.setPosition(rand() % 880, rand() % 520);
	reverse = false;
	*/
}

void Game::newAnimal()
{
	passport_accepted = false;
	passport_rejected = false;

	int animal_index = rand() % 3;
	int passport_index = rand() % 3;

	if (animal_index == passport_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}

	character->setTexture(animals[animal_index], true);
	character->setScale(1.8, 1.8);
	character->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport->setTexture(passports[passport_index]);
	passport->setScale(0.6, 0.6);
	passport->setPosition(window.getSize().x / 2, window.getSize().y / 3);

}