//Name: Muhammad Omer Khan    ID: 23I-0650    Assignment # 3 
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
 
    //global array initialization, chose to go with 100 animals
    string animalwordlist[99] = {"zebra", "cheetah", "kangaroo", "koala", "panda",
    "hippo", "rhino", "monkey", "squirrel", "rabbit",
    "deer", "fox", "wolf", "coyote", "lynx",
    "panther", "jaguar", "leopard", "bobcat", "ocelot",
    "parrot", "penguin", "owl", "eagle", "hawk",
    "dolphin", "whale", "shark", "seal", "otter",
    "snake", "lizard", "turtle", "frog", "toad",
    "gazelle", "antelope", "buffalo", "camel", "llama",
    "armadillo", "hedgehog", "platypus", "possum", "koala",
    "mongoose", "lemur", "meerkat", "gorilla", "chimpanzee",
    "cheetah", "puma", "lynx", "honeybadger", "bobcat",
    "hyena", "jackal", "mongoose", "otter", "raccoon",
    "squirrel", "hedgehog", "bat", "koala", "opossum",
    "lemur", "chameleon", "pangolin", "echidna", "quokka",
    "numbat", "okapi", "fennecfox", "kiwi", "axolotl",
    "narwhal", "sloth", "anteater", "armadillo", "chinchilla",
    "platypus", "tapir", "binturong", "quokka", "jaguarundi",
    "jerboa", "vole", "lemming", "fossa", "caracal",
    "bongo", "markhor", "ibex", "gazelle", "springbok",
    "alpaca", "bat", "beetle", "capybara"};
 

//function to randomize and return word from global array
string rand_word()
{
    string randword;
    int randindex = 0;
    srand(time(0));
    
    //obtaining a random index value b/w 0 and 100 to use to obtain string
    randindex = rand()%101;
    randword = animalwordlist[randindex];
    return randword;
}


//function that displays hangman after each guess
void displayhangman(int lives)
{
    switch (lives)
    {
        //displays an unhung hangman in the case none of the six lives are lost
        case 6: 
        cout<<"  +---+\n  |   |\n      |\n      |\n      |\n========"<<endl; 
        break;

        case 5:
        cout<<"  +---+\n  |   |\n  0   |\n      |\n      |\n========"<<endl; 
        break;

        case 4:
        cout<<"  +---+\n  |   |\n  0   |\n  |   |\n      |\n========"<<endl;
        break;
        
        case 3:
        cout<<"  +---+\n  |   |\n  0   |\n /|   |\n      |\n========"<<endl; 
        break;
        
        case 2:
        cout<<"  +---+\n  |   |\n  0   |\n /|\\  |\n      |\n========"<<endl; 
        break;
        
        case 1:
        cout<<"  +---+\n  |   |\n  0   |\n /|\\  |\n /    |\n========"<<endl; 
        break;
        
        case 0:
        cout<<"  +---+\n  |   |\n  0   |\n /|\\  |\n / \\  |\n========"<<endl; 
        break;                
    }
}

 
int main()
{
    string playername;
    string returnedrandword;
    cout<<"Welcome to Hangman!"<<endl;
    cout<<"Enter your name: ";
    getline(cin, playername);
 
    //array to store players name, to use for question condition
    const int pnamesize = playername.size();
    char pname[pnamesize];
    
    for(int i=0; i<pnamesize; i++)
    {
        pname[i] = playername[i];
    }



    returnedrandword = rand_word();

    //obtaining size of returned random word as a constant integer variable and declaring an array of the same size 
    const int arrayelements = returnedrandword.size();
    char wordcharacterarray[arrayelements]; 
    

    //copying string random word into a character array
    for (int i = 0; i <arrayelements; ++i) 
    {
    wordcharacterarray[i] = returnedrandword[i];
    }
    
    cout<<returnedrandword<<endl; //Used to test program
    int lives = 6; 
    char playerguess;
    
    //initializing a second array to be empty
    char wordchararray2[arrayelements] = {}; 
    

    //main outer loop
    for (int i=0; i<arrayelements; i++)
    {
        //flag to use when determining whether player guess was correct or not
        bool checkflag = false;

        cout<<"Enter your guess: ";
        cin>>playerguess;
        
        //comparing player guess input with stored random word values
        for (int i=0; i<(arrayelements); i++)
        {
        if (wordcharacterarray[i]==playerguess)
        {
            wordchararray2[i] = wordcharacterarray[i];
            cout<<"Correct guess!"<<endl;
            
            //implementing the second condition of the question
            for (int i=0; i<pnamesize; i++)
            {
                if ((playername[i]==playerguess)&&(lives<6))
                {
                    cout<<"You gained an extra life!"<<endl;
                    lives++;
                    cout<<"You now have "<<lives<<" lives"<<endl;
                }
            }
            

            displayhangman(lives);
            checkflag = true;
            break;
        }
        }

        if (checkflag == false)
        {
            cout<<"Wrong guess!"<<endl;
            lives-=1;
            displayhangman(lives);
            checkflag = true;
        }

        //if structure that breaks from loop in case lives drop to 0
        if (lives == 0)
        {
            break;
        }

        }

        //comparison to check whether both arrays hold the same word    
        bool flagcheck = false;
        for (int i=0; i<arrayelements; i++) 
        {
        if (wordcharacterarray[i] == wordchararray2[i]) 
        {
        flagcheck = true;
        }
        }
    
        if (flagcheck == true)
        {
        cout<<"You guessed the word!"<<endl;
        }


    if (lives == 0)
    {
        cout<<"You ran out of lives!\nThe word was: "<<returnedrandword<<endl;
    }
 
  
return 0;
}