#pragma once
#include <memory>
#include <set>
#include <algorithm>

#include "elements.h"

class Document
{
public:
    explicit Document()
    {
        std::cout << "Create new document" << std::endl;
    }

    explicit Document(std::string filename)
    {
        std::cout << "Import document from file" << filename << std::endl;
    }

    ~Document()
    {
        std::cout << "Delete document\n";
    }

    void exportInFile(std::string filename)
    {
        std::cout << "Export document in file" << filename << std::endl;
    }

    void createElement(std::unique_ptr<GraphicElement> element)
    {
        elements.emplace_back(std::move(element));
    }

    void removeElement(const std::vector<Coordinates> &coord)
    {
        auto it = std::find_if(elements.begin(), elements.end(),
                       [&coord](const std::unique_ptr<GraphicElement> &el) {
                           return el->isSame(coord);
                       });
        if (it != std::end(elements)) {
            elements.erase(it);
        }



    }

private:
    std::vector<std::unique_ptr<GraphicElement>> elements;
    std::set<std::unique_ptr<GraphicElement>> elementsSet;
};
