using std::string;

class thread;
class post;

struct node {
    string creator;
    post* head;
    node* left;
    node* right;
};
class tree {
private:
    node* root;


    node* delete_tree(node*);
    node* insert(string, node* );

    node* find(node*, string) const;

    node* create_node(node*);

    node* search_node(node* ,node*);

    void link_posts(node*,node*);
    void insert_posts(post* ,string);
public:

    tree(post*,int);
    ~tree();


    void enhancetrees(node*);
    void inorder(node*) const;


    node* get_root() const;

};
