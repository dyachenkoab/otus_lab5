#ifndef EDITOR_H
#define EDITOR_H
#include "header.h"

class GraphicEditor
{
public:
    void createDocument()
    {
        document = std::make_unique<Document>();
    }

    void importDocument(std::string filename)
    {
        document = std::make_unique<Document>(std::move(filename));
    }

    void exportDocument(std::string filename)
    {
        document->exportInFile(std::move(filename));
    }

    void addElement(std::unique_ptr<GraphicElement> element)
    {
        document->createElement(std::move(element));
    }

    void removeElement(const std::vector<Coordinates> &element)
    {
        document->removeElement(element);
    }

private:
    std::unique_ptr<Document> document;
};


#endif // EDITOR_H
