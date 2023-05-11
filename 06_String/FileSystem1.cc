#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path workspace_path = "C:/Users/Jan/OneDrive/_Coding/UdemyCpp";
    fs::path chapter_path;
    chapter_path = workspace_path;
    chapter_path /= "5_STLString";
    fs::path current_file_path = fs::current_path();
    current_file_path /= "FileSystem1.cc";

    std::cout << workspace_path << '\n';
    std::cout << chapter_path << '\n';
    std::cout << current_file_path << '\n';

    std::cout << "relative_path: " << current_file_path.relative_path() << '\n';
    std::cout << "parent_path: " << current_file_path.parent_path() << '\n';
    std::cout << "filename: " << current_file_path.filename() << '\n';
    std::cout << "stem: " << current_file_path.stem() << '\n';
    std::cout << "extension: " << current_file_path.extension() << '\n';

    std::cout << "exists: " << std::boolalpha << fs::exists(current_file_path)
              << '\n';
    std::cout << "is_regular_file: " << std::boolalpha
              << fs::is_regular_file(current_file_path) << '\n';
    std::cout << "is_directory: " << std::boolalpha
              << fs::is_directory(current_file_path) << '\n';
}
