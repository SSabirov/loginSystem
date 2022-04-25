// passwordAuth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include <string>



/***********************Function Definitions**********/
bool isValid(std::string username, std::string password);
void signUp(std::string username,std::string password);

int main()
{   
    signUp("said", "said123");
    
    std::cout<< isValid("said", "said123");


}


/******************Funtions****************/


//function to input new credentials and create txt file 
void signUp(std::string username, std::string password)
{

    std::ofstream file;

    file.open(username + ".txt");   //directory will appear inside vs project 
    file << username << std::endl << password;
    file.close();
}

//function to test the validity of exisiting credentials
bool isValid(std::string username, std::string password)
{
    std::string un,pw;

    std::ifstream read(username + ".txt");   
    std::getline(read, un);
    std::getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
