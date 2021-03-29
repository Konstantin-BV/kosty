
#include <iostream>
#include <string>
#include <map>
using namespace std;
struct Node
{
    Node* left;   //   левый сын
    Node* right;  //  правый сын, 
    Node* parent;      // родитель
    char color;  // цвет
    string key;
    Node(Node* l, Node* r, Node* p, string v) : left(l), right(r), parent(p), color('r'), key(v) {}
    Node(Node* l, Node* r, Node* p, char d, string v) : left(l), right(r), parent(p), color(d), key(v) {}
};
class RBtree
{
private:

public:
    Node* NIL = new Node(NULL, NULL, NULL, 'b', "0");
    Node* root = NULL;
    map <string, int> associa;

    void print(Node* ROOT)
    {

        if (ROOT == NULL)
        {
            cout << NIL->key << NIL->color << "  ";
            return;
        }


        print(ROOT->left);

        cout << associa[ROOT->key] << ROOT->color << "  ";

        print(ROOT->right);
        return;
    }
    void get_values(Node* ROOT)
    {

        if (ROOT == NULL)
        {
            return;
        }
        print(ROOT->left);
        cout << associa[ROOT->key] << "  ";
        print(ROOT->right);
        return;
    }
    void get_keys(Node* ROOT)
    {
        if (ROOT == NULL)
        {
            return;
        }
        print(ROOT->left);
        cout << ROOT->key << "  ";
        print(ROOT->right);
        return;
    }
    void Repainting(Node* ROOT)
    {
        if (ROOT->color == 'r')
            ROOT->color = 'b';
        else
            ROOT->color = 'r';
    }
    void InsertMap(string k, int i)
    {
        associa[k] = i;
    }
    void
        rotate_left(struct Node* n)
    {
        struct Node* pivot = n->right;

        pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
        if (n->parent != NULL) {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->left = pivot;
        }
        if (n == root)
            root = pivot;
        n->right = pivot->left;
        if (pivot->left != NULL)
            pivot->left->parent = n;

        n->parent = pivot;
        pivot->left = n;
    }

    void
        rotate_right(struct Node* n)
    {
        struct Node* pivot = n->left;

        pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
        if (n->parent != NULL)
        {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }
        if (n == root)
            root = pivot;
        n->left = pivot->right;
        if (pivot->right != NULL)
            pivot->right->parent = n;

        n->parent = pivot;
        pivot->right = n;
    }

    void
        insert_case1(struct Node* n)
    {
        if (!n->parent)
            n->color = 'b';
        else
            insert_case2(n);
    }
    void
        insert_case2(struct Node* n)
    {
        if (n->parent->color == 'b')
            return; /* Tree is still valid */
        else
            insert_case3(n);
    }
    Node* uncle(struct Node* n)
    {
        struct Node* g = n->parent->parent;
        if (g == NULL)
            return NULL; // No grandparent means no uncle
        if (n->parent == g->left)
            return g->right;
        else
            return g->left;
    }
    void insert_case3(struct Node* n)
    {
        struct Node* u = uncle(n), * g;

        if ((u != NULL) && (u->color == 'r')) {
            // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
            n->parent->color = 'b';
            u->color = 'b';
            if ((n != NULL) && (n->parent != NULL))
                g = n->parent->parent;
            else
                g = NULL;
            g->color = 'r';
            insert_case1(g);
        }
        else {
            insert_case4(n);
        }
    }
    void
        insert_case4(struct Node* n)
    {
        Node* g;
        if ((n != NULL) && (n->parent != NULL))
            g = n->parent->parent;
        else
            g = NULL;
        if ((n == n->parent->right) && (n->parent == g->left)) {
            rotate_left(n->parent);
            n = n->left;
        }
        else if ((n == n->parent->left) && (n->parent == g->right)) {
            rotate_right(n->parent);
            n = n->right;
        }
        insert_case5(n);
    }
    void
        insert_case5(struct Node* n)
    {
        struct Node* g = n->parent->parent;

        n->parent->color = 'b';
        g->color = 'r';
        if ((n == n->parent->left) && (n->parent == g->left)) {
            rotate_right(g);
        }
        else { /* (n == n->parent->right) && (n->parent == g->right) */
            rotate_left(g);
        }
    }
    void Insert(Node* PARENT, Node* ROOT, string value)
    {
        if (!root)
        {
            root = new Node(NULL, NULL, PARENT, value);
            Repainting(root);
        }
        else
        {
            if (!PARENT)
            {
                PARENT = root;
            }
            if (value > PARENT->key)
            {
                if (!ROOT->right)
                {

                    ROOT->right = new Node(NULL, NULL, ROOT, value);
                    insert_case1(ROOT->right);
                    // fixViolation(root, ROOT->right);
                }
                else
                {
                    Insert(ROOT, ROOT->right, value);

                }
            }
            else
            {
                if (!ROOT->left)
                {
                    ROOT->left = new Node(NULL, NULL, ROOT, value);
                    insert_case1(ROOT->left);
                    // fixViolation(root, ROOT->left);
                }
                else
                {
                    Insert(ROOT, ROOT->left, value);
                }
            }
        }
    }
    Node* sibling(struct Node* n)
    {
        if (n == n->parent->left)
            return n->parent->right;
        else
            return n->parent->left;
    }
    void replace_node(Node* n, Node* child)
    {
        child->parent = n->parent;
        if (n == n->parent->left) {
            n->parent->left = child;
        }
        else {
            n->parent->right = child;
        }
    }

    void
        remove(struct Node* n)
    {
        /*
         * Условие: n имеет не более одного ненулевого потомка.
         */
        struct Node* child;
        if (!n->right)
            child = n->left;
        else
            child = n->right;
        replace_node(n, child);
        if (n->color == 'b') {
            if (child->color == 'r')
                child->color = 'b';
            else
                delete_case1(child);
        }
        free(n);
    }
    void
        delete_case1(struct Node* n)
    {
        if (n->parent != NULL)
            delete_case2(n);
    }
    void delete_case2(struct Node* n)
    {
        struct Node* s = sibling(n);

        if (s->color == 'r') {
            n->parent->color = 'r';
            s->color = 'b';
            if (n == n->parent->left)
                rotate_left(n->parent);
            else
                rotate_right(n->parent);
        }
        delete_case3(n);
    }
    void delete_case3(struct Node* n)
    {
        struct Node* s = sibling(n);

        if ((n->parent->color == 'b') &&
            (s->color == 'b') &&
            (s->left->color == 'b') &&
            (s->right->color == 'b')) {
            s->color = 'r';
            delete_case1(n->parent);
        }
        else
            delete_case4(n);
    }
    void delete_case4(struct Node* n)
    {
        struct Node* s = sibling(n);

        if ((n->parent->color == 'r') &&
            (s->color == 'b') &&
            (s->left->color == 'b') &&
            (s->right->color == 'b')) {
            s->color = 'r';
            n->parent->color = 'b';
        }
        else
            delete_case5(n);
    }
    void delete_case5(struct Node* n)
    {
        struct Node* s = sibling(n);

        if (s->color == 'b')
        {
            if ((n == n->parent->left) &&
                (s->right->color == 'b') &&
                (s->left->color == 'r')) { /* this last test is trivial too due to cases 2-4. */
                s->color = 'r';
                s->left->color = 'b';
                rotate_right(s);
            }
            else if ((n == n->parent->right) &&
                (s->left->color == 'b') &&
                (s->right->color == 'r')) {/* this last test is trivial too due to cases 2-4. */
                s->color = 'r';
                s->right->color = 'b';
                rotate_left(s);
            }
        }
        delete_case6(n);
    }
    void delete_case6(struct Node* n)
    {
        struct Node* s = sibling(n);

        s->color = n->parent->color;
        n->parent->color = 'b';

        if (n == n->parent->left) {
            s->right->color = 'b';
            rotate_left(n->parent);
        }
        else {
            s->left->color = 'b';
            rotate_right(n->parent);
        }
    }
    void clear()
    {
        associa.clear();
        root = NULL;
    }
    Node* find(string finder)
    {
        Node* ROOT = root;
        while (finder != ROOT->key)
        {
            if (finder > ROOT->key)
            {
                if (ROOT->right == NULL)
                    return NULL;
                ROOT = ROOT->right;
            }
            else
            {
                if (ROOT->left == NULL)
                    return NULL;
                ROOT = ROOT->left;
            }
        }
        return ROOT;
    }
};

