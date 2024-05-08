#include <iostream>
#include <vector>
#include "test_generated.h" // Include the generated FlatBuffers code

int main()
{
    // Use a FlatBuffers Builder to construct a Person object
    flatbuffers::FlatBufferBuilder builder(1024);

    // Create FlatBuffers strings for name, address, current job
    auto name = builder.CreateString("John Doe");
    auto address = builder.CreateString("1234 Elm Street");
    auto cur_job = builder.CreateString("Software Engineer");

    // Create a FlatBuffers vector for the list_of_jobs
    std::vector<flatbuffers::Offset<flatbuffers::String>> jobs;
    jobs.push_back(builder.CreateString("Developer"));
    jobs.push_back(builder.CreateString("Designer"));
    auto list_of_jobs = builder.CreateVector(jobs);

    // Create a Person object in FlatBuffers
    auto person = Test::CreatePerson(
        builder,
        name,
        address,
        list_of_jobs,
        cur_job,
        75000.0 // Current salary
    );

    // Finish the FlatBuffer
    builder.Finish(person);

    // Now you have a serialized Person object in a FlatBuffer
    uint8_t *buf = builder.GetBufferPointer();
    size_t size = builder.GetSize();

    // Let's deserialize it and read the data
    auto person_ptr = Test::GetPerson(buf); // Deserialize from buffer

    std::cout << "Name: " << person_ptr->name()->str() << std::endl;
    std::cout << "Address: " << person_ptr->address()->str() << std::endl;
    std::cout << "Current Job: " << person_ptr->cur_job()->str() << std::endl;
    std::cout << "Current Salary: " << person_ptr->cur_salary() << std::endl;

    std::cout << "List of Jobs:" << std::endl;
    for (const auto &job : *person_ptr->list_of_jobs())
    {
        std::cout << "- " << job->str() << std::endl;
    }

    return 0;
}
