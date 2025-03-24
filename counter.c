#include <stdio.h>
#include <windows.h>

#define BLACK 0
#define BLUE 3
#define GREEN 2
#define white 1
void setColorText(int colorText, int colorBackground)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorText + (colorBackground * 16));
}

void menu();
void counter();
void timer();
void exiting_program();
int main()
{
    menu();
    return 0;
}

void menu()
{

    int response;
    printf("\033[2J\033[H");
    setColorText(BLUE, BLACK);
    printf("   ╔════════════════════════════════╗\n");
    printf("   ║      ⌚ COUNTER & TIMER ⌚     ║\n");
    printf("   ╠════════════════════════════════╣\n");
    printf("   ║  [𝟭]▫️ \033[0m START COUNTER \033[36m          ║\n");
    printf("   ║  [𝟮]▫️ \033[0m START TIMER   \033[36m          ║\n");
    printf("   ║  [𝟯]▫️ \033[0m EXIT          \033[36m          ║\n");
    printf("   ╚════════════════════════════════╝\n");
    if (scanf(" %d", &response) != 1 || response < 1 || response > 3)
    {
        printf("Enter Invalid");
        getchar();
        Sleep(2000);
        menu();
    }

    switch (response)
    {
    case 1:
        counter();
        break;
    case 2:
        timer();
        break;
    case 3:
        exiting_program();
        break;
    default:
        printf("Enter Invalid \n");
        break;
    }
}
void counter()
{
    int hours, minutes, seconds;
    printf("\033[2J\033[H");
    printf("   ╔════════════════════════════════╗\n");
    printf("   ║    \033[0m ENTER TIME (HH:MM:SS) \033[36m     ║\n");
    printf("   ╠════════════════════════════════╣\n");
    printf("   ║ \033[0m Hours: \033[36m  ");
    scanf("%d", &hours);
    printf("                                    ║\n");
    printf("   ║ \033[0m Minutes: \033[36m  ");
    scanf("%d", &minutes);
    printf("                                    ║\n");
    printf("   ║ \033[0m Seconds: \033[36m  ");
    scanf("%d", &seconds);
    printf("                                    ║\n");
    printf("   ╚════════════════════════════════╝\n");

    int allSeconds = hours * 3600 + minutes * 60 + seconds;

    for (int i = 0; i <= allSeconds; i++)
    {
        int hoursDisplay = i / 3600;
        int minuteDisplay = (i % 3600) / 60;
        int secondsDisplay = i % 60;

        printf("\033[2J\033[H");
        printf("   ╔════════════════════════════════╗\n");
        printf("   ║         \033[0m TIME: HH:MM:SS\033[36m        ║\n");
        printf("   ╠════════════════════════════════╣\n");
        printf("   ║         \033[0m  [%02d:%02d:%02d]  \033[36m         ║\n", hoursDisplay, minuteDisplay, secondsDisplay);
        printf("   ╚════════════════════════════════╝\n");
        Sleep(1000);
    }
}

void timer()
{
    int hours, minutes, seconds;
    printf("\033[2J\033[H");
    printf("   ╔════════════════════════════════╗\n");
    printf("   ║    \033[0m ENTER TIME (HH:MM:SS) \033[36m     ║\n");
    printf("   ╠════════════════════════════════╣\n");
    printf("   ║ \033[0m Hours: \033[36m  ");
    scanf("%d", &hours);
    printf("                                    ║\n");
    printf("   ║ \033[0m Minutes: \033[36m  ");
    scanf("%d", &minutes);
    printf("                                    ║\n");
    printf("   ║ \033[0m Seconds: \033[36m  ");
    scanf("%d", &seconds);
    printf("                                    ║\n");
    printf("   ╚════════════════════════════════╝\n");
    int allSeconds = hours * 3600 + minutes * 60 + seconds;

    for (int i = allSeconds; i >= 0; i--)
    {
        int hoursDisplay = i / 3600;
        int minuteDisplay = (i % 3600) / 60;
        int secondsDisplay = i % 60;

        printf("\033[2J\033[H");
        printf("   ╔════════════════════════════════╗\n");
        printf("   ║         \033[0m TIME: HH:MM:SS\033[36m        ║\n");
        printf("   ╠════════════════════════════════╣\n");
        printf("   ║         \033[0m  [%02d:%02d:%02d]  \033[36m         ║\n", hoursDisplay, minuteDisplay, secondsDisplay);
        printf("   ╚════════════════════════════════╝\n");
        Sleep(1000);
    }
}

void exiting_program()
{
    char text[50] = "                    CLOSING PROGRAM...  ";
    printf("\033[2J\033[H");
    printf("\033[33m");

    for (int j = 0; j < 2; j++)
    {

        for (int i = 0; i < 49; i++)
        {
            printf("\r%s", text); // \r retorna ao início da linha
            Sleep(100);

            char temp = text[0];
            for (int j = 0; j < 48; j++)
            {
                text[j] = text[j + 1];
            }
            text[48] = temp;
        }
    }

    printf("\n\033[0m");
    exit(0);
}