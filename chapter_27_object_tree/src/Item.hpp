#pragma once
#include <iostream>
#include <memory>
#include <vector>

class Item
{
public:
    Item(std::string name, std::shared_ptr<Item> parent = nullptr)
        : m_name(name)
        , m_parent(parent)
    {
        std::cout << "ctor " << m_name << std::endl;
    }

    ~Item()
    {
        std::cout << "dtor " << m_name << std::endl;
    }

    void log(std::string delimiter)
    {
        std::string parentName;
        if(m_parent.lock())
        {
            parentName = " *** " + m_parent.lock()->getName();
        }

        std::cout << "LOG: " << delimiter << m_name << parentName << std::endl;

        delimiter.append("-");
        for(auto child : m_children)
        {
            child->log(delimiter);
        }
    }

    void addChild(std::shared_ptr<Item> child)
    {
        m_children.push_back(child);
    }

    const std::string getName()
    {
        return m_name;
    }

    std::shared_ptr<Item> getChildByName(const std::string& name) const
    {
        for(auto child : m_children)
        {
            if(child->getName().compare(name) == 0)
            {
                return child;
            }
        }

        return nullptr;
    }

private:
    std::string m_name;
    std::weak_ptr<Item> m_parent;
    std::vector<std::shared_ptr<Item>> m_children;
};