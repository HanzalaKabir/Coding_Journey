#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Global variables
int bird_x = 100;
int bird_y = 100;
int pipe_x = 300;
int pipe_y = 200;
int pipe_gap = 100;
int score = 0;

// Function declarations
void draw_bird();
void draw_pipe();
void update_positions();
void check_collision();
void end_game();

// Main function
int main()
{
    // Initialize random number generator
    srand(time(NULL));

    // Start the game loop
    while (true)
    {
        // Clear the screen
        cout << "\033[2J";

        // Draw the bird
        draw_bird();

        // Draw the pipes
        draw_pipe();

        // Update the positions of the bird and the pipes
        update_positions();

        // Check for collisions
        check_collision();

        // Display the score
        cout << "Score: " << score << endl;

        // Wait for a key press
        char key = getchar();

        // If the user presses the spacebar, make the bird flap
        if (key == ' ')
        {
            bird_y -= 20;
        }

        // If the bird hits a pipe, end the game
        if (bird_y < pipe_y || bird_y > pipe_y + pipe_gap)
        {
            break;
        }
    }

    // Display the game over message
    cout << "Game Over!" << endl;

    // Wait for the user to press a key
    getchar();

    return 0;
}

// Function to draw the bird
void draw_bird()
{
    cout << "   (__)" << endl;
    cout << "  (oo)" << endl;
    cout << ":  /" << endl;
    cout << " /:  " << endl;
}

// Function to draw the pipes
void draw_pipe()
{
    cout << "      _" << endl;
    cout << "     (__)" << endl;
    cout << "   / /  " << endl;
    cout << " * / /  *" << endl;
    cout << "    ~~  " << endl;
}

// Function to update the positions of the bird and the pipes
void update_positions()
{
    // Move the bird down
    bird_y += 2;

    // Move the pipes to the left
    pipe_x -= 5;

    // If the pipes have moved off the screen, create new pipes
    if (pipe_x < -100)
    {
        pipe_x = 600;
        pipe_y = rand() % 300 + 100;
    }
}

// Function to check for collisions
void check_collision()
{
    // Check if the bird has hit the top or bottom of the screen
    if (bird_y < 0 || bird_y > 400)
    {
        end_game();
    }

    // Check if the bird has hit a pipe
    if (bird_x > pipe_x - 20 && bird_x < pipe_x + 20 &&
        bird_y > pipe_y - 20 && bird_y < pipe_y + 20)
    {
        end_game();
    }
}

// Function to end the game
void end_game()
{
    cout << "Game Over!" << endl;
    exit(0);
}
