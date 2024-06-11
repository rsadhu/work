#include <iostream>
#include <random>
#include <vector>
#include <utility>
#include <cmath>
#include <chrono>
#include <thread>
#include <set>

const int FIELD_SIZE = 100;
const int NUM_PLAYERS = 10;
const int MAX_STEP_SIZE = 2; // Maximum step size in meters

struct Player
{
    double x;
    double y;
    double z = 0;
};

std::vector<Player> initializePlayers(int numPlayers, int fieldSize)
{
    std::vector<Player> players;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0, fieldSize);

    for (int i = 0; i < numPlayers; ++i)
    {
        players.push_back({dis(gen), dis(gen)});
    }

    return players;
}

void movePlayers(std::vector<Player> &players, int maxStepSize)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> stepDis(-maxStepSize, maxStepSize);
    std::uniform_real_distribution<> angleDis(0, 2 * M_PI);
    std::set<double> u_x, u_y;

    for (auto &player : players)
    {

        do
        {
            double angle = angleDis(gen);
            double step = stepDis(gen);
            player.x += step * cos(angle);
            player.y += step * sin(angle);

        } while ((u_x.find(player.x) != u_x.end() && u_y.find(player.y) != u_y.end()));

        // Ensure players stay within the field boundaries
        player.x = std::max(0.0, std::min(static_cast<double>(FIELD_SIZE), player.x));
        player.y = std::max(0.0, std::min(static_cast<double>(FIELD_SIZE), player.y));
    }
}

void printPlayerPositions(const std::vector<Player> &players)
{
    for (const auto &player : players)
    {
        std::cout << player.x << " " << player.y << ", ";
    }
}

int main()
{
    std::vector<Player> players = initializePlayers(NUM_PLAYERS, FIELD_SIZE);
    while (true)
    {
        movePlayers(players, MAX_STEP_SIZE);
        printPlayerPositions(players);
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
