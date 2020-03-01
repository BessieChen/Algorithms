//
//  BST.h
//  BST_cpp
//
//  Created by 陈贝茜 on 2019/7/21.
//  Copyright © 2019 Bessie Chen. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <queue>
using namespace std;

template<typename K, typename V>
class BST
{
private:
    
    struct Node
    {
        K key;
        V value;
        Node *left;
        Node *right;
        
        Node(K key, V value)
        {
            this->key = key;
            this->value = value;
            this->left = nullptr;
            this->right = nullptr;
        }
        
        Node(const Node *node)
        {
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };
    
    Node *root;
    int size;
    
    void destroy(Node *node)//采用的是后序遍历，先保证左右子被删除
    {
        //if(node == nullptr) return; //其实这一句可以不要，直接就执行下一句。
        if(node != nullptr)
        {
            destroy(node->left);
            destroy(node->right);
            delete node;
            size--;
        }
    }
    
public:
    BST()
    {
        root = nullptr;
        size = 0;
    }
    
    ~BST()
    {
        destroy(root);
    }
    
    // ----------  基本 -----------
    int getSize()
    {
        return size;
    }
    
    bool isEmpty()
    {
        return size == 0;
    }
    
    void print()
    {
        generateString(root, 0);
    }
    
    //------------- 特有 ------------------
    void preOrder()
    {
        preOrder(root);
    }
    
    void inOrder()
    {
        inOrder(root);
    }
    
    void postOrder()
    {
        postOrder(root);
    }
    
    void levelOrder()
    {
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            Node *node = queue.front();//注意cpp的queue的pop()是没有返回值的，不像我们自己的pop()
            queue.pop();
            cout<<node->key<<" : "<<node->value<<endl;
            
            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        }
        
    }
    
    //------------- 增删改查 ------------------
    void add(K key, V value)
    {
        root = add(root, key, value);
    }
    
    bool set(K key, V newVal)
    {
        Node *node = getNode(root, key);
        if(node == nullptr) return false;
        node->value = newVal;
        return true;
    }
    
    bool contains(K key)
    {
        return getNode(root, key) != nullptr;
    }
    
    V* get(K key)
    {
        Node *node = getNode(root, key);
        if(node == nullptr) return nullptr;
        return &(node->value);
    }
    
    V* minimum()
    {
        return &(minimum(root)->value);
    }
    
    void removeMin()
    {
        assert(size > 0);
        root = removeMin(root);
    }
    
    void remove(K key)
    {
        assert(size > 0);
        root = remove(root, key);
    }
    
    
private:
    //------------- 基本函数 ------------------
    void generateString(Node *node, int depth)
    {
        generateDepth(depth + 1);
        if(node == nullptr)
        {
            cout<<"NULL"<<endl;
        }
        else
        {
            cout<<node->value<<endl;
            generateString(node->left, depth + 1);
            generateString(node->right, depth + 1);
        }
    }
    
    void generateDepth(int depth)
    {
        for(int i = 0 ; i < depth + 1; i++)
        {
            cout<<"--|";
        }
    }
    //------------- 特有 ------------------
    void preOrder(Node *node)
    {
        if(node != nullptr)
        {
            cout<<node->key<<" : "<<node->value<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    
    void inOrder(Node *node)
    {
        if(node != nullptr)
        {
            inOrder(node->left);
            cout<<node->key<<" : "<<node->value<<endl;
            inOrder(node->right);
        }
    }
    
    void postOrder(Node *node)
    {
        if(node != nullptr)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<" : "<<node->value<<endl;
        }
    }
    
    //------------- 增删改查 ------------------
    Node* add(Node *node, K key, V value)
    {
        if(node == nullptr)
        {
            size++;
            return new Node(key, value);
        }
        
        if(node->key < key)
        {
            node->right = add(node->right, key, value);
        }
        else if(node->key > key)
        {
            node->left = add(node->left, key, value);
        }
        else
        {
            node->value = value;
        }
        return node;
    }
    
    Node* getNode(Node* node, K key)
    {
        if(node == nullptr) return node;
        if(node->key < key)
        {
            return getNode(node->right, key);
        }
        else if(node->key > key)
        {
            return getNode(node->left, key);
        }
        else
        {
            return node;
        }
    }
    
    Node* minimum(Node *node)
    {
        if(node == nullptr) return node;
        if(node->left == nullptr) return node;
        return minimum(node->left);
    }
    
    Node* removeMin(Node *node)
    {
        if(node == nullptr)
        {
            return node;
        }
        if(node->left == nullptr)
        {
            size--;
            return node->right;
        }
        node->left = removeMin(node->left);
        return node;
    }
    
    Node* remove(Node *node, K key)
    {
        if(node == nullptr) return node;
        if(node->key < key)
        {
            node->right = remove(node->right, key);
        }
        else if(node->key > key)
        {
            node->left = remove(node->left, key);
        }
        else
        {
            if(node->left == nullptr)
            {
                size--;
                return node->right;
            }
            else if(node->right == nullptr)
            {
                size--;
                return node->left;
            }
            else
            {
                Node *successor = new Node(minimum(node->right));
                successor->right = removeMin(node->right);
                successor->left = node->left;
                delete node;
                return successor;
            }
        }
        return node;
    }
    
};

#endif /* BST_h */
