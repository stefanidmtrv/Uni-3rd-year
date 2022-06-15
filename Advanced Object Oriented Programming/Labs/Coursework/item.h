// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// An Item class contains multiple 'entries' as
// key/value pairs (e.g., a key might be 'username'
// and a value would be the username, another might be
// 'url' and the value is the website address the
// username is for.
// -----------------------------------------------------

#ifndef ITEM_H
#define ITEM_H
#include <map>
#include <iostream>
#include "lib_json.hpp"

class Item {
    private:
    std::string name;
    std::map<std::string, std::string> entries;

    public:
    Item(const std::string &ident);
    ~Item();
    unsigned int size() const;
    bool empty() const;
    void setIdent( std::string &ident);
    std::string getIdent() const;
    bool addEntry(const std::string &key, const std::string &value);
    std::string getEntry(const std::string &key) const;
    bool deleteEntry(const std::string &key);
    std::map<std::string, std::string>getEntries() const;
    std::string str() const ;
    friend bool operator==(const Item& item1, const Item& item2);
   

};

#endif // ITEM_H
