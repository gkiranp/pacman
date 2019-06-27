#include "pacman.h"

//All pacman.h implementations

namespace Action {

//Implementation for Game Control class
void Game_Controller_t::load_map(const vector<vector<char> >& vy)
{
	if (vy.size() > 0) {
		for (auto &r : vy)
			for (auto &c : vy[r])
				Map[r][c] = vy[r][c];
	}
}

void Game_Controller_t::redraw_map(void)
{
	//drawing into STDOUT
}

void Game_Controller_t::update_map(void)
{
	//update Ghost positions, pacman positions
}

void Game_Controller_t::reset_map(void)
{
}

void Game_Controller_t::update_score(void)
{
}

void Game_Controller_t::reset_pacman_pos(void)
{
}

void Game_Controller_t::reset_ghost_pos(uint8_t ghost_num)
{
}

void Game_Controller_t::refill_cookies(void)
{
}

bool Game_Controller_t::has_cookie(const Position_t &atPos)
{
}

bool Game_Controller_t::eat_cookie(const Position_t &atPos)
{
}

bool Game_Controller_t::is_pos_valid(const Position_t &pos)
{
	//Check position is within the boundry
	if()
	//Check there are no walls in this position

}

//Implementation for Movement class
bool Movement_t::is_moveable(Move_t m)
{
	Position_t nextPos = pos;
	if(m == UP) {
		nextPos.posX--;
	}
	else if (m == DOWN) {
		nextPos.posX++;
	}
	else if (m == LEFT) {
		nextPos.posY--;
	}
	else if (m == RIGHT) {
		nextPos.posY++;
	}
	return m_gc->is_pos_valid(nextPos);
}

bool Movement_t::move_left()
{
	if (is_moveable(LEFT)) {
		pos.posY--;
		return true;
	}
	return false;
}

bool Movement_t::move_right()
{
	if (is_moveable(RIGHT)) {
		pos.posY++;
		return true;
	}
	return false;
}

bool Movement_t::move_up()
{
	if (is_moveable(UP)) {
		pos.posX--;
		return true;
	}
	return false;
}

bool Movement_t::move_down()
{
	if (is_moveable(DOWN)) {
		pos.posX++;
		return true;
	}
	return false;
}

} //end-of-namespace-Action
