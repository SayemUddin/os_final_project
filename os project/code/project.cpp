#include <stdio.h>  /* defines FILENAME_MAX */
// #define WINDOWS  /* uncomment this line to use it for windows.*/
#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif
#include<iostream>
//Used for handling directory files
#include <dirent.h>
//For EXIT codes and error handling
#include <errno.h>
#include <stdlib.h>

#include<bits/stdc++.h>
using namespace std;


void cat();
void touch();
void apnd();
void clear();
void help();
void dt();
void exits();
void startscreen();
void rmv();
void renames();
void edit();
void cdir();
void copy();
void cknow();
void lknow();
void ccount();
void usr();

//pwd command
std::string GetCurrentWorkingDir( void ) {
  char buff[FILENAME_MAX];
  GetCurrentDir( buff, FILENAME_MAX );
  std::string current_working_dir(buff);
  return current_working_dir;
}


int main(){

    char a[100];
    cout<<"                                                 ---------------------"<<endl;
    printf("                                                |  GROUP-I Terminal   |\n");
    cout<<"                                                 ---------------------"<<endl<<endl;

    cout<<"                                                      Greetings!"<<endl;
    cout<<"                                             It's great to have you here!!!"<<endl<<endl;
    cout<<"Write basic commands of UBUNTU or type 'help' -"<<endl<<endl;

    while(1){

    printf(">>> ");
    fflush(stdin);
    scanf("%s", a);

    if(strcmp(a, "cat") == 0){

        cat();

    }else if(strcmp(a, "touch") == 0){

        touch();
    }else if(strcmp(a, "pwd") == 0){

        cout<<"The current working directory is :  "<<endl;
        std::cout << GetCurrentWorkingDir() << std::endl;

    }else if(strcmp(a, "ls") == 0){
        cout<<"The files and Directories of the System are:"<<endl;
        system("ls");
    }else if(strcmp(a, "uptime") == 0){
        cout<<"The current time, how long the system has been running, how many users are currently logged on, and the system load averages"<<endl;
        system("uptime");
    }else if(strcmp(a, "df") == 0){
        cout<<"System Disk Space:"<<endl;
        system("df");
    }else if(strcmp(a, "file") == 0){
        cout<<"Type of the file is:"<<endl;
        system("file");
    }else if(strcmp(a, "uname") == 0){
        cout<<"System Information:"<<endl;
        system("uname");
    }else if(strcmp(a, "top") == 0){
        system("top");
    }else if(strcmp(a, "ps") == 0){
        cout<<"Running processes:"<<endl;
        system("ps");
    }else if(strcmp(a, "dig") == 0){
        system("dig");
    }else if(strcmp(a, "shutdown") == 0){
        system("shutdown");
    }else if(strcmp(a, "apnd") == 0){

        apnd();

    }else if(strcmp(a, "clear") == 0){

        clear();

    }else if(strcmp(a, "help") == 0){

        help();

    }else if(strcmp(a, "dt") == 0){

        dt();

    }else if(strcmp(a, "stscr") == 0){

        startscreen();

    }else if(strcmp(a, "rmv") == 0){

        rmv();

    }else if(strcmp(a, "rm") == 0){

        renames();

    }else if(strcmp(a, "edit") == 0){

        edit();

    }else if(strcmp(a, "cdir") == 0){

        cdir();

    }else if(strcmp(a, "cp") == 0){

        copy();

    }else if(strcmp(a, "cknow") == 0){

        cknow();

    }else if(strcmp(a, "lknow") == 0){

        lknow();

    }else if(strcmp(a, "ccount") == 0){

        ccount();

    }else if(strcmp(a, "exit") == 0){

        exits();

    }
    else if(strcmp(a, "whoami") == 0){

        usr();

    }else{
        printf("Enter only stated things in help\n");
    }


    }

    return 0;

}

void cat(){

    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    char a[100];
    int f=0;

    FILE *p;

    printf("Enter File Name To Read: ");
    scanf("%s", a);

    for(int i=0;i<=sizeof(a);i++)
    {
        if(a[i]=='.')
            f=1;
    }
    if(f==0)
    {
        cout<<"Invalid File Name!!!"<<endl;
        cat();
    }

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    char c;

    p = fopen(a, "r");

    if(p == NULL){
        printf("\nError\n");
    }

    printf("\n");

    c = fgetc(p);

    while(c != EOF){
        printf("%c", c);
        c = fgetc(p);
    }

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");

    fclose(p);

    printf("\n\n Successfully Read\n\n\n");

}

void touch(){

    char a[100];
    int f=0;

   cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;

        FILE *p;

        printf("Enter File Name To Create an empty file: ");
        scanf("%s", a);

        for(int i=0;i<=sizeof(a);i++)
    {
        if(a[i]=='.')
            f=1;
    }
    if(f==0)
    {
        cout<<"Invalid File Name!!!"<<endl;
        touch();
    }
        p = fopen(a, "w");


        fflush(stdin);

        printf("Enter ~ to exit from writing\n");
        printf("Start writing: \n");

        int ch=NULL;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }

        fclose(p);
        printf("\n\nSuccessfully Written\n\n\n");
}

void apnd(){

    char a[100];
    int f=0;

    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;

        FILE *p;

        printf("Enter File Name To Append: ");
        scanf("%s", a);
          for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           apnd();
        }


        if(p == NULL){
        printf("Error");
        }

        p = fopen(a, "a");

        printf("Enter ~ to exit from writing\n");
        printf("Start writing: \n");

        int ch=NULL;

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){

            fputc(ch, p);

        }

    }


        fclose(p);

        printf("\nSuccessfully Appended\n\n");

}

void usr()
{
    cout<<"User of the Linux is:"<<endl;
    system("whoami");
}

void clear(){
    system("clear");
}

void dt(){
    cout<<"Todays Date and time - "<<endl;
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void startscreen(){
    system("cls");

    cout<<"                                                 ---------------------"<<endl;
    printf("                                                |  GROUP-I Terminal   |\n");
    cout<<"                                                 ---------------------"<<endl<<endl;

    cout<<"                                                      Greetings!"<<endl;
    cout<<"                                             It's great to have you here!!!"<<endl<<endl;
    cout<<"Write basic commands of UBUNTU or type 'help' -"<<endl<<endl;


}

void rmv(){
    char a[100];
    int f=0;
    int m;
    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    printf("Enter a file name to remove: ");
    scanf("%s", a);
    for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           rmv();
        }

    m = remove(a);

    if(m == 0){
        printf("Successfully removed a file\n\n\n");
    }else{
        printf("Error in removing please check if the file exists in directory\n");
    }

}

void renames(){

    char a[100], b[100];
    int m;
    int f=0;
    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    printf("Enter a file name to rename: ");
    scanf("%s", a);
    for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           renames();
        }
    printf("\nEnter new name: ");
    scanf("%s", b);

    m = rename(a, b);

    if(m == 0){
        printf("Successfully renamed a file\n");
    }else{
        printf("Error in removing please check if the file exists in directory\n");
    }

}

void edit(){
    char a[100];
    int f=0;
    printf("Warning: Close the editor to use GROUP-I Terminal\n");
    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    printf("Enter file name to edit: ");
    scanf("%s", a);
     for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           edit();
        }
    system(a);

    printf("Successfully opened editing software\n");
}

void cdir(){
    char a[100];

    printf("Your Directory:\n");
    system("dir");
}

void copy(){

    char a[100], b[100];
    int c,f=0;
    FILE *p, *q;
    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;

    printf("Enter existing file name: ");
    scanf("%s", a);
     for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           copy();
        }
    printf("\nEnter copy destination file name: ");
    scanf("%s", b);

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    p = fopen(a, "r");
    q = fopen(b, "a");

    c = fgetc(p);
    while(c != EOF){
        fputc(c, q);
        c = fgetc(p);
    }

    fclose(p);
    fclose(q);

    printf("\nSuccessfully copied\n\n");
    }

}

//character find
void cknow(){

    char a[100], cha;
    int c, count=0,f=0;
    FILE *p;

    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    printf("Enter existing file name: ");
    scanf("%s", a);

    for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           cknow();
        }

    fflush(stdin);
    printf("\nEnter the character to search: ");
    cin>>cha;

    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == cha){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of times %c repeated is = %d\n",  cha, count);
    }
}

//no of lines
void lknow(){

    char a[100], cha;
    int c, count=0,f=0;
    FILE *p;
    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;

    printf("Enter existing file name: ");
    scanf("%s", a);
    for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           lknow();
        }
    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c == '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of lines = %d\n", count);
    }

}

//count the characters
void ccount(){

    char a[100], cha;
    int c, count=0,f=0;
    FILE *p;

    cout<<"File name must contain .sh or any other extension. For example 'project.sh'"<<endl;
    printf("Enter existing file name: ");
    scanf("%s", a);
    for(int i=0;i<=sizeof(a);i++)
          {
             if(a[i]=='.')
                f=1;
          }
         if(f==0)
        {
           cout<<"Invalid File Name!!!"<<endl;
           ccount();
        }
    p = fopen(a, "r");

    if(p == NULL){
        printf("The file is not found\n");
    }else{

    c = fgetc(p);
    while(c != EOF){
        if(c != ' ' && c != '\n'){
            count++;
        }
        c = fgetc(p);
    }

    fclose(p);

    printf("No. of characters in file is = %d\n", count);
    }
}

//help user acknowledge
void help(){
    cout<<"\n\n";
    cout<<"Enter the following Ubuntu commands:\n\n";
    cout<<"whoami   >>> To find user name"<<endl;
    cout<<"pwd      >>> To find current working directory"<<endl;
    cout<<"touch    >>> To create an empty file and modify it\n";
    cout<<"cat      >>> To read from a file\n";
    cout<<"apnd     >>> To append a file\n";
    cout<<"rmv      >>> To remove a file\n";
    cout<<"ls       >>> To list files and directories within a system"<<endl;
    cout<<"df       >>> To report the system’s disk space usage"<<endl;
    cout<<"file     >>> To show the type of a file"<<endl;
    cout<<"ps       >>> To show List running of processes"<<endl;
    cout<<"uname    >>> To show system informatio"<<endl;
    cout<<"top      >>> To show top processes"<<endl;
    cout<<"shutdown >>> To shutdown your device"<<endl;
    cout<<"dig      >>> To gather the domain information"<<endl;
    cout<<"uptime   >>> To show current time, how long the system has been running, how"<<endl;
    cout<<"             many users are currently logged on, and the system load averages"<<endl;
    cout<<"rm       >>> To rename a file from a directory\n";
    cout<<"clear    >>> To clear the screen\n";
    cout<<"dt       >>> To show date and time\n";
    cout<<"stscr    >>> To show start screen\n";
    cout<<"edit     >>> To edit a file\n";
    cout<<"cdir     >>> To see the directory(location) and files\n";
    cout<<"cp       >>> To copy one file to new file or append to a existing file\n";
    cout<<"cknow    >>> To know how many time(s) a character repeated in file\n";
    cout<<"lknow    >>> To know how many line(s) are there in a file\n";
    cout<<"ccount   >>> To calculate the no. of characters\n";

    cout<<"exit     >>> To exit\n";
    cout<<"\n";
}

void exits(){
    exit(1);
}
