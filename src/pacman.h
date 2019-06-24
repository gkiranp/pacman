#pragma once

namespace Action {
	enum Move_t { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77 };

	struct Position_t {
		int32_t posX;
		int32_t posY;
		bool operator==(const Position_t o) {
			if ((posX == o.posX) && (posY == o.posY)) {
				return true;
			}
			else {
				return false;
			}
		}
	};

	// Warning: This class has to be Singleton class
	class Game_Controller_t {
		uint32_t score;
		std::vector< std::vector<int> > Map;
	public:
		void load_map(const vector<vector<int> >& vy);
		void redraw_map(void);
		void update_map(void);
		void reset_map(void);
		void update_score(void);
		void reset_pacman_pos(void);
		void reset_ghost_pos(uint8_t ghost_num);
		void refill_cookies(void);
		bool has_cookie(const Position_t &atPos);
		bool eat_cookie(const Position_t &atPos);
	};

	class Movement_t {
		Position_t pos;
		Game_Controller_t *m_gc;
	public:
		bool move_left();
		bool move_right();
		bool move_up();
		bool move_down();
	private:
		bool is_moveable();
	};

}

namespace Components {
	class Pacman : public Action::Movement_t {
		uint8_t m_life;
		Action::Position_t curPos;
	public:
		uint8_t get_life();
		void update_position(Action::Move_t mov);
		Action::Position_t get_cur_position();
		void take_one_life(void);
	};

	class Ghosts : public Action::Movement_t {
		uint32_t speed;
		Action::Position_t curPos;
	public:
		void update_position(Action::Position_t pos);
		Action::Position_t get_cur_position();
	};
}
