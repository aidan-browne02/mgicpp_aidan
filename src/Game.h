
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseButtonPressed(sf::Event event);
  void mouseButtonReleased(sf::Event event);
  void keyPressed(sf::Event event);
  bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
  void spawn();
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);
  int score;

 private:
  sf::RenderWindow& window;
  sf::Sprite bird;
  sf::Sprite background;
  sf::Texture bird_texture;
  sf::Texture background_texture;
  sf::Font font;
  sf::Text title_text;
  sf::Text play;
  sf::Text quit;
  sf::Text score_text;
  bool in_menu;
  bool play_selected;
  float speed;
  bool reverse;

  sf::Sprite* character;
  sf::Sprite* passport;
  sf::Texture* animals = new sf::Texture[3];
  sf::Texture* passports = new sf::Texture[3];
  bool passport_accepted;
  bool passport_rejected;
  bool should_accept;
  sf::Sprite* dragged = nullptr;
  sf::Sprite* accept_button;
  sf::Sprite* reject_button;
  sf::Texture* accept_bt;
  sf::Texture* reject_bt;
};

#endif // PLATFORMER_GAME_H
