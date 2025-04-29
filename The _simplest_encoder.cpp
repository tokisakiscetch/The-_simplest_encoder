#include <iostream>
#include <vector>
#include <string>
#include <cctype>

std::string input_text()
{
    std::string text;
    std::cout << "Enter text -> ";
    std::getline(std::cin, text);
    return text;
}

int main()
{
    std::vector<char> alphabet{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
                              'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                              'u', 'v', 'w', 'x', 'y', 'z' };
    std::string text = input_text();
    std::string encodered_text;

    for (size_t i{}; i < text.length(); i++)
    {
        char sym = tolower(text[i]);
        bool found{ false };

        for (size_t j{}; j < alphabet.size(); j++)
        {
            if (sym == alphabet[j])
            {
                if (i == 0)
                {
                    encodered_text += toupper(alphabet[(j + 1) % alphabet.size()]);
                }
                else
                {
                    encodered_text += alphabet[(j + 1) % alphabet.size()];
                }
                found = true;
                break;
            }
        }

        if (!found)
        {
            encodered_text += text[i];
        }
    }

    std::cout << encodered_text << std::endl;
    return 0;
}