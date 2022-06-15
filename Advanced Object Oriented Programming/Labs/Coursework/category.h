// -----------------------------------------------------
// CSC371 Advanced Object Oriented Programming (2021/22)
// Department of Computer Science, Swansea University
//
// Author: 1909435
//
// Canvas: https://canvas.swansea.ac.uk/courses/24793
// -----------------------------------------------------
// A category contains one or more Items, each with
// their own identifier ('ident').
// -----------------------------------------------------

#ifndef CATEGORY_H
#define CATEGORY_H
#include <iostream>
#include "item.h"
#include "lib_json.hpp"

class Category {
    private:
    std::string name;
    std::map<std::string, Item> items;
    

    public:
        Category(const std::string &ident);
        ~Category();
        unsigned int size() const;
        bool empty() const;
        std::string getIdent() const;
        void setIdent(std::string &ident);
        Item& newItem(const std::string &ident);
        bool addItem(const Item &item);
        const Item& getItem(const std::string &itemIdent) const;
        bool deleteItem(const std::string &itemIdent);
        std::map<std::string, Item> getCategories() const;
        std::string str() const;
        friend bool operator==(const Category& cat1, const Category& cat2);

};

#endif // CATEGORY_H
