#include <iostream>
#include <fstream>
#include <vector>
#include "test.pb.h" // Include the generated protobuf code

int main()
{
    // Create a Person object
    Test::Person person;

    person.set_name("John Doe");
    person.set_address("1234 Elm Street");
    person.add_list_of_jobs("Developer"); // Repeated field
    person.add_list_of_jobs("Designer");  // Repeated field
    person.set_cur_job("Software Engineer");
    person.set_cur_salary(75000.0);

    // Serialize the Person object to a binary format
    std::ofstream output("person.bin", std::ios::binary);
    if (person.SerializeToOstream(&output))
    {
        std::cout << "Person object serialized successfully." << std::endl;
    }
    else
    {
        std::cerr << "Failed to serialize the Person object." << std::endl;
    }
    output.close();

    // Deserialize the binary data to read the Person object
    Test::Person deserialized_person;
    std::ifstream input("person.bin", std::ios::binary);
    if (deserialized_person.ParseFromIstream(&input))
    {
        std::cout << "Name: " << deserialized_person.name() << std::endl;
        std::cout << "Address: " << deserialized_person.address() << std::endl;
        std::cout << "Current Job: " << deserialized_person.cur_job() << std::endl;
        std::cout << "Current Salary: " << deserialized_person.cur_salary() << std::endl;

        std::cout << "List of Jobs:" << std::endl;
        for (int i = 0; i < deserialized_person.list_of_jobs_size(); ++i)
        {
            std::cout << "- " << deserialized_person.list_of_jobs(i) << std::endl;
        }
    }
    else
    {
        std::cerr << "Failed to deserialize the Person object." << std::endl;
    }
    input.close();

    return 0;
}
