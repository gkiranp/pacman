#include <iostream>
#include <thread>
#include <vector>
#include <condition_variable>
#include <mutex>
#include <string>

#include "pacman.h"

std::mutex mu_keypress;

int main()
{
	Action::Game_Controller_t g_game_ctrl;
	Components::Pacman g_Pacman;
	Components::Ghosts g_ghost1, g_ghost2, g_ghost3, g_ghost4;

	auto keypress = [&g_Pacman]() {
		char c = 0;
		while (true)
		{
			c = getch();
			switch (c) {
				case static_cast<char>(Action::UP) :
				case static_cast<char>(Action::DOWN) :
				case static_cast<char>(Action::LEFT) :
				case static_cast<char>(Action::RIGHT) :
				{
					std::unique_lock<std::mutex> key_lock(mu_keypress);
					g_Pacman.update_position(static_cast<Action::Move_t>(c));
				}
				break;
			default:
				break;
			}

		}
	};

	auto game_controller = [&]() { //Game Controller has access to all the components and variables
		while (true) {
			//Let's draw the map first
			game_ctrl.redraw_map();
			//Check Pacman position, Ghost's position and Cookies
			if ((g_Pacman.get_cur_position() == g_ghost1.get_cur_position()) ||
				(g_Pacman.get_cur_position() == g_ghost2.get_cur_position()) ||
				(g_Pacman.get_cur_position() == g_ghost3.get_cur_position()) ||
				(g_Pacman.get_cur_position() == g_ghost4.get_cur_position()))
			{
				if (g_Pacman.get_life() > 0) {
					g_Pacman.take_one_life();
					game_ctrl.reset_pacman_pos();
				}
			}
			else if (game_ctrl.has_cookie(g_Pacman.get_cur_position()))
			{
				game_ctrl.eat_cookie(g_Pacman.get_cur_position());
				game_ctrl.update_score();
			}
		}
	};

	auto automove_ghosts = [&g_ghost1, &g_ghost2, &g_ghost3, &g_ghost4]() {
		enum Direction {mv_up = 1, mv_down = 2, mv_left = 3, mv_right = 4};
		uint8_t mv = 0;
		while (true) {
			//Move Ghost 1
			mv = (rand() % 4);
			if (mv == mv_up) {
				g_ghost1.move_up();
			}
			else if (mv == mv_down) {
				g_ghost1.move_down();
			}
			else if (mv == mv_left) {
				g_ghost1.move_left();
			}
			else if (mv == mv_right) {
				g_ghost1.move_right();
			}
			//Move Ghost 2
			mv = (rand() % 4);
			if (mv == mv_up) {
				g_ghost2.move_up();
			}
			else if (mv == mv_down) {
				g_ghost2.move_down();
			}
			else if (mv == mv_left) {
				g_ghost2.move_left();
			}
			else if (mv == mv_right) {
				g_ghost2.move_right();
			}
			//Move Ghost 3
			mv = (rand() % 4);
			if (mv == mv_up) {
				g_ghost3.move_up();
			}
			else if (mv == mv_down) {
				g_ghost3.move_down();
			}
			else if (mv == mv_left) {
				g_ghost3.move_left();
			}
			else if (mv == mv_right) {
				g_ghost3.move_right();
			}
			//Move Ghost 4
			mv = (rand() % 4);
			if (mv == mv_up) {
				g_ghost4.move_up();
			}
			else if (mv == mv_down) {
				g_ghost4.move_down();
			}
			else if (mv == mv_left) {
				g_ghost4.move_left();
			}
			else if (mv == mv_right) {
				g_ghost4.move_right();
			}
		}
	};

	//Trigger other 3 child threads
	std::thread kp = std::thread(keypress);
	std::thread gc = std::thread(game_controller);
	std::thread ag = std::thread(automove_ghosts);

	kp.join();
	gc.join();
	ag.join();

	return 0;
}
