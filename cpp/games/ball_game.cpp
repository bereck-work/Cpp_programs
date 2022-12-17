#include <iostream>
#include <cstdlib> // for rand() "random no generator"
#include <ctime> // for time(NULL) "seed for random numer generator"
#include <curses.h>

using std::cout, std::endl;



enum Ball_Direction{STOP, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT};


// Ball Class
class Ball{
	public:
		int x, y, center_x, center_y; // to hold positions (current and center)
		Ball_Direction direction; // to hold direction of motion of ball


		// constructor
		Ball(int x, int y){ // initial position of the ball
			this->center_x = x; // center_X and center_y store the initial value
			this->center_y = y;
			this->x = x; // x and y store current value of the ball position
			this->y = y;
			this->direction = STOP; // ball is initialized static
		}

		// function to bring the ball back to its starting position (center)
		void reset_ball(){
			x = center_x;
			y = center_y;
			direction = STOP; // to stop the motion of ball
		}

		// function to change direction of ball when it hits either a wall or a blade
		void change_ball_direction(Ball_Direction d){
			direction = d;
		}

		// function to initialize the direction of ball randomly
		void randomize_ball_direction(){
			direction = (Ball_Direction)((rand()%6) + 1);
		}

		// function to move ball around the screen
		void move_ball(){ // x increases along right
			switch(direction){ // y increases along bottom
				case STOP:
					break;
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UPLEFT:
					x--;
					y--;
					break;
				case DOWNLEFT:
					x--;
					y++;
					break;
				case UPRIGHT:
					x++;
					y--;
					break;
				case DOWNRIGHT:
					x++;
					y++;
					break;
				default: // in case direction take exceptional value, ignore it.
					break;
			}
		}
}; // end of Ball class


// Blade Class
class Blade{
	public:
		int x, y, initial_x, initial_y; // to hold position of blades (current and default)

		// constructor
		Blade(int x, int y){
			this->initial_x = x;
			this->initial_y=y;
			this->x = x;
			this->y = y;
		}

		// to reset blade positions while Ping_Pong restarting
		void blade_reset(){
			x = initial_x;
			y = initial_y;
		}

		// to move balde up
		void blade_move_up(){
			y--;
		}

		// to move balde down
		void blade_move_down(){
			y++;
		}
}; // end of Blade class



// Ping_Pong Class
class Ping_Pong{
	public:
		int width, height, score_1, score_2;// height and width of the Ping_Pong area
											// scores  of player 1 and player 2
		char up_1, down_1, up_2, down_2; // keys used by players to move up or down
		bool terminate; // to terminate the Ping_Pong

		Ball *ball; // 1 ball
		Blade *player_1, *player_2; // 2 players

		// constructor
		Ping_Pong(int width, int height){
			srand(time(NULL)); // seeding random number generator to generate random directions

			// initializing variables
			this->terminate = false;
			this->up_1 = 'w'; // player_1 move up using 'w'
			this->up_2 = 'i'; // player_2 move up using 'i'
			this->down_1 = 's'; // player_1 move down using 's'
			this->down_2 = 'k'; // player_2 move down using 'k'
			this->score_1 = 0; // both players get initial score = 0
			this->score_2 = 0;

			this->width=width; // user can specify the dimensions of the grid
			this->height = height;

			this->ball = new Ball(width/2, height/2);
			this->player_1 = new Blade(1, height/2 -3);
			this->player_2 = new Blade(width-2, height/2 -3);
		}

		// Incrementing score
		void increment_score(Blade *player){
			if (player == player_1) score_1+=5; // increment player 1 score
			else score_2+=5;// increment player 2 score

			ball->reset_ball(); // put ball back at center
			player_1->blade_reset(); // put both blades at starting position
			player_2->blade_reset();
		}

		// Drawing the board (at each moment -- this will explain the blips)
		void draw_layout(){
			system("cls"); // first clearing the screen to remove prev timestep

			// printing above wall
			for (int i=0; i< width+2; i++) cout << "\xB2";
			cout << endl;

			// printing side walls, ball and blades
			for(int i=0; i<height; i++){ // to traverse along height
				for(int j=0; j<width; j++){ // to traverse along width

					if (j==0) cout << "\xB2"; // left wall element

					if(ball->x == j && ball->y == i) cout << "O"; // printing ball at its
																// position
					// printing player_1 blade (length=4)
					else if(player_1->x == j && player_1->y == i) cout << "\xDB";
					else if(player_1->x == j && player_1->y + 1 == i) cout << "\xDB";
					else if(player_1->x == j && player_1->y + 2 == i) cout << "\xDB";
					else if(player_1->x == j && player_1->y + 3 == i) cout << "\xDB";

					// printing player_2 blade (length=4)
					else if(player_2->x == j && player_2->y == i) cout << "\xDB";
					else if(player_2->x == j && player_2->y + 1 == i) cout << "\xDB";
					else if(player_2->x == j && player_2->y + 2 == i) cout << "\xDB";
					else if(player_2->x == j && player_2->y + 3 == i) cout << "\xDB";


					else cout << " "; // rest of the area is blank

					if (j==width-1) cout << "\xB2"; // right wall element
				} // end of inner for loop

				cout << "\xB2" << endl;
			} // end of outer for loop

			// printing bottom wall
			for (int i=0; i< width+2; i++) cout << "\xB2";
			cout << endl;

			// printing scores
			cout << "Score 1: " << score_1 << "\t\t\tScore 2: " << score_2 << endl;

		} // end of Draw function

		// function to respond to player inputs
		void play(){
			ball->move_ball(); // to move the ball in direction specified by 'direction'

			if (addstr("Use W A S D for directions: ")){ // if any key is pressed : take action
				char key = getch(); // get the pressed key character

				// player_1 move up
				if (key == up_1 && player_1->y > 0) player_1->blade_move_up();
				// player_2 move up
				else if (key == up_2 && player_2->y > 0) player_2->blade_move_up();
				// player_1 move down
				else if (key == down_1 && player_1->y + 4 < height) player_1->blade_move_down();
				// player_2 move down
				else if (key == down_2 && player_2->y + 4 < height) player_2->blade_move_down();
				// terminate if 't' is pressed
				else if (key == 't') terminate = true;

				// if it's new game move the ball in random directions
				if (ball->direction == STOP) ball->randomize_ball_direction();
			}
		} // end of input

		// function to monitor ball position
		void monitor_ball(){

			// if ball hits player_1 blade
			for (int i =0; i<4; i++)
				if(ball->x == player_1->x + 1)
					if (ball->y == player_1->y + i)
						ball->change_ball_direction( (Ball_Direction)(rand()%3 + 4 ));

			// if ball hits player_2 blade
			for (int i =0; i<4; i++)
				if(ball->x == player_2->x - 1)
					if (ball->y == player_2->y + i)
						ball->change_ball_direction( (Ball_Direction)(rand()%3 + 1 ));

			// if ball hits bottom wall
			if (ball->y == height-1)
				ball->change_ball_direction(ball->direction == DOWNRIGHT ? UPRIGHT : UPLEFT);

			// if ball hits top wall
			if (ball->y == 0)
				ball->change_ball_direction(ball->direction == UPRIGHT ? DOWNRIGHT : DOWNLEFT);

			// if ball hits right wall --> player_1 wins
			if(ball->x == width-1)
				increment_score(player_1);

			// if ball hits left wall --> player_2 wins
			if(ball->x == 0)
				increment_score(player_2);

		}

		// function to call the functions --> yeah that's pretty much it
		void lets_ping_pong(){
			while(!terminate){
				draw_layout();
				play();
				monitor_ball();
			}
		}
};



int main(){
	Ping_Pong game(40, 20); // instantiating the game
	game.lets_ping_pong(); // playing
	return 0; // leaving
}
