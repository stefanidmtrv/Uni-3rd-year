// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------

#include "category.h"
#include <stdexcept>

#include "lib_json.hpp"

using json = nlohmann::json;

Category::Category(const std::string &ident) : name(ident) {}
Category::~Category() {}

unsigned int Category::size() const
{
    return this->items.size();
}



bool Category::empty() const
{
    return Category::size() == 0;
}


std::string Category::getIdent() const
{
    return this->name;
}


void Category::setIdent(std::string &ident)
{
    this->name = ident;
}

Item &Category::newItem(const std::string &ident)
{
    try
    {
        for (auto it = items.begin(); it != items.end(); it++)
        {

            if (it->second.getIdent() == ident)
            {
                return it->second;
            }
        }

        Item newItem{ident};
        items.insert({getIdent(), newItem});
        return items.find(getIdent())->second;
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error");
    }
}

bool Category::addItem(const Item &item)
{

    for (auto it = items.begin(); it != items.end(); it++)
    {

        if (it->second.getIdent() == item.getIdent())
        {
            for (auto entry : item.getEntries())
            {
                it->second.addEntry(entry.first, entry.second);
            }
            return false;
        }
    }
    items.insert({item.getIdent(), item});
    return true;
}

const Item &Category::getItem(const std::string &itemIdent) const
{

    auto it = items.begin();
    while (it != items.end())
    {
        if (it->second.getIdent() == itemIdent)
        {
            return it->second;
        }
        else
        {
            it++;
        }
    }
    throw std::out_of_range("Key doesn't exist");
}

bool Category::deleteItem(const std::string &itemIdent)
{
    if (this->items.count(itemIdent) != 0)
    {
        this->items.erase(itemIdent);
        return true;
    }
    else
    {
        throw std::out_of_range("Key doesn't exist");
    }
}

std::map<std::string, Item> Category::getCategories() const
{
    return this->items;
}

bool operator==(const Category &cat1, const Category &cat2)
{
    if ((cat1.name != cat2.name) || (cat1.items.size() != cat2.items.size()))
    {
        return false;
    }

    for (auto cat1Item : cat1.items)
    {
        auto cat2Item = cat2.items.at(cat1Item.first);

        if (!(cat1Item.second == cat2Item))
        {
            return false;
        }
    }

    return true;
}

std::string Category::str() const
{
    json j;
    for (auto it = this->items.begin(); it != this->items.end(); it++)
    {
        j[it->first] = json::parse(it->second.str());
    }
    return j.dump();
}
