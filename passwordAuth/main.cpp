// passwordAuth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>



/***********************Function Definitions**********/
bool isValid(std::string username, std::string password);//function to test the validity of exisiting credentials
bool isLegalPassword(std::string password);//funtion to test if password contains at least 1 uppercase,number and character 
void signUp(std::string username,std::string password);//function to input new credentials and create txt file 


int main()
{   
    int choice;
    std::string username, password;

    do
    {
        std::cout << "1: To sign up :\t2: To Login\t 3: To exit\nYour choice:\t";
        std::cin >> choice;
        switch (choice)
        {
        case 1:std::cout << "Enter new username:\t";
            std::cin >> username;
            std::cout << "Enter new password:\t";
            std::cin >> password;
            signUp(username, password);

        case 2:std::cout << "Enter your username:\t";
            std::cin >> username;
            std::cout << "Enter your password:\t";
            std::cin >> password;
            isValid(username, password);

        default:
            break;
        }
    } while (choice!=3);
    
   
    

    
}


/******************Funtions****************/



void signUp(std::string username, std::string password)
{
    bool passwordStatus= isLegalPassword(password);

    if (passwordStatus == 1)
    {
        std::cout << " The password is legal\n";
        std::ofstream file;

        file.open(username + ".txt");   //directory will appear inside vs project 
        file << username << std::endl << password;
        file.close();
    }
    else
    {
        std::cout << "Password should contain at least 1 uppercase , numnber and 1 character\n";
    }
    
}


bool isValid(std::string username, std::string password)
{
    std::string un,pw;

    std::ifstream read(username + ".txt");   
    std::getline(read, un);
    std::getline(read, pw);

    if (un == username && pw == password)
    {
        std::cout << "Credentials are valid\n";
        return true;
    }
    else
    {
        std::cout << "Invalid username or password\n";
        return false;
    }
}
 

bool isLegalPassword(std::string password)
{
   
    int upperCase = 0, lowerCase = 0, chars = 0,numbers=0;
   
    for (int i = 0; i < password.length(); i++)
    {

        if ((int)password[i] > 64 && (int)password[i] < 91)
        {
           
            upperCase++;
        }
        else if ((int)password[i] > 96 && (int)password[i] < 123)
        {
            
            lowerCase++;
        }
        else if ((int)password[i] > 32 && (int)password[i] < 48)
        {
            chars++;
        }
        else if ((int)password[i] > 47 && (int)password[i] < 58)
        {
            numbers++;
        }
    }
    if (upperCase>0 && lowerCase>0 && chars >0 && numbers>0)
    {
        
        return 1;
    }
    else
    {
        
        return 0;
    }
}
