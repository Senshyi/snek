#pragma once

#include "Board.h"

class Snake {
private:
	class Segment {
	public:
		void initHead(const Location& loc);
		void initBody();
		void follow(const Segment& next);
		void moveBy(const Location& delta_loc);
		void draw(Board& brd) const;
		const Location& getLocation() const;
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void moveBy(const Location& delta_loc);
	Location getNextHeadLocation(const Location& delta_loc) const;
	void grow();
	void draw(Board& brd) const;
	bool isInTileExceptEnd(const Location& target) const;
	bool isInTile(const Location& target) const;
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;

};