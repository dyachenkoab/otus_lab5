#include "editor.h"

int main()
{
    GraphicEditor editor;

    editor.createDocument();

    editor.addElement(
                std::make_unique<Triangle>(std::vector<Coordinates> { { 1, 1 }, { 2, 3 }, { 3, 1 } }, "red"));

    editor.addElement(std::make_unique<Square>(
        std::vector<Coordinates> { { 2, 2 }, { 3, 2 }, { 2, 4 }, { 3, 4 } },
        "transparent"));

    editor.addElement(
        std::make_unique<Line>(std::vector<Coordinates> { { 3, 3 }, { 5, 3 } }, "green"));

    editor.removeElement(std::vector<Coordinates> { { 1, 1 }, { 2, 3 }, { 3, 1 } });

    editor.exportDocument({ "filename" });

    return 0;
}
