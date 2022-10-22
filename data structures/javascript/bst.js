/* BST in js
Copyrigth 2020 Laura Irene Capo Hdz*/



function Node(data, left, right) {
    this.data = data;
    this.left = left;
    this.right = right;
    this.show = show;
}

var isEmpty = true;

function show() {
    return this.data;

}

/*The Node object stores both data and links to other nodes (left and right). There is
also a show() function for displaying the data stored in a node*/

function BST() {
    this.root = root;
    this.insert = insert;
    this.inOrder = inOrder;
    this.preOrder = preOrder;
    this.postOrder = postOrder;

}

function NewBST() {
    var Nodos = [];

}

function NBST() {
    return BST(Nodos, isEmpty);

}

function insert(data) {
    var current = Nodos[0];
    while (current.isEmpty) {
        if (data < current) {
            current = Nodos[current.left];

        } else {
            current = Nodos[current.right];

        }


    }
    current.data, current.isEmpty = data, false;
    current.left = NewBST.Nodos;
    current.left = NewBST.Nodos + 1;
    NewBST.Nodos = add(NewBST.Nodos, BST.isEmpty(true), Nodos.isEmpty(true));


}


function inOrder(node) {
    if (node != null) {
        inOrder(node.left);
        putstr(node.show() + " ");
        inOrder(node.right);
    }
}

function preOrder(node) {
    if (!(node == null)) {
        putstr(node.show() + " ");
        preOrder(node.left);
        preOrder(node.right);
    }
}

function postOrder(node) {
    if (!(node == null)) {
        postOrder(node.left);
        postOrder(node.right);
        putstr(node.show() + " ");
    }
}


function getMin() {
    var current = this.root;
    while (current.left != null) {
        current = current.left;
    }
    return current.data;
}
/*Function get min, finds the minimun value of a BST*/

function getMax() {
    var current = this.root;
    while (!(current.right == null)) {
        current = current.right;
    }
    return current.data;
}
/*Function get max, finds the maximus value of a BST*/


function find(data) {
    var current = this.root;
    while (current.data != data) {
        if (data < current.data) {
            current = current.left;
        } else {
            current = current.right;
        }
        if (current == null) {
            return null;
        }
    }
    return current;
}
/* Function find returns the current node if the value is found in the BST and returns null
if the value is not found.*/

function remove(data) {
    root = removeNode(this.root, data);
}

function removeNode(node, data) {
    if (node == null) {
        return null;
    }
    if (data == node.data) {
        // node has no children
        if (node.left == null && node.right == null) {
            return null;
        }
        // node has no left child
        if (node.left == null) {
            return node.right;
        }
        // node has no right child
        if (node.right == null) {
            return node.left;
        }
        // node has two children
        var tempNode = getSmallest(node.right);
        node.data = tempNode.data;
        node.right = removeNode(node.right, tempNode.data);
        return node;
    } else if (data < node.data) {
        node.left = removeNode(node.left, data);
        return node;
    } else {
        node.right = removeNode(node.right, data);
        return node;
    }
}


function getSize() {
    return getSize(root);
}

function getSize(node) {
    if (node == null) {
        return 0;

    } else {
        var result = 1 + getSize(node.left) + getSize(node.right);
        return result;
    }

}

function getHeight() {
    return getHeight(root);
}

function getHeight(node) {
    if (node == null) {
        return 0;
    } else {
        var result = 1 + Math.max(getHeight(node.right), getHeight(node.left));
        return result;

    }

}

function getDepth() {
    var depth = 0;
    node = this.parent;
    while (node != null) {
        depth++;
        node = node.parent;
    }
    return depth;
}