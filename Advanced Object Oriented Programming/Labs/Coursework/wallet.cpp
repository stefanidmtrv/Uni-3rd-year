// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------

#include "wallet.h"
#include <stdexcept>
#include <fstream>

#include "lib_json.hpp"

using json = nlohmann::json;

Wallet::Wallet() {}
Wallet::~Wallet() {}

unsigned int Wallet::size() const
{

    return this->categories.size();
}

bool Wallet::empty() const
{
    return Wallet::size() == 0;
}

Category &Wallet::newCategory(const std::string &catIdent)
{
    try
    {
        for (auto it = categories.begin(); it != categories.end(); it++)
        {

            if (it->second.getIdent() == catIdent)
            {
                return it->second;
            }
        }

        Category newCat{catIdent};
        categories.insert({catIdent, newCat});
        return categories.find(catIdent)->second;
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error");
    }
}

bool Wallet::addCategory(const Category &category)
{
    try
    {
        for (auto it = categories.begin(); it != categories.end(); it++)
        {

            if (it->second.getIdent() == category.getIdent())
            {
                for (auto entry : category.getCategories())
                {
                    it->second.addItem(entry.second);
                }
                return false;
            }
        }
        categories.insert({category.getIdent(), category});
        return true;
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error");
    }
}

const Category &Wallet::getCategory(const std::string &catIdent) const
{

    auto it = categories.begin();
    while (it != categories.end())
    {
        if (it->second.getIdent() == catIdent)
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

bool Wallet::deleteCategory(const std::string &catIdent)
{
    if (this->categories.count(catIdent) != 0)
    {
        this->categories.erase(catIdent);
        return true;
    }
    else
    {
        throw std::out_of_range("Key doesn't exist");
    }
}

void Wallet::load(const std::string &filename)
{

    try
    {
        std::ifstream inputFile(filename);
        json dbJson = dbJson.parse(inputFile);
        // looping through the json and populating the container with the
        // category, items and entries
        for (json::iterator it = dbJson.begin(); it != dbJson.end(); ++it)
        {
            Category category{it.key()};
            json items = it.value();
            for (json::iterator it2 = items.begin(); it2 != items.end(); ++it2)
            {
                Item item{it2.key()};
                json entries = it2.value();
                for (json::iterator it3 = entries.begin(); it3 != entries.end(); ++it3)
                {
                    item.addEntry(it3.key(), it3.value());
                }
                category.addItem(item);
            }
            this->addCategory(category);
        }
    }
    catch (...)
    {
        throw std::runtime_error("Runtime error");
    }
}

void Wallet::save(const std::string &path)
{

    std::ofstream outputFile(path);

    if (!outputFile.is_open())
    {
        throw std::runtime_error("Runtime error");
    }
    else
    {
        outputFile << this->str();
    }
}

std::string Wallet::str() const
{
    json j;
    for (auto it = this->categories.begin(); it != this->categories.end(); it++)
    {
        j[it->first] = json::parse(it->second.str());
    }
    return j.dump();
}
