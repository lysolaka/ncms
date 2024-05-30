#include "Controller.hpp"
#include <cassert>

namespace sfl {

void Controller::play() {
  sf::Text endText;
  sf::Font textFont;
  assert(("Font file missing!", textFont.loadFromFile("assets/MSFont.ttf")));
  endText.setFont(textFont);

  while (window.isOpen() && board.getGameState() == ms::Board::RUNNING) {
    sf::Event e;
    while (window.pollEvent(e)) {
      switch (e.type) {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::KeyPressed:
        if (e.key.scancode == sf::Keyboard::Scan::Q) {
          board.forceEndGame();
          board.revealAllMines();
        }
        break;
      case sf::Event::MouseButtonPressed: {
        f32 mouse_x = e.mouseButton.x;
        f32 mouse_y = e.mouseButton.y;
        ms::Vector2u pos;
        pos.x = (mouse_x - 4.f) / logicalRectSize;
        pos.y = (mouse_y - 4.f) / logicalRectSize;
        if (!board.isInbound(pos))
          break;
        if (e.mouseButton.button == sf::Mouse::Left)
          board.revealField(pos);
        else if (e.mouseButton.button == sf::Mouse::Right)
          board.toggleFlag(pos);
      } break;
      default:
        break;
      }
    }

    board.updateGameState();
    window.clear(sf::Color::Black);
    display.display();
    window.display();
  }

  endText.setFont(textFont);
  endText.setCharacterSize(800 / 5);
  endText.setPosition(sf::Vector2f(10.f, 300.f));
  endText.setOutlineColor(sf::Color::Black);
  endText.setOutlineThickness(4.f);

  if (board.getGameState() == ms::Board::FINISHED_LOSS) {
    board.revealAllMines();
    endText.setString("YOU LOST");
    endText.setFillColor(sf::Color::Red);
  } else {
    endText.setString("YOU WON!");
    endText.setFillColor(sf::Color::Green);
  }

  while (window.isOpen()) {
    sf::Event e;
    while (window.pollEvent(e)) {
      if (e.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
    display.display();
    window.draw(endText);
    window.display();
  }
}

} // namespace sfl
