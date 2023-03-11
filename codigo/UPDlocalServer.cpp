#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <windows.h>

#pragma execution_character_set( "utf-8" )
namespace fs = std::filesystem;

int main() {
    SetConsoleOutputCP(65001);

    std::cout << "Seja bem vindo(a) ao UPD Local Server\nPor favor, insira o nome do seu projeto: \n> ";

    #pragma region Nome do projeto
    std::string projectName;
    std::getline(std::cin, projectName);
    #pragma endregion

    #pragma region confirmar nome do projeto
    std::string answer = "n";
    while (true) {
        std::cout << "\nO nome do seu projeto é " << projectName << "? (s/n)\n> ";
        std::getline(std::cin, answer);
        if (tolower(answer[0]) == 's') {
            break;
        }
        std::cout << "Insira novamente o nome do seu projeto: \n> ";
        std::getline(std::cin, projectName);
    }
    #pragma endregion

    #pragma region pasta raiz
    std::cout <<
        "\nPara usar o UPD Local Server você precisa de uma pasta raiz configurada no visual studio code. "
        "Para setar a pasta raiz, vá em File > Open Folder, e selecione a pasta do seu projeto, a pasta selecionada será considerada "
        "pelo visual studio code como a pasta raiz do seu projeto.\n\nPor favor, insira o caminho da pasta raiz do seu projeto: \n> ";

    std::string rootFolder = "";
    std::getline(std::cin, rootFolder);
    #pragma endregion

    #pragma region confirmar execução
    std::cout << "\nTenha em mente que todos os arquivos presentes no diretório C:\\Program Files(x86)\\EasyPHP - 5.3.9\\www\\" << projectName << " serão substituidos pelos arquivos na pasta raiz ao atualizar os arquivos. Deseja proceder ainda assim? (s/n)\n> ";
    std::getline(std::cin, answer);

    if (tolower(answer[0]) == 'n') {
        return 0;
    }
    #pragma endregion

    #pragma region arquivo bat
    std::ofstream updLocalServer(rootFolder + "\\UPDlocalServer.bat");
    std::string batCommand =
        "Robocopy \"" + rootFolder + "\" \"C:\\Program Files(x86)\\EasyPHP - 5.3.9\\www\\" + projectName + "\" /mir\n";

    updLocalServer << batCommand;
    updLocalServer.close();
    #pragma endregion

    #pragma region arquivo tasks.json
    fs::create_directories(rootFolder + "\\.vscode");
    std::ofstream tasksJson(rootFolder + "\\.vscode\\tasks.json");
    std::string fileContent =
        "{\n"
        "    \"version\": \"2.0.0\",\n"
        "    \"tasks\" : [\n"
        "        {\n"
        "            \"label\": \"Update Local Server\",\n"
        "                \"type\" : \"process\",\n"
        "                \"command\" : \"./UPDlocalServer.bat\",\n"
        "                \"presentation\" : {\"echo\": true, \"reveal\" : \"always\", \"focus\" : false, \"panel\" : \"shared\", \"showReuseMessage\" : false, \"clear\" : true},\n"
        "                \"group\" : {\"kind\": \"build\", \"isDefault\" : true},\n"
        "        }\n"
        "    ]\n"
        "}\n";
    tasksJson << fileContent;
    tasksJson.close();
    #pragma endregion

    std::cout <<
        "Criação de arquivos concluida, para atualizar a pasta www, abra o visual studio code na "
        "pasta raiz do projeto e use ctrl + shift + B\n";

    std::cout << "\nPressione enter para concluir esse arquivo\n";
    std::cin.get();
}
