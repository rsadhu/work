
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

namespace Generator
{

    struct Data3d
    {
        double x = 0;
        double y = 0;
        double z = 0;
    };

    struct Position
    {
        uint64_t sensorId = 0;
        uint64_t timestamp;
        Data3d player;
    };

    class PositionGenerator
    {

        uint16_t num_of_players_;
        uint16_t size_of_field_;
        uint16_t step_size_;
        std::vector<Position> positions_;

    public:
        PositionGenerator(uint16_t num_of_players = NUM_PLAYERS, uint16_t size_of_field = FIELD_SIZE, uint16_t step_size = MAX_STEP_SIZE)
        {
            num_of_players_ = num_of_players;
            size_of_field_ = size_of_field;
            step_size_ = step_size;
            positions_.resize(num_of_players_);
            this->initializePlayers();
        }

        auto currentTime() const
        {
            auto now = std::chrono::system_clock::now();
            auto duration = now.time_since_epoch();
            return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
        }

        void initializePlayers()
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(0, size_of_field_);

            for (int i = 0; i < num_of_players_; ++i)
            {
                Position pos;
                pos.player = {dis(gen), dis(gen), 0};
                positions_.push_back(pos);
            }
        }

        std::vector<Position> createPositions()
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> stepDis(-this->step_size_, this->step_size_);
            std::uniform_real_distribution<> angleDis(0, 2 * M_PI);
            std::set<double> u_x, u_y;
            int counter = 0;

            for (auto &position : positions_)
            {
                auto &player = position.player;
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
                position.timestamp = currentTime();
                position.sensorId = ++counter;
                std::cout << player.x << " " << player.y << ", ";
            }
            std::cout << "\n";
            return std::move(positions_);
        }

        void printPlayerPositions(const std::vector<Data3d> &players)
        {
            for (const auto &player : players)
            {
                std::cout << player.x << " " << player.y << ", ";
            }
        }
    };
}; // Generator