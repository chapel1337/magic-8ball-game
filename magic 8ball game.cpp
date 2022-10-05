﻿#include <iostream>
#include <string>
#include <random>
#include <windows.h>
using std::cout; using std::cin; using std::ws; using std::string;

string input{ "" };
// string previousResponses[] { "" };
// string previousInputs[] { "" };
// int responsesCount{ 0 };

bool noteSent{ false };

string possibleResponses[]{ 
"it is certain",
"it is decidedly so",
"without a doubt",
"yes definitely",
"you may rely on it",
"as i see it, yes",
"most likely",
"outlook good",
"yes",
"signs point to yes",
"reply hazy, try again",
"ask again later",
"better not tell you now",
"cannot predict now",
"concentrate and ask again",
"don't count on it",
"my reply is no",
"my sources say no", 
"outlook not so good", 
"very doubtful", 
};

// ------- \\

void menu();
void invalidInput(string returnFunction);

void clear()
{
    system("cls");
}

void title(string title)
{
    std::system(("title " + title).c_str());
}

void sleep(auto time)
{
    Sleep(time * 1000);
}

int getRandom(int minimum, int maximum)
{
    // i had to copy this from learncpp.com, i will not be memorizing this prng method anytime soon
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution random{ minimum, maximum };

    return random(mt);
}

// ------- \\

void shake8Ball()
{
    clear();

    int random{ getRandom(1, 20) };
    int i{ 1 };

    for (i; i <= 3; i++)
    {
        switch (i)
        {
            // there's probably a better way to do this
            case 1:
                cout << '.';
            break;

            case 2:
                cout << "..";
            break;

            case 3:
                cout << "...";
            break;
        }

        cout << "\n\n> " << input;

        sleep(0.5);
        clear();
    }

    /*
    switch (random)
    {
        case 1:
            cout << "it is certain";
            break;

        case 2:
            cout << "it is decidedly so";
            break;

        case 3:
            cout << "without a doubt";
            break;

        case 4:
            cout << "yes, definitely";
            break;

        case 5:
            cout << "you may rely on it";
            break;

        case 6:
            cout << "as i see it, yes";
            break;

        case 7:
            cout << "outlook good";
            break;

        case 8:
            cout << "most likely";
            break;

        case 9:
            cout << "yes";
            break;

        case 10:
            cout << "signs point to yes";
            break;

        case 11:
            cout << "reply hazy, try again";
            break;

        case 12:
            cout << "ask again later";
            break;
            
        case 13:
            cout << "better not tell you now";
            break;

        case 14:
            cout << "cannot predict now";
            break;

        case 15:
            cout << "concentrate and ask again";
            break;

        case 16:
            cout << "don't count on it";
            break;

        case 17:
            cout << "my reply is no";
            break;

        case 18:
            cout << "my sources say no";
            break;

        case 19:
            cout << "vutlook not so good";
            break;

        case 20:
            cout << "very doubtful";
            break;   
    }

    */

    cout << possibleResponses[random] << "\n\n";
    cout << "> " << input << "\n\n";

    system("pause");

    // ++responsesCount;
    input = "";

    /*
    previousResponses[responsesCount] += possibleResponses[random];
    previousInputs[responsesCount] += input;

    cout << responsesCount << '\n';
    cout << possibleResponses[random] << '\n';
    cout << input << '\n';

    for (int i{ 0 }; i < std::ssize(previousResponses); ++i)
    {
        cout << previousResponses[i] << '\n';
    }

    for (int i{ 0 }; i < std::ssize(previousInputs); ++i)
    {
        cout << previousInputs[i] << '\n';
    }
    */
    
    menu();
}

void start()
{
    clear();
    title("magic 8ball");

    cout << "input a sentence: \n\n";

    cout << "> ";
    getline(cin >> ws, input);

    if (input != "")
    {
        shake8Ball();
    }
    else
    {
        invalidInput("menu");
    }
}

// ------- \\

/*

void insultingResponses()
{

}

void funnyResponses()
{

}

void moaiResponses()
{
    
}

void changeResponsesMenu()
{
    clear();
    title("magic 8ball - change responses");

    char response{};

    cout << "1. insulting responses\n";
    cout << "2. funny responses\n";
    cout << "3. 🗿 responses\n";

    cout << "> ";
    cin >> response;

    switch (response)
    {
    case '1':
        insultingResponses();
        break;

    case '2':
        funnyResponses();
        break;

    case '3':
        moaiResponses();
        break;

    default:
        invalidInput("settings");
        break;
    }
}

// ------- \\


void changeColorMenu()
{
    clear();

}


void settings()
{
    clear();
    title("magic 8ball - settings");

    char response{};

    cout << "1. change responses\n";
    cout << "2. change color\n";
    cout << "3. back\n";

    cin >> response;

    switch (response)
    {
        case '1':
            changeResponsesMenu();
        break;

        case '2':
            changeColorMenu();
        break;

        case '3':
            menu();
        break;
    }
}


void previouslyAnswered()
{
    clear();
    title("magic 8ball - previously responses");

    if (!noteSent)
    {
        cout << "note: this data is wiped when you exit the program\n";
        noteSent = true;

        // sleep(2);
        clear();
    }

    for (int i{ 0 }; i < std::ssize(previousResponses); ++i)
    {
        cout << "input: " << previousInputs[i] << '\n';
        cout << "response: " << previousResponses[i] << "\n\n";
    }

    system("pause");
    menu();
}
*/

void quit()
{
    clear();
    title("quit");

    for (int i{ 3 }; i >= 1; i--)
    {
        cout << "okay, exiting in " << i;

        sleep(1);
        clear();
    }

    exit(1);
}

void menu()
{
    clear();
    title("magic 8ball - menu");

    char response{};

    cout << "1. start\n";
    // cout << "2. settings\n";
    cout << "2. quit\n\n";

    cout << "> ";
    cin >> response;

    switch (response)
    {
        case '1':
            start();
            break;

            /*
        case '2':
            settings();
            break;
            */

        case '2':
            quit();
            break;

        default:
            invalidInput("menu");
            break;
    }
}

void invalidInput(string returnFunction)
{
    clear();
    title("magic 8ball - invalid input");

    cout << "invalid input\n";
    input = "";

    sleep(2);
    start();

    if (returnFunction == "menu")
    {
        menu();
    }
    /*
    else if (returnFunction == "settings")
    {
        settings();
    }
    */
}

int main()
{
    title("magic 8ball - credits\n");

    cout << "magic 8ball game\n\n";
    cout << "written by chapel1337\n";

    sleep(2);
    menu();
}