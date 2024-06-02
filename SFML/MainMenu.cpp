#include "MainMenu.hpp"
#include <cassert>

namespace sfl {
ms::MenuReturn MainMenu(sf::RenderWindow &win) {

  ms::Vector2u size(10, 10);
  ms::Board::Difficulty diff = ms::Board::NORMAL;
  bool inProgress = true;

  MenuAssets *assets = new MenuAssets;

  assert(("Font MSFont.ttf not found!",
          assets->textFont.loadFromFile("assets/MSFont.ttf")));

  assert(("Texture MSMainMenuBG.png not found!",
          assets->bgTexture.loadFromFile("assets/MSMainMenuBG.png")));
  assets->bg.setTexture(&assets->bgTexture);

  assets->bg.setSize(sf::Vector2f(800.f, 800.f));
  assets->bg.setFillColor(sf::Color::White);

  assets->playButton.setSize(sf::Vector2f(388.f, 67.f));
  assets->playButton.setFillColor(sf::Color::Transparent);
  assets->playButton.setPosition(sf::Vector2f(206.f, 632.f));

  assets->playButtonBox = assets->playButton.getGlobalBounds();

  assert(("Texture MSMinusArrow.png not found!",
          assets->minusButton.loadFromFile("assets/MSMinusArrow.png")));
  assert(("Texture MSPlusArrow.png not found!",
          assets->plusButton.loadFromFile("assets/MSPlusArrow.png")));

  assets->columnsMinus.setSize(sf::Vector2f(33.f, 43.f));
  assets->columnsMinus.setFillColor(sf::Color::White);
  assets->columnsMinus.setPosition(sf::Vector2f(73.f, 283.f));
  assets->columnsMinus.setTexture(&assets->minusButton);

  assets->columnsMinusBox = assets->columnsMinus.getGlobalBounds();

  assets->columnsPlus.setSize(sf::Vector2f(33.f, 43.f));
  assets->columnsPlus.setFillColor(sf::Color::White);
  assets->columnsPlus.setPosition(sf::Vector2f(294.f, 283.f));
  assets->columnsPlus.setTexture(&assets->plusButton);

  assets->columnsPlusBox = assets->columnsPlus.getGlobalBounds();

  assets->rowsMinus.setSize(sf::Vector2f(33.f, 43.f));
  assets->rowsMinus.setFillColor(sf::Color::White);
  assets->rowsMinus.setPosition(sf::Vector2f(473.f, 283.f));
  assets->rowsMinus.setTexture(&assets->minusButton);

  assets->rowsMinusBox = assets->rowsMinus.getGlobalBounds();

  assets->rowsPlus.setSize(sf::Vector2f(33.f, 43.f));
  assets->rowsPlus.setFillColor(sf::Color::White);
  assets->rowsPlus.setPosition(sf::Vector2f(694.f, 283.f));
  assets->rowsPlus.setTexture(&assets->plusButton);

  assets->rowsPlusBox = assets->rowsPlus.getGlobalBounds();

  assets->diffMinus.setSize(sf::Vector2f(33.f, 43.f));
  assets->diffMinus.setFillColor(sf::Color::White);
  assets->diffMinus.setPosition(sf::Vector2f(218.f, 483.f));
  assets->diffMinus.setTexture(&assets->minusButton);

  assets->diffMinusBox = assets->diffMinus.getGlobalBounds();

  assets->diffPlus.setSize(sf::Vector2f(33.f, 43.f));
  assets->diffPlus.setFillColor(sf::Color::White);
  assets->diffPlus.setPosition(sf::Vector2f(551.f, 483.f));
  assets->diffPlus.setTexture(&assets->plusButton);

  assets->diffPlusBox = assets->diffPlus.getGlobalBounds();

  assets->diffLabel.setFont(assets->textFont);
  assets->diffLabel.setCharacterSize(43);

  assets->sizeColumns.setFont(assets->textFont);
  assets->sizeColumns.setCharacterSize(43);

  assets->sizeRows.setFont(assets->textFont);
  assets->sizeRows.setCharacterSize(43);

  while (win.isOpen() && inProgress) {
    sf::Event e;
    while (win.pollEvent(e)) {
      switch (e.type) {
      case sf::Event::Closed:
        win.close();
        break;
      case sf::Event::MouseButtonPressed:
        if (e.mouseButton.button == sf::Mouse::Button::Left) {
          if (assets->playButtonBox.contains(
                  sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            inProgress = false;
          } else if (assets->columnsMinusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            if (size.x != 1)
              size.x--;
          } else if (assets->columnsPlusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            if (size.x != 76)
              size.x++;
          } else if (assets->rowsMinusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            if (size.y != 1)
              size.y--;
          } else if (assets->rowsPlusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            if (size.y != 76)
              size.y++;
          } else if (assets->diffMinusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
            if (diff != ms::Board::EASY)
              diff = (ms::Board::Difficulty)(diff - 1);
          } else if (assets->diffPlusBox.contains(
                         sf::Vector2f(e.mouseButton.x, e.mouseButton.y))) {
#ifdef __ALLOW_DEBUG
            if (diff != ms::Board::DEBUG)
#else
            if (diff != ms::Board::HARD)
#endif
              diff = (ms::Board::Difficulty)(diff + 1);
          }
        }
        break;
      default:
        break;
      }
    }

    win.clear(sf::Color::Black);
    win.draw(assets->bg);

    win.draw(assets->columnsMinus);
    win.draw(assets->columnsPlus);
    win.draw(assets->rowsMinus);
    win.draw(assets->rowsPlus);
    win.draw(assets->diffMinus);
    win.draw(assets->diffPlus);

    assets->sizeColumns.setString(std::to_string(size.x));
    if (size.x >= 10)
      assets->sizeColumns.setPosition(sf::Vector2f(175.f, 278.f));
    else
      assets->sizeColumns.setPosition(sf::Vector2f(185.f, 278.f));
    win.draw(assets->sizeColumns);

    assets->sizeRows.setString(std::to_string(size.y));
    if (size.y >= 10)
      assets->sizeRows.setPosition(sf::Vector2f(575.f, 278.f));
    else
      assets->sizeRows.setPosition(sf::Vector2f(585.f, 278.f));
    win.draw(assets->sizeRows);

    switch (diff) {
    case ms::Board::EASY:
      assets->diffLabel.setString("EASY");
      assets->diffLabel.setPosition(sf::Vector2f(350.f, 478.f));
      break;
    case ms::Board::NORMAL:
      assets->diffLabel.setString("NORMAL");
      assets->diffLabel.setPosition(sf::Vector2f(325.f, 478.f));
      break;
    case ms::Board::HARD:
      assets->diffLabel.setString("HARD");
      assets->diffLabel.setPosition(sf::Vector2f(350.f, 478.f));
      break;
    case ms::Board::DEBUG:
#ifdef __ALLOW_DEBUG
      assets->diffLabel.setString("DEBUG");
      assets->diffLabel.setPosition(sf::Vector2f(337.f, 478.f));
#endif
      break;
    }

    win.draw(assets->diffLabel);

    win.draw(assets->playButton);

    win.display();
  }

  delete assets;

  return ms::MenuReturn(size, diff);
}
} // namespace sfl
