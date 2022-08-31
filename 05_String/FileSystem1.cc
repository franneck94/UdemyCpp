#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path workspace_path = "C:/Users/Jan/OneDrive/_Coding/UdemyCpp";
    fs::path chapter_path;
    chapter_path = workspace_path;
    chapter_path /= "5_STLString";
    fs::path current_file_path = fs::current_path();
    current_file_path /= "FileSystem1.cc";

    std::cout << workspace_path << std::endl;
    std::cout << chapter_path << std::endl;
    std::cout << current_file_path << std::endl;

    std::cout << "relative_path: " << current_file_path.relative_path() << std::endl;
    std::cout << "parent_path: " << current_file_path.parent_path() << std::endl;
    std::cout << "filename: " << current_file_path.filename() << std::endl;
    std::cout << "stem: " << current_file_path.stem() << std::endl;
    std::cout << "extension: " << current_file_path.extension() << std::endl;

    std::cout << "exists: " << std::boolalpha << fs::exists(current_file_path)
              << std::endl;
    std::cout << "is_regular_file: " << std::boolalpha
              << fs::is_regular_file(current_file_path) << std::endl;
    std::cout << "is_directory: " << std::boolalpha
              << fs::is_directory(current_file_path) << std::endl;
}
