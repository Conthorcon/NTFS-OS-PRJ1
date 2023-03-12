#include "NTFS.h"
#include "Byte.h"
#include <windows.h>

void inputDriver(wchar_t driver[])
{
    printf("================== PLEASE ENTER YOUR VOLUMN ==================\n");
    printf("Enter one CAPITAL LETTER. Example: C, D, E, ...\n\n");
    printf(">> Enter your drive path: ");
    
    wcin >> driver;
    wcscat(driver,L":");

    wcout  << driver << endl;
}
int main(int argc, char **argv)
{
    system("cls");
    SetConsoleOutputCP(65001);

    BYTE sector[1024];
    
    wchar_t driver[3];
    wchar_t path[10] = L"\\\\.\\";
    inputDriver(driver);
    wcscat(path,driver);

    ReadSector(path,0, sector);

    if(strcmp(byte2PChar(sector + 3,4),"NTFS") == 0)
    {
        NTFS(sector,driver);
    }
    else
    {
        //FAT32
    }
}