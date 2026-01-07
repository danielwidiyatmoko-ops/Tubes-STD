#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

// primitive data structure for the Multi-Level Linked List
typedef struct MLLPNode *MLLPNodePtr; //pointer to MLL Parent Node
typedef struct MLLCNode *MLLCNodePtr; //pointer to MLL Child Node
/************************
 Diagram of MLL structure:

  MLL
   |
 first -> [ PNode ] -> [ PNode ] -> NULL
              |            |-> [ CNode ] -> NULL
              v
            [ CNode ] -> [ CNode ] -> NULL
 ***********************/
struct MLLCNode {
    int data;                     
    MLLCNodePtr next;            
};
struct MLLPNode {
    int info;                      
    MLLCNodePtr childHead;       
    MLLPNodePtr next;            
};

struct MLL {
    MLLPNodePtr first;      // Pointer to the head of the parent node list
};

#endif // MLL_H_INCLUDED