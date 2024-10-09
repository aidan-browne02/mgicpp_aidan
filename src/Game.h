
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
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
  void spawn();
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
};

#endif // PLATFORMER_GAME_H
