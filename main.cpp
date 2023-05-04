/* Split
 *
 * Description
 *
 * Program splits the string from separator. Empty space will occur if the
 * string has two separators successively or if string starts or ends with
 * separator. If there are more separators successively then an empty will occur
 * from every space where is no chars. If variable parts_no_empty is false, then
 * program won't return parts where is no chars.
 *
 * Writer of the program
 *
 * Name: EILeh
 */

#include <iostream>
#include <string>
#include <vector>


// Takes a line that user wants to split as a parameter, the separator is the
// char that the line is separated from and variable parts_no_empty has a truth
// value if user wants the empty parts or not.
std::vector<std::string> split(std::string line, char separator,
                               bool parts_no_empty = false)
{

    std::vector<std::string> splitted_vector = {};
    std::string substring = "";

    // Goes through the given string line char by char.
    for ( char c : line )
    {
        // If current char is the separator.
        if ( c == separator )
        {
            // If part_no_empty is false and substring is not empty, substring
            // is added to a variable splitted_vector and the cleared.
            if (!(parts_no_empty && substring.empty()))
            {
                splitted_vector.push_back(substring);
                substring.clear();
            }
        }

        // If c is not separator, current char is added to the substring that it
        // forms a wanted split string.
        else
        {
            substring += c;
        }
    }

    // If variable parts_no_empty is false and substring is not empty, then adds
    // the last split to the vector as well.
    if (!(parts_no_empty && substring.empty()))
    {
        splitted_vector.push_back(substring);
        substring.clear();
    }

    return splitted_vector;

}


int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
