// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------

#include "item.h"

#include <stdexcept>
#include "lib_json.hpp"

using json = nlohmann::json;

Item::Item(const std::string &ident) : name(ident) {}
Item::~Item() {}

unsigned int Item::size() const
{

    return this->entries.size();
}

bool Item::empty() const
{
    return Item::size() == 0;
}

void Item::setIdent(std::string &ident)
{
    this->name = ident;
}

std::string Item::getIdent() const
{
    return this->name;
}

bool Item::addEntry(const std::string &key, const std::string &value)
{
    if (this->entries.count(key) != 0)
    {
        this->entries.erase(key);
        this->entries.insert({key, value});
        return false;
    }
    else
    {
        this->entries.insert({key, value});
        return true;
    }
}

std::string Item::getEntry(const std::string &key) const
{
    return (this->entries.at(key));
}

bool Item::deleteEntry(const std::string &key)
{
    if (this->entries.count(key) != 0)
    {
        this->entries.erase(key);
        return true;
    }
    else
    {
        throw std::out_of_range("Key doesn't exist");
    }
}

std::map<std::string, std::string> Item::getEntries() const
{
    return this->entries;
}

bool operator==(const Item &item1, const Item &item2)
{
    return item1.name == item2.name && item1.entries == item2.entries;
}

std::string Item::str() const
{
    json j;
    for (auto it = this->entries.begin(); it != this->entries.end(); it++)
    {
        j[it->first] = it->second;
    }
    return j.dump();
}
