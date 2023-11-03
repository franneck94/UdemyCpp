#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    const fs::path workspace_path = "C:/Users/Jan/OneDrive/_Coding/UdemyCpp";
    fs::path chapter_path;
    chapter_path = workspace_path;
    chapter_path /= "06_String";

    std::cout << workspace_path << '\n';
    std::cout << chapter_path << '\n';

    auto current_file_path = fs::current_path();
    current_file_path /= "FileSystem1.cc";
    std::cout << current_file_path << '\n';

    std::cout << "relative_path: " << current_file_path.relative_path() << '\n';
    std::cout << "parent_path: " << current_file_path.parent_path() << '\n';
    std::cout << "filename: " << current_file_path.filename() << '\n';
    std::cout << "stem: " << current_file_path.stem() << '\n';
    std::cout << "extension: " << current_file_path.extension() << '\n';

    std::cout << "exists: " << fs::exists(current_file_path) << '\n';
    std::cout << "is file: " << fs::is_regular_file(current_file_path) << '\n';
    std::cout << "is dir: " << fs::is_directory(current_file_path) << '\n';
}
