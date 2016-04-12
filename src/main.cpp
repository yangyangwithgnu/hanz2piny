#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lib/self/libhanz2piny/Hanz2Piny.h"
#include "lib/helper/CmdlineOption.h"
#include "lib/helper/RichTxt.h"

using namespace std;

static const string g_softname(RichTxt::bold_on + "hanz2piny" + RichTxt::bold_off);
static const string g_version("0.1.0");
static const string g_myemail("yangyangwithgnu@yeah.net");
static const string g_myemail_color(RichTxt::bold_on + RichTxt::foreground_green + g_myemail + RichTxt::reset_all);
static const string g_mywebspace("http://yangyangwithgnu.github.io");
static const string g_mywebspace_color(RichTxt::bold_on + RichTxt::foreground_green + g_mywebspace + RichTxt::reset_all);


static void
showLogo (void)
{
#ifndef CYGWIN
    cout << endl
         << "  ██╗  ██╗ █████╗ ███╗   ██╗███████╗    ██████╗     ██████╗ ██╗███╗   ██╗██╗   ██╗" << endl
         << "  ██║  ██║██╔══██╗████╗  ██║╚══███╔╝    ╚════██╗    ██╔══██╗██║████╗  ██║╚██╗ ██╔╝" << endl
         << "  ███████║███████║██╔██╗ ██║  ███╔╝      █████╔╝    ██████╔╝██║██╔██╗ ██║ ╚████╔╝ " << endl
         << "  ██╔══██║██╔══██║██║╚██╗██║ ███╔╝      ██╔═══╝     ██╔═══╝ ██║██║╚██╗██║  ╚██╔╝  " << endl
         << "  ██║  ██║██║  ██║██║ ╚████║███████╗    ███████╗    ██║     ██║██║ ╚████║   ██║   " << endl
         << "  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝    ╚══════╝    ╚═╝     ╚═╝╚═╝  ╚═══╝   ╚═╝   " << endl
         << endl;
#endif // CYGWIN
}

static void
showHelpInfo (void)
{
    showLogo();

    cout << endl
         << "  hanz2piny is a tool that easy convert chinese hanzi to mandarin pinyin. It "
            "fast, no-DB-file, and supports polyphone." << endl;

    cout << endl
         << "  Some limiting condition you should keep in mind. ONE, hanz2piny just handle simplified and "
            "traditional chinese hanzi, no japan kanji, no korea hanja, and just output mandarin pinyin, "
            "no cantonese pinyin, no taiwanese pinyin; TWO, hanz2piny just handle the little-endian UTF-8 "
            "encoding file, no UTF-16 (yes, similar as your unicode), no ASCII. "
            "" << endl;

    cout << endl
         << "  The usage is very simple, total eight command line options, and only one needs you set up: " << endl;

    cout << endl << "\t--help. show this help info, ignore the others options;" << endl;
    cout << endl << "\t--version. show current version, ignore the others options except --help;" << endl;
    cout << endl << "\t--tone. set on that pinyin with tone;" << endl;
    cout << endl << "\t--camel. set on that the first letter of every pinyin in capital, I.E., camel style;" << endl;
    cout << endl << "\t--polyphone. some hanzi have more one pinyin, these ones I.E. polyphone. You can get "
                    "all option pinyin, set up argument as all; you focus pinyin in name, set up name; you "
                    "focus pinyin in non-name, set up noname. The default argument is noname;" << endl;
    cout << endl << "\t--replace-unknown. some char that hanz2piny could not handle, you can replace them by "
                    "set on this option;" << endl;
    cout << endl << "\t--replace-unknown-with. some char that hanz2piny could not handle, you can replace "
                    "them with string by set up this argument; " << endl;
    cout << endl << "\t--path. set up the file path that chinese hanzi file, make sure the file is exist "
                    "and the encoding is UTF-8. " << endl;

    cout << endl;
}

static void
showVersionInfo (void)
{
    cout << endl
         << g_softname << " version " << g_version << endl
         << "email " << g_myemail_color << endl
         << "webspace " << g_mywebspace_color << endl << endl;
}


int
main (int argc, char* argv[])
{
    // 解析命令行选项
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    CmdlineOption cmdline_options((unsigned)argc, argv);
    vector<string> cmdline_arguments_list;

    // --help, first priority, ignore other options
    if (cmdline_options.hasOption("--help")) {
        showHelpInfo();
        exit(EXIT_SUCCESS);
    }

    // --version, second priority, ignore other options
    if (cmdline_options.hasOption("--version")) {
        showVersionInfo();
        exit(EXIT_SUCCESS);
    }

    // --tone
    const bool tone = cmdline_options.hasOption("--tone"); 

    // --camel
    const bool camel = cmdline_options.hasOption("--camel"); 

    // --polyphone
    Hanz2Piny::Polyphone polyphone;
    cmdline_arguments_list = cmdline_options.getArgumentsList("--polyphone");
    if (cmdline_arguments_list.empty()) {
        polyphone = Hanz2Piny::noname;
    } else {
        if ("all" == cmdline_arguments_list[0]) {
            polyphone = Hanz2Piny::all;
        } else if ("name" == cmdline_arguments_list[0]) {
            polyphone = Hanz2Piny::name;
        } else {
            polyphone = Hanz2Piny::noname;
        }
    }

    // --replace-unknown
    const bool replace_unknown = cmdline_options.hasOption("--replace-unknown"); 

    // --replace-unknown-with
    cmdline_arguments_list = cmdline_options.getArgumentsList("--replace-unknown-with");
    const string replace_unknown_with = (cmdline_arguments_list.empty() ? "" : cmdline_arguments_list[0]);

    // --path
    cmdline_arguments_list = cmdline_options.getArgumentsList("--path");
    if (cmdline_arguments_list.empty()) {
        cerr << "ERROR! there is no --path, more info see --help. " << endl;
        exit(EXIT_FAILURE);
    }
    const string file_path = cmdline_arguments_list[0];

    // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


    const Hanz2Piny hanz2piny;
    if (!hanz2piny.isUtf8File(file_path)) {
        cerr << "ERROR! fail to open UTF-8 encoding file " << file_path
             << ". make sure the file is exist and the encoding is UTF-8. "
             << endl;
        exit(EXIT_FAILURE);
    }
    
    ifstream utf8_ifs(file_path);
    string line;
    while (getline(utf8_ifs, line)) {
        // 去掉 BOM 头
        if (hanz2piny.isStartWithBom(line)) {
            line = string(line.cbegin() + 3, line.cend());
        }
        
        vector<pair<bool, vector<string>>> pinyin_list_list = hanz2piny.toPinyinFromUtf8( line,
                                                                                          tone,
                                                                                          replace_unknown,
                                                                                          replace_unknown_with );
        for (const auto& e : pinyin_list_list) {
            const bool ok = e.first;
            auto pinyin_list = e.second;
            
            if (pinyin_list.size() == 1) {          // 单音字
                auto pinyin = pinyin_list[0];
                if (ok && camel) {
                    pinyin[0] = (char)toupper(pinyin[0]);
                }
                cout << pinyin;
            } else if (pinyin_list.size() > 1) {    // 多音字
                switch (polyphone) {
                    case Hanz2Piny::all: {
                        cout << '<';
                        for (auto pinyin : pinyin_list) {
                            if (ok && camel) {
                                pinyin[0] = (char)toupper(pinyin[0]);
                            }
                            cout << pinyin << ", ";
                        }
                        cout << "\b\b>";
                    }
                    break;
                    
                    case Hanz2Piny::name: {
                        auto pinyin = pinyin_list[0];
                        if (ok && camel) {
                            pinyin[0] = (char)toupper(pinyin[0]);
                        }
                        cout << pinyin;
                    }
                    break;
                    
                    case Hanz2Piny::noname: {
                        auto pinyin = pinyin_list[1];
                        if (ok && camel) {
                            pinyin[0] = (char)toupper(pinyin[0]);
                        }
                        cout << pinyin;
                    }
                    break;
                }
            } else {                                // 该 UTF-8 编码并无对应汉字，相应也就不存在拼音
                NULL;
            }
        }
        cout << endl;
    }


    return(EXIT_SUCCESS);
}

