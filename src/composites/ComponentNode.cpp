#include "composites/ComponentNode.h"
#include "visitors/Visitor.h"

//* DESTRUCTOR
ComponentNode::~ComponentNode (void) = default;

int ComponentNode::get_type() const {
    return type_;
}

int ComponentNode::item () const {
    throw InvalidFunctionCall_Exception("ComponentNode::item() called improperly");
    return 0;
}

//* default left node to return a nullptr
ComponentNode* ComponentNode::left () const {
    return nullptr;
}

//* default right node to return a nullptr
ComponentNode* ComponentNode::right () const {
    return nullptr;
}

// accept a visitor
void ComponentNode::accept (Visitor &visitor) const {
    throw InvalidFunctionCall_Exception("ComponentNode::accept() called improperly");
}

