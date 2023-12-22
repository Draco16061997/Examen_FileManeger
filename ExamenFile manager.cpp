

#include <iostream>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace fs = std::filesystem;

//
//Реализовать простейший файловый менеджер с использованием ООП(классы, наследование и так далее).
//Файловый менеджер должен иметь такие возможности :
//■ показывать содержимое дисков;
//■ создавать папки / файлы;
//■ удалять папки / файлы;
//■ переименовывать папки / файлы;
//■ копировать / переносить папки / файлы;
//■ вычислять размер папки / файла;
//■ производить поиск по маске(с поиском по подпапкам) и так далее.



class FileManeger
{
public:
    void ls(string path)
    {
        for (const auto& file : fs::directory_iterator(path))
        {
            cout << file.path().string() << endl;
        }
    };

    void cd(string name)
    {
        fs::create_directory(std::string(name));
        cout << "created folder " << name << endl;
    };

    void cf(string name)
    {
        ofstream outputFile(name);
        cout << "created file " << name << endl;
    };

    void removeFile(string name)
    {
        try {
            fs::remove(name);
            std::cout << "Файл удален." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось удалить файл: " << e.what() << std::endl;
        }
    }

    void removeDir(string name)
    {
        try {
            fs::remove_all(name);
            std::cout << "Папка удалена." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось удалить папку: " << e.what() << std::endl;
            }
    }

    void renameFile(string oldName, string newName)
    {
        try {
            fs::rename(oldName, newName);
            std::cout << "Файл успешно переименован." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось переименовать файл: " << e.what() << std::endl;
        }
    }




};


void main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");


    FileManeger win;

    win.ls("d:\\");
    win.cd("d:\\testsssss");
    win.cf("d:\\123.txt");
    win.renameFile("d:\\123.txt", "d:\\321.txt");
    win.removeDir("d:\\testsssss");
    win.removeFile("d:\\321.txt");

    

    /*std::string folderPath = "d:\\test";
    std::string filePath = "d:\\edrgdtgdtghr.txt";


    if (fs::exists(folderPath) && fs::is_directory(folderPath)) {
        try {
            fs::remove_all(folderPath);
            std::cout << "Папка удалена." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось удалить папку: " << e.what() << std::endl;
    //    }
    //}
    //else {
    //    std::cerr << "Указанный путь не является папкой или не существует." << std::endl;
    //}


    if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
        try {
            fs::remove(filePath);
            std::cout << "Файл удален." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось удалить файл: " << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Указанный путь не является файлом или не существует." << std::endl;
    }*/


    /*
    std::string oldFilePath = "d:\\dz.txt";
    std::string newFilePath = "d:\\new_file.txt";


    if (fs::exists(oldFilePath) && fs::is_regular_file(oldFilePath)) {
        try {
            fs::rename(oldFilePath, newFilePath);
            std::cout << "Файл успешно переименован." << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Не удалось переименовать файл: " << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Указанный путь не является файлом или не существует." << std::endl;
    }*/






}



















