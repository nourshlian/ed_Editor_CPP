#pragma once

#include<vector>
#include<string>

using namespace std;

class Document{

    private: 

        vector<string> doc;
        int currentLine;
        
    public:

        Document();
        ~Document();

        void append(string); // a | i
        void print(); // %p
        void printLine(int); // n
        void changeLine(); // c
        void deleteLine(int); // d
        void forwardSearch(string); // /text
        void backwardSearch(string); // ?text
        void replaceText(string, string); // s/old/new
        void combine(int, int); // x,yj

        int getcurrentLine();

};