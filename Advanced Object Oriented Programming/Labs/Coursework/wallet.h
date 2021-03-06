// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// The root object that holds all data for 371pass. This
// class contains Categories, which in turn hold Items,
// which hold a mapping of entries.
// -----------------------------------------------------

#ifndef WALLET_H
#define WALLET_H

#include "item.h"
#include "category.h"
#include "lib_json.hpp"

class Wallet {
    private:
    std::map<std::string,Category> categories;

    public:
    Wallet();
    ~Wallet();
    unsigned int size() const;
    bool empty() const;
    Category& newCategory(const std::string &catIdent);
    bool addCategory(const Category &category);
    const Category& getCategory(const std::string &catIdent) const;
    bool deleteCategory(const std::string &catIdent);
    void load(const std::string &filename);
    std::string str() const;
    void save(const std::string &path);
};

#endif // WALLET_H
