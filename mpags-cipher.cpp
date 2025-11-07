#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
    const std::vector<std::string> cmdLineArgs{argv, argv + argc};

    // Check for --help flag
    for (const auto &it : cmdLineArgs) {
        // std::cout << it << std::endl;
        if (it == "--help" || it == "-h") {
            std::cout << "Usage: mpags-cipher [-h|--help]...\n\n"
                         "Encrypt/decrypt input alphanumeric text using classical cyphers\n\n"
                         "Options:\n"
                          "-h|--help Display this information\n"
                         "--version Display version\n"
                         "-i input_file Specify input file\n"
                         "-o output_file Specify output file\n";
            return 0;
        }
    }
    // Check for --version flag
    for (const auto &it : cmdLineArgs) {
        if (it == "--version") {
            std::cout << "mpags-cipher 1.0.0" << std::endl;
            return 0;
        }
    }

    std::string input_file, output_file;
    for (int i = 0; i < argc; ++i) {
        if (cmdLineArgs[i] == "-i") {
            if (!input_file.empty()) {
                std::cerr << "Error: More than one input file specified" << std::endl;
                return 1;
            }
            if (i + 1 == argc || cmdLineArgs[i + 1][0] == '-') {
                std::cerr << "Error: No input file specified" << std::endl;
                return 1;
            }
            input_file = cmdLineArgs[++i];
        }
        else if (cmdLineArgs[i] == "-o") {
            if (!output_file.empty()) {
                std::cerr << "Error: More than one output file specified" << std::endl;
                return 1;
            }
            if (i + 1 == argc || cmdLineArgs[i + 1][0] == '-') {
                std::cerr << "Error: No output file specified" << std::endl;
                return 1;
            }
            output_file = cmdLineArgs[++i];
        }
    }
    if (!input_file.empty()) {
        std::cout << "Input file:" << input_file << std::endl;
    }
    if (!output_file.empty()) {
        std::cout << "Ouput file:" << output_file << std::endl;
    }

    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}