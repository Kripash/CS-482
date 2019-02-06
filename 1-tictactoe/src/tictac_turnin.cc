#include <tictac_support.h>
#include <stdio.h>
#include <iostream>
#include <vector>


//my struct to help me scale down this problem, contains row for the row number of moves, col of moves, score of the move and the board that is played with
typedef struct
{
	int row;
	int col;
	int score;
	int board[3][3];
}miniMaxMove;


/**
 * This function is the printBoard function. It was used for debugging and testing purposes.
 *
 * This function prints out the tic tac toe board.
 *
 * @param int board[][3] which is the board to be printed.
 * @return This function does not return anything.
 *
 * @pre none.
 * @post Prints out the board passed in as the parameter.
 *
 */
void printBoard(int board[][3])
{
	for(int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			std::cout << board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


/**
 * This function is the gameIsOver function.
 *
 * This function checks to see if the game is over my checking for possible 3 in a rows.
 *
 * @param int board[][3] which is the board to be checked for 3 in a row.
 * @param int player which is the first_player to make the move.
 * @return This function returns the score based on the player who won, it will return the 1 if the first player won and -1 if the second player won, or 0 if its a tie/no win.
 *
 * @pre none.
 * @post Evalues to see if the gameisOver.
 *
 */
int gameIsOver(int board[][3], int player)
{
	//check the rows to see if there is a 3 in a row
	for (int row = 0; row < 3; row++)
    {
        if(board[row][0] == board[row][1] && board [row][1]== board[row][2])
        {
            if (board[row][0] == player)
			{
                return 1;
			}
            else if (board[row][0] == (-1 * player))
			{
                return -1;
			}
        }
    }
 
    // Check the columns to see if there is a 3 in a row
    for (int col = 0; col < 3; col++)
    {
        if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
        {
            if(board[0][col] == player)
			{
                return 1;
 			}
            else if (board[0][col] == (-1 * player))
			{
                return -1;
			}
        }
    }
 
    // Checking the diagonals to see if there is a 3 in a row
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == player)
		{
            return 1;
		}
        else if (board[0][0] == (-1 * player))
		{
            return -1;
		}
    }
 	//checking diagonals to se if there is a 3 in a row
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        if (board[0][2] == player)
		{
            return 1;
		}        
		else if (board[0][2] == (-1 * player))
		{
            return -1;
		}
    }
 
    //no win
    return 0;	
}

/**
 * This function is the boardIsFull function.
 *
 * This function checks to see if the game is full and there are no valid moves left.
 *
 * @param int board[][3] which is the board to be checked for the full board.
 * @return This function returns true if the board is full and false if the board has valid moves left.
 *
 * @pre none.
 * @post Evalues to see if the board is full.
 *
 */
bool boardIsFull(int board[][3])
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			// find an empty square
			if(board[i][j] == 0)
			{
				return false;
			}
		}
	}
	return true;
}

/**
 * This function is the copyArray function.
 *
 * This function copies the contents of a board/array to another board/array.
 *
 * @param int src[][3] which is the board that will be copied over. 
 * @param int des[][3] which is the board that will hold the copied board.
 * @return none
 *
 * @pre none.
 * @post Copies the contents of a board/array to another board.
 *
 */
void copyArray(int src [][3], int dest[][3])
{

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dest[i][j] = src[i][j];
		}
	}
}

/**
 * This function is the minimax function.
 *
 * This function recursive calls itself and uses the minimax algorithm to solve the tic tac toe best move solver. 
 * The function checks to see if the game is over first and if it is, it returns the score associated with the player. 
 * If game is not over, the function checks to see if the board is full to decide whether to return or continue searching with the valid moves. 
 * The function will then increment the number of moves go through the board and make a move and assign a miniMaxMove object to hold the current move and recursively call itself to look for all of the solutions. 
 * The function will only store the value of the returned miniMaxMove from the recursive call because it will over ride the current move if we try to do that.
 * Based on whose turn it is, we decide if the algorithm/recursive call should try to approach a min value or max value to optimize the player/AI making the move.
 *
 * @param miniMaxMove &game, which is the reference to the current game/board to be played. 
 * @param int player, which is the current player making the move 
 * @param int first_player, which is the original player that made the move and that we have to try to find the optimal move for
 * @param std::vector<miniMaxMove> &possibleMoves, holds all of the possible moves for the game to be compared for the best move.
 * @param int &num_moves, reference to the current number of moves the AI has played out.
 * @return This function returns a miniMaxMove struct object that holds the solution to the best move(hopefully).
 *
 * @pre none.
 * @post Finds the best possible move for the current state of the game using minimax.
 *
 */
miniMaxMove minimax(miniMaxMove &game, int player, int first_player, std::vector<miniMaxMove> &possibleMoves, int &num_moves)
{
	int score = gameIsOver(game.board, first_player);
	std::vector<miniMaxMove> possiblePlays;

	if(score == 1 || score == -1)
	{
		miniMaxMove end_game;
		end_game.score = score;
		return end_game;
	} 
	
	if(boardIsFull(game.board))
	{
		miniMaxMove full;
		full.score = 0;
		return full;
	}	

	int pass = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			//find an empty square
			if(game.board[i][j] == 0)
			{
				miniMaxMove mm_move;
				mm_move.row = i;
				mm_move.col = j;
				game.board[i][j] = player;	
				int score = gameIsOver(game.board, first_player);
				if(score == 1)
				{
					num_moves++;
					mm_move.score = 1;
					possiblePlays.push_back(mm_move);
					pass = 1;
				}
				game.board[i][j] = 0;
			}
		}
	}

	if(pass == 0)
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				//find an empty square
				if(game.board[i][j] == 0)
				{
					// that's the move, store it in the object then make the move.
					miniMaxMove mm_move;
					mm_move.row = i;
					mm_move.col = j;
					game.board[i][j] = player;				
					num_moves++;	
					//store the score of the recursive object that is passed, we only care about the object because at the win condition, we don't want the moves from it, we only want the current move used to get that score
					mm_move.score = minimax(game, (-1 * player), first_player,possibleMoves, num_moves).score;
					//store all of the generated moves into a vector
					possiblePlays.push_back(mm_move);
					possibleMoves.push_back(mm_move);
					//set the move back so the AI does not make the actual move until the entire recursion is done.
					game.board[i][j] = 0;
				}
			}
		}
	}

	//figure out which move is the best using the min max principle. If the current player is the first player to make the move, we want to maximize our move.
	//other wise minimmize the move set the best_possible_move to that after the score comparison based on the player.
	miniMaxMove best_possible_move;
	if(player == first_player)
	{
		best_possible_move.score = -100;
		for(int i = 0; i < possiblePlays.size(); i++)
		{
			if(possiblePlays[i].score > best_possible_move.score)
			{
				best_possible_move.score = possiblePlays[i].score;
				best_possible_move.row = possiblePlays[i].row;
				best_possible_move.col = possiblePlays[i].col;
			}
		}

	}
	else if(player == (-1 * first_player))
	{
		best_possible_move.score = 100;
		for(int i = 0; i < possiblePlays.size(); i++)
		{
			if(possiblePlays[i].score < best_possible_move.score)
			{
				best_possible_move.score = possiblePlays[i].score;
				best_possible_move.row = possiblePlays[i].row;
				best_possible_move.col = possiblePlays[i].col;
			}
		}

	}

	return best_possible_move;
}


/**
 * This function is the make_move function.
 *
 * This function will be responsible for making the actual move for the tic tac toe game. 
 * The function will first figure out whose move it is and then store that as the AI. 
 * The function will then check to see if the game is already over, if it is not, the function will continue to play out all the available moves. Otherwise it will 0 if the board is solved at the beginning.
 * The function will create a vector for all of the possibleGames and the tictactoe board of the struct miniMaxMove. 
 * The function will then copy the board passed in to this function to the tictactoe variable board so that it can be used to simualte all of the avaialble moves.
 * The function creates a final_move miniMaxMove object to hold the final move/best possible move for the game and assigns it to the recursive call/return of the mini max function. 
 * The function will then print the move that the board contains and sets the board to contain that move.
 * 
 *
 * @param int board[][3] which is the board to play tic tac toe on.
 * @return This function returns the number of steps it took to make the best move.
 *
 * @pre none.
 * @post Finds the best possible move for the current state of the game using minimax.
 *
 */
int make_move( int board[][3] )
{
	// figure out what move it is
	int state = 0;
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			state += board[i][j];
		}
	}

	state = -state;
	
	if(state == 0)
	{
		state = 1;
	}
	static int first_player = state;
	int num_moves = 0;

	int score = gameIsOver(board, state);
	if(score == 1 || score == -1)
	{
		//std::cout << num_moves << std::endl;
		return num_moves;	
	}
	else if(boardIsFull(board))
	{
		//std::cout << num_moves << std::endl;
		return num_moves;	
	}
	
	std::vector<miniMaxMove> possibleGames;
	miniMaxMove tictactoe;
	copyArray(board, tictactoe.board);

	//printBoard(tictactoe.board);

	miniMaxMove final_move;
	final_move = minimax(tictactoe, state, first_player,possibleGames, num_moves);
	
	printf("player [%d] made move: [%d,%d]\n", state, final_move.col, final_move.row);

	//forgot about row major vs col major, but its just flipped, assign the player value to the board.
	board[final_move.row][final_move.col] = state;
	
	//printBoard(board);

	//return size of game played
	//std::cout << num_moves << std::endl;
	return num_moves;
}
