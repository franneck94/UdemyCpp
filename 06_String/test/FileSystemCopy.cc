#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const auto current_path = fs::current_path();

    for (auto it = fs::directory_iterator(current_path);
         it != fs::directory_iterator{};
         ++it)
    {
        if (fs::is_regular_file(*it))
        {
            std::cout << "Is file: " << *it << "\n";
        }
        else
        {
            std::cout << "Is dir: " << *it << "\n";
        }
    }

    auto new_directory_path = fs::current_path();
    new_directory_path /= "test";

    if (!fs::exists(new_directory_path))
    {
        fs::create_directory(new_directory_path);
    }

    auto current_file_path = fs::current_path();
    current_file_path /= "FileSystem2.cc";

    fs::path new_file_path;
    new_file_path /= new_directory_path;
    new_file_path /= "FileSystemCopy.cc";

    if (!fs::exists(new_file_path))
    {
        fs::copy_file(current_file_path, new_file_path);
    }
}
