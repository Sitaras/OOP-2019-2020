#include <iostream>
#include <string>
#include "forum.h"
using namespace std;

    tree::tree(post* posts_ar,int nump):root(NULL){
        for(int i=0;i<nump;i++){
          if (root==NULL)
            root=insert(posts_ar[i].get_creator(), root); /* create the tree nodes from authors/creators of the posts of thread */
          else
            insert(posts_ar[i].get_creator(), root);
        }
        for(int i=0;i<nump;i++){
            insert_posts(&posts_ar[i],posts_ar[i].get_creator()); /* insert posts of same authors/creators to the same node */
                                                                  /* as list */
        }
    }

    tree::~tree() {
        root = delete_tree(root);
    }

    node* tree::delete_tree(node* t) { /* delete tree node by node (postorder) */
        if(t == NULL)
            return NULL;
        else{
            delete_tree(t->left);
            delete_tree(t->right);
            delete t;
        }
        return NULL;
    }

    node* tree::insert(string x, node* t) /* insert creators/authors to the tree */
    {
        if(t == NULL)
        {
            t = new node;
            t->creator = x;
            t->head=NULL;
            t->left =NULL;
            t->right = NULL;
        }
        else if(x < t->creator)
            t->left = insert(x, t->left);
        else if(x > t->creator)
            t->right = insert(x, t->right);
        return t;
    }

    void tree::insert_posts(post* p,string s){
       node* cr_node = find(root, s); /* node of creator/author finded */
       if(cr_node->head == NULL){     /* if head isn't NULL, */
         cr_node->head=p;             /* insert p (post) at the end of the list */
       }
       else{
         post* temp=cr_node->head;
         while(temp->get_next()!=NULL){
            temp=temp->get_next();
         }
         temp->set_next(p);
       }
    }


    node* tree::find(node* t, string x) const { /* find node and return it */
        if(t == NULL)
            return NULL;
        else if(x < t->creator)
            return find(t->left, x);
        else if(x > t->creator)
            return find(t->right, x);
        else
            return t;
    }


    node* tree::create_node(node* t2){
      node* temp = new node;
      temp->creator=t2->creator;
      temp->head=t2->head;
      temp->left=NULL;
      temp->right=NULL;

      return temp;

    }

    void tree::link_posts(node* t1,node* t2){ /* link lists of posts t1 (basic) and t2 */
      post* temp = t1->head;
      while(temp->get_next()!=NULL){
        temp=temp->get_next();
      }
      temp->set_next(t2->head);
    }

    node* tree::search_node(node* t1,node* t2) { /* compare nodes of t1 (basic) and t2 */
            if(t1 == NULL){                      /* if creator/author of t1 is greater than t2 then */
                t1 = create_node(t2);            /* go to the left child of t1 to find it */
                return t1;                       /* else go to the right.If these are same, just link the list of t2 posts to t1 */
            }                                    /* If creator/author doesn't exist, create new node and insert this to t1 */
            else if(t1->creator > t2->creator)
                 t1->left=search_node(t1->left, t2);
            else if(t1->creator < t2->creator)
                t1->right=search_node(t1->right, t2);
            else
                link_posts(t1,t2);
            return t1;
        }

    void tree::enhancetrees(node* n){ /* "this" is the basic tree that enhancing */
      if(n==NULL)
        return;
      enhancetrees(n->left);          /* inorder traversal -> take the nodes of the other tree one by one */
      search_node(this->get_root(),n);
      enhancetrees(n->right);

    }

    void tree::inorder(node* t) const { /* tree printing */
        if(t == NULL)
            return;
        inorder(t->left);
        cout <<"->"<<t->creator << ": \n";
        post* temp=t->head;
        while (temp!= NULL) {
          cout << temp->get_text() << " "<<endl;
          temp=temp->get_next();
        }
        cout << endl;
        inorder(t->right);
    }


    node* tree::get_root() const {
          return root;
        }
////////////////////////////////////////////////////////////////////////////////
void forum::print_sorted() const {
  tree* tree1=NULL, *tree_temp=NULL;

  tree1=new tree(th_array[0].get_po_array(),th_array[0].get_numposts()); /* basic tree -> that will be enhance */

  for(int i=1; i<threads;i++){ /* tree1 enhances with trees (one by one) that made from other threads */
    tree_temp=new tree(th_array[i].get_po_array(),th_array[i].get_numposts());
    tree1->enhancetrees(tree_temp->get_root());
    delete tree_temp;
  }
  cout <<endl<< "~~~~~~~~ Final Tree ~~~~~~~~" << endl;
  tree1->inorder(tree1->get_root()); /* print the final tree after enhancing */
  delete tree1;

}
