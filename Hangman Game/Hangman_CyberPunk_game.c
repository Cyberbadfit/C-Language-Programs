#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(ms) usleep(ms * 1000)
#endif

#define MAX_LENGTH 50
#define MAX_ATTEMPTS 7

const char *easyWords[] = {
    "apple", "banana", "orange", "grape", "house",
    "school", "garden", "friend", "window", "planet"
};

const char *mediumWords[] = {
    "computer", "keyboard", "internet", "security", "software",
    "database", "terminal", "compiler", "network", "protocol"
};

const char *hardWords[] = {
    "cryptography", "cybersecurity", "microprocessor",
    "virtualization", "multithreading", "polymorphism",
    "decentralized", "authentication", "encyclopedia", "nanotechnology"
};

char guessedLetters[100];
int guessedCount = 0;

void printSlow(const char *text)
{
    while (*text)
    {
        printf("%c", *text);
        fflush(stdout);
        SLEEP(15);
        text++;
    }
}

void loadingAnimation()
{
    system(CLEAR);

    printf("\n\n");
    printf("\033[1;36m");
    printSlow("      INITIALIZING CYBERBADFIT HANGMAN ENGINE\n\n");
    printf("\033[0m");

    for (int i = 0; i < 35; i++)
    {
        printf("#");
        fflush(stdout);
        SLEEP(40);
    }

    printf("\n\n");

    printSlow("Loading AI Difficulty Engine...\n");
    SLEEP(300);

    printSlow("Loading Smart Hint System...\n");
    SLEEP(300);

    printSlow("Loading Word Database...\n");
    SLEEP(300);

    printSlow("Loading Cyber Decorations...\n");
    SLEEP(300);

    printf("\n\033[1;32mSYSTEM READY!\033[0m\n");
    SLEEP(1000);
}

void banner()
{
    printf("\033[1;35m");
    printf("=====================================================\n");
    printf("        MODERN AI HANGMAN - CYBERBADFIT\n");
    printf("=====================================================\n");
    printf("\033[0m");
}

void cyberEffects()
{
    printf("\033[1;32m");

    for (int i = 0; i < 50; i++)
    {
        printf("=");
    }

    printf("\033[0m\n");
}

void drawHangman(int attempts)
{
    printf("\n\033[1;31m");

    switch (attempts)
    {
    case 0:
        printf("\n\n\n\n\n");
        break;

    case 1:
        printf("\n\n\n\n____\n");
        break;

    case 2:
        printf(" |\n |\n |\n |\n_|___\n");
        break;

    case 3:
        printf(" ______\n |\n |\n |\n_|___\n");
        break;

    case 4:
        printf(" ______\n |    |\n |    O\n |\n_|___\n");
        break;

    case 5:
        printf(" ______\n |    |\n |    O\n |    |\n_|___\n");
        break;

    case 6:
        printf(" ______\n |    |\n |    O\n |   /|\\\\\n_|___\n");
        break;

    case 7:
        printf(" ______\n |    |\n |    X\n |   /|\\\\\n_|___/ \\\\\n");
        break;
    }

    printf("\033[0m");
}

int alreadyGuessed(char letter)
{
    for (int i = 0; i < guessedCount; i++)
    {
        if (guessedLetters[i] == letter)
            return 1;
    }

    return 0;
}

void showGuessedLetters()
{
    printf("\n\033[1;33mUsed Letters: \033[0m");

    for (int i = 0; i < guessedCount; i++)
    {
        printf("%c ", guessedLetters[i]);
    }

    printf("\n");
}

void displayWord(const char *hidden)
{
    for (int i = 0; i < strlen(hidden); i++)
    {
        printf("%c ", hidden[i]);
    }

    printf("\n");
}

void giveHint(const char *word, char *hidden)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (hidden[i] == '_')
        {
            hidden[i] = word[i];

            printf("\n\033[1;36m");
            printf("[AI HINT] Revealed Letter: %c\n", word[i]);
            printf("\033[0m");

            return;
        }
    }
}

const char *getRandomWord(int difficulty)
{
    if (difficulty == 1)
        return easyWords[rand() % 10];
    else if (difficulty == 2)
        return mediumWords[rand() % 10];
    else
        return hardWords[rand() % 10];
}

int calculateScore(int attemptsLeft, int hintsUsed)
{
    int score = (attemptsLeft * 100) - (hintsUsed * 50);

    if (score < 0)
        score = 0;

    return score;
}

void gameLoop()
{
    int difficulty;
    int attempts = 0;
    int hintsUsed = 0;
    int won = 0;

    guessedCount = 0;

    system(CLEAR);

    banner();

    printf("\nChoose Difficulty:\n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    printf("\nSelect: ");
    scanf("%d", &difficulty);

    const char *word = getRandomWord(difficulty);

    char hidden[MAX_LENGTH];

    for (int i = 0; i < strlen(word); i++)
    {
        hidden[i] = '_';
    }

    hidden[strlen(word)] = '\0';

    while (attempts < MAX_ATTEMPTS)
    {
        system(CLEAR);

        banner();
        cyberEffects();

        printf("\nAttempts Left: %d\n", MAX_ATTEMPTS - attempts);

        drawHangman(attempts);

        printf("\nWord: ");
        displayWord(hidden);

        showGuessedLetters();

        printf("\nOptions:\n");
        printf("1. Guess Letter\n");
        printf("2. Use AI Hint\n");
        printf("3. Exit Game\n");

        int choice;

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        if (choice == 3)
        {
            printSlow("\nExiting Game...\n");
            return;
        }

        if (choice == 2)
        {
            hintsUsed++;

            giveHint(word, hidden);

            SLEEP(1000);

            if (strcmp(word, hidden) == 0)
            {
                won = 1;
                break;
            }

            continue;
        }

        char guess;

        printf("\nEnter Letter: ");
        scanf(" %c", &guess);

        guess = tolower(guess);

        if (alreadyGuessed(guess))
        {
            printf("\nAlready Used!\n");
            SLEEP(1000);
            continue;
        }

        guessedLetters[guessedCount++] = guess;

        int found = 0;

        for (int i = 0; i < strlen(word); i++)
        {
            if (word[i] == guess)
            {
                hidden[i] = guess;
                found = 1;
            }
        }

        if (!found)
        {
            attempts++;

            printf("\n\033[1;31mWrong Guess!\033[0m\n");
        }
        else
        {
            printf("\n\033[1;32mCorrect Guess!\033[0m\n");
        }

        SLEEP(1000);

        if (strcmp(word, hidden) == 0)
        {
            won = 1;
            break;
        }
    }

    system(CLEAR);

    banner();

    if (won)
    {
        printf("\n\033[1;32m");
        printSlow("YOU WON THE GAME!\n");
        printf("\033[0m");

        int score = calculateScore(MAX_ATTEMPTS - attempts, hintsUsed);

        printf("\nFinal Score: %d\n", score);

        printf("\n\033[1;36mCyber Intelligence Level Increased!\033[0m\n");
    }
    else
    {
        drawHangman(7);

        printf("\n\033[1;31mGAME OVER\033[0m\n");
        printf("\nCorrect Word Was: %s\n", word);
    }

    cyberEffects();

    printf("\nDeveloper: CYBERBADFIT\n");
}

int main()
{
    srand(time(NULL));

    loadingAnimation();

    while (1)
    {
        gameLoop();

        char again;

        printf("\nPlay Again? (y/n): ");
        scanf(" %c", &again);

        if (tolower(again) != 'y')
        {
            printSlow("\nShutting Down CYBERBADFIT Hangman Engine...\n");

            SLEEP(1000);

            break;
        }
    }

    return 0;
}