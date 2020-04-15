#include"Editor.h"
#include<iostream>
#include<string>

using namespace std;

void Editor::loop(){

    string input="";

    while(getline(cin,input)){

        if(!input.compare("Q"))
            return;

        if(!input.compare("a") || !input.compare("i"))
            this->ed.append(input);

        else if(!input.compare("c"))
            this->ed.changeLine();
        
        else if(!input.compare("%p"))
            this->ed.print();
        
        else if(input.at(input.size()-1) == 'n')
            this->ed.printLine(stoi(input.substr(0,input.size()-1)));
        
        else if(input.at(input.size()-1) == 'd')
            this->ed.deleteLine(stoi(input.substr(0,input.size()-1)));
        
        else if(input.at(0) == '/')
            this->ed.forwardSearch(input.substr(1,input.size()-1));
          
        else if(input.at(0) == '?')
            this->ed.backwardSearch(input.substr(1,input.size()-1));
        
        else if(input.at(0) == 's'){
            string helper = input.substr(2);
            string olds = helper.substr(0,helper.find("/"));
            string news = helper.substr(helper.find("/")+1, helper.size() - olds.size() -2);
            this->ed.replaceText(olds, news);

        }

        else if(input.at(input.size()-1) == 'j'){
            this->ed.combine(stoi(input.substr(0,input.find(","))), stoi(input.substr(input.find(",")+1, input.size()-1)));

        }





    }

}
// int main() { 
//         Editor editor; 
//         editor.loop(); 
//         return 0; 
// }


