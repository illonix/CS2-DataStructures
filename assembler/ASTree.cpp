//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2025 Kent State University. All rights reserved.
//  Spring 2025
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header;
    if (actual.tree)
        tree   = new AST(*(actual.tree));
    else
        tree = 0;
}

// Destructor for srcML
//
srcML::~srcML() {
    delete tree;
}


// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::insertMainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->insertMainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::insertFileHeader(const std::string& profileName) {
    tree->insertFileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::insertMainReport(const std::vector<std::string>& profileName) {
        tree->insertMainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::insertFunctionCount(const std::string& profileName) {
    tree->insertFunctionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::insertLineCount(const std::string& profileName) {
    tree->insertLineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    //TODO: IMPLEMENT
    if(!child.empty()) {
        std::list<AST*>::iterator ptr = child.begin();
        while(ptr != child.end()) {
            delete *ptr;
            ++ptr;
        }
    }
    //Recursively traverse tree and delete from bottom up
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //TODO: IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
    //TODO: IMPLEMENT
    nodeType = actual.nodeType;
    tag =      actual.tag;
    closeTag = actual.closeTag;
    text =     actual.text;

    if(actual.child.empty()) return;
    for(std::list<AST*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i) {
        child.push_back(new AST(**i)); // This line may be wrong if anything is
    }


    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //TODO: IMPLEMENT
    //Swap all the top level childern (pointers to AST)
    nodes tempType = nodeType;
    nodeType = rhs.nodeType;
    rhs.nodeType = tempType;

    std::string tempTag = tag;
    tag = rhs.tag;
    rhs.tag = tempTag;

    std::string tempCloseTag = closeTag;
    closeTag = rhs.closeTag;
    rhs.closeTag = tempCloseTag;

    std::list<AST*> tempChild = child;
    child = rhs.child;
    rhs.child = tempChild;

    std::string tempText = text;
    text = rhs.text;
    rhs.text = tempText;
}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::insertMainHeader(const std::vector<std::string>& profileName,
                           const std::vector<std::string>& fileName) {

    auto ptr = child.begin();

    // Find the main function
    while (ptr != child.end() && (*ptr)->tag != "function") {
        ++ptr;
    }

    // Insert #include "profile.hpp"
    AST* include = new AST(token, "#include \"profile.hpp\"\n");
    child.insert(ptr, include);

    // Insert each profile declaration
    for (size_t i = 0; i < profileName.size(); ++i) {
        std::string profileDecl = "profile " + profileName[i] + "(\"" + fileName[i] + "\");\n";
        include = new AST(token, profileDecl);
        child.insert(ptr, include);
    }

    if (ptr != child.begin()) {
        (*(--ptr))->text += '\n';
    }

    // TODO: Skip down a couple lines or find main and put it before it
    // Add a node with #include "profile.hpp"
    // For each file profile name, add a node with a profile
    // declaration "profile foo_cpp("foo.cpp");"
}

void AST::insertFileHeader(const std::string& profileName) {
    auto ptr = child.begin();

    // Find first function, constructor, or destructor
    while (ptr != child.end() &&
          (*ptr)->tag != "function" &&
          (*ptr)->tag != "constructor" &&
          (*ptr)->tag != "destructor") {
        ++ptr;
    }

    // Insert #include "profile.hpp"
    AST* include = new AST(token, "#include \"profile.hpp\"\n");
    child.insert(ptr, include);

    // Insert extern declaration
    include = new AST(token, "extern profile " + profileName + ";\n");
    child.insert(ptr, include);

    if (ptr != child.begin()) {
        (*(--ptr))->text += '\n';
    }

    // TODO: Skip down a couple lines or find first function and put it before it
    // Add #include "profile.hpp"
    // Add external declaration "extern profile foo_cpp;"
}

void AST::insertMainReport(const std::vector<std::string>& profileName) {
    auto ptr = child.begin();

    // Find main function
    while (ptr != child.end() &&
          ((*ptr)->tag != "function" || (*ptr)->getChild("name")->getName() != "main")) {
        ++ptr;
    }

    // Get block's block_content and find the insertion point
    auto blockContent = (*ptr)->getChild("block")->getChild("block_content");
    auto blockptr = blockContent->child.end();
    --blockptr; // Move before the closing "}"

    // Search backwards for a return statement
    while (blockptr != blockContent->child.begin() && (*blockptr)->tag != "return") {
        --blockptr;
    }

    if (blockptr == blockContent->child.begin()) {
        blockptr = --blockContent->child.end(); // If no return found, insert before closing "}"
    }

    // Insert report printouts before return
    for (size_t i = 0; i < profileName.size(); ++i) {
        std::string reportStmt = "\nstd::cout << " + profileName[i] + " << std::endl;";
        blockContent->child.insert(blockptr, new AST(token, reportStmt));
    }

    if (blockptr != blockContent->child.begin()) {
        (*(--blockptr))->text += "\n\n";
    }

    // TODO: Find the main function
    // Insert report printouts before return
}



// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::insertFunctionCount(const std::string& profileName) {

    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");
std::list<AST*>::iterator funcIter = child.begin();
std::list<AST*>::iterator insertPos;

while (funcIter != child.end()) {
    if ((*funcIter)->tag == "function" || 
        (*funcIter)->tag == "constructor" || 
        (*funcIter)->tag == "destructor") {
        
        std::list<AST*>::iterator nameIter = (*funcIter)->child.begin();

        while (nameIter != (*funcIter)->child.end()) {
            if ((*nameIter)->tag == "name") {

                std::list<AST*>::iterator blockSearchIter = (*funcIter)->child.begin();

                while (blockSearchIter != (*funcIter)->child.end()) {
                    if ((*blockSearchIter)->tag == "block") {

                        std::list<AST*>::iterator braceSearchIter = (*blockSearchIter)->child.begin();

                        while (braceSearchIter != (*blockSearchIter)->child.end()) {
                            if ((*braceSearchIter)->text == "{") {
                                insertPos = braceSearchIter;
                            }
                            ++braceSearchIter;
                        }
                    }
                    ++blockSearchIter;
                }

                // Accounts for every function
                std::string funcName = (*nameIter)->getName();
                std::string toInsert = " " + profileName + ".count(__LINE__, \"" + funcName + "\");";
                child.insert(++insertPos, new AST(token, toInsert));
            }
            ++nameIter;
        }
    }
    ++funcIter;
}

    

}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::insertLineCount(const std::string& profileName) {

    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing
    std::string insertInto = " " + profileName + ".count(__LINE__);";
    std::list<AST*>::iterator i = child.begin();
    while (i != child.end()) {
        if (!(*i)->child.empty()) {
            (*i)->insertLineCount(profileName); //Recursive call to count lines 
        }
        if ((*i)->tag == "expr_stmt") {
            if (!isStopTag((*i)->tag))
                (*i)->child.push_back(new AST(token, insertInto));
        }
        ++i;
    }
    
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST         *subtree;
    std::string temp;
    char        ch;
    
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

