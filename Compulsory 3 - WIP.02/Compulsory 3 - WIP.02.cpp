#include <iostream>
#include "file.h"
#include "folder.h"
using namespace std;

int main(){

    int selectedMenu = 0;
    string newFileName;
    string newFolderName;
    string fileName;
    string folderName; //for calling folders with user input for method getFolder()

    Folder mainFolder("Main Folder", 12);

    mainFolder.addFolder("Documents", 31);
    mainFolder.addFolder("Pictures", 30);
    mainFolder.addFolder("Downloads", 29);
    mainFolder.addFolder("Videos", 28);

    mainFolder.getFolder("Documents")->addFile("CV.docx", 27); //fetches the folder "Documents" so we can use the method "addFile" using pointers to add a new file within the folder
    mainFolder.getFolder("Documents")->addFile("Carbonara_Recipie.docx", 26);
    mainFolder.getFolder("Documents")->addFile("Budget.excl", 25);
    mainFolder.getFolder("Documents")->addFile("glarpy.excl", 25);
    mainFolder.getFolder("Documents")->addFile("whoops.excl", 25);
    mainFolder.getFolder("Documents")->addFile("fill.excl", 25);
    mainFolder.getFolder("Documents")->addFile("incomeTax.excl", 25);
    mainFolder.getFolder("Documents")->addFile("paxcal.excl", 25);
    mainFolder.getFolder("Documents")->addFile("INtexpo.excl", 25);
    mainFolder.getFolder("Documents")->addFile("integerList.excl", 25);
    mainFolder.getFolder("Documents")->addFolder("Schoolwork", 24);
    mainFolder.getFolder("Documents")->addFolder("Programming", 23);
    mainFolder.getFolder("Documents")->addFolder("Speeches", 22);

    mainFolder.getFolder("Pictures")->addFile("Markiplier(Ft.Jerma).jpg", 71123);
    mainFolder.getFolder("Pictures")->addFile("jerma_01.WEBP", 81123);
    mainFolder.getFolder("Pictures")->addFile("Jerma.png", 81123);
    mainFolder.getFolder("Pictures")->addFolder("Memories_2007", 110307);
    mainFolder.getFolder("Pictures")->addFolder("Birthdays", 61123);

    mainFolder.getFolder("Downloads")->addFile("Def_not_a_virus.exe", 81222);
    mainFolder.getFolder("Downloads")->addFile("Pirated_Music.mp3", 130520);
    mainFolder.getFolder("Downloads")->addFile("newGame_Installer.exe", 61123);

    mainFolder.getFolder("Videos")->addFolder("Memories_2013", 20114);
    mainFolder.getFolder("Videos")->addFolder("Speeches", 200422);

    //mainFolder.getFolder("Documents")->getFolder("Schoolwork")->addFile("I_havent_done_shit.txt", 21);

    mainFolder.printInfo();
    cout << endl;
    mainFolder.printFolders();

    while (selectedMenu == 0) {
        cout << "\n1. view main folder. \n";
        cout << "2. view contents of folder \n";
        cout << "3. add new file to folder. \n";
        cout << "4. add new folder to folder. \n";
        cout << "5. change name of file. \n";
        cout << "6. change name of folder. \n";
        cout << "7. view largest file in folder. \n";
        cout << "8. Exit.\n";

        cin >> selectedMenu; cout << endl;

        switch (selectedMenu) 
        {
        case 1:
            mainFolder.printInfo();
            cout << endl;
            mainFolder.printFolders();

            cout << "\n";
            selectedMenu = 0; //reset back to main menu
            break;

        case 2:
            cout << "choose folder: ";
            cin >> folderName; cout << endl;

            mainFolder.getFolder(folderName)->printInfo(); //prints info of folder inputted by the user
            mainFolder.getFolder(folderName)->printContent(); //prints content of folder inputted by the user

            folderName = ""; //reset variable used to avoid complication in code
            selectedMenu = 0; 
            break;

        case 3:
            cout << "which folder do you want to add to?: ";
            cin >> folderName;
            cout << "choose name of new file: ";
            cin >> newFileName;
            mainFolder.getFolder(folderName)->addFile(newFileName, 61123); //adds a file into the folder inputted by the user

            folderName = "";
            newFileName = "";
            selectedMenu = 0;
            break;

        case 4:
            cout << "which folder do you want to add to?: ";
            cin >> folderName;
            cout << "choose name of new folder: ";
            cin >> newFolderName;
            mainFolder.getFolder(folderName)->addFolder(newFolderName, 61123); //adds a folder into the folder inputted by the user

            folderName = "";
            newFolderName = "";
            selectedMenu = 0;
            break;

        case 5:
            cout << "choose location of file: ";
            cin >> folderName;
            cout << "which file would you like to change name of?: ";
            mainFolder.getFolder(folderName)->changeFileName(); //changes name of the file chosen by the user within the given folder

            folderName = "";
            selectedMenu = 0;
            break;

        case 6:
            cout << "choose location of folder: ";
            cin >> folderName;
            mainFolder.getFolder(folderName)->changeFolderName(); //changes name of the folder chosen by the user within the given folder

            folderName = "";
            selectedMenu = 0;
            break;

        case 7:
            cout << "choose folder: ";
            cin >> folderName;

            cout << endl << "Largest file in " << folderName << " is: \n";
            mainFolder.getFolder(folderName)->findLargest(); //outputs the information of the largest file within the folder inputted by the user

            folderName = "";
            selectedMenu = 0;
            break;

        case 8:
            return 0;
            break;

        default:
            cout << "how.\n"; //just having a default case in case something goes wrong
            return 0;
        }

    }

    return 0;
}
