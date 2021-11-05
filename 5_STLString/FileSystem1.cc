#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main()
{
    fs::path workspace_path = "C:/Users/Jan/Dropbox/_Coding/UdemyCpp";
    fs::path chapter_path = workspace_path;
    chapter_path /= "5_STLString";
    fs::path currentfile_path = fs::current_path();
    currentfile_path /= "FileSystem1.cc";

    std::cout << "workspace_path = " << workspace_path << '\n';
    std::cout << "chapter_path = " << chapter_path << '\n';
    std::cout << "currentfile_path = " << currentfile_path << '\n';

    std::cout << "relative_path " << currentfile_path.relative_path() << std::endl;
    std::cout << "parent_path " << currentfile_path.parent_path() << std::endl;
    std::cout << "filename " << currentfile_path.filename() << std::endl;
    std::cout << "stem " << currentfile_path.stem() << std::endl;
    std::cout << "extension " << currentfile_path.extension() << std::endl;

    std::cout << currentfile_path << " exists: " << std::boolalpha << fs::exists(currentfile_path) << std::endl;
    std::cout << currentfile_path << " is file: " << std::boolalpha << fs::is_regular_file(currentfile_path)
              << std::endl;
    std::cout << currentfile_path << " is directory: " << std::boolalpha << fs::is_directory(currentfile_path)
              << std::endl;
}
