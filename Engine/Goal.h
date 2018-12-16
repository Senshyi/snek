#pragma once

#include "Snake.h"
#include "Board.h"
#include <random>

class Goal {
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake);
	void respawn(std::mt19937& rng, const Board& brd, const Snake& snake);
	void draw(Board& brd) const;
	const Location& getLocation() const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};