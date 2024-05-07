#include <stdio.h>
#include <tgbot/tgbot.h>
#include <iostream>
#define SQLITECPP_COMPILE_DLL
#include <SQLiteCpp/SQLiteCpp.h>
#include <vector>
#include <sqlite3.h>
#include <ctime>
#include <time.h>
#include <fstream>

#include <SFML/Graphics.hpp> 
#include <random> 
#include "..//GachiTonoKaiBot/steam/steam_api.h"
#include <cctype>



using namespace SQLite;
using namespace std;
using namespace TgBot;
using namespace StringTools;

// ������� ���� ������ � ������
Database db("Database.db", OPEN_READWRITE | OPEN_CREATE);

const vector <string> variant =
{
u8"���, �� ", u8"���,�� ", u8"��� �� ",
u8"���, �� ", u8"���,�� ", u8"��� �� ",

u8"�����, ���, �� ",
u8"����� ���, ��",
u8"����� ��� �� ",
};
const vector <string> check =
{
u8"�� ���?" ,u8"�� �����?",

u8"��� ��", u8"��� ���", u8"��� ����",
u8"��� �� ", u8"��� ��� ", u8"��� ���� ",
u8"��� ��", u8"��� ���", u8"��� ����",

u8"������ ���",
u8"��� ������",
u8"���, ������"
};

const vector <string> ban =
{
u8"���, ������ ", u8"���,������ ", u8"��� ������ ",
u8"���, ������ ", u8"���,������ ", u8"��� ������ ",

u8"����� ��� ������ ",
u8"�����, ���, ������ ",
u8"����� ���, ������",

u8"���, ��� ", u8"���,��� ", u8"��� ��� ",
u8"���, ��� ", u8"���,��� ", u8"��� ��� ",

u8"����� ��� ��� ",
u8"�����, ���, ��� ",
u8"����� ���, ���",

u8"���, ��� ", u8"���,��� ", u8"��� ��� ",
u8"���, ��� ", u8"���,��� ", u8"��� ��� ",

u8"����� ��� ��� ",
u8"�����, ���, ��� ",
u8"����� ���, ���",
};

const vector <string> like =
{
u8"���, � ", u8"���,� ", u8"��� � ",
u8"���, � ", u8"���,� ", u8"��� � ",

u8"���, ������ � ", u8"���,������ � ", u8"��� ������ � ",
u8"���, ������ � ", u8"���,������ � ", u8"��� ������ � ",
};

int week()
{
    time_t t = time(NULL);
    tm* now = localtime(&t);
    return now->tm_wday;
}

ChatMember::Ptr UserInfo(Bot& bot, Message::Ptr message)
{
    ChatMember::Ptr ChatMemberUser = bot.getApi().getChatMember(message->chat->id, message->from->id);
    return ChatMemberUser;
}

int paint(int height)
{
    int width = height;
   
    // Create the window 
    sf::RenderWindow window(sf::VideoMode(width, height), "MegaRandomPhoto");

    // Random number generator 
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> dist(0, 255);

    // Create the image 
    sf::Image image;
    image.create(width, height, sf::Color::White);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int randomValue = dist(rng);
            if (randomValue < 128)
                image.setPixel(x, y, sf::Color::Black);
            else
                image.setPixel(x, y, sf::Color::White);
        }
    }

    // Create the texture 
    sf::Texture texture;
    texture.loadFromImage(image);

    // Create the sprite 
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.getTexture()->copyToImage().saveToFile("Photo/RandomPhoto.jpg");

    // Start the game loop 
    //while (window.isOpen())
    //{
    //    // Handle events 
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //    }

    //    // Clear the screen 
    //    window.clear();

    //    // Draw the sprite 
    //    window.draw(sprite);

    //    // Display the screen 
    //    window.display();
    //}

    return 0;
}

int main()
{
    setlocale(LC_ALL, "RU");
    srand(time(NULL));
    

    Bot bot("6335241580:AAEfid9JQ8f2hK5vBMDT59MAe1KNNIHdojw");
   
    //SteamAPI_Init();

    //bot.getEvents().onCommand("gamestats", [&bot](TgBot::Message::Ptr message) {
    //    std::string gameId = message->text.substr(11); // Extract the game ID from the command message
    //    CGameID gameID(gameId.c_str());

    //    if (gameID.IsValid()) {
    //        uint64_t playtime = SteamUserStats()->GetUserStatsForGame(SteamUser()->GetSteamID(), gameID)->GetStatInt("total_playtime");

    //        std::string response = "Total playtime in " + gameId + ": " + std::to_string(playtime) + " minutes";
    //        bot.getApi().sendMessage(message->chat->id, response);
    //    }
    //    else {
    //        bot.getApi().sendMessage(message->chat->id, "Invalid game ID. Please provide a valid Steam game ID.");
    //    }
    //    });

    //������� - start@GachiTonoKaiBot
    bot.getEvents().onCommand("start", [&bot](Message::Ptr message) 
    {
        switch (UserInfo(bot, message)->user->id)
        {
            
        case 1732616250:
            
            bot.getApi().sendMessage(message->chat->id, u8"����������� ���, ���������");
            break;
        case 1643155787:
            bot.getApi().sendMessage(message->chat->id, UserInfo(bot, message)->user->firstName + u8", ��� �� Python ����");
            break;
        case 987626057:
            bot.getApi().sendMessage(message->chat->id, UserInfo(bot, message)->user->firstName + u8", �� ������ ������� ������ �� Minecraft");
            break;
        case 5089396169:
            bot.getApi().sendMessage(message->chat->id, UserInfo(bot, message)->user->firstName + u8", ��� ������ �����");
            break;
        default:
            bot.getApi().sendMessage(message->chat->id, u8"������ " + UserInfo(bot, message)->user->firstName + u8", � ���, ��������� ��� ���� ��������� t.me/Tochn0. �� ������ ������ � �������� �� ������ ���������� � ���� ������ ���� ����������.��� ������, � ������� �������� �� ������������ t.me/+fVL4pYqFKnBmM2U6.");
            break;
        }
        try 
        {
            // ��������� ���� ������
            SQLite::Database database("Database.db", SQLite::OPEN_READWRITE);

            // �������������� SQL-������ � ����������
            SQLite::Statement query(db, "SELECT COUNT(*) FROM users WHERE user_id = ?");

            // ����������� �������� ���������
            query.bind(1, UserInfo(bot, message)->user->id);
            /*query.bind(2, message->chat->username);
            query.bind(3, message->chat->firstName);
            query.bind(4, message->chat->lastName);*/



            // ��������� ������ � �������� ���������
            if (query.executeStep()) 
            {
                int count = query.getColumn(0).getInt();

                // ���� ���������� ����������� ����� 1, ������������ � �������� id ����������
                if (count > 0) 
                {
                    cout << "User " << UserInfo(bot, message)->user->username << " with id " << UserInfo(bot, message)->user->id << " has already been logged into the database." << endl;
                }
                else 
                {
                    cout << "User " << UserInfo(bot, message)->user->username << " with id " << UserInfo(bot, message)->user->id << " has not been found and has been successfully logged into the database." << endl;
                    bot.getApi().sendMessage(message->chat->id, UserInfo(bot, message)->user->firstName + u8", ��� �� ���� � Base, �� ������ �� ��� ���� ");

                    // ��������� ������ � �������
                    SQLite::Statement query(db, "INSERT INTO users(user_id, username, user_name, user_surname) VALUES(?1, ?2, ?3, ?4)");
                    query.bind(1, UserInfo(bot, message)->user->id);
                    query.bind(2, UserInfo(bot, message)->user->username);
                    query.bind(3, UserInfo(bot, message)->user->firstName);
                    query.bind(4, UserInfo(bot, message)->user->lastName);
                    query.exec();
                }
            }
        }
        catch (const std::exception& e) 
        {
            // ��������� ������
            std::cout << "Error: " << e.what() << std::endl;
        }
    });
    //������� - daniel
    bot.getEvents().onCommand("daniel", [&bot](Message::Ptr message) 
    {
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("Cat.jpg", "image/jpg"));
        bot.getApi().sendMessage(message->chat->id, u8"��� ��� ����� ����� t.me/slaveforleatherbags_bot ������ ��� ����������");
    });
    
    //������� - Create Photo
    bot.getEvents().onCommand("cp", [&bot](Message::Ptr message)
    {
            try
            {
                string size = message->text.substr(4);
                stoi(size);
                cout << "User write size " << size << endl;
                if (stoi(size) > 3000 || stoi(size) <= 0)
                {
                    bot.getApi().sendMessage(message->chat->id, u8"������ �� ������ ���� �� ���������, ��������� ����������� ��������:");
                    int size = 800;
                    paint(size);
                    return 0;
                }
                paint(stoi(size));
            }
            catch (const std::exception&)
            {
                bot.getApi().sendMessage(message->chat->id, u8"������ �� ������ ���� �� ���������, ��������� ����������� ��������:");
                int size = 800;
                paint(size);
            }

            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("Photo/RandomPhoto.jpg", "image/jpg"));
        
    });

    
    bot.getEvents().onCommand("schedule", [&bot](Message::Ptr message) {

        bot.getApi().sendMessage(message->chat->id, u8"��� ���� ����������:");
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("Monday.jpg", "image/jpg"));
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("Thursday.jpg", "image/jpg"));

    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) 
    {
        if (message->document != nullptr) {
            string fileId = message->document->fileId;
            File::Ptr file = bot.getApi().getFile(fileId);
            const std::string& url = "https://api.telegram.org/file/bot" + bot.getToken() + "/" + file->filePath;
            string fileName = message->document->fileName;

            std::ofstream outfile("downloads/" + fileName, ofstream::binary);
            if (outfile.is_open()) 
            {
                outfile << url;
                bot.getApi().downloadFile(url);
                bot.getApi().sendMessage(message->chat->id, "File downloaded successfully!");
                bot.getApi().sendMessage(message->chat->id, "Here is the link to download your file " + url);
                cout << message->chat->username << " File downloaded successfully!" << std::endl;
            }
            else {
                cerr << "Error opening file for writing." << std::endl;
            }
        }
    });

    //������� - schedulenow
    bot.getEvents().onCommand("schedulenow"  , [&bot](Message::Ptr message)
    {
        switch (week())
        {
        case 1:
            bot.getApi().sendMessage(message->chat->id, u8"������� �����������. ��� ��� ����������:");
            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("����������/�����������.jpg", "image/jpg"));
            break;
        case 2:
            bot.getApi().sendMessage(message->chat->id, u8"������� �������. ��� ��� ����������:");
            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("����������/�������.jpg", "image/jpg"));
            break;
        case 3:
            bot.getApi().sendMessage(message->chat->id, u8"������� �����. ��� ��� ����������:");
            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("����������/�����.jpg", "image/jpg"));
            break;
        case 4:
            bot.getApi().sendMessage(message->chat->id, u8"������� �������. ��� ��� ����������:");
            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("����������/�������.jpg", "image/jpg"));
            break;
        case 5:
            bot.getApi().sendMessage(message->chat->id, u8"������� �������. ��� ��� ����������:");
            bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("����������/�������.jpg", "image/jpg"));
            break;
        case 6:
            bot.getApi().sendMessage(message->chat->id, u8"������� �������, �������");
            break;
        case 0:
            bot.getApi().sendMessage(message->chat->id, u8"������� �����������. ������ � �����, ����� �����");
            break;
        default:
            bot.getApi().sendMessage(1732616250, u8"�������� ��� ��������!!!");
            return;
        }
    });
    //������� - time
    bot.getEvents().onCommand("time", [&bot](Message::Ptr message) 
    {

        bot.getApi().sendMessage(message->chat->id, u8"��� ����� ������:");
        bot.getApi().sendPhoto(message->chat->id, InputFile::fromFile("time.jpg", "image/jpg"));

    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message)
    {


        if (startsWith(message->text, u8"���, ������� ���������"))
        {
            bot.getApi().sendMessage(message->chat->id, u8"����");
            SteamAPI_RestartAppIfNecessary(480);
        }


    });

    bot.getEvents().onAnyMessage([&bot](Message::Ptr message) 
    {
        printf("User wrote %s\n", message->text.c_str());
        if (startsWith(message->text, u8"��� ������"))
        {
            switch (message->chat->id)
            {
            case 1732616250:
                bot.getApi().sendMessage(message->chat->id, u8"����������� ���, ���������");
                break;
            case 5089396169:
                bot.getApi().sendMessage(message->chat->id, u8"������ - ������. ����� ����");
                break;
            default:
                bot.getApi().sendMessage(message->chat->id, u8"������, " + UserInfo(bot, message)->user->firstName);
            }
        }
        if (startsWith(message->text, u8"��"))
        {
            bot.getApi().sendMessage(message->chat->id, u8"...");
        }
        //��� �� ���?
        for (int i = 0; i < check.size(); i++)
        {
            if (startsWith(message->text, check[i]))
            {
                cout << "The answer option worked CHECK" << endl;

                switch (rand() % 7)
                {
                case 0:case 1:
                    bot.getApi().sendMessage(message->chat->id, u8"� �����");
                    break;
                case 2:case 3:
                    bot.getApi().sendMessage(message->chat->id, u8"��");
                    break;
                case 4:case 5:
                    bot.getApi().sendMessage(message->chat->id, u8"������, " + UserInfo(bot, message)->user->firstName);
                    break;
                case 6:
                    bot.getApi().sendMessage(message->chat->id, u8"...");
                    break;
                }
            }
        }
        //�������� ������
        for (int j = 0; j < variant.size(); j++)
        {
            
            if (startsWith(message->text, variant[j]))
            {
                cout << "The answer option worked VAR" << endl;
                switch (rand() % 7)
                {
                case 0:case 1:
                    bot.getApi().sendMessage(message->chat->id, u8"��");
                    break;
                case 2:case 3:
                    bot.getApi().sendMessage(message->chat->id, u8"���");
                    break;
                case 4:case 5:
                    bot.getApi().sendMessage(message->chat->id, u8"��������");
                    break;
                case 6:
                    bot.getApi().sendMessage(message->chat->id, u8"����� ����");
                    break;
                }
            }
        }
        //like
        for (int j = 0; j < like.size(); j++)
        {
            if (startsWith(message->text, like[j]))
            {
                cout << "The answer option worked LIKE" << endl;
                bot.getApi().sendMessage(message->chat->id, u8"�������" + UserInfo(bot, message)->user->firstName);
            }
        }
        //ban
        for (int j = 0; j < ban.size(); j++)
        {
            if (startsWith(message->text, ban[j]))
            {
                cout << "The answer option worked BAN" << endl;
                switch (rand() % 7)
                {
                case 0:case 1:
                    bot.getApi().sendMessage(message->chat->id, u8"� �� ����");
                    break;
                case 2:case 3:
                    bot.getApi().sendMessage(message->chat->id, u8"����� �� ��� �����������");
                    break;
                case 4:case 5:
                    bot.getApi().sendMessage(message->chat->id, u8"����� �� ��� ������ ������? ���� �������� �����? ");
                    break;
                case 6:
                    bot.getApi().sendMessage(message->chat->id, u8"� ������ ������� ����. ������ � ����?");
                    break;
                }
            }
        }
    });


    // ��������� ������ � �������
    try 
    {
        printf("Bot username: %s\n", bot.getApi().getMe()->username.c_str());
        cout << "Nomber week " << week() << endl;
        TgLongPoll longPoll(bot);
        printf("Bot activated\n");
        while (true) 
        {
            printf("Long poll started\n");
            longPoll.start();
        }
    }
    catch (TgException& e) 
    {
        printf("error: %s\n", e.what());
    }

    return 0;   
}

