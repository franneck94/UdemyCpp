#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
    fs::path chapter_path = fs::current_path();
    fs::path currentfile_path = fs::current_path();
    currentfile_path /= "FileSystem2.cc";

    for (auto it = fs::directory_iterator(chapter_path); it != fs::directory_iterator(); ++it)
    {
        std::cout << *it << std::endl;
    }

    std::cout << currentfile_path << " exists: " << std::boolalpha << fs::exists(currentfile_path) << std::endl;
    std::cout << currentfile_path << " is file: " << std::boolalpha << fs::is_regular_file(currentfile_path) << std::endl;
    std::cout << currentfile_path << " is directory: " << std::boolalpha << fs::is_directory(currentfile_path) << std::endl;

    fs::path new_directory_path;
    new_directory_path /= fs::current_path();
    new_directory_path /= "test";
    if (!fs::exists(new_directory_path))
    {
        fs::create_directory(new_directory_path);
    }
    fs::path destionation_path;
    destionation_path /= new_directory_path;
    destionation_path /= "FileSystemCopy.cc";
    destionation_path.replace_extension("cpp");
    if (!fs::exists(destionation_path))
    {
        fs::copy_file(currentfile_path, destionation_path);
    }
    std::system("ls -l test");
    std::system("tree test");
    // fs::remove_all("test");
}
