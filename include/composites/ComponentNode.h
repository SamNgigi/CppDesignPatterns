#ifndef _COMPONENT_NODE_H
#define _COMPONENT_NODE_H

#include <string>
#include <memory>
#include <stdexcept>

// Forward declaration
class Visitor;

class ComponentNode {
    public:
    class InvalidFunctionCall_Exception: public std::domain_error{
        public:
        explicit InvalidFunctionCall_Exception(const std::string &message): std::domain_error(message){}
    };

    /**
     * @brief The constansts below uniquely identify the type of each terminal symbol.
     */
    static const int MULTIPLICATION = 0;
    static const int DIVISION = 1;
    static const int ADDITION = 2;
    static const int SUBTRACTION = 3;
    static const int NEGATION = 4;
    static const int LEFT_PARENTHESIS = 5;
    static const int RIGHT_PARENTESIS = 6;
    static const int ID = 7;
    static const int NUMBER = 8;
    static const int DELIMITER = 9;

    /**
     * @brief The relative precedence of each terminal symbol above when it appears at the top of the stack
     */
    constexpr static const int top_of_stack_precedence_[] = {
        12, 11, 7, 6, 10, 2, 3, 15, 14, 1
    };

    /**
     * @brief The relative precedence of each terminal symbol above when it appears at the top of the stack
     */
    constexpr static const int current_token_precedence_[] = {
        9, 8, 5, 4, 13, 18, 2, 17, 16, 1
    };

    //* DESTRUCTOR
    virtual ~ComponentNode () = 0;

    //* Returns the type of the component node ,Unary, Binary, Add etc.
    //* Used by the In_Order_Intepreter's operator-precedence parsing algorithm
    [[nondiscard]] int get_type() const;

    //* Returns the item stored in the node. Throws std::domain_error if called directly
    [[nondiscard]] virtual int item() const;
    //* Return left child - returns 0 if called directly
    [[nondiscard]] virtual ComponentNode *left() const;
    //* Returns right child - returns 0 if called directly
    [[nondiscard]] virtual ComponentNode *right() const;
    //* Accepts a visitor to perform some action on the node's item. 
    //* Completely arbitrary visitor template. Throws std::domain_error if called directly
    virtual void accept(Visitor &visitor) const;


    private:
    int type_;

    


};

#endif /* _COMPONENT_NODE_H */