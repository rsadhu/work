#include <iostream>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

int main()
{
    // Get the current working directory
    fs::path cwd = fs::current_path();
    std::cout << "Current working directory: " << cwd << std::endl;

    // Create a new directory
    fs::path new_dir = cwd / "example_dir";
    if (!fs::exists(new_dir))
    {
        fs::create_directory(new_dir);
        std::cout << "Created directory: " << new_dir << std::endl;
    }
    else
    {
        std::cout << "Directory already exists: " << new_dir << std::endl;
    }

    return 0;
}
