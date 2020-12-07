﻿#ifndef LEVEL_GUARD_HPP
#define LEVEL_GUARD_HPP

#include "Box2DObject.hpp"
#include "SmartSprite.hpp"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

// fwd decl
class Player;

class Wall : public jt::Box2DObject {
public:
    Wall(std::shared_ptr<b2World> world, b2BodyDef const* def);
};

class Level {
public:
    enum class TileType : std::uint8_t { EMPTY, WALL };

    void loadLevel(std::string const& fileName, std::shared_ptr<b2World> world);

    TileType getTileTypeAt(unsigned int x, unsigned int y) const;

    jt::vector2u getLevelSizeInTiles() const;

    jt::vector2 getPlayerStartPositionInTiles() const;
    float getPlayerStartAngle() const;

private:
    std::vector<TileType> m_levelVec {};
    jt::vector2u m_levelSize { 0, 0 };
    jt::vector2u m_playerStart { 0, 0 };
    float m_playerStartAngle { 0.0f };

    std::size_t posToIndex(unsigned int x, unsigned int y) const;
};

#endif