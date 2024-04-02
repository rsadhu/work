class Node
{
    constructor(data)
    {
        this.val = data;
        this.left = null;
        this.right =  null;
    }
}


class BTree
{
    constructor()
    {
        this.root =  null;
    }

    add(data)
    {
        if (this.root === null)
        {
            this.root =  new Node(data);
        }
        else{
            let tra = this.root;
            while(tra != null)
            {
                if (data < tra.val)
                {
                    if (tra.left == null)
                    {
                        tra.left = new Node(data);
                        break
                    }
                    tra = tra.left;
                }
                else
                if (data > tra.val)
                {
                    if (tra.right == null)
                    {
                        tra.right = new Node(data);
                        break
                    }
                    tra = tra.right;
                }
            }
        }
    }

    addRec(root, data)
    {
        if (root == null)
        {
            root = new Node(data);
            return root;
        }

        if (data < root.val)
            root.left = this.addRec(root.left, data);

        if (data > root.val)
            root.right = this.addRec(root.right, data);

        return root;
    }

    insert(data)
    {
        this.root = this.addRec(this.root, data);
    }

    inOrder(root= this.root)
    {
        if (root != null)
        {
            this.inOrder(root.left);
            console.log(root.val);
            this.inOrder(root.right);
        }
    }

    clone(root = this.root)
    {
        if (root==null)
            return null;

        let new_node = new Node(root.val);
        new_node.left = this.clone(root.left);
        new_node.right = this.clone(root.right);
        return new_node;
    }

    mirror(root=this.root)
    {
        if (root == null)
            return root;

        let new_node = new Node(root.val);
        new_node.left = this.mirror(root.right);
        new_node.right = this.mirror(root.left);
        return new_node;
    }
}


bst = new BTree();

data = [50, 20, 70, 30, 60, 90, 10];

for (let d of data)
{
    bst.insert(d);
}

bst.inOrder();

root = bst.clone();

bst.inOrder(root);

mirror = bst.mirror();

bst.inOrder(mirror);