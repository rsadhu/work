#include "generator.hpp"
#include "data_ipublisher.h"
#include "data_publisher_impl.h"
#include "schemas/position.pb.h"
#include "google/protobuf/util/json_util.h"

int main()
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    std::unique_ptr<IPublisher> pub = std::make_unique<Publisher>();

    while (true)
    {
        Generator::PositionGenerator pg(NUM_PLAYERS, FIELD_SIZE);
        std::vector<Generator::Position> positions = pg.createPositions();

        for (auto loc_pos : positions)
        {
            // Create a Position message
            myprotobuf::Position position;
            myprotobuf::Data3d *data3d = position.mutable_position_m();
            data3d->set_x(loc_pos.player.x);
            data3d->set_y(loc_pos.player.y);
            data3d->set_z(loc_pos.player.z);
            position.set_timestamp_ms(loc_pos.timestamp);
            position.set_sensorid(loc_pos.sensorId);

            // Serialize the message to a string
            std::string serialized_data;

            if (!position.SerializeToString(&serialized_data))
            {
                std::cerr << "Failed to serialize position message." << std::endl;
                return -1;
            }
            // std::cout << serialized_data << "\n";

            pub->publish(serialized_data);

            // myprotobuf::Position position_1;
            // if (!position_1.ParseFromString(serialized_data))
            // {
            //     std::cerr << " Failed t deserialize, this is bad\n";
            //     return -1;
            // }
            // std::cout << position_1.mutable_position_m()->x() << " " << position_1.mutable_position_m()->y() << "\n";

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        //   std::cout << "\n";
    }
    // Shutdown Google's Protocol Buffers library
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}