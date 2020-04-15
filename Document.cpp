#include<iostream>
#include"Document.h"

using namespace std;


Document::Document(){

    currentLine = 0;
}

Document::~Document(){}

int Document::getcurrentLine(){

    return this->currentLine;
}

void Document::print(){ // %p

    for(int i = 0; i < this->doc.size(); i++)
        cout << this->doc[i] << endl;
}

void Document::printLine(int index){ // n

    this->currentLine = index;
    cout << index << "\t" << this->doc[index-1] << endl;
}

void Document::deleteLine(int index){ // d

    this->currentLine = index;
    this->doc.erase(this->doc.begin()-1 + this->currentLine--);
}

void Document::append(string in_arg){
    string in = "";
    while (getline(cin, in)){
        
        if(in.compare(".") == 0)
            break;
        
        if(this->doc.size() == 0)
            this->doc.push_back(in);
        
        else if(!in_arg.compare("a")) // insert after
            this->doc.insert(this->doc.begin() + this->currentLine, in);

        else // insert before
            this->doc.insert(this->doc.begin() + this->currentLine -1, in);
        this->currentLine++;
    }
}

void Document::changeLine(){

    this->doc.erase(this->doc.begin() + this->currentLine-1);
    this->currentLine--;
    append("a");

}

void Document::forwardSearch(string input){

    for(auto it = this->doc.begin() + this->currentLine -1; it != this->doc.end(); ++it){
        
        string line = *it;
        auto find = line.find(input);

         if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) +1;
            return;
        }
    }
    this->currentLine = this->doc.size();
}

void Document::backwardSearch(string text){

    for(auto it = this->doc.begin() + this->currentLine -1; it != this->doc.begin(); --it){
        string word = *it;
        auto find = word.find(text);
        if(find != string::npos){
            cout << *it << endl;
            this->currentLine = distance(this->doc.begin(), it) +1;
            return;
        }
    }
    this->currentLine = 1;
}

void Document::replaceText(string olds, string news){

    this->doc.at(currentLine -1).replace(this->doc.at(currentLine -1).find(olds), olds.size(), news);
}

void Document::combine(int index_1, int index_2){

    string help = "";
    help.append(this->doc[index_1 -1]);
    help.append(this->doc[index_2 -1]);
    this->deleteLine(index_2 -1);
    this->currentLine = index_1;
    this->doc[currentLine -1].replace(0,this->doc[currentLine -1].size(),help);

}


