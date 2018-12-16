#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	segments[0].initHead(loc);
}

void Snake::moveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].follow(segments[i - 1]);
	}
	segments[0].moveBy(delta_loc);
}

Location Snake::getNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].getLocation());
	l.add(delta_loc);
	return l;
}

void Snake::grow()
{
	if (nSegments < nSegmentsMax) {
		segments[nSegments].initBody();
		nSegments++;
	}
}

void Snake::draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].draw(brd);
	}
}

bool Snake::isInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSegments - 1; i++) {
		if (segments[i].getLocation() == target) {
			return true;
		}
	}
	return false;
}

bool Snake::isInTile(const Location & target) const
{
	for (int i = 0; i < nSegments; i++) {
		if (segments[i].getLocation() == target) {
			return true;
		}
	}
	return false;
}

void Snake::Segment::initHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::initBody()
{
	c = Snake::bodyColor;
}

void Snake::Segment::follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::moveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.add(delta_loc);
}

void Snake::Segment::draw(Board & brd) const
{
	brd.drawCell(loc, c);
}

const Location& Snake::Segment::getLocation() const
{
	return loc;
}
